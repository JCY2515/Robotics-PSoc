
#include "project.h"

int main(void)
{
    char Number_Pressed = '-';
    LCD_Char_1_Start();
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString("Wong");
    LCD_Char_1_Position(1,0);
    LCD_Char_1_PrintString("Value= ");
    LCD_Char_1_PutChar(Number_Pressed);
    LCD_Char_1_WriteControl(LCD_Char_1_CURSOR_WINK);
    
    Col_0_Write(0);
    Col_1_Write(0);
    Col_2_Write(0);

    for(;;)
    {
        Col_0_Write(1);
        if (Row_1_Read() == 1)
        {
            Number_Pressed = '1';
        }
        else if (Row_2_Read() == 1)
        {
            Number_Pressed = '4';
        }
        else if (Row_3_Read() == 1)
        {
            Number_Pressed = '7';
        }
        else if (Row_4_Read() == 1)
        {
            Number_Pressed = '*';
        }
        
        Col_0_Write(0);
        Col_1_Write(1);
        if (Row_1_Read() == 1)
        {
            Number_Pressed = '2';
        }
        else if (Row_2_Read() == 1)
        {
            Number_Pressed = '5';
        }
        else if (Row_3_Read() == 1)
        {
            Number_Pressed = '8';
        }
        else if (Row_4_Read() == 1)
        {
            Number_Pressed = '0';
        }
        
        Col_1_Write(0);
        Col_2_Write(1);
        if (Row_1_Read() == 1)
        {
            Number_Pressed = '3';
        }
        else if (Row_2_Read() == 1)
        {
            Number_Pressed = '6';
        }
        else if (Row_3_Read() == 1)
        {
            Number_Pressed = '9';
        }
        else if (Row_4_Read() == 1)
        {
            Number_Pressed = '#';
        }
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("Wong");
        LCD_Char_1_Position(1,0);
        LCD_Char_1_PrintString("Value= ");
        LCD_Char_1_PutChar(Number_Pressed);
        CyDelay(50);
    }
}
