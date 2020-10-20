/* ==========================================================================================================================
 * Damiano R Tasso 944232
 * 
 * The code presents a logic in which every time the state changes its value differets functions are used:
 * - Timer_Stop(): timer stopped to keep track of the time;
 * - UART_Init(): initialize the Uart.
 * rx_index and state are initialized in order to be in the wating state (IDLE) and to be in the beginnig situation.
 * In the state == COMPLETE is used the RGBLed_Write_Led_Color(init) function to initialize the color received by the string.
 *
 * ==========================================================================================================================
*/
#include "project.h"
#include "UART_ServiceRoutine.h"
#include "Timer_ServiceRoutine.h"
#include "RGBLedDriver.h"
#include "Global.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    
    isr_UART_StartEx(UART_RX_ISR);
    isr_Timer_StartEx(TIMER_ISR);
    
    RGBLed_Start();

    for(;;)
    {
        switch(state)
        {
            case HEADER_RECEIVED:
                Timer_Stop();
                break;
            case V_RECEIVED:
                Timer_Stop();
                UART_Init();
                UART_PutString("RGB LED Program $$$");
                rx_index = 0;
                state = IDLE;
                break;
            case ERROR:
                Timer_Stop();
                UART_Init();
                UART_PutString("Error, in the trasmitted string\r\n"); 
                rx_index = 0;
                state = IDLE;
                break;
            case TIME:
                Timer_Stop();
                UART_Init();
                rx_index = 0;
                UART_PutString("Error, byte not received in 5 seconds\r\n");
                state = IDLE;
                break;
            case COMPLETE:
                RGBLed_Write_Led_Color(init);
                Timer_Stop();
                UART_Init();
                UART_PutString("Initialization completed!\r\n");
                rx_index = 0;
                state = IDLE;
                break;
        }
    }
}

/* [] END OF FILE */