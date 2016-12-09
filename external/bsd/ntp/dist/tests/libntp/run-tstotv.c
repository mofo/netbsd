/*	$NetBSD: run-tstotv.c,v 1.1.1.3.8.2 2015/11/08 01:51:16 riz Exp $	*/

/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "config.h"
#include "ntp_fp.h"
#include "timevalops.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_Seconds(void);
extern void test_MicrosecondsExact(void);
extern void test_MicrosecondsRounding(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}

char const *progname;


//=======MAIN=====
int main(int argc, char *argv[])
{
  progname = argv[0];
  UnityBegin("tstotv.c");
  RUN_TEST(test_Seconds, 8);
  RUN_TEST(test_MicrosecondsExact, 9);
  RUN_TEST(test_MicrosecondsRounding, 10);

  return (UnityEnd());
}