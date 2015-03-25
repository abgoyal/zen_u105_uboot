/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <common.h>

#include <asm/arch/tiger_lcd.h>
#include <asm/arch/dispc_reg.h>


#include "sprdfb.h"

extern struct ops_mipi sprdfb_mipi_ops;

extern int32_t sprdfb_dsi_init(struct sprdfb_device *dev);
extern int32_t sprdfb_dsi_uninit(struct sprdfb_device *dev);
extern int32_t sprdfb_dsi_ready(struct sprdfb_device *dev);

extern uint32_t rgb_calc_h_timing(struct timing_rgb *timing);
extern uint32_t rgb_calc_v_timing(struct timing_rgb *timing);


static uint32_t mipi_readid(struct panel_spec *self)
{
	uint32_t id = 0;
	return id;
}


static void mipi_dispc_init_config(struct panel_spec *panel)
{
	uint32_t reg_val = 0;

	FB_PRINT("sprdfb: [%s]\n", __FUNCTION__);

	if(NULL == panel){
		FB_PRINT("sprdfb: [%s] fail.(Invalid Param)\n", __FUNCTION__);
		return;
	}

	if(SPRDFB_PANEL_TYPE_MIPI != panel->type){
		FB_PRINT("sprdfb: [%s] fail.(not  mcu panel)\n", __FUNCTION__);
		return;
	}

	if(SPRDFB_MIPI_MODE_CMD == panel->info.mipi->work_mode){
		/*use edpi as interface*/
		dispc_set_bits((1<<1), DISPC_CTRL);
	}else{
		/*use dpi as interface*/
	}

	/*h sync pol*/
	if(SPRDFB_POLARITY_NEG == panel->info.mipi->h_sync_pol){
		reg_val |= (1<<0);
	}

	/*v sync pol*/
	if(SPRDFB_POLARITY_NEG == panel->info.mipi->v_sync_pol){
		reg_val |= (1<<1);
	}

	/*de sync pol*/
	if(SPRDFB_POLARITY_NEG == panel->info.mipi->de_pol){
		reg_val |= (1<<2);
	}

	if(SPRDFB_MIPI_MODE_VIDEO == panel->info.mipi->work_mode){
#ifdef CONFIG_DPI_SINGLE_RUN
		/*single run mode*/
		reg_val |= (1<<3);
#endif
	}else{
		if(!(panel->cap & PANEL_CAP_NOT_TEAR_SYNC)){
			FB_PRINT("sprdfb: mipi_dispc_init_config not support TE\n");
			/*enable te*/
			reg_val |= (1<<8);
		}
		/*te pol*/
		if(SPRDFB_POLARITY_NEG == panel->info.mipi->te_pol){
			reg_val |= (1<<9);
		}
		/*use external te*/
		reg_val |= (1<<10);
	}

	/*dpi bits*/
	switch(panel->info.rgb->video_bus_width){
	case 16:
		break;
	case 18:
		reg_val |= (1 << 6);
		break;
	case 24:
		reg_val |= (2 << 6);
		break;
	default:
		break;
	}

	dispc_write(reg_val, DISPC_DPI_CTRL);

	FB_PRINT("sprdfb: [%s] DISPC_DPI_CTRL = 0x%x\n", __FUNCTION__, dispc_read(DISPC_DPI_CTRL));
}

static void mipi_dispc_set_timing(struct sprdfb_device *dev)
{
	FB_PRINT("sprdfb: [%s]\n", __FUNCTION__);

	dispc_write(dev->panel_timing.rgb_timing[RGB_LCD_H_TIMING], DISPC_DPI_H_TIMING);
	dispc_write(dev->panel_timing.rgb_timing[RGB_LCD_V_TIMING], DISPC_DPI_V_TIMING);
}

static int32_t sprdfb_mipi_panel_check(struct panel_spec *panel)
{
	if(NULL == panel){
		FB_PRINT("sprdfb: [%s] fail. (Invalid param)\n", __FUNCTION__);
		return 0;
	}

	if(SPRDFB_PANEL_TYPE_MIPI != panel->type){
		FB_PRINT("sprdfb: [%s] fail. (not mipi param)\n", __FUNCTION__);
		return 0;
	}

	FB_PRINT("sprdfb: [%s]\n",__FUNCTION__);

	return 1;
}

static void sprdfb_mipi_panel_mount(struct sprdfb_device *dev)
{
	if((NULL == dev) || (NULL == dev->panel)){
		FB_PRINT("sprdfb: [%s]: Invalid Param\n", __FUNCTION__);
		return;
	}

	FB_PRINT("sprdfb: [%s]\n",__FUNCTION__);

	if(SPRDFB_MIPI_MODE_CMD == dev->panel->info.mipi->work_mode){
		dev->panel_if_type = SPRDFB_PANEL_IF_EDPI;
	}else{
		dev->panel_if_type = SPRDFB_PANEL_IF_DPI;
	}

	dev->panel->info.mipi->ops = &sprdfb_mipi_ops;

	if(NULL == dev->panel->ops->panel_readid){
		dev->panel->ops->panel_readid = mipi_readid;
	}

	dev->panel_timing.rgb_timing[RGB_LCD_H_TIMING] = rgb_calc_h_timing(dev->panel->info.mipi->timing);
	dev->panel_timing.rgb_timing[RGB_LCD_V_TIMING] = rgb_calc_v_timing(dev->panel->info.mipi->timing);
}

static void sprdfb_mipi_panel_init(struct sprdfb_device *dev)
{
	sprdfb_dsi_init(dev);

	mipi_dispc_init_config(dev->panel);
	mipi_dispc_set_timing(dev);
}

static void sprdfb_mipi_panel_uninit(struct sprdfb_device *dev)
{
	sprdfb_dsi_uninit(dev);
}

static void sprdfb_mipi_panel_ready(struct sprdfb_device *dev)
{
	sprdfb_dsi_ready(dev);
}

static void sprdfb_mipi_panel_suspend(struct sprdfb_device *dev)
{
	sprdfb_dsi_uninit(dev);
}

static void sprdfb_mipi_panel_resume(struct sprdfb_device *dev)
{
	sprdfb_dsi_init(dev);
}


struct panel_if_ctrl sprdfb_mipi_ctrl = {
	.if_name		= "mipi",
	.panel_if_check		= sprdfb_mipi_panel_check,
	.panel_if_mount		 	= sprdfb_mipi_panel_mount,
	.panel_if_init		= sprdfb_mipi_panel_init,
	.panel_if_uninit		= sprdfb_mipi_panel_uninit,
	.panel_if_ready		=sprdfb_mipi_panel_ready,
	.panel_if_before_refresh	= NULL,
	.panel_if_after_refresh	= NULL,
	.panel_if_suspend = sprdfb_mipi_panel_suspend,
	.panel_if_resume = sprdfb_mipi_panel_resume,
};

