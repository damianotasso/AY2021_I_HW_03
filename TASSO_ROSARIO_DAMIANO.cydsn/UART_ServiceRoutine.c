/* ========================================
 * Damiano R Tasso 944232
 *
 * The UART is set so that an interrupt is generated every time is reved a byte. 
 * Every time the interrupt is generated the receved byte is read with the UART_ReadRxData(), the Timer is reset in the way to start and count the right period
 * and the rx_index in incremented. 
 * For each incrementation of the rx_index and if the right condition of the received byte is correct, I know which part of the string I had received. \in this
 * way is possible to set the state variable in the right way, in order to control the initialization in the main.c.
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
