/* drivers/video/sc8810/lcd_ili9341s.c
 *
 * Support for ili9341s LCD device
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

#include <common.h>

#include <asm/arch/sc8810_lcd.h>
#define mdelay(a) udelay(a * 1000)
#define printk printf

#define  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printk
#else
#define LCD_PRINT(...)
#endif

static void __raw_bits_or(unsigned int v, unsigned int a)
{
        __raw_writel((__raw_readl(a) | v), a);
}

static int32_t ili9341boe_init(struct lcd_spec *self)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("ili9341boe_init\n");

	send_cmd(0xCF); 
	send_data(0x00); 
	send_data(0xF9); 
	send_data(0x30); 

	send_cmd(0xED); 
	send_data(0x64); 
	send_data(0x03); 
	send_data(0x12); 
	send_data(0x81); 

	send_cmd(0xCB); 
	send_data(0x39); 
	send_data(0x2C); 
	send_data(0x00); 
	send_data(0x34); 
	send_data(0x02); 

	send_cmd(0xF7); 
	send_data(0x20); 
	
	send_cmd(0xEA); 
	send_data(0x00);  
	send_data(0x00); 

	send_cmd(0xC0); 
	send_data(0x1D);  

	send_cmd(0xC1); 
	send_data(0x10);  

	send_cmd(0xC5);
	send_data(0x3C);//14
	send_data(0x2A);//44

	send_cmd( 0xC7); 
	send_data(0x00);

	send_cmd( 0xE8);
	send_data( 0x85);
	send_data( 0x00);	
	send_data( 0x78);

	send_cmd( 0x35);
	send_data( 0x00);

	send_cmd( 0x36); 
	send_data( 0xD8);

	send_cmd( 0x3A); 
	send_data( 0x05);//66

	send_cmd( 0xB1);
	send_data( 0x00);
	send_data( 0x16);
	
	send_cmd( 0xB5);
	send_data( 0x04);
	send_data( 0x04);
	send_data( 0x0A);
	send_data( 0x14);

	send_cmd( 0xB6); 
	send_data( 0x0A);
	send_data( 0xC2); 

	send_cmd( 0xF6); 
	send_data( 0x01);
	send_data( 0x30); 
	send_data( 0x00); 

	send_cmd( 0xF2); 
	send_data( 0x03);
	
	send_cmd( 0xE0); 
	send_data( 0x0F);
	send_data( 0x24);	  
	send_data( 0x20);
	send_data( 0x0F);	  
	send_data( 0x0F);

	send_data( 0x0B);	  
	send_data( 0x50);
	send_data( 0xA4);	  
	send_data( 0x3E);
	send_data( 0x06);

	send_data( 0x10);
	send_data( 0x01);
	send_data( 0x1A);
	send_data( 0x19);
	send_data( 0x0F);

	send_cmd( 0xE1); 
	send_data(  0x00);
	send_data(  0x18);	  
	send_data(  0x19);
	send_data(  0x03);	  
	send_data(  0x0F);

	send_data(  0x04);	  
	send_data(  0x31);
	send_data(  0x53);	  
	send_data(  0x46);
	send_data(  0x09);

	send_data(  0x12);
	send_data(  0x0F);
	send_data(  0x26);
	send_data(  0x2A);
	send_data(  0x03);

	send_cmd( 0xE2 ); 
	send_data(  0x08);
	send_data(  0x09);	  
	send_data(  0x09);
	send_data(  0x09);	  
	send_data(  0x09);

	send_data(  0x09);	  
	send_data(  0x09);
	send_data(  0x09);	  
	send_data(  0x09);
	send_data(  0x09);

	send_data(  0x09);
	send_data(  0x09);
	send_data(  0x09);
	send_data(  0x09);
	send_data(  0x88);

	send_data(  0x88);

	send_cmd( 0xE3 ); 
	send_data(  0x00);
	send_data(  0x00);	  
	send_data(  0x00);
	send_data(  0x00);	  
	send_data(  0x06);

	send_data(  0x06);	  
	send_data(  0x07);
	send_data(  0x03);	  
	send_data(  0x05);
	send_data(  0x04);

	send_data(  0x04);
	send_data(  0x04);
	send_data(  0x04);
	send_data(  0x04);
	send_data(  0x02);

	send_data(  0x02);
	send_data(  0x01);
	send_data(  0x01);
	send_data(  0x01);
	send_data(  0x01);

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);	  

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);

	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);
	send_data(  0x00);

	send_data(  0x00);
	send_data(  0x80);
	send_data(  0x80);
	send_data(  0x80);
	send_data(  0x80);

	send_data(  0x82);
	send_data(  0x82);
	send_data(  0x82);
	send_data(  0x82);

       //Display on

	send_cmd(0x11); // (SLPOUT)

	mdelay(120); // 100ms

	send_cmd(0x29); // (DISPON)

	mdelay(100); // 100ms
	
	LCD_PRINT("ili9341boe_init: end\n");

	return 0;
}

static int32_t ili9341boe_set_window(struct lcd_spec *self,
		uint16_t left, uint16_t top, uint16_t right, uint16_t bottom)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("ili9341boe_set_window\n");
    
	send_cmd(0x2A); // col
	send_data((left >> 8));
	send_data((left & 0xFF));
	send_data((right >> 8));
	send_data((right & 0xFF));

	send_cmd(0x2B); // row
	send_data((top >> 8));
	send_data((top & 0xFF));
	send_data((bottom >> 8));
	send_data((bottom & 0xFF));
	
	send_cmd(0x2C); //Write data

	return 0;
}


static int32_t ili9341boe_invalidate(struct lcd_spec *self)
{
	LCD_PRINT("ili9341boe_invalidate\n");

	return self->ops->lcd_set_window(self, 0, 0, 
			self->width-1, self->height-1);
	
}

static int32_t ili9341boe_invalidate_rect(struct lcd_spec *self,
				uint16_t left, uint16_t top,
				uint16_t right, uint16_t bottom)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("ili9341boe_invalidate_rect : (%d, %d, %d, %d)\n",left, top, right, bottom);

	//send_cmd(0x44); // TE scanline
	//send_data((top >> 8));
	//send_data((top & 0xFF));

	return self->ops->lcd_set_window(self, left, top, 
			right, bottom);
}

static int32_t ili9341boe_set_direction(struct lcd_spec *self, uint16_t direction)
{

	LCD_PRINT("ili9341boe_set_direction\n");
	return 0;
}

static int32_t ili9341boe_enter_sleep(struct lcd_spec *self, uint8_t is_sleep)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;

	if(is_sleep) {
		//send_cmd(0x10);
		mdelay(120); 
	}
	else {
		//send_cmd(0x11);
		mdelay(120); 
	}
	return 0;
}

static uint32_t ili9341boe_read_id(struct lcd_spec *self)
{
	uint32_t read_value = 0;
	Send_data send_cmd = self->info.mcu->ops->send_cmd;

	Read_data read_data = self->info.mcu->ops->read_data;

	send_cmd(0x04);

	read_data(); 
	read_value += read_data()<< 16;
	read_value += read_data()<< 8;
	read_value += read_data();
  
	return read_value; 
}

static struct lcd_operations lcd_ili9341boe_operations = {
	.lcd_init            = ili9341boe_init,
	.lcd_set_window      = ili9341boe_set_window,
	.lcd_invalidate      = ili9341boe_invalidate,
	.lcd_invalidate_rect = ili9341boe_invalidate_rect,
	.lcd_set_direction   = ili9341boe_set_direction,
	.lcd_enter_sleep     = ili9341boe_enter_sleep,
	.lcd_readid          = ili9341boe_read_id,
};
#if 0
static struct timing_mcu lcd_ili9341s_timing = {
	.rcss = 170,  // 25 ns
	.rlpw = 50,
	.rhpw = 100,
	.wcss = 70,
	.wlpw = 20,
	.whpw = 20,
};
#endif
#if 0
static struct timing_mcu lcd_ili9341boe_timing[] = {
[LCD_REGISTER_TIMING] = {        
	.rcss = 25,  // 25 ns
	.rlpw = 45,
	.rhpw = 90,
	.wcss = 30,
	.wlpw = 15,
	.whpw = 15,
},
[LCD_GRAM_TIMING] = {        
	.rcss = 25,  // 25 ns
	.rlpw = 45,
	.rhpw = 90,
		.wcss = 30,
	.wlpw = 15,
	.whpw = 15,
}

};
#endif
static struct timing_mcu lcd_ili9341boe_timing[] = {
[LCD_REGISTER_TIMING] = {        
	.rcss = 50,  // 25 ns
	.rlpw = 90,
	.rhpw = 180,
	.wcss = 60,
	.wlpw = 30,
	.whpw = 30,
},
[LCD_GRAM_TIMING] = {        
	.rcss = 50,  // 25 ns
	.rlpw = 90,
	.rhpw = 180,
	.wcss = 60,
	.wlpw = 30,
	.whpw = 30,
}

};

static struct info_mcu lcd_ili9341boe_info = {
	.bus_mode = LCD_BUS_8080,
	.bus_width = 16,
	.timing = &lcd_ili9341boe_timing,
	.ops = NULL,
};

struct lcd_spec lcd_panel_ili9341boe = {
	.width = 240,
	.height = 320,
	.mode = LCD_MODE_MCU,
	.direction = LCD_DIRECT_NORMAL,
	.info = {.mcu = &lcd_ili9341boe_info},
	.ops = &lcd_ili9341boe_operations,
};

