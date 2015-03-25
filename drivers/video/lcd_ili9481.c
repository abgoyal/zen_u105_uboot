/* drivers/video/sc8800g/sc8800g_lcd_ili9481.c
 *
 * Support for ILI9481 LCD device
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

#define  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printf
#else
#define LCD_PRINT(...)
#endif

static int32_t ili9481_init(struct lcd_spec *self)
{
	Send_cmd	send_cmd = self->info.mcu->ops->send_cmd;
	Send_data	send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("ili9481_init\n");
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif

	self->ops->lcd_reset(self);
#if 0
	send_cmd(0x11);				// SLPOUT 
	LCD_DelayMS(35);
	send_cmd(0xB9);
	send_data(0xFF);
	send_data(0x83);
	send_data(0x57);
	LCD_DelayMS(1);

	send_cmd(0xB1);	  //SETPower 
	send_data(0x00);	 //STB 
	send_data(0x14);	 //VGH = 13V, VGL = -10V 
	send_data(0x1C);	 //VSPR = 4.41V 
	send_data(0x1C);	 //VSNR = -4.41V 
	send_data(0xC3);	 //AP 
	send_data(0x6C); //38		 //FS 
	LCD_DelayMS(1); 

	send_cmd(0xB4);   //SETCYC 
	send_data(0x22);		 //2-dot 
	send_data(0x40);	 //RTN 
	send_data(0x00);	 //DIV 
	send_data(0x2A);	 //N_DUM 
	send_data(0x2A);	 //I_DUM 
	send_data(0x20);	 //GDON 
	send_data(0x78);	 //GDOFF  ==4E
	LCD_DelayMS(1); 

	send_cmd(0xB6);	//VCOMDC 
	send_data(0x22);
	LCD_DelayMS(1);

	send_cmd(0xC0);   //SETSTBA 
	send_data(0x34);	 //N_OPON 
	send_data(0x34);	 //I_OPON 
	send_data(0x02);	 //STBA 
	send_data(0x3C);	 //STBA 
	send_data(0xC8);	 //STBA 
	send_data(0x08);	 //GENON 
	LCD_DelayMS(1); 

	send_cmd(0xC2);   // Set Gate EQ 
	send_data(0x00); 
	send_data(0x08); 
	send_data(0x04); 
	LCD_DelayMS(1); 

	send_cmd(0xCC);   //Set Panel 
	send_data(0x01);  

	send_cmd(0xE0);	//Set Gamma 
	send_data(0x03);		  //VRP0[6:0]
	send_data(0x07);		  //VRP1[6:0]
	send_data(0x13);		  //VRP2[6:0]
	send_data(0x20);		  //VRP3[6:0]
	send_data(0x29);		  //VRP4[6:0]
	send_data(0x3C);		  //VRP5[6:0]
	send_data(0x49);		  //VRP6[6:0]
	send_data(0x52);		  //VRP7[6:0]
	send_data(0x47);		  //VRP8[6:0]
	send_data(0x40);		  //VRP9[6:0]
	send_data(0x3A);		  //VRP10[6:0]
	send_data(0x32);		  //VRP11[6:0]
	send_data(0x30);		  //VRP12[6:0]
	send_data(0x2B);		  //VRP13[6:0]
	send_data(0x27);		  //VRP14[6:0]
	send_data(0x1C);		  //VRP15[6:0]

	send_data(0x03);		  //VRP0[6:0]
	send_data(0x07);		  //VRP1[6:0]
	send_data(0x13);		  //VRP2[6:0]
	send_data(0x20);		  //VRP3[6:0]
	send_data(0x29);		  //VRP4[6:0]
	send_data(0x3C);		  //VRP5[6:0]
	send_data(0x49);		  //VRP6[6:0]
	send_data(0x52);		  //VRP7[6:0]
	send_data(0x47);		  //VRP8[6:0]
	send_data(0x40);		  //VRP9[6:0]
	send_data(0x3A);		  //VRP10[6:0]
	send_data(0x32);		  //VRP11[6:0]
	send_data(0x30);		  //VRP12[6:0]
	send_data(0x2B);		  //VRP13[6:0]
	send_data(0x27);		  //VRP14[6:0]
	send_data(0x1C);		  //VRP15[6:0]

	send_data(0x00);
	send_data(0x01);		
	LCD_DelayMS(1); 

	send_cmd(0x3A);			   
	send_data(0x55);	   

	send_cmd(0x36);
	send_data(0xc8);

	send_cmd(0x35);	// TE on
	send_data(0x00);

	send_cmd(0x29); // display on
	LCD_DelayMS(5);
	send_cmd(0x2C);
#else 
//ÖÐ¹âµç Ì©¼ª
	send_cmd(0x11);

	LCD_DelayMS(120);

	send_cmd(0xF0);
	send_data(0x01); 

	send_cmd(0xF6);
	send_data(0xC4); 


	send_cmd(0xD0);
	send_data(0x07);  //07  
	send_data(0x40);  //41    40
	send_data(0x1d);  //08

	LCD_DelayMS(20);

	send_cmd(0xD1);
	send_data(0x00);    
	send_data(0x0a);   //0c
	send_data(0x1f);  //1C

	send_cmd(0xD2);
	send_data(0x01);
	send_data(0x12);

	send_cmd(0x3A);
	send_data(0x55); 

	
	send_cmd(0xC1);
	send_data(0x10); //10
	send_data(0x18); //10
	send_data(0x22); //10

	
	send_cmd(0xC5);
	send_data(0x02);  //02  85Hz   . 01   100HZ
	               
	send_cmd(0xC8);
	send_data(0x01);  //01  
	send_data(0x03);  //03  
	send_data(0x14);    
	send_data(0x07);    
	send_data(0x0f);    //0f
	send_data(0x00);    
	send_data(0x47);    
	send_data(0x14);   //14 
	send_data(0x67);   //67 
	send_data(0x05);    
	send_data(0x00);    
	send_data(0x15);

	send_cmd(0x36);
	send_data(0x0a);  //48    //0a

	send_cmd(0xE4);
	send_data(0xA0);

	send_cmd(0xB3);
	send_data(0x02);    
	send_data(0x00);    
	send_data(0x00);    
	send_data(0x30);
	send_cmd(0x35);	// TE on
	send_data(0x00);
	LCD_DelayMS(10);

	send_cmd(0x29);
#endif
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif    
	return 0;
}

static int32_t ili9481_enter_sleep(struct lcd_spec *self, uint8_t is_sleep)
{
	LCD_PRINT("ili9481_enter_sleep\n");
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
	if ( is_sleep ){
		self->info.mcu->ops->send_cmd(0x0028);
		LCD_DelayMS(10);
		self->info.mcu->ops->send_cmd(0x0010);
		LCD_DelayMS(120);
	}
	else{
#ifndef LCD_ADJUST_PARAM
		self->info.mcu->ops->send_cmd(0x0011);
		LCD_DelayMS(120);
		self->info.mcu->ops->send_cmd(0x0029);
		LCD_DelayMS(50);
		self->info.mcu->ops->send_cmd(0x2C);
#else
		self->ops->lcd_reset(self);
		self->ops->lcd_init(self);
#endif

	}
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
    __raw_writel(0, LCM_CTRL);
#endif
	return 0;
}

static int32_t ili9481_set_window(struct lcd_spec *self,
		uint16_t left, uint16_t top, uint16_t right, uint16_t bottom)
{
	LCD_PRINT("ili9481_set_window\n");
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif
	self->info.mcu->ops->send_cmd(0x002A);
	self->info.mcu->ops->send_data((left >> 8));
	self->info.mcu->ops->send_data((left & 0xFF));
	self->info.mcu->ops->send_data((right >> 8));
	self->info.mcu->ops->send_data((right & 0xFF));

	self->info.mcu->ops->send_cmd(0x2B); //power setting 
	self->info.mcu->ops->send_data((top >> 8)); 
	self->info.mcu->ops->send_data((top & 0xFF)); 
	self->info.mcu->ops->send_data((bottom >> 8)); 
	self->info.mcu->ops->send_data((bottom & 0xFF)); 
	
	self->info.mcu->ops->send_cmd(0x002c);
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif
	return 0;
}

static int32_t ili9481_invalidate(struct lcd_spec *self)
{
	LCD_PRINT("ili9481_invalidate\n");

	return self->ops->lcd_set_window(self, 0, 0, 
			self->width-1, self->height-1);
}

static uint32_t ili9481_readid(struct lcd_spec *self)
{
	Send_cmd	send_cmd = self->info.mcu->ops->send_cmd;
	Read_data	read_data = self->info.mcu->ops->read_data;
	uint32_t	lcm_dev_id = 0, data_read; 
	uint32_t    value[6] ={0};
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif	

	send_cmd(0xBF);
	value[0] = read_data();  //param1:dummy	
	LCD_PRINT("ili9481_readid(0): 0x%x\n", value[0]);
	value[1] = read_data();  //param2:0
	LCD_PRINT("ili9481_readid(1): 0x%x\n", value[1]);

	value[2] = read_data(); //param3:94h
	LCD_PRINT("ili9481_readid(2): 0x%x\n", value[2]);
	//lcm_dev_id = data_read & 0xFF;
	
	value[3] = read_data(); //param4:9ch
	LCD_PRINT("ili9481_readid(3): 0x%x\n", value[3]);

	value[4] = read_data(); //param4:9ch
	LCD_PRINT("ili9481_readid(4): 0x%x\n", value[4]);

	if ((0x94 == value[3])&&(0x81 == value[4]))
	{
		lcm_dev_id = 0x9481;
	}
	LCD_PRINT("ili9481_readid: 0x%x\n", lcm_dev_id);   
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif	

	return lcm_dev_id;
}

static int32_t ili9481_set_direction(struct lcd_spec *self, uint16_t direction)
{
	LCD_PRINT("ili9481_set_direction\n");
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(4, LCM_CTRL);
#endif	

	switch (direction) {
	case LCD_DIRECT_NORMAL:
		self->info.mcu->ops->send_cmd_data(0x0036, 0x00);
		break;
	case LCD_DIRECT_ROT_90:
		self->info.mcu->ops->send_cmd_data(0x0036, 0x00E8);
		break;
	case LCD_DIRECT_ROT_180:
	case LCD_DIRECT_MIR_HV:
		self->info.mcu->ops->send_cmd_data(0x0036, 0x0008);
		break;
	case LCD_DIRECT_ROT_270:
		self->info.mcu->ops->send_cmd_data(0x0036, 0x0028);
		break;
	case LCD_DIRECT_MIR_H:
		self->info.mcu->ops->send_cmd_data(0x0036, 0x0088);
		break;
	case LCD_DIRECT_MIR_V:
		self->info.mcu->ops->send_cmd_data(0x0036, 0x0048);
		break;
	default:
		LCD_PRINT("unknown lcd direction!\n");
		self->info.mcu->ops->send_cmd_data(0x0036, 0x00c8);
		direction = LCD_DIRECT_NORMAL;
		break;
	}

	self->direction = direction;
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	__raw_writel(0, LCM_CTRL);
#endif
	return 0;
}

static int32_t ili9481_invalidate_rect(struct lcd_spec *self,
				uint16_t left, uint16_t top,
				uint16_t right, uint16_t bottom)
{
	LCD_PRINT("ili9481_invalidate_rect : (%d, %d, %d, %d)\n",left, top, right, bottom);

	/*left 	= (left >= self->width)    ? (self->width-1) : left;
	right 	= (right >= self->width)   ? (self->width-1) : right;
	top 	= (top >= self->height)    ? (self->height-1) : top;
	bottom 	= (bottom >= self->height) ? (self->height-1) : bottom;

	
	if ( ( right < left ) || ( bottom < top ) )
	{
		return ERR_LCD_OPERATE_FAIL;
	}
	*/

	return self->ops->lcd_set_window(self, left, top, 
			right, bottom);
}

static struct lcd_operations lcd_ili9481_operations = {
	.lcd_init = ili9481_init,
	.lcd_set_window = ili9481_set_window,
	.lcd_invalidate_rect = ili9481_invalidate_rect,
	.lcd_invalidate = ili9481_invalidate,
	.lcd_set_direction = ili9481_set_direction,
	.lcd_enter_sleep = ili9481_enter_sleep,
	.lcd_readid = ili9481_readid,
};

static struct timing_mcu lcd_ili9481_timing[] = {
[LCD_REGISTER_TIMING] = {                // read/write register timing
		.rcss = 5,  // 15ns
		.rlpw = 150,
		.rhpw = 150,
		.wcss = 10,
		.wlpw = 50,
		.whpw = 50,
	},
[LCD_GRAM_TIMING] = {                // read/write gram timing
		.rcss = 5,  // 15ns
		.rlpw = 150,
		.rhpw = 150,
		.wcss = 10,
		.wlpw = 40,//50
		.whpw = 40,//50
	},
};

static struct info_mcu lcd_ili9481_info = {
	.bus_mode = LCD_BUS_8080,
#ifdef CONFIG_LCD_DATA_WIDTH_8BIT
	.bus_width = 8,
#else
	.bus_width = 16,
#endif
	.timing = lcd_ili9481_timing,
	.ops = NULL,
};

struct lcd_spec lcd_panel_ili9481 = {
	.width = 320,
	.height = 480,
	.mode = LCD_MODE_MCU,
	.direction = LCD_DIRECT_NORMAL,
	.info = {.mcu = &lcd_ili9481_info},
	.ops = &lcd_ili9481_operations,
};

