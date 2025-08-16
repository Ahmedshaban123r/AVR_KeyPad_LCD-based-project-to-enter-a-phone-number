#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "KeyPad.h"

int main(void)
{
	DDRA = (DDRA & ~KEYPAD_ROW_MASK) | KEYPAD_COL_MASK;
	PORTA |= KEYPAD_ROW_MASK;

	LCD_init();

	LCD_command(0x80);
	LCD_display_string(" Enter a number");
	LCD_command(0xC0);

	char number[12];
	int pos = 0;

	while (1)
	{
		char key = keypad_scan();
		if (key != '\0')
		{
			if ((key >= '0' && key <= '9') || key == '#')
			{
				if (key == '#')
				{
					if (pos == 11 && number[0] == '0' && number[1] == '1')
					{
						LCD_command(0xC0);
						for (int i = 0; i < 16; i++) LCD_data(' ');
						LCD_command(0xC0);
						LCD_display_string(" Saved");
						_delay_ms(3000);
					}
					else
					{
						LCD_command(0xC0);
						for (int i = 0; i < 16; i++) LCD_data(' ');
						LCD_command(0xC0);
						LCD_display_string(" Invalid");
						_delay_ms(3000);
					}

					LCD_command(0xC0);
					for (int i = 0; i < 16; i++) LCD_data(' ');
					LCD_command(0xC0);
					pos = 0;
				}
				else
				{
					if (pos < 11)
					{
						number[pos] = key;
						LCD_data(key);
						pos++;
					}
				}
			}
		}
	}
}