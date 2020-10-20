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
    Timer_ReadStatusRegister();
    state = TIME;
}
/* [] END OF FILE */
