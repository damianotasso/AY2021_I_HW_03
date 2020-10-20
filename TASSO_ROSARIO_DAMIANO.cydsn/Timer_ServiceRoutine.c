/* ===================================================================================================================================
 * Damiano R Tasso 944232
 *  
 * The Timer generates an ISR o the TC, so every 5 seconds generates the interrupt. When this is generated the Status Register is read
 * and the state is initialized as TIME. in order to keep track of the 5 seconds and to return in the IDLE state.
 * 
 * ===================================================================================================================================
*/
#include "Timer_ServiceRoutine.h"
#include "Global.h"

CY_ISR(TIMER_ISR)
{
    Timer_ReadStatusRegister();
    state = TIME;
}
/* [] END OF FILE */
