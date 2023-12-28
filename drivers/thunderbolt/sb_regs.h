/* SPDX-License-Identifier: GPL-2.0 */
/*
 * USB4 port sideband registers found on routers and retimers
 *
 * Copyright (C) 2020, Intel Corporation
 * Authors: Mika Westerberg <mika.westerberg@linux.intel.com>
 *	    Rajmohan Mani <rajmohan.mani@intel.com>
 */

#ifndef _SB_REGS
#define _SB_REGS

#define USB4_SB_VENDOR_ID			0x00
#define USB4_SB_PRODUCT_ID			0x01
#define USB4_SB_OPCODE				0x08

enum usb4_sb_opcode {
	USB4_SB_OPCODE_ERR = 0x20525245,			/* "ERR " */
	USB4_SB_OPCODE_ONS = 0x444d4321,			/* "!CMD" */
	USB4_SB_OPCODE_ROUTER_OFFLINE = 0x4e45534c,		/* "LSEN" */
	USB4_SB_OPCODE_ENUMERATE_RETIMERS = 0x4d554e45,		/* "ENUM" */
	USB4_SB_OPCODE_SET_INBOUND_SBTX = 0x5055534c,		/* "LSUP" */
	USB4_SB_OPCODE_UNSET_INBOUND_SBTX = 0x50555355,		/* "USUP" */
	USB4_SB_OPCODE_QUERY_LAST_RETIMER = 0x5453414c,		/* "LAST" */
	USB4_SB_OPCODE_GET_NVM_SECTOR_SIZE = 0x53534e47,	/* "GNSS" */
	USB4_SB_OPCODE_NVM_SET_OFFSET = 0x53504f42,		/* "BOPS" */
	USB4_SB_OPCODE_NVM_BLOCK_WRITE = 0x574b4c42,		/* "BLKW" */
	USB4_SB_OPCODE_NVM_AUTH_WRITE = 0x48545541,		/* "AUTH" */
	USB4_SB_OPCODE_NVM_READ = 0x52524641,			/* "AFRR" */
	USB4_SB_OPCODE_READ_LANE_MARGINING_CAP = 0x50434452,	/* "RDCP" */
	USB4_SB_OPCODE_RUN_HW_LANE_MARGINING = 0x474d4852,	/* "RHMG" */
	USB4_SB_OPCODE_RUN_SW_LANE_MARGINING = 0x474d5352,	/* "RSMG" */
	USB4_SB_OPCODE_READ_SW_MARGIN_ERR = 0x57534452,		/* "RDSW" */
};

#define USB4_SB_METADATA			0x09
#define USB4_SB_METADATA_NVM_AUTH_WRITE_MASK	GENMASK(5, 0)
#define USB4_SB_DATA				0x12

/* USB4_SB_OPCODE_READ_LANE_MARGINING_CAP */
#define USB4_MARGIN_CAP_0_MODES_HW		BIT(0)
#define USB4_MARGIN_CAP_0_MODES_SW		BIT(1)
#define USB4_MARGIN_CAP_0_2_LANES		BIT(2)
#define USB4_MARGIN_CAP_0_VOLTAGE_INDP_MASK	GENMASK(4, 3)
#define USB4_MARGIN_CAP_0_VOLTAGE_INDP_SHIFT	3
#define USB4_MARGIN_CAP_0_VOLTAGE_MIN		0x0
#define USB4_MARGIN_CAP_0_VOLTAGE_HL		0x1
#define USB4_MARGIN_CAP_0_VOLTAGE_BOTH		0x2
#define USB4_MARGIN_CAP_0_TIME			BIT(5)
#define USB4_MARGIN_CAP_0_VOLTAGE_STEPS_MASK	GENMASK(12, 6)
#define USB4_MARGIN_CAP_0_VOLTAGE_STEPS_SHIFT	6
#define USB4_MARGIN_CAP_0_MAX_VOLTAGE_OFFSET_MASK GENMASK(18, 13)
#define USB4_MARGIN_CAP_0_MAX_VOLTAGE_OFFSET_SHIFT 13
#define USB4_MARGIN_CAP_1_TIME_DESTR		BIT(8)
#define USB4_MARGIN_CAP_1_TIME_INDP_MASK	GENMASK(10, 9)
#define USB4_MARGIN_CAP_1_TIME_INDP_SHIFT	9
#define USB4_MARGIN_CAP_1_TIME_MIN		0x0
#define USB4_MARGIN_CAP_1_TIME_LR		0x1
#define USB4_MARGIN_CAP_1_TIME_BOTH		0x2
#define USB4_MARGIN_CAP_1_TIME_STEPS_MASK	GENMASK(15, 11)
#define USB4_MARGIN_CAP_1_TIME_STEPS_SHIFT	11
#define USB4_MARGIN_CAP_1_TIME_OFFSET_MASK	GENMASK(20, 16)
#define USB4_MARGIN_CAP_1_TIME_OFFSET_SHIFT	16
#define USB4_MARGIN_CAP_1_MIN_BER_MASK		GENMASK(25, 21)
#define USB4_MARGIN_CAP_1_MIN_BER_SHIFT		21
#define USB4_MARGIN_CAP_1_MAX_BER_MASK		GENMASK(30, 26)
#define USB4_MARGIN_CAP_1_MAX_BER_SHIFT		26
#define USB4_MARGIN_CAP_1_MAX_BER_SHIFT		26

/* USB4_SB_OPCODE_RUN_HW_LANE_MARGINING */
#define USB4_MARGIN_HW_TIME			BIT(3)
#define USB4_MARGIN_HW_RH			BIT(4)
#define USB4_MARGIN_HW_BER_MASK			GENMASK(9, 5)
#define USB4_MARGIN_HW_BER_SHIFT		5

/* Applicable to all margin values */
#define USB4_MARGIN_HW_RES_1_MARGIN_MASK	GENMASK(6, 0)
#define USB4_MARGIN_HW_RES_1_EXCEEDS		BIT(7)
/* Different lane margin shifts */
#define USB4_MARGIN_HW_RES_1_L0_LL_MARGIN_SHIFT	8
#define USB4_MARGIN_HW_RES_1_L1_RH_MARGIN_SHIFT	16
#define USB4_MARGIN_HW_RES_1_L1_LL_MARGIN_SHIFT	24

/* USB4_SB_OPCODE_RUN_SW_LANE_MARGINING */
#define USB4_MARGIN_SW_TIME			BIT(3)
#define USB4_MARGIN_SW_RH			BIT(4)
#define USB4_MARGIN_SW_COUNTER_MASK		GENMASK(14, 13)
#define USB4_MARGIN_SW_COUNTER_SHIFT		13
#define USB4_MARGIN_SW_COUNTER_NOP		0x0
#define USB4_MARGIN_SW_COUNTER_CLEAR		0x1
#define USB4_MARGIN_SW_COUNTER_START		0x2
#define USB4_MARGIN_SW_COUNTER_STOP		0x3

#endif
