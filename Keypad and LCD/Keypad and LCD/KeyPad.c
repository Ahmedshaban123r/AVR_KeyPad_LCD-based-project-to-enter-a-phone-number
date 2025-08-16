/*
 * keypad_d.c
 *
 * Created: 8/12/2025 3:24:36 PM
 *  Author: ASUS
 */ 
#include "KeyPad.h"
#include "LCD.h"

// Function to read the pressed key on the keypad
char readKeypad()
{
	while(1)
	{
		// Loop through the columns
		for (int col = 0; col < 4; col++)
		{
			// Set data direction for columns and activate a single column
			KEYPAD_DDR = KEYPAD_COL_MASK;
			KEYPAD_PORT = ~(1 << (col + 4));  // Shift to the correct column position
			
			// Check each row for a pressed key
			for (int row = 0; row < 4; row++)
			{
				// If a key is pressed in the current row
				if (!(KEYPAD_PIN & (1 << row)))
				{
					// Wait for key release
					while (!(KEYPAD_PIN & (1 << row)));
					// Return the corresponding character from the keypad matrix
					return keypad[row][col];
				}
			}
		}
		
	}
	return 0;  // This line should technically never be reached
}

// Function to scan the keypad and return the pressed key
char keypad_scan()
{
	char key = readKeypad();  // Read the pressed key
	if (key != 0)
	{
		// Display the pressed key on the LCD (assuming LCD_DISPLAY_CHAR is defined elsewhere)
	//	LCD_data(key);
	}
	
	return key;  // Return the pressed key
}