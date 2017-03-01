#!/bin/sh
#
# Copyright (c) 2010 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Joerg Sonnenberger.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

usage() {
	echo "Usage: $0 [-d]" >&2
	exit 2
}

header_ascii() {
}

footer_ascii() {	
}

enter_ascii() {
	if [ -z "$1" ]; then
		echo "$2"
	else
		echo "$indent|"
		echo "$indent+- $2"
	fi
	if [ "$3" = "yes" ]; then
		if [ -n "$1" ]; then
			indent="$indent   "
		fi
	else
		indent="$indent|  "
	fi
}
leave_ascii() {
	if [ "$3" = "yes" ]; then
		if [ -n "$1" ]; then
			indent="${indent%   }"
		fi
	else
		indent="${indent%|  }"
	fi
}

header_dot() {
	echo 'digraph "Device tree" {'
}
enter_dot() {
	if [ "$1" = "root" ]; then
		echo "$2"
	else
		echo "$1" "->" "$2"
	fi
}
leave_dot() {
}
footer_dot() {
	echo '}'
}

print_tree() {
	local child
	local children
	local children2
	[ "$1" = "root" ] || enter_node "$1" "$2" "$3"
	children2=$(drvctl -l $2 | while read parent child; do echo $child; done)
	if [ -n "$children2" ]; then
		children=""
		for child in $children2; do
			children="$children $child"
		done
		children2=""
		for child in ${children}; do
			children2="$children2 $child"
			if [ "$children" = "$children2" ]; then
				print_tree "$2" "$child" "yes"
			else
				print_tree "$2" "$child" "no"
			fi
		done
	fi
	[ "$1" = "root" ] || leave_node "$1" "$2" "$3"
}

args=`getopt d $*`
[ $? -eq 0 ] || usage

set -- $args

output=ascii

while [ $# -gt 0 ]; do
	case "$1" in
	-d)
		output=dot
		;;
	--)
		;;
	*)
		usage
		;;
	esac
	shift
done

case $output in
dot)
	enter_node() enter_dot "$@"
	leave_node() leave_dot "$@"
	print_header() header_dot "$@"
	print_footer() footer_dot "$@"
	;;
ascii)
	enter_node() enter_ascii "$@"
	leave_node() leave_ascii "$@"
	print_header() header_ascii "$@"
	print_footer() footer_ascii "$@"
	;;
esac

print_header
print_tree "root" "" "yes"
print_footer
