/******************************************************************************
 ** File Name:    dispc_v3_reg.h                                     *
 ** Author:       Shan.He                                           *
 ** DATE:         30/08/2012                                        *
 ** Copyright:    2012 Spreatrum, Incoporated. All Rights Reserved. *
 ** Description:                                                    *
 ******************************************************************************/
/******************************************************************************
 **                   Edit    History                               *
 **---------------------------------------------------------------------------*
 ** DATE          NAME            DESCRIPTION                       *

 ******************************************************************************/
#ifndef _DISPC_REG_H_
#define _DISPC_REG_H_


#include <asm/io.h>
#include <asm/arch/sc8810_reg_base.h>


/* DISPC regs offset */
#define DISPC_CTRL		(0x0000)
#define DISPC_SIZE_XY		(0x0004)
#define DISPC_RSTN		(0x0008)

#define DISPC_STS			(0x0010)

#define DISPC_IMG_CTRL			(0x0020)
#define DISPC_IMG_Y_BASE_ADDR	(0x0024)
#define DISPC_IMG_UV_BASE_ADDR	(0x0028)
#define DISPC_IMG_V_BASE_ADDR	(0x002c)
#define DISPC_IMG_SIZE_XY			(0x0030)
#define DISPC_IMG_PITCH			(0x0034)
#define DISPC_IMG_DISP_XY			(0x0038)
#define DISPC_BG_COLOR			(0x003c)

#define DISPC_OSD_CTRL		(0x0040)
#define DISPC_OSD_BASE_ADDR	(0x0044)
#define DISPC_OSD_SIZE_XY		(0x0048)
#define DISPC_OSD_PITCH		(0x004c)
#define DISPC_OSD_DISP_XY		(0x0050)
#define DISPC_OSD_ALPHA		(0x0054)
#define DISPC_OSD_CK			(0x0058)

#define DISPC_Y2R_CTRL			(0x0060)
#define DISPC_Y2R_CONTRAST		(0x0064)
#define DISPC_Y2R_SATURATION		(0x0068)
#define DISPC_Y2R_BRIGHTNESS		(0x006c)

#define DISPC_INT_EN			(0x0070)
#define DISPC_INT_CLR			(0x0074)
#define DISPC_INT_STATUS		(0x0078)
#define DISPC_INT_RAW		(0x007c)

#define DISPC_DPI_CTRL		(0x0080)
#define DISPC_DPI_H_TIMING	(0x0084)
#define DISPC_DPI_V_TIMING	(0x0088)
#define DISPC_DPI_STS0		(0x008c)
#define DISPC_DPI_STS1		(0x0090)

#define DISPC_DBI_CTRL		(0x00a0)
#define DISPC_DBI_TIMING0		(0x00a4)
#define DISPC_DBI_TIMING1		(0x00a8)
#define DISPC_DBI_RDATA		(0x00ac)
#define DISPC_DBI_CMD		(0x00b0)
#define DISPC_DBI_DATA		(0x00b4)
#define DISPC_DBI_QUEUE		(0x00b8)

#define DISPC_TE_SYNC_DELAY	(0x00bc)

static inline uint32_t dispc_read(uint32_t reg)
{
	return __raw_readl(DISPC_CTL_BEGIN + reg);
}

static inline void dispc_write(uint32_t value, uint32_t reg)
{
	__raw_writel(value, (DISPC_CTL_BEGIN + reg));
}

static inline void dispc_set_bits(uint32_t bits, uint32_t reg)
{
	dispc_write(dispc_read(reg) | bits, reg);
}

static inline void dispc_clear_bits(uint32_t bits, uint32_t reg)
{
	dispc_write(dispc_read(reg) & ~bits, reg);
}

#endif

