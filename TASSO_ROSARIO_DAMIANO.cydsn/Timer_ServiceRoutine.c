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
#include "Timer_ServiceRoutine.h"
#include "Global.h"

CY_ISR(TIMER_ISR)
{
    flag_time = 1;
    flag = 0;
    rx_index = 0;
}
/* [] END OF FILE */
