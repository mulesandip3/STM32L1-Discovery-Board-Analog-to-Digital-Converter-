#include "main.h"

#define GAIN		0.03425
#define OFFSET	140

int main(void)
{
	char str[16];
	uint16_t adc;
	
	lcd_init();
	adc_init(ADC_Channel_0);
	delay_ms(100);
	lcd_send_byte(LCD_CMD, 0x01);
	while(1)
	{
		GPIO_ToggleBits(GPIOC, LED_B);
		while(GPIO_ReadInputDataBit(GPIOC, BUTTON) != SET)
		{
			//adc = ADC_GetConversionValue(ADC1);
			lcd_send_byte(LCD_CMD, LCD_LINE1);
			sprintf(str, "count: %u", (ADC_GetConversionValue(ADC1)));
			lcd_puts(str);
			delay_ms(100);
		}
	}
}

