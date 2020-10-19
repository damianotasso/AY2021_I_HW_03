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
        if(flag == 1)
        {
            if((rx_index == 1) && (received == HEADER))
            {
                state = HEADER_RECEIVED;
                flag = 0; 
                Timer_Stop();
            }
            if(state == HEADER_RECEIVED)
            {
                if(rx_index == 2)
                {
                    Timer_Stop();
                    red_received = received;
                    flag = 0;
                }
                if(rx_index == 3)
                {
                    Timer_Stop();
                    green_received = received;
                    flag = 0;
                }
                if(rx_index == 4)
                {
                    Timer_Stop();
                    blue_received = received;
                    flag = 0;
                }
                /*
                switch(rx_index)
                {
                    case 2:
                        Timer_Stop();
                        red_received = received;
                        flag = 0;
                        break;
                    case 3:
                        Timer_Stop();
                        green_received = received;
                        flag = 0;
                        break;
                    case 4:
                        Timer_Stop();
                        blue_received = received;
                        flag = 0;
                        break;
                }*/
            }
            if((rx_index == 5 ) && (received == TAIL))
            {
                Timer_Stop();
                init.red = red_received;
                init.green = green_received;
                init.blue = blue_received;
                RGBLed_Write_Led_Color(init);
                UART_PutString("Initialization completed!\r\n");
                rx_index = 0;
                flag = 0;
            }
            if(received == 'v')
            {
                UART_PutString("RGB LED Program $$$");
                rx_index = 0;
                flag = 0;
            }
            
            if((flag_time == 1) && (received != 'v'))
            {
                UART_PutString("Error, byte not received in 5 seconds!\r\n");
                Timer_Stop();
                flag = 0;
            }
        }
        
    }
}

/* [] END OF FILE */
