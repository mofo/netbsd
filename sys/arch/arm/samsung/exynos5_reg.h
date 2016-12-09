/*	$NetBSD: exynos5_reg.h,v 1.10.4.1 2015/01/04 11:19:00 martin Exp $	*/

/*-
 * Copyright (c) 2014 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Nick Hudson.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ARM_SAMSUNG_EXYNOS5_REG_H_
#define _ARM_SAMSUNG_EXYNOS5_REG_H_

/*
 * Physical memory layout of Exynos5 SoCs as per documentation
 *
 * Base Address	Limit Address	Size	Description
 * 0x00000000	0x0000FFFF	 64 KB	iROM/iRAM/SROM
 * 0x02000000	0x0200FFFF	 64 KB	iROM (mirror of 0x0 to 0xFFFF)
 * 0x02020000	0x02077FFF	352 KB	iRAM
 * 0x03000000	0x03027FFF	160 KB	Data memory of SRP
 * 0x03028000	0x0303FFFF	 96 KB	I-cache of SRP
 * 0x03040000	0x03048FFF	 36 KB	Configuration memory of SRP (write-only)
 * 0x03800000	0x0386FFFF		SFR region of AudioSS
 * 0x04000000	0x04020000	128 KB	SROMC's Bank 0
 * 0x05000000	0x05020000	128 KB	SROMC's Bank 1
 * 0x06000000	0x06020000	128 KB	SROMC's Bank 2
 * 0x07000000	0x07020000	128 KB	SROMC's Bank 3
 * 0x10000000	0x1FFFFFFF		SFR region
 * 0x40000000	0xFFFFFFFF		DRAM
*/

/* CORE */
#define EXYNOS5_CORE_SIZE			0x0f000000
#define EXYNOS5_SDRAM_PBASE			0x40000000

#define EXYNOS5_CMU_CORE_PART_OFFSET		0x00010000
#define   EXYNOS5_CMU_APLL			0x00010000	/* ARM core clock */
#define   EXYNOS5_CMU_MPLL			0x00014000	/* MEM cntr. clock */
#define EXYNOS5_CMU_TOP_PART_OFFSET		0x00020000
#define   EXYNOS5_CMU_CPLL			0x00020020	/* Video hardware codec clock */
#define   EXYNOS5_CMU_DPLL			0x00020030	/* Audio and ext. interf. clock */
#define   EXYNOS5_CMU_VPLL			0x00020040	/* Dither PLL (EMI reduction) clock */
#define   EXYNOS5_CMU_GPLL			0x00020050	/* Graphic 3D proc. clock */
#define EXYNOS5_CMU_MEM_PART_OFFSET		0x00030000
#define   EXYNOS5_CMU_BPLL			0x00030010
#define   EXYNOS5_CMU_KPLL			0x00038000
#define EXYNOS5_ALIVE_OFFSET			0x00040000
#define EXYNOS5_PMU_OFFSET			0x00040000	/* alias */
#define EXYNOS5_SYSREG_OFFSET			0x00050000
#define EXYNOS5_TMU_OFFSET			0x00060000
#define EXYNOS5_MONOTONIC_CNT_OFFSET		0x000C0000

#define EXYNOS5_HDMI_CEC_OFFSET			0x001B0000
#define EXYNOS5_MCT_OFFSET			0x001C0000
#define EXYNOS5_WDT_OFFSET			0x001D0000
#define EXYNOS5_RTC_OFFSET			0x001E0000

#define EXYNOS5_INT_COMB_CPU_OFFSET		0x00440000
#define EXYNOS5_INT_COMB_IOP_OFFSET		0x00450000
#define EXYNOS5_GIC_CPU_OFFSET			0x00480000
#define EXYNOS5_GIC_IOP_DISTRIBUTOR_OFFSET	0x00481000
#define EXYNOS5_GIC_IOP_CONTROLLER_OFFSET	0x00482000
#define EXYNOS5_MPCORE PRIVATE REGION_OFFSET	0x00500000
#define EXYNOS5_NS MDMA0			0x00800000
#define EXYNOS5_SSS_OFFSET			0x00830000
#define EXYNOS5_SSS_KEY_OFFSET			0x00840000
#define EXYNOS5_2D_OFFSET			0x00850000
#define EXYNOS5_CSSYS_OFFSET			0x00880000
#if 0
#define EXYNOS5_A15 (EAGLE)			0x00890000
#define EXYNOS5_A5 (IOP)			0x008A0000
#define EXYNOS5_A5 (ISP)			0x008B0000
#endif
#define EXYNOS5_SYSMMU_MDMA_OFFSET		0x00A40000
#define EXYNOS5_SYSMMU_SSS_OFFSET		0x00A50000
#define EXYNOS5_SYSMMU_2D_OFFSET		0x00A60000
#define EXYNOS5_DREXII_PHY0_OFFSET		0x00C00000
#define EXYNOS5_DREXII_PHY1_OFFSET		0x00C10000
#define EXYNOS5_AS_A_3D_OFFSET			0x00CC0000
#define EXYNOS5_AS_A_C2C_OFFSET			0x00CD0000
#define EXYNOS5_AS_A_LEFT_BUS_OFFSET		0x00CE0000
#define EXYNOS5_AS_A_RIGHT0_BUS_OFFSET		0x00CF0000
#define EXYNOS5_AS_A_DISP1_BUS_OFFSET		0x00D00000
#define EXYNOS5_GPIO_C2C_OFFSET			0x00D10000
#define EXYNOS5_DREXII_OFFSET			0x00DD0000
#define EXYNOS5_AS_A_EFCON_OFFSET		0x00DE0000
#define EXYNOS5_AP_C2C_OFFSET			0x00E00000
#define EXYNOS5_CP_C2C_OFFSET			0x00E40000
#define EXYNOS5_AS_A_ACP_BLK_OFFSET		0x00E80000
#define EXYNOS5_AS_A_CPU_P_BLK_OFFSET		0x00E90000
#define EXYNOS5_AS_A_LBX_BUS_OFFSET		0x00F00000
#define EXYNOS5_AS_A_R1BX_BUS_OFFSET		0x00F10000
#define EXYNOS5_AS_A_R0BX_BUS_OFFSET		0x00F20000
#define EXYNOS5_AS_A_CPU_OFFSET			0x00F30000
#define EXYNOS5_MFC_OFFSET			0x01000000
#define EXYNOS5_SYSMMU_MFC0_R			0x01200000
#define EXYNOS5_SYSMMU_MFC1_L			0x01210000
#define EXYNOS5_GPIO_LEFT_OFFSET		0x01400000
#define EXYNOS5_AS_A_MFC_OFFSET			0x01680000
#define EXYNOS5_AS_A_GENX_OFFSET		0x016A0000
#define EXYNOS5_3D ENGINE_OFFSET		0x01800000
#define EXYNOS5_ROTATOR_OFFSET			0x01C00000
#define EXYNOS5_NS_MDMA1			0x01C10000
#define EXYNOS5_SYSMMU_ROTATOR_OFFSET		0x01D40000
#define EXYNOS5_SYSMMU_MDMA1			0x01D50000
#define EXYNOS5_AS_A_FILE_OFFSET		0x01DA0000
#define EXYNOS5_AS_A_GPS_OFFSET			0x01DB0000
#define EXYNOS5_AS_A_JPEG_OFFSET		0x01DC0000
#define EXYNOS5_JPEG_OFFSET			0x01E00000
#define EXYNOS5_SYSMMU_JPEG_OFFSET		0x01F20000

#define EXYNOS5_USB3_XHCI0_OFFSET		0x02000000
#define EXYNOS5_USB3_PHY0_OFFSET		0x02100000

#define EXYNOS5_USB2HOST_OFFSET			0x02110000
#define EXYNOS5_USB2_HOST_EHCI_OFFSET		0x02110000
#define EXYNOS5_USB2_HOST_OHCI_OFFSET		0x02120000
#define EXYNOS5_USB2_HOST_PHYCTRL_OFFSET	0x02130000
#define EXYNOS5_USB2_DEVICE_LINK_OFFSET		0x02140000

#define EXYNOS5_MIPI_HSI_OFFSET			0x02160000
#define EXYNOS5_SATA PHY CONTROL_OFFSET		0x02170000
#define EXYNOS5_MCUCTL_IOP_OFFSET		0x02180000	/* XXX unknown XXX */
#define EXYNOS5_WDT_IOP_OFFSET			0x02190000
#define EXYNOS5_PDMA0				0x021A0000
#define EXYNOS5_PDMA1				0x021B0000
#define EXYNOS5_RTIC_OFFSET			0x021C0000
#define EXYNOS5_SATA_I2C_PHY_CONTROL_OFFSET	0x021D0000
#define EXYNOS5_MSH0				0x02200000
#define EXYNOS5_MSH1				0x02210000
#define EXYNOS5_MSH2				0x02220000
#define EXYNOS5_MSH3				0x02230000
#define EXYNOS5_SROMC_OFFSET			0x02250000
#define EXYNOS5_SATA_OFFSET			0x022F0000
#if 0
#define EXYNOS5_AXI_FILE_D64 (GPV)		0x02300000
#define EXYNOS5_AXI_FILE_D64 (GPV)		0x02310000
#endif
#define EXYNOS5_AXI_USB_SATA_D64		0x02320000
#if 0
#define EXYNOS5_AXI_USB_SATA_D64		0x02330000
#endif
#define EXYNOS5_SYSMMU_IOPROCESSOR_OFFSET	0x02360000
#define EXYNOS5_SYSMMU_RTIC_OFFSET		0x02370000
#define EXYNOS5_AS_A_IOP_FD64X_OFFSET		0x02380000
#define EXYNOS5_AS_A_AUDIO_OFFSET		0x02390000

#define EXYNOS5_USB3_XHCI1_OFFSET		0x02400000
#define EXYNOS5_USB3_PHY1_OFFSET		0x02500000

#if 0
#define EXYNOS5_AXI_GPS (GPV)			0x02600000
#define EXYNOS5_AXI_GPS (GPV)			0x02610000
#endif
#define EXYNOS5_AS_A_GPSCPU_OFFSET		0x02620000
#define EXYNOS5_SYSMMU_GPS_OFFSET		0x02630000
#define EXYNOS5_UART0_OFFSET			0x02C00000
#define EXYNOS5_UART1_OFFSET			0x02C10000
#define EXYNOS5_UART2_OFFSET			0x02C20000
#define EXYNOS5_UART3_OFFSET			0x02C30000
#define EXYNOS5_USI0_OFFSET			0x02C50000
#define EXYNOS5_I2C0_OFFSET			0x02C60000
#define EXYNOS5_I2C1_OFFSET			0x02C70000
#define EXYNOS5_I2C2_OFFSET			0x02C80000
#define EXYNOS5_I2C3_OFFSET			0x02C90000
#define EXYNOS5_I2C4_OFFSET			0x02CA0000
#define EXYNOS5_I2C5_OFFSET			0x02CB0000
#define EXYNOS5_I2C6_OFFSET			0x02CC0000
#define EXYNOS5_I2C7_OFFSET			0x02CD0000
#define EXYNOS5_I2CHDMI_OFFSET			0x02CE0000
#define EXYNOS5_USI_OFFSET			0x02D00000
#define EXYNOS5_TSADC_OFFSET			0x02D10000
#define EXYNOS5_SPI0_OFFSET			0x02D20000
#define EXYNOS5_SPI1_OFFSET			0x02D30000
#define EXYNOS5_SPI2_OFFSET			0x02D40000
#define EXYNOS5_USI2_OFFSET			0x02D50000
#define EXYNOS5_I2S1_OFFSET			0x02D60000
#define EXYNOS5_I2S2_OFFSET			0x02D70000
#define EXYNOS5_PCM1_OFFSET			0x02D80000
#define EXYNOS5_PCM2_OFFSET			0x02D90000
#define EXYNOS5_AC97_OFFSET			0x02DA0000
#define EXYNOS5_SPDIF_OFFSET			0x02DB0000
#define EXYNOS5_PWM_OFFSET			0x02DD0000
#define EXYNOS5_USI3_OFFSET			0x02DE0000
#define EXYNOS5_FIMC_ISP_OFFSET			0x03000000
#define EXYNOS5_FIMC_DRC_TOP_OFFSET		0x03010000
#define EXYNOS5_FIMC_SCALERC_OFFSET		0x03020000
#define EXYNOS5_FIMC_SCALERP_OFFSET		0x03030000
#define EXYNOS5_FIMC_FD_TOP_OFFSET		0x03040000
#define EXYNOS5_FIMC_ODC_OFFSET			0x03050000
#define EXYNOS5_FIMC_DIS_OFFSET			0x03060000
#define EXYNOS5_FIMC_3DNR_OFFSET		0x03070000
#define EXYNOS5_ASYNC_AXI_M_OFFSET		0x030F0000
#define EXYNOS5_MPWM_ISP_OFFSET			0x03110000
#define EXYNOS5_I2C2_ISP_OFFSET			0x03120000
#define EXYNOS5_I2C0_ISP_OFFSET			0x03130000
#define EXYNOS5_I2C1_ISP_OFFSET			0x03140000
#define EXYNOS5_MTCADC_ISP_OFFSET		0x03150000
#define EXYNOS5_PWM_ISP_OFFSET			0x03160000
#define EXYNOS5_WDT_ISP_OFFSET			0x03170000
#define EXYNOS5_MCUCTL_ISP_OFFSET		0x03180000
#define EXYNOS5_UART_ISP_OFFSET			0x03190000
#define EXYNOS5_SPI0_ISP_OFFSET			0x031A0000
#define EXYNOS5_SPI1_ISP_OFFSET			0x031B0000
#define EXYNOS5_GIC_C_ISP_OFFSET		0x031E0000
#define EXYNOS5_GIC_D_ISP_OFFSET		0x031F0000
#define EXYNOS5_SYSMMU_FIMC_ISP_OFFSET		0x03260000
#define EXYNOS5_SYSMMU_FIMC_DRC_OFFSET		0x03270000
#define EXYNOS5_SYSMMU_FIMC_SCALERC_OFFSET	0x03280000
#define EXYNOS5_SYSMMU_FIMC_SCALERP_OFFSET	0x03290000
#define EXYNOS5_SYSMMU_FIMC_FD_OFFSET		0x032A0000
#define EXYNOS5_SYSMMU_ISPCPU_OFFSET		0x032B0000
#define EXYNOS5_SYSMMU_FIMC_ODC_OFFSET		0x032C0000
#define EXYNOS5_SYSMMU_FIMC_DIS0		0x032D0000
#define EXYNOS5_SYSMMU_FIMC_DIS1		0x032E0000
#define EXYNOS5_SYSMMU_FIMC_3DNR_OFFSET		0x032F0000
#define EXYNOS5_GPIO_RIGHT_OFFSET		0x03400000
#define EXYNOS5_AS_A_MFC0_OFFSET		0x03620000
#define EXYNOS5_AS_A_ISP0_OFFSET		0x03640000
#define EXYNOS5_AS_A_ISP1_OFFSET		0x03650000
#define EXYNOS5_AS_A_RIGHT1_OFFSET		0x03670000
#define EXYNOS5_FIMC_LITE0_OFFSET		0x03C00000
#define EXYNOS5_FIMC_LITE1_OFFSET		0x03C10000
#define EXYNOS5_MIPI_CSI0_OFFSET		0x03C20000
#define EXYNOS5_MIPI_CSI1_OFFSET		0x03C30000
#define EXYNOS5_SYSMMU_FIMC_LITE0_OFFSET	0x03C40000
#define EXYNOS5_SYSMMU_FIMC_LITE1_OFFSET	0x03C50000
#define EXYNOS5_FIMC_LITE2_OFFSET		0x03C90000
#define EXYNOS5_SYSMMU_FIMC_LITE2_OFFSET	0x03CA0000
#define EXYNOS5_GSCALER0_OFFSET			0x03E00000
#define EXYNOS5_GSCALER1_OFFSET			0x03E10000
#define EXYNOS5_GSCALER2_OFFSET			0x03E20000
#define EXYNOS5_GSCALER3_OFFSET			0x03E30000
#define EXYNOS5_AS_A_GS0_OFFSET			0x03E40000
#define EXYNOS5_AS_A_GS1_OFFSET			0x03E50000
#define EXYNOS5_AS_A_GS2_OFFSET			0x03E60000
#define EXYNOS5_AS_A_GS3_OFFSET			0x03E70000
#define EXYNOS5_SYSMMU_GSCALER0_OFFSET		0x03E80000
#define EXYNOS5_SYSMMU_GSCALER1_OFFSET		0x03E90000
#define EXYNOS5_SYSMMU_GSCALER2_OFFSET		0x03EA0000
#define EXYNOS5_SYSMMU_GSCALER3_OFFSET		0x03EB0000
#define EXYNOS5_GPIO_USB_OFFSET			0x04000000
#define EXYNOS5_AS_A_GSCALER_OFFSET		0x04220000
#define EXYNOS5_DISP1_MIX_OFFSET		0x04400000
#define EXYNOS5_DISP1_ENH_OFFSET		0x04410000
#define EXYNOS5_DISP1_CTRL_OFFSET		0x04420000
#define EXYNOS5_MIE_OFFSET			0x04430000
#define EXYNOS5_TV_MIXER_OFFSET			0x04450000
#define EXYNOS5_MIPI_DSI1_OFFSET		0x04500000
#define EXYNOS5_DP1_OFFSET			0x04510000
#define EXYNOS5_HDMI_0_OFFSET			0x04530000
#define EXYNOS5_HDMI_1_OFFSET			0x04540000
#define EXYNOS5_HDMI_2_OFFSET			0x04550000
#define EXYNOS5_HDMI_3_OFFSET			0x04560000
#define EXYNOS5_HDMI_4_OFFSET			0x04570000
#define EXYNOS5_HDMI_5_OFFSET			0x04580000
#define EXYNOS5_HDMI_6_OFFSET			0x04590000
#define EXYNOS5_DP1_1_OFFSET			0x045B0000
#define EXYNOS5_SYSMMU_DISP1_OFFSET		0x04640000
#define EXYNOS5_SYSMMU_TV_OFFSET		0x04650000
#define EXYNOS5_AS_A_TV_OFFSET			0x046D0000
#if 0
#define EXYNOS5_AES0&EF0 (NEW)			0x08000000
#define EXYNOS5_AES0&EF0 (NEW)			0x08010000
#define EXYNOS5_AES0&EF0 (NEW)			0x08020000
#define EXYNOS5_AES0&EF0 (NEW)			0x08030000
#define EXYNOS5_AES0&EF0 (NEW)			0x08040000
#define EXYNOS5_AES0&EF0 (NEW)			0x08050000
#define EXYNOS5_AES0&EF0 (NEW)			0x08060000
#define EXYNOS5_AES0&EF0 (NEW)			0x08070000
#define EXYNOS5_AES0&EF0 (NER)			0x08080000
#define EXYNOS5_AES0&EF0 (NER)			0x08090000
#define EXYNOS5_AES0&EF0 (NER)			0x080A0000
#define EXYNOS5_AES0&EF0 (NER)			0x080B0000
#define EXYNOS5_AES0&EF0 (NER)			0x080C0000
#define EXYNOS5_AES0&EF0 (NER)			0x080D0000
#define EXYNOS5_AES0&EF0 (NER)			0x080E0000
#define EXYNOS5_AES0&EF0 (NER)			0x080F0000
#define EXYNOS5_AES0&EF0 (EW)			0x08100000
#define EXYNOS5_AES0&EF0 (EW)			0x08110000
#define EXYNOS5_AES0&EF0 (EW)			0x08120000
#define EXYNOS5_AES0&EF0 (EW)			0x08130000
#define EXYNOS5_AES0&EF0 (EW)			0x08140000
#define EXYNOS5_AES0&EF0 (EW)			0x08150000
#define EXYNOS5_AES0&EF0 (EW)			0x08160000
#define EXYNOS5_AES0&EF0 (EW)			0x08170000
#define EXYNOS5_AES0&EF0 (ER)			0x08180000
#define EXYNOS5_AES0&EF0 (ER)			0x08190000
#define EXYNOS5_AES0&EF0 (ER)			0x081A0000
#define EXYNOS5_AES0&EF0 (ER)			0x081B0000
#define EXYNOS5_AES0&EF0 (ER)			0x081C0000
#define EXYNOS5_AES0&EF0 (ER)			0x081D0000
#define EXYNOS5_AES0&EF0 (ER)			0x081E0000
#define EXYNOS5_AES0&EF0 (ER)			0x081F0000
#define EXYNOS5_EFCON0_OFFSET			0x08200000
#define EXYNOS5_AES0 SFR_OFFSET			0x08300000
#define EXYNOS5_AES1&EF1 (NEW)			0x08400000
#define EXYNOS5_AES1&EF1 (NEW)			0x08410000
#define EXYNOS5_AES1&EF1 (NEW)			0x08420000
#define EXYNOS5_AES1&EF1 (NEW)			0x08430000
#define EXYNOS5_AES1&EF1 (NEW)			0x08440000
#define EXYNOS5_AES1&EF1 (NEW)			0x08450000
#define EXYNOS5_AES1&EF1 (NEW)			0x08460000
#define EXYNOS5_AES1&EF1 (NEW)			0x08470000
#define EXYNOS5_AES1&EF1 (NER)			0x08480000
#define EXYNOS5_AES1&EF1 (NER)			0x08490000
#define EXYNOS5_AES1&EF1 (NER)			0x084A0000
#define EXYNOS5_AES1&EF1 (NER)			0x084B0000
#define EXYNOS5_AES1&EF1 (NER)			0x084C0000
#define EXYNOS5_AES1&EF1 (NER)			0x084D0000
#define EXYNOS5_AES1&EF1 (NER)			0x084E0000
#define EXYNOS5_AES1&EF1 (NER)			0x084F0000
#define EXYNOS5_AES1&EF1 (EW)			0x08500000
#define EXYNOS5_AES1&EF1 (EW)			0x08510000
#define EXYNOS5_AES1&EF1 (EW)			0x08520000
#define EXYNOS5_AES1&EF1 (EW)			0x08530000
#define EXYNOS5_AES1&EF1 (EW)			0x08540000
#define EXYNOS5_AES1&EF1 (EW)			0x08550000
#define EXYNOS5_AES1&EF1 (EW)			0x08560000
#define EXYNOS5_AES1&EF1 (EW)			0x08570000
#define EXYNOS5_AES1&EF1 (ER)			0x08580000
#define EXYNOS5_AES1&EF1 (ER)			0x08590000
#define EXYNOS5_AES1&EF1 (ER)			0x085A0000
#define EXYNOS5_AES1&EF1 (ER)			0x085B0000
#define EXYNOS5_AES1&EF1 (ER)			0x085C0000
#define EXYNOS5_AES1&EF1 (ER)			0x085D0000
#define EXYNOS5_AES1&EF1 (ER)			0x085E0000
#define EXYNOS5_AES1&EF1 (ER)			0x085F0000
#endif
#define EXYNOS5_EFCON1_OFFSET			0x08600000
#define EXYNOS5_NS_NDMA_OFFSET			0x08680000
#define EXYNOS5_S_NDMA_OFFSET			0x08690000
#define EXYNOS5_AES1_OFFSET			0x08700000

/* AUDIOCORE */
#define EXYNOS5_AUDIOCORE_VBASE			(EXYNOS_CORE_VBASE + EXYNOS5_CORE_SIZE)
#define EXYNOS5_AUDIOCORE_PBASE			0x03800000	/* Audio SFR */
#define EXYNOS5_GPIO_I2S_OFFSET			(EXYNOS5_CORE_SIZE + 0x00060000)
#define EXYNOS5_AUDIOCORE_SIZE			0x00070000


/* used Exynos5 USB PHY registers */
#define USB_PHY_HOST_CTRL0		0x00
#define  HOST_CTRL0_PHY_SWRST		__BIT(0)
#define  HOST_CTRL0_LINK_SWRST		__BIT(1)
#define  HOST_CTRL0_UTMI_SWRST		__BIT(2)
#define  HOST_CTRL0_WORDINTERFACE	__BIT(3)
#define  HOST_CTRL0_FORCESUSPEND	__BIT(4)
#define  HOST_CTRL0_FORCESLEEP		__BIT(5)
#define  HOST_CTRL0_SIDDQ		__BIT(6)
#define  HOST_CTRL0_COMMONON_N		__BIT(9)	/* common block configuration during suspend */
#define  HOST_CTRL0_RETENABLE		__BIT(10)
#define  HOST_CTRL0_TESTBURNIN		__BIT(11)
#define  HOST_CTRL0_FSEL_MASK		__BITS(16, 18)	/* holds FSEL_CLKSEL_ */
#define  HOST_CTRL0_REFCLKSEL_MASK	__BITS(19, 20)
#define   HOST_CTRL0_REFCLKSEL_XTAL	0
#define   HOST_CTRL0_REFCLKSEL_EXTL	1
#define   HOST_CTRL0_REFCLKSEL_CLKCORE	2
#define  HOST_CTRL0_PHY_SWRST_ALL     __BIT(31)

#define USB_PHY_HSIC_CTRL1		0x10
#define USB_PHY_HSIC_TUNE1		0x14
#define USB_PHY_HSIC_CTRL2		0x20
#define USB_PHY_HSIC_TUNE2		0x24

#define  HSIC_CTRL_PHY_SWRST		__BIT(0)
#define  HSIC_CTRL_UTMI_SWRST		__BIT(2)
#define  HSIC_CTRL_WORDINTERFACE	__BIT(3)
#define  HSIC_CTRL_FORCESUSPEND	__BIT(4)
#define  HSIC_CTRL_FORCESLEEP		__BIT(5)
#define  HSIC_CTRL_SIDDQ		__BIT(6)
#define  HSIC_CTRL_REFCLKDIV_MASK	__BITS(16,22)
#define    HSIC_CTRL_REFCLKDIV_12		0x24
#define    HSIC_CTRL_REFCLKDIV_15		0x1c
#define    HSIC_CTRL_REFCLKDIV_16		0x1a
#define    HSIC_CTRL_REFCLKDIV_19_2		0x15
#define    HSIC_CTRL_REFCLKDIV_20		0x14
#define  HSIC_CTRL_REFCLKSEL_MASK	__BITS(23, 24)
#define    HSIC_CTRL_REFCLKSEL_DEFAULT	2

#define USB_PHY_HOST_EHCICTRL		0x30
#define   HOST_EHCICTRL_ENA_INCR16	__BIT(26)
#define   HOST_EHCICTRL_ENA_INCR8	__BIT(27)
#define   HOST_EHCICTRL_ENA_INCR4	__BIT(28)
#define   HOST_EHCICTRL_ENA_INCRXALIGN	__BIT(29)

#define USB_PHY_HOST_OHCICTRL		0x34
#define   HOST_OHCICTRL_CLKCK_RST	__BIT(0)
#define   HOST_OHCICTRL_CNTSEL		__BIT(1)
#define   HOST_OHCICTRL_APPSTARTCLK	__BIT(2)
#define   HOST_OHCICTRL_SUSPLGCY	__BIT(3)

#define USB_PHY_OTG_SYS			0x38
#define   OTG_SYS_FORCESUSPEND		__BIT(0)
#define   OTG_SYS_SIDDQ_UOTG		__BIT(1)
#define   OTG_SYS_OTGDISABLE		__BIT(2)
#define   OTG_SYS_FORCESLEEP		__BIT(3)
#define   OTG_SYS_FSEL_MASK		__BITS(4, 6)	/* holds FSEL_CLKSEL_ */
#define   OTG_SYS_COMMON_ON		__BIT(7)
#define   OTG_SYS_IDPULLUP_UOTG		__BIT(8)
#define   OTG_SYS_REFCLKSEL_MASK	__BITS(9, 10)
#define   OTG_SYS_REFCLKSEL_XTAL	__SHIFTIN(OTG_SYS_REFCLKSEL_MASK, 0)
#define   OTG_SYS_REFCLKSEL_EXTL	__SHIFTIN(OTG_SYS_REFCLKSEL_MASK, 1)
#define   OTG_SYS_REFCLKSEL_CLKCORE	__SHIFTIN(OTG_SYS_REFCLKSEL_MASK, 2)
#define   OTG_SYS_PHY0_SWRST		__BIT(12)
#define   OTG_SYS_LINK_SWRST_UOTG	__BIT(13)
#define   OTG_SYS_PHYLINK_SWRST		__BIT(14)

#endif /* _ARM_SAMSUNG_EXYNOS5_REG_H_ */