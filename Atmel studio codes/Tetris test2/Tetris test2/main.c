  /*
 * Tetris test2.c
 *
 * Created: 5/13/2022 7:42:45 PM
 * Author : Dulakshi
 */ 


#include "functions.h"
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int activity=0;


int main(void)
{
	DDRB |= 1 << 5; // Configuring PB5 / D13 as Output
	DDRC = 0xFF;
	UCSR0B |= RX_COMPLETE_INTERRUPT; //from usart header file

	   DDRD &= ~(1<<DDD2);  //set switches as inputs
	   DDRD &= ~(1<<DDD3);
	   DDRD &= ~(1<<DDD4);
	   DDRD &= ~(1<<DDD5);
	   
	   PCICR |= (1 << PCIE2); //enable PCIE2 bit in PCINT register
	   
	   PCMSK2 |= (1 << PCINT18); //enable PCINT18 bit in Pin Change Mask Register 
	   PCMSK2 |= (1 << PCINT19); //enable PCINT19 bit in Pin Change Mask Register 
	   PCMSK2 |= (1 << PCINT20); //enable PCINT20 bit in Pin Change Mask Register 
	   PCMSK2 |= (1 << PCINT21); //enable PCINT21 bit in Pin Change Mask Register 
	   
	   sei(); //enable the global interrupts
	   	USART_Init(); //calling function of USART initiate
	   	MAX7219_init(); //calling function of MAX7219 drier initiate
	   	name_display(); //calling game name display function
		GameOver(); //calling game over display function
   
    while (1) 
    {   
		blockgen(); //displaying the blocks according to the generated random number
		
		
		
		
    }

}

ISR(PCINT2_vect){
	
	if (!(PIND &(1<<PIND2))){ //if button ROTATE pressed
		
		
		activity=1;
		
		
	}
	if(!(PIND &(1<<PIND3)))//if button LEFT pressed
	{
		
		
		activity =2;
		
	}
	if(!(PIND &(1<<PIND4)))  //if button RIGHT pressed
	{
		
	
		activity=3;
		
	}


}