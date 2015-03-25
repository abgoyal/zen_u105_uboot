#include <asm/arch/sc8810_lcd.h>
#include <asm/io.h>

struct lcd_cfg{
	uint32_t lcd_id;
	struct lcd_spec* panel;
};

#define  LCD_PANEL_ID_RM61581_TRULY	(0x6158|0x00)  //ÃÃÃÃ»(ÃÃÃÂŽÃÃÃÂŒ)
#define  LCD_PANEL_ID_HX8357			(0x8357|0x00)  //ÃÂ¢ÂµÃ

#if defined (CONFIG_LCD_HX8357_1) || defined(CONFIG_LCD_HX8357)
extern  struct lcd_spec lcd_panel_hx8357;
#endif

#ifdef CONFIG_LCD_RM61581_TRULY
extern  struct lcd_spec lcd_panel_eR6158_truly;
#endif
#ifdef CONFIG_LCD_HX8369
extern struct lcd_spec lcd_panel_hx8369;
#endif
#ifdef CONFIG_LCD_ILI9486
extern struct lcd_spec lcd_panel_ili9486;
#endif
#ifdef CONFIG_LCD_ILI9481
extern struct lcd_spec lcd_panel_ili9481;
#endif
#ifdef CONFIG_LCD_ILI9341S
extern struct lcd_spec lcd_panel_ili9341s;
#endif

#ifdef CONFIG_LCD_ILI9341_BOE
extern struct lcd_spec lcd_panel_ili9341boe;
#endif

#ifdef CONFIG_LCD_ILI9341_BOE_MINT
extern struct lcd_spec lcd_panel_ili9486;
#endif

#ifdef CONFIG_LCD_NT35510
extern struct lcd_spec lcd_nt35510_spec;
#endif

#ifdef CONFIG_LCD_S6D04H0
extern struct lcd_spec lcd_s6d04h0_spec;
#endif

#ifdef CONFIG_LCD_NT35310
extern struct lcd_spec lcd_panel_nt35310;
#endif

#ifdef CONFIG_LCD_HX8357D
extern struct lcd_spec lcd_panel_hx8357d;
#endif 

#ifdef CONFIG_LCD_ST7796S
extern struct lcd_spec lcd_panel_st7796s;
#endif 


#ifdef CONFIG_LCD_ILI9488
extern struct lcd_spec lcd_panel_ili9488;
#endif 

#ifdef CONFIG_LCD_R61581B
extern struct lcd_spec lcd_panel_r61581b;
#endif 

struct lcd_cfg lcd_panel[] = {
#ifdef CONFIG_LCD_ST7796S
	{
		.lcd_id = 0x7796,
		.panel = &lcd_panel_st7796s,
	},
#endif
#ifdef CONFIG_LCD_HX8357D
	{
		.lcd_id = 0x99,
		.panel = &lcd_panel_hx8357d,
	},
#endif

#ifdef CONFIG_LCD_ILI9488
	{
		.lcd_id = 0X9488,
		.panel = &lcd_panel_ili9488,
	},
#endif

#ifdef CONFIG_LCD_R61581B
	{
		.lcd_id = 0x01012215,
		.panel = &lcd_panel_r61581b,
	},
#endif


#ifdef CONFIG_LCD_HX8357_1
	{
		.lcd_id = 0x57,
		.panel = &lcd_panel_hx8357,
	},
#endif
#ifdef CONFIG_LCD_ILI9341S
	{
		.lcd_id = 0x61,
		.panel = &lcd_panel_ili9341s,
        },
#endif
#ifdef CONFIG_LCD_NT35510
	{
                .lcd_id = 0x5bbc,/* !!! WORK AROUND !!! */
                .panel = &lcd_nt35510_spec,
        },
#endif
#ifdef CONFIG_LCD_ILI9341_BOE
	{
		.lcd_id = 0x61a4,
		.panel = &lcd_panel_ili9341boe,
        },
#endif
#ifdef CONFIG_LCD_ILI9341_BOE_MINT
	{
		.lcd_id = 0x60b4,
		.panel = &lcd_panel_ili9486,
	},
#endif
#ifdef CONFIG_LCD_ILI9486
	{
		.lcd_id = 0x5BBC,
		.panel = &lcd_panel_ili9486,
	},
#endif
#ifdef CONFIG_LCD_ILI9481
	{
		.lcd_id = 0x9481,
		.panel = &lcd_panel_ili9481,
    },
#endif
#ifdef CONFIG_LCD_RM61581_TRULY
	{
		.lcd_id = LCD_PANEL_ID_RM61581_TRULY,
		.panel = &lcd_panel_eR6158_truly,
	},
#endif
#ifdef CONFIG_LCD_HX8357
	{
		.lcd_id = LCD_PANEL_ID_HX8357,
		.panel = &lcd_panel_hx8357,
	},
#endif
#ifdef CONFIG_LCD_HX8369
	{
		.lcd_id = 0x69,
		.panel = &lcd_panel_hx8369,
	},
#endif

#ifdef CONFIG_LCD_S6D04H0
	{
		.lcd_id = 0x61bc11,
		.panel = &lcd_s6d04h0_spec,
	},
#endif

////add jinq for can't save the calibration parameters, 
#if  1//def CONFIG_LCD_NT35310
	{
		.lcd_id = 0x5555,
		.panel = &lcd_panel_nt35310,
	},
#endif
};

