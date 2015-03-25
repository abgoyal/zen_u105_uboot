#include <common.h>
#include <asm/io.h>

#include <asm/arch/regs_adi.h>
#include <asm/arch/adi_hal_internal.h>
#include <asm/arch/analog_reg_v3.h>

uint16_t adc_voltage_table[2][2] =
{
    {3750, 4200},
    {3210, 3600},
};
uint16_t CHGMNG_AdcvalueToVoltage (uint16_t adcvalue)
{
	int32_t temp;
	temp = adc_voltage_table[0][1] - adc_voltage_table[1][1];
	temp = temp * (adcvalue - adc_voltage_table[0][0]);
	temp = temp / (adc_voltage_table[0][0] - adc_voltage_table[1][0]);

	printf("uboot battery voltage:%d,adc4200:%d,adc3600:%d\n",temp + adc_voltage_table[0][1],
		adc_voltage_table[0][0],adc_voltage_table[1][0]);

	return temp + adc_voltage_table[0][1];
}

void CHG_TurnOn (void)
{
    ANA_REG_AND (ANA_CHGR_CTL1,~CHGR_PD_BIT);
}

void CHG_ShutDown (void)
{
    ANA_REG_OR (ANA_CHGR_CTL1,CHGR_PD_BIT);
}

void CHG_SetRecharge (void)
{
	ANA_REG_OR (ANA_CHGR_CTL0,CHGR_RECHG_BIT);
}

void CHG_Init (void)
{
	unsigned int chip_id = 0;

	ANA_REG_MSK_OR(ANA_CHGR_CTL0,CHGR_CC_EN_BIT,(CHGR_CC_EN_BIT | CHGR_CC_EN_RST_BIT));
	ANA_REG_MSK_OR(ANA_CHGR_CTL1,
		    (2 << CHGR_CHG_CUR_SHIFT) & CHGR_CHG_CUR_MSK,CHGR_CHG_CUR_MSK); //set charge current 500mA
	CHG_SetRecharge();

	chip_id = ANA_REG_GET(ANA_CHIP_ID_LOW);
	chip_id |= (ANA_REG_GET(ANA_CHIP_ID_HIGH) << 16);
	if (chip_id == 0x8820A001) {	//metalfix
		adc_voltage_table[0][0] = 3329;
		adc_voltage_table[1][0] = 2855;
	}
}

