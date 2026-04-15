/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    int i = 00;
    LCD_Char_1_Start();
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_Position(1,2);
    LCD_Char_1_PrintNumber(1);
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
