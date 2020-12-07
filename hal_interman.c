
/* hal_intermain.c -- interrupt manager HAL and BSL layers implementation
//
// Copyright (C) 1985-2020 by Michel de Champlain
//
*/
#include "hal_intermain.h"
#include <avr/io.h>
#include <avr/interrupt.h>




void hal_Interrupt_Disable(void){
    cli(); // interrupt disabled

}


void hal_Interrupt_Enable(void){

    DDRD &= ~(1 << DDD2);       // Clear the PD2 pin
                            	//  (PCINT0 pin) is set to input
    PORTD |= (1 << PORTD2);     //  pull-up enabled
    EICRA |= (1 << ISC00);      // set INT0 to trigger on ANY logic change
    EIMSK |= (1 << INT0);       // Turns on INT0

    sei();  //enable interrupt

}

u16 hal_Interrupt_SaveAndDisable(void){
    
//Save Status Register 
   u16 registerControl = *SREG;

// call the disable Disable method 
	hal_Interrupt_Disable(); 
	
	return registerControl;


}
void hal_Interrupt_Restore(u16 flags){

//Restore and return addr

u16 *register_addr  = SREG;

	*register_addr = flags;
     
     
}