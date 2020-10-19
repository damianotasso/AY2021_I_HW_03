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
#include "RGBLedDriver.h"

void RGBLed_Start()
{
    PWM_RG_Start();
    PWM_B_Start();
};

void RGBLed_Stop()
{
    PWM_RG_Stop();
    PWM_B_Stop();
};

static void Write_Led_Red(uint8_t r);
static void Write_Led_Green(uint8_t g);
static void Write_Led_Blue(uint8_t b);


static void Write_Led_Red(uint8_t r)
{
    PWM_RG_WriteCompare1(r);
}

static void Write_Led_Green(uint8_t g)
{
    PWM_RG_WriteCompare2(g);
}

static void Write_Led_Blue(uint8_t b)
{
    PWM_B_WriteCompare(b);
}

void RGBLed_Write_Led_Color(color c)
{
    Write_Led_Red(c.red);
    Write_Led_Green(c.green);
    Write_Led_Blue(c.blue);
}

/* [] END OF FILE */
