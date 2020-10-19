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
#ifndef __GLOBAL_H__
    #define __GLOBAL_H__
    
    #include "project.h"
    
    #define HEADER 0xA0
    #define HEADER_RECEIVED 1
    #define TAIL 0xC0
    
    
    uint8_t flag;
    uint8_t received;
    uint8_t rx_index;
    uint8_t flag_time;
    uint8_t state;
    uint8_t red_received;
    uint8_t green_received; 
    uint8_t blue_received;

    
#endif    

/* [] END OF FILE */
