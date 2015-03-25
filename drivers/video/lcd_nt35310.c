/* drivers/video/sc8810/lcd_nt35310.c
 *
 * Support for nt35310 LCD device
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

#define printk printf

//20130408 OK
#define LCD_PRINT(...)
static int32_t nt35310_init(struct lcd_spec *self)
{
    int32_t i,n;
    
    Send_data send_cmd = self->info.mcu->ops->send_cmd;
    Send_data send_data = self->info.mcu->ops->send_data;

#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
    
    //***************************************  
    send_cmd(0xED);  
    send_data(0x01);  
    send_data( 0xFE); 
    
    send_cmd(0xEE);  
    send_data(0xDE);  
    send_data(0x21);
    
    send_cmd(0xB3);  
    send_data(0x20);
    
    send_cmd(0xF1);  
    send_data(0x01);
    
    send_cmd(0xDF);  
    send_data(0x10);
    
    send_cmd(0x51);  
    send_data(0xFF);  
    
    send_cmd(0x53);  
    send_data(0x2C);
    
    send_cmd(0x55);  
    send_data(0x02);  
    
    
    
    send_cmd(0xC0);  
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
    send_data(0X44);  //44
    send_data(0X44); //44
    send_data(0X10);  //10
    send_data(0X10);  //10
#else
    send_data(0X4c);  //44
    send_data(0X4c); //44
    send_data(0X11);  //10
    send_data(0X11);  //10
#endif
    
    send_cmd(0xC4);  
    send_data(0X6e);
    
    
    send_cmd(0xBF);  
    send_data(0xAA);
    
    send_cmd(0xB0);  
    send_data(0x0D);  
    send_data(0x00);  
    send_data(0x0D);  
    send_data(0x00);  
    send_data( 0x11);  
    send_data(0x00);  
    send_data( 0x19); 
    send_data(0x00);  
    send_data( 0x21);  
    send_data(0x00);  
    send_data( 0x2D);  
    send_data(0x00);  
    send_data( 0x3D);  
    send_data(0x00);  
    send_data( 0x5D);  
    send_data(0x00);  
    send_data( 0x5D);  
    send_data(0x00);
    
    send_cmd(0xB1);  
    send_data( 0x80);  
    send_data(0x00);  
    send_data( 0x8B);  
    send_data(0x00);  
    send_data( 0x96);  
    send_data(0x00);
    
    send_cmd(0xB2);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x02);  
    send_data(0x00);  
    send_data( 0x03);  
    send_data(0x00);
    
    send_cmd(0xB3);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00); 
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00); 
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);  
    send_data( 0x00);  
    send_data(0x00);
    
    send_cmd(0xB4);  
    send_data( 0x8B);  
    send_data(0x00);  
    send_data( 0x96);  
    send_data(0x00);  
    send_data( 0xA1);  
    send_data(0x00);
    
    send_cmd(0xB5);  
    send_data( 0x02);  
    send_data(0x00);  
    send_data( 0x03);  
    send_data(0x00);  
    send_data( 0x04);  
    send_data(0x00);
    
    send_cmd(0xB6);  
    send_data( 0x00);  
    send_data(0x00);
    
    send_cmd(0xB8);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);
    
    send_cmd(0xC2);  
    send_data(0x0A);  
    send_data(0x00);  
    send_data(0x04); 
    send_data(0x00);
    
    send_cmd(0xC7);  
    send_data(0x00); 
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);
    
    send_cmd(0xC9);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00); 
    send_data(0x00); 
    send_data(0x00); 
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00); 
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);
    
    send_cmd(0xB7);  
    send_data(0x3F);  
    send_data(0x00);  
    send_data(0x5E);  
    send_data(0x00);  
    send_data(0x9E);  
    send_data(0x00);  
    send_data(0x74);  
    send_data(0x00);  
    send_data(0x8C);  
    send_data(0x00);  
    send_data(0xAC);  
    send_data(0x00);  
    send_data(0xDC);  
    send_data(0x00);  
    send_data(0x70);  
    send_data(0x00);  
    send_data(0xB9);  
    send_data(0x00);  
    send_data(0xEC);  
    send_data(0x00);  
    send_data(0xDC);  
    send_data(0x00); 
    
    send_cmd(0xE0);  
    send_data(0x01);  
    send_data(0x00); 
    send_data(0x05); 
    send_data(0x00);  
    send_data(0x0F);  
    send_data(0x00);  
    send_data(0x2F);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x54); 
    send_data(0x00);  
    send_data(0x67);  
    send_data(0x00);  
    send_data(0x7C);  
    send_data(0x00);  
    send_data(0x8C);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0xA8);  
    send_data(0x00);  
    send_data(0xBA);  
    send_data(0x00);  
    send_data(0xC5);  
    send_data(0x00);  
    send_data(0xCB);  
    send_data(0x00);  
    send_data(0xD3);  
    send_data(0x00);  
    send_data(0xDA);  
    send_data(0x00);  
    send_data(0xE3);  
    send_data(0x00);  
    send_data(0xF3);  
    send_data(0x00);
    
    send_cmd(0xE2);  
    send_data(0x01);  
    send_data(0x00);  
    send_data(0x05);  
    send_data(0x00);  
    send_data(0x0F);  
    send_data(0x00);  
    send_data(0x2F);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x67);  
    send_data(0x00);  
    send_data(0x7C);  
    send_data(0x00);  
    send_data(0x8C);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0xA8);  
    send_data(0x00);  
    send_data(0xBA);  
    send_data(0x00);  
    send_data(0xC5); 
    send_data(0x00);  
    send_data(0xCB);  
    send_data(0x00);  
    send_data(0xD3);  
    send_data(0x00);  
    send_data(0xDA);  
    send_data(0x00);  
    send_data(0xE3);  
    send_data(0x00);  
    send_data(0xF3);  
    send_data(0x00);
    
    send_cmd(0xE4);  
    send_data(0x01);  
    send_data(0x00);  
    send_data(0x05);  
    send_data(0x00);  
    send_data(0x0F);  
    send_data(0x00);  
    send_data(0x2F);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x67);  
    send_data(0x00);  
    send_data(0x7C);  
    send_data(0x00);  
    send_data(0x8C);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0xA8);  
    send_data(0x00);  
    send_data(0xBA);  
    send_data(0x00);  
    send_data(0xC5);  
    send_data(0x00);  
    send_data(0xCB);  
    send_data(0x00);  
    send_data(0xD3);  
    send_data(0x00);  
    send_data(0xDA);  
    send_data(0x00);  
    send_data(0xE3);  
    send_data(0x00);  
    send_data(0xF3);  
    send_data(0x00);
    		
    send_cmd(0xE1);  
    send_data(0x00); 
    send_data(0x00);  
    send_data(0x04);  
    send_data(0x00);  
    send_data(0x0F);  
    send_data(0x00);  
    send_data(0x2F);  
    send_data(0x00); 
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x66);  
    send_data(0x00);  
    send_data(0x7D);  
    send_data(0x00);  
    send_data(0x8B);  
    send_data(0x00);  
    send_data(0x99); 
    send_data(0x00);  
    send_data(0xA8);  
    send_data(0x00);  
    send_data(0xBA);  
    send_data(0x00);  
    send_data(0xC5); 
    send_data(0x00);  
    send_data(0xCB);  
    send_data(0x00);  
    send_data(0xD4);  
    send_data(0x00);  
    send_data(0xD9);  
    send_data(0x00);  
    send_data(0xE3);  
    send_data(0x00);  
    send_data(0xF3);  
    send_data(0x00);
    
    send_cmd(0xE3);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x04);  
    send_data(0x00);  
    send_data(0x0F);  
    send_data(0x00);  
    send_data(0x2F);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x66);  
    send_data(0x00); 
    send_data(0x7D);  
    send_data(0x00);  
    send_data(0x8B);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0xA8);  
    send_data(0x00);  
    send_data(0xBA); 
    send_data(0x00);  
    send_data(0xC5);  
    send_data(0x00);  
    send_data(0xCB);  
    send_data(0x00);  
    send_data(0xD4);  
    send_data(0x00);  
    send_data(0xD9);  
    send_data(0x00);  
    send_data(0xE3);  
    send_data(0x00);  
    send_data(0xF3);  
    send_data(0x00);
    
    send_cmd(0xE5);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x04);  
    send_data(0x00);  
    send_data(0x0F);  
    send_data(0x00);  
    send_data(0x2F);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x66);  
    send_data(0x00);  
    send_data(0x7D);  
    send_data(0x00);  
    send_data(0x8B);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0xA8); 
    send_data(0x00);  
    send_data(0xBA);  
    send_data(0x00);  
    send_data(0xC5);  
    send_data(0x00);  
    send_data(0xCB);  
    send_data(0x00);  
    send_data(0xD4);  
    send_data(0x00);  
    send_data(0xD9);  
    send_data(0x00);  
    send_data(0xE3);  
    send_data(0x00);  
    send_data(0xF3);  
    send_data(0x00);
    
    send_cmd(0xE6);  
    send_data(0x21);  
    send_data(0x00);  
    send_data(0x55);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0x77);  
    send_data(0x00);  
    send_data(0x77);  
    send_data(0x00);  
    send_data(0x76);  
    send_data(0x00);  
    send_data(0x78);  
    send_data(0x00);  
    send_data(0x98);  
    send_data(0x00);  
    send_data(0xBB);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0x66);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x34);  
    send_data(0x00);  
    send_data(0x44);  
    send_data(0x00);  
    send_data(0x34);  
    send_data(0x00);
    
    send_cmd(0xE7);  
    send_data(0x21);  
    send_data(0x00);  
    send_data(0x55);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0x77);  
    send_data(0x00);  
    send_data(0x77);  
    send_data(0x00);  
    send_data(0x76);  
    send_data(0x00);  
    send_data(0x78);  
    send_data(0x00);  
    send_data(0x98);  
    send_data(0x00);  
    send_data(0xBB);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0x66);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x34);  
    send_data(0x00);  
    send_data(0x44);  
    send_data(0x00);  
    send_data(0x34);  
    send_data(0x00);
    
    send_cmd(0xE8);  
    send_data(0x21);  
    send_data(0x00);  
    send_data(0x55);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0x77);  
    send_data(0x00);  
    send_data(0x77);  
    send_data(0x00);  
    send_data(0x76);  
    send_data(0x00);  
    send_data(0x78);  
    send_data(0x00);  
    send_data(0x98);  
    send_data(0x00);  
    send_data(0xBB);  
    send_data(0x00);  
    send_data(0x99);  
    send_data(0x00);  
    send_data(0x66);  
    send_data(0x00);  
    send_data(0x54);  
    send_data(0x00);  
    send_data(0x45);  
    send_data(0x00);  
    send_data(0x34);  
    send_data(0x00);  
    send_data(0x44);  
    send_data(0x00);  
    send_data(0x34);  
    send_data(0x00);
    
    send_cmd(0xE9);  
    send_data(0xAA);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);
    
    send_cmd(0xE9);  
    send_data(0xAA);  
    send_data(0x00);  
    send_data(0x00);  
    send_data(0x00);
    send_cmd(0x00);  
    send_data(0xAA);
    
    send_cmd(0xC6);  
    send_data(0x00);  
    send_data(0xE2);  
    send_data(0xE2);  
    send_data(0xE2 );
    
    send_cmd(0xF2);  
    send_data(0xF1);  
    send_data(0x54);  
    send_data(0xA5);  
    send_data(0x04);  
    send_data(0x1E);  
    send_data(0x44);  
    send_data(0x90);  
    send_data(0x02);  
    send_data(0x2C);  
    send_data(0x2C);  
    send_data(0x32);  
    send_data(0x4A );
    
    send_cmd(0xF3);  
    send_data(0x0C );
    
	//zyt add
	send_cmd(0x36);  
	send_data(0x00);  // 180°

    send_cmd(0x3A);//P242 set the interface pixel format
    send_data(0x55);
    
    send_cmd(0x35);  
    send_data(0x00);
    
    send_cmd(0x11);
    
    LCD_DelayMS(120);		
    
    send_cmd(0x29);
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif    
    return 0;
}




static int32_t nt35310_set_window(struct lcd_spec *self,uint16_t left, uint16_t top, uint16_t right, uint16_t bottom)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("nt35310_set_window\n");
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
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
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif
	return 0;
}


static int32_t nt35310_invalidate(struct lcd_spec *self)
{
	LCD_PRINT("nt35310_invalidate\n");

	return self->ops->lcd_set_window(self, 0, 0,self->width-1, self->height-1);
}

static int32_t nt35310_invalidate_rect(struct lcd_spec *self,	uint16_t left, uint16_t top,uint16_t right, uint16_t bottom)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("nt35310_invalidate_rect : (%d, %d, %d, %d)\n",left, top, right, bottom);

	return self->ops->lcd_set_window(self, left, top,right, bottom);
}

static int32_t nt35310_set_direction(struct lcd_spec *self, uint16_t direction)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	return 0;
}

static int32_t nt35310_enter_sleep(struct lcd_spec *self, uint8_t is_sleep)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
	if(is_sleep)
    {
        send_cmd(0x28);
        LCD_DelayMS(10);
        send_cmd(0x10); // Set_address_mode
        LCD_DelayMS(60);
    }
	else
    {
    
       //send_cmd(0x1100); // Set_address_mode
       //LCD_DelayMS(60);
       //send_cmd(0x2900);
       //LCD_DelayMS(10);
       
       nt35310_init(self);
    }
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
    __raw_writel(0, LCM_CTRL);
#endif
	return 0;
}

#define LCM_NAME "LT_COE"
static uint32_t nt35310_read_id(struct lcd_spec *self)
{
	uint16_t id_high;
	uint16_t id_low;
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;
	Read_data read_data = self->info.mcu->ops->read_data;
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif	
	send_cmd(0xd4);
	read_data();
	read_data();
	id_low =read_data();//0x53
	id_high =(id_low<<8)|read_data();
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif	
	
	LCD_PRINT( "fb0 lcd_id(0x%x),%s\n",id_high,LCM_NAME);

	return 0x5555;// id_high;
	/*
为了解决校准参数校准不过，特此放到最后,id直接返回
	*/
}


static struct lcd_operations lcd_nt35310_operations = 
{
	.lcd_init            = nt35310_init,
	.lcd_set_window      = nt35310_set_window,
	.lcd_invalidate      = nt35310_invalidate,
	.lcd_invalidate_rect = nt35310_invalidate_rect,
	.lcd_set_direction   = nt35310_set_direction,
	.lcd_enter_sleep     = nt35310_enter_sleep,
	.lcd_readid          = nt35310_read_id,
};

static struct timing_mcu lcd_nt35310_timing[] = 
{
    [LCD_REGISTER_TIMING] = 
	{                // read/write register timing
		.rcss = 25,  // 25 ns
		.rlpw = 70,
		.rhpw = 70,
		.wcss = 25,
		.wlpw = 75,
		.whpw = 75,
	},
    [LCD_GRAM_TIMING] = 
    {                // read/write gram timing
        .rcss = 25,  // 25 ns
        .rlpw = 70,
        .rhpw = 70,
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
        .wcss = 10,
        .wlpw = 20,
        .whpw = 20,
#else
        .wcss = 15,
        .wlpw = 35,
        .whpw = 35,
#endif
    }
};

static struct info_mcu lcd_nt35310_info = 
{
	.bus_mode = LCD_BUS_8080,
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	.bus_width = 8,
#else
	.bus_width = 16,
#endif
	.timing = lcd_nt35310_timing,
	.ops = NULL,
};

struct lcd_spec lcd_panel_nt35310 =
{
	.width = 320,
	.height = 480,
	.mode = LCD_MODE_MCU,
	.direction = LCD_DIRECT_NORMAL,
	.info = {.mcu = &lcd_nt35310_info},
	.ops = &lcd_nt35310_operations,
};

