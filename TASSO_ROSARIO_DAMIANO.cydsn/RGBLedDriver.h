/* ==========================================================================================================================
 * Damiano R Tasso 944232
 * 
 * In this .h file are declared some functions: 
 * - RGBLed_Start(): it activates the PWM   
 * - RGBLed_Write_Led_Color(): it initializes the color on the RGB Led
 * Is also defined a new type (color) as a struct that will contain the values used by the RGBLed_Write_Led_Color() function
 * to set he new color.
 * ==========================================================================================================================
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
    
    void RGBLed_Write_Led_Color(color c);
    
#endif    
/* [] END OF FILE */
