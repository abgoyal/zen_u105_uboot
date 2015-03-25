/* drivers/video/sc8810/lcd_nt35516.c
 *
 *
 *
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

#include <asm/arch/tiger_lcd.h>

#define printk printf

#define  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printk
#else
#define LCD_PRINT(...)
#endif

#define HX8362_SpiWriteCmd(cmd) \ 
{ \
	spi_send_cmd((cmd & 0xFF));\
}

#define  HX8362_SpiWriteData(data)\
{ \
	spi_send_data((data & 0xFF));\
}


static int32_t hx8362_init(struct panel_spec *self)
{
	uint32_t test_data[8] = {0};
	uint32_t left = 0;
	uint32_t top = 0;	
	uint32_t right = 480;
	uint32_t bottom = 854;		
	uint32_t data = 0;
	spi_send_cmd_t spi_send_cmd = self->info.rgb->bus_info.spi->ops->spi_send_cmd; 
	spi_send_data_t spi_send_data = self->info.rgb->bus_info.spi->ops->spi_send_data; 
	spi_read_t spi_read = self->info.rgb->bus_info.spi->ops->spi_read; 


	LCD_PRINT("hx8362_init\n");

	HX8362_SpiWriteCmd(0xB9); // SET password
	HX8362_SpiWriteData(0xFF); // 
	HX8362_SpiWriteData(0x83); // 
	HX8362_SpiWriteData(0x63); // 

	HX8362_SpiWriteCmd(0xB1);
	HX8362_SpiWriteData(0x01);
	HX8362_SpiWriteData(0x00);
	HX8362_SpiWriteData(0x44);
	HX8362_SpiWriteData(0x08);
	HX8362_SpiWriteData(0x01);
	HX8362_SpiWriteData(0x0E); //
	HX8362_SpiWriteData(0x0E); //
	HX8362_SpiWriteData(0x1B); //the lower ,Saturation is better
	HX8362_SpiWriteData(0x23); //the lower ,Saturation is better
	HX8362_SpiWriteData(0x3F);
	HX8362_SpiWriteData(0x3F);
	HX8362_SpiWriteData(0x40);
	HX8362_SpiWriteData(0x32);
	HX8362_SpiWriteData(0x00);
	HX8362_SpiWriteData(0xE6);
	HX8362_SpiWriteData(0xE6);
	HX8362_SpiWriteData(0xE6);
	HX8362_SpiWriteData(0xE6);
	HX8362_SpiWriteData(0xE6);

	HX8362_SpiWriteCmd(0xB2); // SET DISP
	HX8362_SpiWriteData(0x08); // 
	HX8362_SpiWriteData(0x03); // 

	HX8362_SpiWriteCmd(0xB4);
	HX8362_SpiWriteData(0x00);//Column inversion
	HX8362_SpiWriteData(0x18); 
	HX8362_SpiWriteData(0x9C);
	HX8362_SpiWriteData(0x08);
	HX8362_SpiWriteData(0x18);
	HX8362_SpiWriteData(0x04);
	HX8362_SpiWriteData(0x82);

	HX8362_SpiWriteCmd(0xB6); //Set_VCOM 
	HX8362_SpiWriteData(0x1B); //0x10

	HX8362_SpiWriteCmd(0xCC); // SET Panel
	HX8362_SpiWriteData(0x01); //

	udelay(5000);

	HX8362_SpiWriteCmd(0xE0);  // SET Gamma
	HX8362_SpiWriteData(0x00);
	HX8362_SpiWriteData(0x05);
	HX8362_SpiWriteData(0x07);
	HX8362_SpiWriteData(0x0C);
	HX8362_SpiWriteData(0x13);
	HX8362_SpiWriteData(0x2F);
	HX8362_SpiWriteData(0x0B);
	HX8362_SpiWriteData(0x1D);
	HX8362_SpiWriteData(0x86);
	HX8362_SpiWriteData(0x0D);
	HX8362_SpiWriteData(0x91);
	HX8362_SpiWriteData(0x16);
	HX8362_SpiWriteData(0x99);
	HX8362_SpiWriteData(0x16);
	HX8362_SpiWriteData(0x16);
	HX8362_SpiWriteData(0x09);
	HX8362_SpiWriteData(0x05);
	HX8362_SpiWriteData(0x00);
	HX8362_SpiWriteData(0x05);
	HX8362_SpiWriteData(0x07);
	HX8362_SpiWriteData(0x0C);
	HX8362_SpiWriteData(0x13);
	HX8362_SpiWriteData(0x2F);
	HX8362_SpiWriteData(0x0B);
	HX8362_SpiWriteData(0x1D);
	HX8362_SpiWriteData(0x86);
	HX8362_SpiWriteData(0x0D);
	HX8362_SpiWriteData(0x91);
	HX8362_SpiWriteData(0x16);
	HX8362_SpiWriteData(0x99);
	HX8362_SpiWriteData(0x16);
	HX8362_SpiWriteData(0x16);
	HX8362_SpiWriteData(0x09);
	HX8362_SpiWriteData(0x05);

	HX8362_SpiWriteCmd(0xC1); //COLMOD 
	HX8362_SpiWriteData(0x01); // 
	//R
	HX8362_SpiWriteData(0x07 );
	HX8362_SpiWriteData(0x0A );
	HX8362_SpiWriteData(0x1A );
	HX8362_SpiWriteData(0x2F );
	HX8362_SpiWriteData(0x3E );
	HX8362_SpiWriteData(0x4A );
	HX8362_SpiWriteData(0x52 );
	HX8362_SpiWriteData(0x5A );
	HX8362_SpiWriteData(0x62 );
	HX8362_SpiWriteData(0x69 );
	HX8362_SpiWriteData(0x70 );
	HX8362_SpiWriteData(0x76 );
	HX8362_SpiWriteData(0x7D );
	HX8362_SpiWriteData(0x82 );
	HX8362_SpiWriteData(0x86 );
	HX8362_SpiWriteData(0x8C );
	HX8362_SpiWriteData(0x93 );
	HX8362_SpiWriteData(0x9A );
	HX8362_SpiWriteData(0x9F );
	HX8362_SpiWriteData(0xA4 );
	HX8362_SpiWriteData(0xA9 );
	HX8362_SpiWriteData(0xB0 );
	HX8362_SpiWriteData(0xB6 );
	HX8362_SpiWriteData(0xBB );
	HX8362_SpiWriteData(0xC2 );
	HX8362_SpiWriteData(0xC9 );
	HX8362_SpiWriteData(0xCF );
	HX8362_SpiWriteData(0xD7 );
	HX8362_SpiWriteData(0xE0 );
	HX8362_SpiWriteData(0xE7 );
	HX8362_SpiWriteData(0xEF );
	HX8362_SpiWriteData(0xF8 );
	HX8362_SpiWriteData(0xFF );
	HX8362_SpiWriteData(0x34 );
	HX8362_SpiWriteData(0x1E );
	HX8362_SpiWriteData(0x92 );
	HX8362_SpiWriteData(0x9E );
	HX8362_SpiWriteData(0x01 );
	HX8362_SpiWriteData(0xE6 );
	HX8362_SpiWriteData(0x08 );
	HX8362_SpiWriteData(0x6F );
	HX8362_SpiWriteData(0x02 );
	//G
	HX8362_SpiWriteData(0x07 );
	HX8362_SpiWriteData(0x0A );
	HX8362_SpiWriteData(0x1A );
	HX8362_SpiWriteData(0x2F );
	HX8362_SpiWriteData(0x3E );
	HX8362_SpiWriteData(0x4A );
	HX8362_SpiWriteData(0x52 );
	HX8362_SpiWriteData(0x5A );
	HX8362_SpiWriteData(0x62 );
	HX8362_SpiWriteData(0x69 );
	HX8362_SpiWriteData(0x70 );
	HX8362_SpiWriteData(0x76 );
	HX8362_SpiWriteData(0x7D );
	HX8362_SpiWriteData(0x82 );
	HX8362_SpiWriteData(0x86 );
	HX8362_SpiWriteData(0x8C );
	HX8362_SpiWriteData(0x93 );
	HX8362_SpiWriteData(0x9A );
	HX8362_SpiWriteData(0x9F );
	HX8362_SpiWriteData(0xA4 );
	HX8362_SpiWriteData(0xA9 );
	HX8362_SpiWriteData(0xB0 );
	HX8362_SpiWriteData(0xB6 );
	HX8362_SpiWriteData(0xBB );
	HX8362_SpiWriteData(0xC2 );
	HX8362_SpiWriteData(0xC9 );
	HX8362_SpiWriteData(0xCF );
	HX8362_SpiWriteData(0xD7 );
	HX8362_SpiWriteData(0xE0 );
	HX8362_SpiWriteData(0xE7 );
	HX8362_SpiWriteData(0xEF );
	HX8362_SpiWriteData(0xF8 );
	HX8362_SpiWriteData(0xFF );
	HX8362_SpiWriteData(0x34 );
	HX8362_SpiWriteData(0x1E );
	HX8362_SpiWriteData(0x92 );
	HX8362_SpiWriteData(0x9E );
	HX8362_SpiWriteData(0x01 );
	HX8362_SpiWriteData(0xE6 );
	HX8362_SpiWriteData(0x08 );
	HX8362_SpiWriteData(0x6F );
	HX8362_SpiWriteData(0x02 );
	//B
	HX8362_SpiWriteData(0x07 );
	HX8362_SpiWriteData(0x0A );
	HX8362_SpiWriteData(0x1A );
	HX8362_SpiWriteData(0x2F );
	HX8362_SpiWriteData(0x3E );
	HX8362_SpiWriteData(0x4A );
	HX8362_SpiWriteData(0x52 );
	HX8362_SpiWriteData(0x5A );
	HX8362_SpiWriteData(0x62 );
	HX8362_SpiWriteData(0x69 );
	HX8362_SpiWriteData(0x70 );
	HX8362_SpiWriteData(0x76 );
	HX8362_SpiWriteData(0x7D );
	HX8362_SpiWriteData(0x82 );
	HX8362_SpiWriteData(0x86 );
	HX8362_SpiWriteData(0x8C );
	HX8362_SpiWriteData(0x93 );
	HX8362_SpiWriteData(0x9A );
	HX8362_SpiWriteData(0x9F );
	HX8362_SpiWriteData(0xA4 );
	HX8362_SpiWriteData(0xA9 );
	HX8362_SpiWriteData(0xB0 );
	HX8362_SpiWriteData(0xB6 );
	HX8362_SpiWriteData(0xBB );
	HX8362_SpiWriteData(0xC2 );
	HX8362_SpiWriteData(0xC9 );
	HX8362_SpiWriteData(0xCF );
	HX8362_SpiWriteData(0xD7 );
	HX8362_SpiWriteData(0xE0 );
	HX8362_SpiWriteData(0xE7 );
	HX8362_SpiWriteData(0xEF );
	HX8362_SpiWriteData(0xF8 );
	HX8362_SpiWriteData(0xFF );
	HX8362_SpiWriteData(0x34 );
	HX8362_SpiWriteData(0x1E );
	HX8362_SpiWriteData(0x92 );
	HX8362_SpiWriteData(0x9E );
	HX8362_SpiWriteData(0x01 );
	HX8362_SpiWriteData(0xE6 );
	HX8362_SpiWriteData(0x08 );
	HX8362_SpiWriteData(0x6F );
	HX8362_SpiWriteData(0x02 );

	HX8362_SpiWriteCmd(0x3A); //COLMOD 
	HX8362_SpiWriteData(0x77); // 

	HX8362_SpiWriteCmd(0x11);//Sleep Out 
	udelay(120000);
	HX8362_SpiWriteCmd(0x35); //Tearing Effect 
	HX8362_SpiWriteData(0x00); // 
	HX8362_SpiWriteCmd(0x36);
	HX8362_SpiWriteData(0x02); 
	HX8362_SpiWriteCmd(0x29); 
	udelay(10000);
	HX8362_SpiWriteCmd(0x2C); 

}

static int32_t hx8362_enter_sleep(struct panel_spec *self, uint8_t is_sleep)
{
	spi_send_cmd_t spi_send_cmd = self->info.rgb->bus_info.spi->ops->spi_send_cmd; 
	spi_send_data_t spi_send_data = self->info.rgb->bus_info.spi->ops->spi_send_data; 
	
	if(is_sleep==1){
		//Sleep In
		HX8362_SpiWriteCmd(0x28);
		udelay(120000); 
		HX8362_SpiWriteCmd(0x10);
		udelay(10000); 
	}else{
		//Sleep Out
		HX8362_SpiWriteCmd(0x11);
		udelay(120000); 
		HX8362_SpiWriteCmd(0x29);
		udelay(10000); 
	}

	return 0;
}




static int32_t hx8362_set_window(struct panel_spec *self,
		uint16_t left, uint16_t top, uint16_t right, uint16_t bottom)
{
	uint32_t *test_data[4] = {0};
	spi_send_cmd_t spi_send_cmd = self->info.rgb->bus_info.spi->ops->spi_send_cmd; 
	spi_send_data_t spi_send_data = self->info.rgb->bus_info.spi->ops->spi_send_data; 
	spi_read_t spi_read = self->info.rgb->bus_info.spi->ops->spi_read;
#if 0

	LCD_PRINT("zxdbg add -hx8362_set_window: %d, %d, %d, %d\n",left, top, right, bottom);

	HX8362_SpiWriteCmd(0x2A00); 
	HX8362_SpiWriteData((left>>8));// set left address
	HX8362_SpiWriteData((left&0xff));
	HX8362_SpiWriteData((right>>8));// set right address
	HX8362_SpiWriteData((right&0xff));

	HX8362_SpiWriteCmd(0x2B00); 
	HX8362_SpiWriteData((top>>8));// set left address
	HX8362_SpiWriteData((top&0xff));
	HX8362_SpiWriteData((bottom>>8));// set bottom address
	HX8362_SpiWriteData((bottom&0xff));

//	HX8362_SpiWriteCmd(0x2C00);

	HX8362_SpiWriteCmd(0x2A00); 
	spi_read(test_data);
	spi_read(test_data+1);
	HX8362_SpiWriteCmd(0x2B00); 
	spi_read(test_data+2);
	spi_read(test_data+3);
#endif
	LCD_PRINT("zxdbg add -hx8362_read read: %x, %x, %x, %x\n",test_data[0], test_data[1], test_data[2], test_data[3]);

	return 0;
}
static int32_t hx8362_invalidate(struct panel_spec *self)
{
	LCD_PRINT("hx8362_invalidate\n");

	return self->ops->panel_set_window(self, 0, 0,
		self->width - 1, self->height - 1);
}



static int32_t hx8362_invalidate_rect(struct panel_spec *self,
				uint16_t left, uint16_t top,
				uint16_t right, uint16_t bottom)
{
	LCD_PRINT("hx8362_invalidate_rect \n");

	return self->ops->panel_set_window(self, left, top,
			right, bottom);
}

static int32_t hx8362_read_id(struct panel_spec *self)
{
	int32_t id  = 0x62;
	int32_t data  = 0;
	spi_send_cmd_t spi_send_cmd = self->info.rgb->bus_info.spi->ops->spi_send_cmd;
	spi_send_data_t spi_send_data = self->info.rgb->bus_info.spi->ops->spi_send_data;
	spi_read_t spi_read = self->info.rgb->bus_info.spi->ops->spi_read;

	HX8362_SpiWriteCmd(0xB9); // SET password
	HX8362_SpiWriteData(0xFF); //
	HX8362_SpiWriteData(0x83); //
	HX8362_SpiWriteData(0x63); //

	HX8362_SpiWriteCmd(0xFE); // SET SPI READ INDEX
	HX8362_SpiWriteData(0xF4); // GETHXID
	HX8362_SpiWriteCmd(0xFF); // GET SPI READ

	spi_read(&id);
	id &= 0xff;
	LCD_PRINT(" hx8362_read_id u-boot id = %d\n",id);

	return id;
}

static struct panel_operations lcd_hx8362_operations = {
	.panel_init = hx8362_init,
	.panel_set_window = hx8362_set_window,
	.panel_invalidate_rect= hx8362_invalidate_rect,
	.panel_invalidate = hx8362_invalidate,
	.panel_enter_sleep = hx8362_enter_sleep,
	.panel_readid          = hx8362_read_id
};

static struct timing_rgb lcd_hx8362_rgb_timing = {
	.hfp = 10,  /* unit: pixel */
	.hbp = 6,
	.hsync = 8,
	.vfp = 3, /*unit: line*/
	.vbp = 3,
	.vsync = 4,
};

static struct spi_info lcd_nt35516_rgb_spi_info = {
	.ops = NULL,
};

static struct info_rgb lcd_hx8362_rgb_info = {
	.cmd_bus_mode  = SPRDFB_RGB_BUS_TYPE_SPI,
	.video_bus_width = 24, /*18,16*/
	.h_sync_pol = SPRDFB_POLARITY_NEG,
	.v_sync_pol = SPRDFB_POLARITY_NEG,
	.de_pol = SPRDFB_POLARITY_POS,
	.timing = &lcd_hx8362_rgb_timing,
	.bus_info = {
		.spi = &lcd_nt35516_rgb_spi_info,
	}
};

//lcd_panel_nt35516
struct panel_spec lcd_panel_hx8362_rgb_spi_spec = {
	.width = 480,
	.height = 854,
	.type = LCD_MODE_RGB,
	.direction = LCD_DIRECT_NORMAL,
	.info = {
		.rgb = &lcd_hx8362_rgb_info
	},
	.ops = &lcd_hx8362_operations,
};
