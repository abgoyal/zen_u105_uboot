#include <asm/arch/sci_types.h>
#include <asm/arch/sc_reg.h>
#include <asm/arch/adi_hal_internal.h>
#include <boot_mode.h>
#include <asm/arch/gpio.h>
#include <asm/arch/asm_generic_gpio.h>
#include <asm/arch/gpio_phy.h>
#include <asm/arch/rtc_reg_v3.h>
#include <asm/arch/mfp.h>
#include <linux/gpio.h>

unsigned check_reboot_mode(void)
{
	unsigned rst_mode= 0;

	rst_mode = ANA_REG_GET(ANA_HWRST_STATUS);
	rst_mode &= HWRST_STATUS_POWERON_MASK;
	ANA_REG_SET(ANA_HWRST_STATUS, 0); //clear flag
	if(rst_mode == HWRST_STATUS_RECOVERY)
		return RECOVERY_MODE;
	else if(rst_mode == HWRST_STATUS_FASTBOOT)
		return FASTBOOT_MODE;
	else if(rst_mode == HWRST_STATUS_NORMAL)
		return NORMAL_MODE;
	else if(rst_mode == HWRST_STATUS_NORMAL2)
		return WATCHDOG_REBOOT;
	else if(rst_mode == HWRST_STATUS_ALARM)
		return ALARM_MODE;
	else if(rst_mode == HWRST_STATUS_SLEEP)
		return SLEEP_MODE;
	else
		return 0;
}

void reboot_devices(unsigned reboot_mode)
{
    unsigned rst_mode = 0;
    if(reboot_mode == RECOVERY_MODE){
      rst_mode = HWRST_STATUS_RECOVERY;
    }
    else if(reboot_mode == FASTBOOT_MODE){
      rst_mode = HWRST_STATUS_FASTBOOT;
    }else if(reboot_mode == NORMAL_MODE){
      rst_mode = HWRST_STATUS_NORMAL;
    }else{
      rst_mode = 0;
    }

    ANA_REG_SET(ANA_HWRST_STATUS, rst_mode);
    reset_cpu(0);
#if 0
    asm volatile("ldr r1,=0x20900218"); //remap ROM to 0x0000_0000
    asm volatile("ldr r2,=1");
    asm volatile("str r2,[r1]");
    asm volatile("mov pc,#0");
#endif
}
void power_down_devices(unsigned pd_cmd)
{
    power_down_cpu(0);
}

int power_button_pressed(void)
{
#if 1
	static int init_done = 0;
	if(init_done == 0){
		gpio_request(EIC_KEY_POWER, "power_key");
		gpio_direction_input(EIC_KEY_POWER);
		init_done = 1;
	}
    return ! gpio_get_value_cansleep(EIC_KEY_POWER);
#else

	ANA_REG_OR(ANA_APB_CLK_EN, BIT_3|BIT_11);
	ANA_REG_SET(ADI_EIC_MASK, 0xff);
	udelay(3000);
	int status = ANA_REG_GET(ADI_EIC_DATA);
	//printf("eica status %x\n", status);
	#if !(defined (CONFIG_SC8825))
	return !!(status & (1 << 3)/*PBINT*/);//low level if pb hold
	#else
	return !(status & (1 << 3)/*PBINT*/);
	#endif
#endif
}

int charger_connected(void)
{
#if 1
	static int init_done = 0;
	if(init_done == 0){
		gpio_request(EIC_CHARGER_DETECT, "charger_key");
		gpio_direction_input(EIC_CHARGER_DETECT);
		init_done = 1;
	}
    return !! gpio_get_value_cansleep(EIC_CHARGER_DETECT);
#else
	ANA_REG_OR(ANA_APB_CLK_EN, BIT_3|BIT_11);
	ANA_REG_SET(ADI_EIC_MASK, 0xff);
	udelay(3000);
	int status = ANA_REG_GET(ADI_EIC_DATA);
	//printf("charger_connected eica status %x\n", status);
	return !!(status & (1 << 2));
#endif
}

int alarm_triggered(void)
{
    printf("ANA_RTC_INT_RSTS is 0x%x\n", ANA_RTC_INT_RSTS);
    printf("value of it 0x%x\n", ANA_REG_GET(ANA_RTC_INT_RSTS));
    return ANA_REG_GET(ANA_RTC_INT_RSTS) & BIT_4;
}
