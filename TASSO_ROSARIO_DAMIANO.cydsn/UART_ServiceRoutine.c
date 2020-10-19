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
#include "UART_ServiceRoutine.h"


CY_ISR(UART_RX_ISR)
{
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        received = UART_ReadRxData();
        flag = 1; 
        rx_index++ ;
        
        if(state == HEADER_RECEIVED)
        {
            Timer_ReadStatusRegister();
            Timer_Start();
        }
    }
}

/* [] END OF FILE */
