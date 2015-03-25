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

#include <asm/arch/sc8810_lcd.h>
#define mdelay(a) udelay(a * 1000)
#define LCD_DelayMS mdelay

#define  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printf
#else
#define LCD_PRINT(...)
#endif

static int32_t s6d04h0_init(struct lcd_spec *self)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("s6d04h0_init\n");

	send_cmd(0xF0);
	send_data(0x5A);
	send_data(0x5A);

	send_cmd(0xF4);
	send_data(0x09);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x77);
	send_data(0x77);
	send_data(0x07);
	send_data(0x02);
	send_data(0x2E);
	send_data(0x47);
	send_data(0x05);

	send_cmd(0xF5);
	send_data(0x00);
	send_data(0x24);
	send_data(0x5E);
	send_data(0x00);
	send_data(0x00);
	send_data(0x0B);

	send_cmd(0xF6);
	send_data(0x00);
	send_data(0x01);
	send_data(0x07);
	send_data(0x00);
	send_data(0x01);
	send_data(0x0C);
	send_data(0x01);
	send_data(0x0C);
	send_data(0x07);

	send_cmd(0x35);
	send_data(0x00);

	send_cmd(0x36);
	send_data(0x98);

	send_cmd(0x3A);
	send_data(0x05);

	send_cmd(0xF7);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xF2);
	send_data(0x28);
	send_data(0x67);
	send_data(0x03);
	send_data(0x02);
	send_data(0x02);
	send_data(0x00);
	send_data(0x00);
	send_data(0x1D);
	send_data(0x48);
	send_data(0x00);
	send_data(0x07);
	send_data(0x01);

	send_cmd(0xF9);
	send_data(0x04);

	send_cmd(0xFA);		// (PDISPCTRL_WRCTL)
	send_data(0x00);
	send_data(0x00);
	send_data(0x10);
	send_data(0x17);
	send_data(0x25);
	send_data(0x31);
	send_data(0x21);
	send_data(0x31);
	send_data(0x2B);
	send_data(0x28);
	send_data(0x2B);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xFB);		// (PDISPCTRL_WRCTL)
	send_data(0x00);
	send_data(0x00);
	send_data(0x30);
	send_data(0x32);
	send_data(0x33);
	send_data(0x32);
	send_data(0x23);
	send_data(0x2B);
	send_data(0x23);
	send_data(0x1C);
	send_data(0x12);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xF9);
	send_data(0x02);

	send_cmd(0xFA);		// (PDISPCTRL_WRCTL)
	send_data(0x00);
	send_data(0x00);
	send_data(0x10);
	send_data(0x17);
	send_data(0x25);
	send_data(0x31);
	send_data(0x21);
	send_data(0x31);
	send_data(0x2B);
	send_data(0x28);
	send_data(0x2B);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xFB);		// (PDISPCTRL_WRCTL)
	send_data(0x00);
	send_data(0x00);
	send_data(0x30);
	send_data(0x32);
	send_data(0x33);
	send_data(0x32);
	send_data(0x23);
	send_data(0x2B);
	send_data(0x23);
	send_data(0x1C);
	send_data(0x12);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xF9);
	send_data(0x01);

	send_cmd(0xFA);		// (PDISPCTRL_WRCTL)
	send_data(0x00);
	send_data(0x00);
	send_data(0x10);
	send_data(0x17);
	send_data(0x25);
	send_data(0x31);
	send_data(0x21);
	send_data(0x31);
	send_data(0x2B);
	send_data(0x28);
	send_data(0x2B);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xFB);		// (PDISPCTRL_WRCTL)
	send_data(0x00);
	send_data(0x00);
	send_data(0x30);
	send_data(0x32);
	send_data(0x33);
	send_data(0x32);
	send_data(0x23);
	send_data(0x2B);
	send_data(0x23);
	send_data(0x1C);
	send_data(0x12);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);
	send_data(0x00);

	send_cmd(0xF0);
	send_data(0xA5);
	send_data(0xA5);

	send_cmd(0x11);		// (SLPOUT)

	LCD_DelayMS(130);	// 120ms

	send_cmd(0x29);		// (DISPON)

	LCD_DelayMS(40);	// 40ms

	return 0;
}

static int32_t s6d04h0_off(struct lcd_spec *self)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	send_cmd(0x10);		// (SLPIN)
	LCD_DelayMS(120);

	return 0;
}

static int32_t s6d04h0_set_window(struct lcd_spec *self,
				  uint16_t left, uint16_t top, uint16_t right,
				  uint16_t bottom)
{
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Send_data send_data = self->info.mcu->ops->send_data;

	LCD_PRINT("s6d04h0_set_window:%d, %d, %d, %d\n", left, top, right,
		  bottom);

	send_cmd(0x2A);		// col
	send_data((left >> 8));
	send_data((left & 0xFF));
	send_data((right >> 8));
	send_data((right & 0xFF));

	send_cmd(0x2B);		// row
	send_data((top >> 8));
	send_data((top & 0xFF));
	send_data((bottom >> 8));
	send_data((bottom & 0xFF));

	send_cmd(0x2C);

	return 0;
}

static int32_t s6d04h0_invalidate(struct lcd_spec *self)
{

	return self->ops->lcd_set_window(self, 0, 0,
					   self->width - 1, self->height - 1);

}

static int32_t s6d04h0_invalidate_rect(struct lcd_spec *self,
				       uint16_t left, uint16_t top,
				       uint16_t right, uint16_t bottom)
{

	LCD_PRINT("s6d04h0_invalidate_rect\n");

	return self->ops->lcd_set_window(self, left, top, right, bottom);
}

static int32_t s6d04h0_set_direction(struct lcd_spec *self,
				     uint16_t direction)
{

	LCD_PRINT("s6d04h0_set_direction\n");
	return 0;
}

static int32_t s6d04h0_enter_sleep(struct lcd_spec *self, uint8_t is_sleep)
{
	if (is_sleep) {
		LCD_PRINT("[LCD] s6d04h0_enter_sleep\n");
		self->ops->lcd_close(self);
	} else {
		LCD_PRINT("[LCD] s6d04h0_enter_wakeup\n");
		self->ops->lcd_init(self);
	}
	return 0;
}

static uint32_t s6d04h0_read_id(struct lcd_spec *self)
{
	uint32_t read_value = 0;
	Send_data send_cmd = self->info.mcu->ops->send_cmd;
	Read_data read_data = self->info.mcu->ops->read_data;

	send_cmd(0x04);

	read_data();
	read_value += read_data() << 16;
	read_value += read_data() << 8;
	read_value += read_data();

	LCD_PRINT("s6d04h0_read_id=%#x=====\n", read_value);

	return read_value;
}

static struct lcd_operations lcd_s6d04h0_operations = {
	.lcd_init = s6d04h0_init,
	.lcd_close = s6d04h0_off,
	.lcd_set_window = s6d04h0_set_window,
	.lcd_invalidate = s6d04h0_invalidate,
	.lcd_invalidate_rect = s6d04h0_invalidate_rect,
	.lcd_set_direction = s6d04h0_set_direction,
	.lcd_enter_sleep = s6d04h0_enter_sleep,
	.lcd_readid = s6d04h0_read_id,
};

static struct timing_mcu lcd_s6d04h0_timing[] = {
	[LCD_REGISTER_TIMING] = {
				 .rcss = 25,
				 .rlpw = 45,
				 .rhpw = 90,
				 .wcss = 30,
				 .wlpw = 15,
				 .whpw = 15,
				 },
	[LCD_GRAM_TIMING] = {
			     .rcss = 25,
			     .rlpw = 45,
			     .rhpw = 90,
			     .wcss = 30,
			     .wlpw = 15,
			     .whpw = 15,
			     }
};

static struct info_mcu lcd_s6d04h0_info = {
	.bus_mode = LCD_BUS_8080,
	.bus_width = 16,
	.timing = lcd_s6d04h0_timing,
	.ops = NULL,
};

struct lcd_spec lcd_s6d04h0_spec = {
	.width = 240,
	.height = 320,
	.mode = LCD_MODE_MCU,
	.direction = LCD_DIRECT_NORMAL,
	.info = {
		 .mcu = &lcd_s6d04h0_info},
	.ops = &lcd_s6d04h0_operations,
};

#if 0
struct lcd_cfg lcd_s6d04h0 = {
	.lcd_cs = -1,
	.lcd_id = 0xC0,		/* RDID3:LCD module ID */
	.lcd_name = "lcd_s6d04h0",
	.panel = &lcd_s6d04h0_spec,
};

static int lcd_regulator(void)
{
	int err;
	struct regulator *lcd_regulator = NULL;
	struct regulator *lcdio_regulator = NULL;
	lcd_regulator = regulator_get(NULL, REGU_NAME_LCD);
	if (IS_ERR(lcd_regulator)) {
		pr_err("LCD s6d04h0:could not get lcd regulator\n");
		return -1;
	}
	err = regulator_enable(lcd_regulator);
	if (err) {
		pr_err("LCD s6d04h0:could not enable lcd regulator\n");
		return -1;
	}
	err = regulator_set_voltage(lcd_regulator, 3000000, 3000000);
	if (err)
		pr_err("LCD s6d04h0:could not set lcd to 3000mv.\n");
	lcdio_regulator = regulator_get(NULL, REGU_NAME_LCDIO);
	if (IS_ERR(lcdio_regulator)) {
		pr_err("LCD s6d04h0:could not get lcdio regulator\n");
		return -1;
	}
	err = regulator_enable(lcdio_regulator);
	if (err) {
		pr_err("LCD s6d04h0:could not enable lcdio regulator\n");
		return -1;
	}
	err = regulator_set_voltage(lcdio_regulator, 2800000, 2800000);
	if (err)
		pr_err("LCD s6d04h0:could not set lcdio to 1800mv.\n");
	return 0;
}

static int __init lcd_s6d04h0_init(void)
{
	lcd_regulator();
	return sprd_register_panel(&lcd_s6d04h0);
}
#endif

subsys_initcall(lcd_s6d04h0_init);
