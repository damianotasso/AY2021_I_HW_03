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
#ifndef __RGB_LED_DRIVER_H__
    #define __RGB_LED_DRIVER_H__
    
    #include "project.h"
    #include "Global.h"
    #include "PWM_RG.h"
    #include "PWM_B.h"
    
    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue; 
    } color;
    
    color init;
    
    void RGBLed_Start();
    void RGBLed_Stop();
    
    void RGBLed_Write_Led_Color(color c);
    
#endif    
/* [] END OF FILE */
