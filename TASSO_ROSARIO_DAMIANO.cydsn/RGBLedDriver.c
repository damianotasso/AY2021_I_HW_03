/* ========================================================================================================================
 * Damiano R Tasso 944232
 *
 * in this .c file are implemented the function declared in the .h file. In particular thr RGBLed_Write_Led_Color(color c)
 * funcition set the color in order to change the Compare value of the corresponding PWM with the received data by the UART
 * ========================================================================================================================
*/
#include "project.h"
#include "RGBLedDriver.h"

void RGBLed_Start()
{
    PWM_RG_Start();
    PWM_B_Start();
};

void RGBLed_Write_Led_Color(color c)
{   
    PWM_RG_WriteCompare1(c.red);
    PWM_RG_WriteCompare2(c.green);
    PWM_B_WriteCompare(c.blue);
}

/* [] END OF FILE */