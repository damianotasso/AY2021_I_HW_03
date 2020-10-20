/* ======================================================================================================================================
 * Damiano R Tasso 944232
 * 
 * in this .h file are declared the global variables used in the project, in particulare are defined the states and the HEADE/TAIL value:
 * - IDLE: the waiting state. In this stat I am wating a new byte/string
 * - HEADER_RECEIVED: the state in which I'm sure to had received the right HEADER 
 * - ERROR: this state contains errors like receive wrong HEADER/TAIL 
 * - V_RTECEIVED: this state is set when the char 'v' is received
 * - TIME: this state is used when the 5 seconds have been passed 
 * - COMPLETE: in this state all the receved bytes are right and the new color is set
 * ======================================================================================================================================
*/
#ifndef __GLOBAL_H__
    #define __GLOBAL_H__
    
    #include "project.h"
    
    #define HEADER 0xA0
    #define TAIL 0xC0
    #define IDLE 0
    #define HEADER_RECEIVED 1
    #define ERROR 2
    #define V_RECEIVED 3
    #define COMPLETE 4
    #define TIME 5 
    
    
    uint8_t received;
    uint8_t rx_index;
    uint8_t state;
    
#endif    

/* [] END OF FILE */
