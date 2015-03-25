/* drivers/video/sc8810/lcd_r61581b.c
 *
 * Support for r61581b LCD device
 *
 * Copyright (C) 2010 Spreadtrum
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

#include <asm/arch/sc8810_lcd.h>
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
#include <asm/arch/sc8810_reg_base.h>
#include <asm/arch/sc8810_lcd.h>
#include <asm/arch/lcdc_reg_v3.h>
#include <asm/arch/lcm_reg_v3.h>
#include <asm/io.h>
#endif

#undef  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printf
#else
#define LCD_PRINT(...)
#endif

static int32_t r61581b_init(struct lcd_spec *self)
{
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif

	self->info.mcu->ops->send_cmd(0xff);
	LCD_DelayMS(130);	
	self->info.mcu->ops->send_cmd(0xff);
	LCD_DelayMS(5);
	self->info.mcu->ops->send_cmd(0xff);
	self->info.mcu->ops->send_cmd(0xff);
	self->info.mcu->ops->send_cmd(0xff);
	self->info.mcu->ops->send_cmd(0xff);
	LCD_DelayMS(10);

	self->info.mcu->ops->send_cmd(0xb0);
	self->info.mcu->ops->send_data(0x00);

	self->info.mcu->ops->send_cmd(0x11);
	LCD_DelayMS(150);

	self->info.mcu->ops->send_cmd(0xb3);
	self->info.mcu->ops->send_data(0x02);
	self->info.mcu->ops->send_data(0x00); //17
	self->info.mcu->ops->send_data(0x00); //0x18
	self->info.mcu->ops->send_data(0x00);

	self->info.mcu->ops->send_cmd(0xC0);
	self->info.mcu->ops->send_data(0x13);//0x00
	self->info.mcu->ops->send_data(0x3B);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x02);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x01);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x43);

	self->info.mcu->ops->send_cmd(0xC1);// Frame frequency
	self->info.mcu->ops->send_data(0x08);//0x00
	self->info.mcu->ops->send_data(0x10);//0x16 22 clocks,  0x1a 26clocks   
	self->info.mcu->ops->send_data(0x08);
	self->info.mcu->ops->send_data(0x08);

	self->info.mcu->ops->send_cmd(0xC4);
	self->info.mcu->ops->send_data(0x11);//0x00
	self->info.mcu->ops->send_data(0x07);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x03);

	self->info.mcu->ops->send_cmd(0xC6);
	self->info.mcu->ops->send_data(0x00);//0x00

	self->info.mcu->ops->send_cmd(0xC8);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x13);
	self->info.mcu->ops->send_data(0x5c);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x07);
	self->info.mcu->ops->send_data(0x14);
	self->info.mcu->ops->send_data(0x08);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x21);

	self->info.mcu->ops->send_data(0x08);
	self->info.mcu->ops->send_data(0x14);
	self->info.mcu->ops->send_data(0x07);
	self->info.mcu->ops->send_data(0x53);
	self->info.mcu->ops->send_data(0x0c);
	self->info.mcu->ops->send_data(0x13);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x21);
	self->info.mcu->ops->send_data(0x00);

	self->info.mcu->ops->send_cmd(0x35);
	self->info.mcu->ops->send_data(0x00);//0A

	self->info.mcu->ops->send_cmd(0x36);
	self->info.mcu->ops->send_data(0x00);//��ת


	self->info.mcu->ops->send_cmd(0x3A);//
	self->info.mcu->ops->send_data(0x55);

	self->info.mcu->ops->send_cmd(0x44);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x01);

	self->info.mcu->ops->send_cmd(0xd0);
	self->info.mcu->ops->send_data(0x07);
	self->info.mcu->ops->send_data(0x07);
	self->info.mcu->ops->send_data(0x1d);
	self->info.mcu->ops->send_data(0x03);

	self->info.mcu->ops->send_cmd(0xd1);//set vcom 
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x30);
	self->info.mcu->ops->send_data(0x10);

	self->info.mcu->ops->send_cmd(0xd2);
	self->info.mcu->ops->send_data(0x03);
	self->info.mcu->ops->send_data(0x14);
	self->info.mcu->ops->send_data(0x04);

	self->info.mcu->ops->send_cmd(0x29);
	LCD_DelayMS(30);

	self->info.mcu->ops->send_cmd(0x2A);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x01);
	self->info.mcu->ops->send_data(0x3F);

	self->info.mcu->ops->send_cmd(0x2B);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x00);
	self->info.mcu->ops->send_data(0x01);
	self->info.mcu->ops->send_data(0xDF);
	
	self->info.mcu->ops->send_cmd(0x35);  // TE on
    self->info.mcu->ops->send_data(0x00);

	self->info.mcu->ops->send_cmd(0xb4); 
	self->info.mcu->ops->send_data(0x00);

	LCD_DelayMS(120);
	self->info.mcu->ops->send_cmd(0x2c);// Set_display_on  

#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif    
	return 0;
}

static int32_t r61581b_set_window(struct lcd_spec *self,
		uint16_t left, uint16_t top, uint16_t right, uint16_t bottom)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;
	Send_cmd_data send_cmd_data = self->info.mcu->ops->send_cmd_data;

#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
    /* set window size  */
	send_cmd_data(0x002A, (left >> 8));
	send_data( (left & 0xff));
	send_data((right >> 8));
	send_data((right & 0xff));
//	send_cmd_data(0x002A,  (left & 0xff));
//	send_cmd_data(0x002A, (right >> 8));
//	send_cmd_data(0x002A, (right & 0xff));

	send_cmd_data(0x002B, (top >> 8));
	send_data( (top & 0xff));
	send_data((bottom >> 8));
	send_data((bottom & 0xff));
//	send_cmd_data(0x002B, (top & 0xff));
//	send_cmd_data(0x002B,(bottom >> 8));
//	send_cmd_data(0x002B,(bottom & 0xff));

#if 0
	switch (self->direction) {
	case LCD_DIRECT_NORMAL:
    default:
		send_cmd_data(0x0080, (left >> 8));
		send_cmd_data(0x0081, (left & 0xff));
		send_cmd_data(0x0082, (top >> 8));
		send_cmd_data(0x0083, (top & 0xff));
        break;
	case LCD_DIRECT_ROT_90:
		send_cmd_data(0x0080, (top >> 8));
		send_cmd_data(0x0081, (top & 0xff));
		send_cmd_data(0x0082, (left >> 8));
		send_cmd_data(0x0083, (left & 0xff));
	    break;
    case LCD_DIRECT_ROT_180:
	case LCD_DIRECT_MIR_HV:
		send_cmd_data(0x0080, (right >> 8));
		send_cmd_data(0x0081, (right & 0xff));
		send_cmd_data(0x0082, (bottom >> 8));
		send_cmd_data(0x0083, (bottom & 0xff));
	    break;
	case LCD_DIRECT_ROT_270:
		send_cmd_data(0x0080, (bottom >> 8));
		send_cmd_data(0x0081, (bottom & 0xff));
		send_cmd_data(0x0082, (left >> 8));
		send_cmd_data(0x0083, (left & 0xff));
	    break;
	case LCD_DIRECT_MIR_H:
		send_cmd_data(0x0080, (left >> 8));
		send_cmd_data(0x0081, (left & 0xff));
		send_cmd_data(0x0082, (bottom >> 8));
		send_cmd_data(0x0083, (bottom & 0xff));
	    break;
	case LCD_DIRECT_MIR_V:
		send_cmd_data(0x0080, (right >> 8));
		send_cmd_data(0x0081, (right & 0xff));
		send_cmd_data(0x0082, (top >> 8));
		send_cmd_data(0x0083, (top & 0xff));
	    break;
	}
#endif
	send_cmd(0x002c);
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif
	return 0;
}


static int32_t r61581b_invalidate(struct lcd_spec *self)
{

	return self->ops->lcd_set_window(self, 0, 0, 
			self->width-1, self->height-1);

}

static int32_t r61581b_invalidate_rect(struct lcd_spec *self,
				uint16_t left, uint16_t top,
				uint16_t right, uint16_t bottom)
{

	return self->ops->lcd_set_window(self, left, top, 
			right, bottom);
}

static int32_t r61581b_set_direction(struct lcd_spec *self, uint16_t direction)
{
	self->direction = direction;

	return 0;
}

static uint32_t r61581b_read_id(struct lcd_spec *self)
{
	LCD_PRINT( "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz  ");
    unsigned int id = 0;
    int i = 0;    

    Send_data send_cmd = self->info.mcu->ops->send_cmd;
    Send_data send_data = self->info.mcu->ops->send_data;
    Read_data read_data = self->info.mcu->ops->read_data;
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
    send_cmd(0xB0);
    send_data(0x04);
    send_cmd(0xBF);
	for(; i < 4; i ++)
	{
		id <<= 8;
		id |= (unsigned int)read_data();
	}
   	LCD_PRINT( "   zxy     read_id = %d",id);
 	if( 0x01012211 == id){
                  id = 0x01012215;
	}
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
    __raw_writel(0, LCM_CTRL);
#endif
	return id; // 0x01012215
}

static int32_t r61581b_enter_sleep(struct lcd_spec *self, uint8_t is_sleep)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif	
	if ( is_sleep ){
		send_cmd(0x0028);
        LCD_DelayMS(50);
		send_cmd(0x0010);
        LCD_DelayMS(50);
	}
	else{
	//	send_cmd(0x11);
	//	LCD_DelayMS(120);
	//	send_cmd(0x29);
	//	LCD_DelayMS(20);
        r61581b_init(self);
	}
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif	
	return 0;
}

static struct lcd_operations lcd_r61581b_operations = {
	.lcd_init            = r61581b_init,
	.lcd_set_window      = r61581b_set_window,
	.lcd_invalidate      = r61581b_invalidate,
	.lcd_invalidate_rect = r61581b_invalidate_rect,
	.lcd_set_direction   = r61581b_set_direction,
	.lcd_enter_sleep     = r61581b_enter_sleep,
	.lcd_readid          = r61581b_read_id,
};

static struct timing_mcu lcd_r61581b_timing[] = {
[LCD_REGISTER_TIMING] = {                // read/write register timing
		.rcss = 450,
		.rlpw = 170,
		.rhpw = 250,
		.wcss = 60,
		.wlpw = 30,
		.whpw = 30,
	},
[LCD_GRAM_TIMING] = {                // read/write gram timing
		.rcss = 450,
		.rlpw = 170,
		.rhpw = 250,
		.wcss = 60,
		.wlpw = 30,
		.whpw = 30,
	}
};

static struct info_mcu lcd_r61581b_info = {
	.bus_mode = LCD_BUS_8080,
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	.bus_width = 8,
#else
	.bus_width = 16,
#endif
	.timing = lcd_r61581b_timing,
	.ops = NULL,
};

struct lcd_spec lcd_panel_r61581b = {
	.width = 320,
	.height = 480,
	.mode = LCD_MODE_MCU,
	.direction = LCD_DIRECT_NORMAL,
	.info = {.mcu = &lcd_r61581b_info},
	.ops = &lcd_r61581b_operations,

};


