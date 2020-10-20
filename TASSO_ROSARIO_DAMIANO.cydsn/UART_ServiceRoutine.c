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
#include "RGBLedDriver.h"


CY_ISR(UART_RX_ISR)
{
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        received = UART_ReadRxData();
        rx_index++ ;
        Timer_Start();
        Timer_WritePeriod(250);
        
        if(rx_index == 1)
        {
            if(received == 'v')
            {
                state = V_RECEIVED;
            }
            else if(received == HEADER)
            {
                state = HEADER_RECEIVED;
            }
            else if(received != HEADER)
            {
                state = ERROR;
            }
        }
        if(rx_index == 2)
        {
            init.red = received;
        }
        if(rx_index == 3)
        {
            init.green = received;
        }
        if(rx_index == 4)
        {
            init.blue = received;
        }
        if(rx_index == 5)
        {
            if(received == TAIL)
            {
                state = COMPLETE;
            }
            else if(received != TAIL)
            {
                state = ERROR;
            }
        }
    }
}

/* [] END OF FILE */
