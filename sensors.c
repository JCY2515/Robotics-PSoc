#include "project.h"

int main(void)
{
    int Count;
    QuadDec_1_Start();
    LCD_Char_1_Start();
    for(;;)
    {
        Count=QuadDec_1_GetCounter();
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintNumber(Count);
        CyDelay(50);
    }
}

