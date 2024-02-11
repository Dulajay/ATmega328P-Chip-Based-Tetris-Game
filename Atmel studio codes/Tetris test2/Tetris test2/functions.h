#include "max7219.h"
#include "uart.h"

#define F_CPU 8000000UL
#include <util/delay.h>
int c1,c2,c3,c4;
int r1,r2,r3,r4;

unsigned char MAP[8][8]={
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};

void name_display()
{

	  	MAX7219_set_row(2,0b01111100); //T   7,6,5,4,3,2,1,0
	  	MAX7219_set_column(4,0b01111100);  
	  	_delay_ms(5000);
	  	MAX7219_clear();

		MAX7219_set_column(6,0b01000100); //E
		MAX7219_set_column(5,0b01000100);
		MAX7219_set_column(4,0b01010100);
		MAX7219_set_column(3,0b01010100);
		MAX7219_set_column(2,0b01111100);
		_delay_ms(5000);
		MAX7219_clear();
	
	
	  	MAX7219_set_row(2,0b01111100); //T
	  	MAX7219_set_column(4,0b01111100);
	  	_delay_ms(5000);
	  	MAX7219_clear();
	
		MAX7219_set_row(2,0b00111100); //R
		MAX7219_set_row(4,0b00111100);
		MAX7219_set_column(2,0b01111100);
		MAX7219_set_column(6,0b01101000);
		_delay_ms(5000);
		MAX7219_clear();
	
		MAX7219_set_row(2,0b00111000);  //I
		MAX7219_set_row(6,0b00111000);
		MAX7219_set_column(4,0b01111100);
		_delay_ms(5000);
		MAX7219_clear();
	
		MAX7219_set_row(2,0b01111000); //S
		MAX7219_set_row(3,0b00000100);
		MAX7219_set_row(4,0b00111000);
		MAX7219_set_row(5,0b01000000);
		MAX7219_set_row(6,0b00111100);
		_delay_ms(5000);
		MAX7219_clear();
	
}
	
void blocks1()    //I piece                             
	
	{   c1=3; r1=1; //pixel 1 initial position
		c2=4; r2=1; //pixel 2
		c3=5; r3=1; //pixel 3
		c4=6; r4=1; //pixel 4
		
		for(int i=0;i<8;i++)	
		{
			MAX7219_set_pixel(r1,c1,true);
			MAX7219_set_pixel(r2,c2,true);
			MAX7219_set_pixel(r3,c3,true);
			MAX7219_set_pixel(r4,c4,true);
			_delay_ms(2000);
			MAX7219_clear();
			r1++; r2++; r3++; r4++;
		}
			
	}
	
	void blocks2()   	//J shape
	
	{   c1=6; r1=1; //pixel 1 initial position
		c2=5; r2=1; //pixel 2
		c3=4; r3=1; //pixel 3
		c4=4; r4=0; //pixel 4
		
		
		for (int i=0;i<8;i++)
		{
			MAX7219_set_pixel(r1,c1,true);
			MAX7219_set_pixel(r2,c2,true);
			MAX7219_set_pixel(r3,c3,true);
			MAX7219_set_pixel(r4,c4,true);
			_delay_ms(2000);
			MAX7219_clear();
			r1++; r2++; r3++; r4++;
			
		}
	}
		
		void blocks3()   //L shape
		
		{   c1=6; r1=0; //pixel 1 initial position
			c2=6; r2=1; //pixel 2
			c3=5; r3=1; //pixel 3
			c4=4; r4=1; //pixel 4
			
			
			for (int i=0;i<8;i++)
			{
				MAX7219_set_pixel(r1,c1,true);
				MAX7219_set_pixel(r2,c2,true);
				MAX7219_set_pixel(r3,c3,true);
				MAX7219_set_pixel(r4,c4,true);
				_delay_ms(2000);
				MAX7219_clear();
				r1++; r2++; r3++; r4++;
				
			}
		}	
		
		void blocks4() //O piece
		
		{   c1=6; r1=0; //pixel 1 initial position
			c2=5; r2=0; //pixel 2
			c3=6; r3=1; //pixel 3
			c4=5; r4=1; //pixel 4
			
			
			for (int i=0;i<8;i++)
			{
				MAX7219_set_pixel(r1,c1,true);
				MAX7219_set_pixel(r2,c2,true);
				MAX7219_set_pixel(r3,c3,true);
				MAX7219_set_pixel(r4,c4,true);
				_delay_ms(2000);
				MAX7219_clear();
				r1++; r2++; r3++; r4++;
				
			}
		}
		
		void blocks5()  //S piece
		
		{   c1=6; r1=0; //pixel 1 initial position
			c2=5; r2=0; //pixel 2
			c3=5; r3=1; //pixel 3
			c4=4; r4=1; //pixel 4
			
			
			for (int i=0;i<8;i++)
			{
				MAX7219_set_pixel(r1,c1,true);
				MAX7219_set_pixel(r2,c2,true);
				MAX7219_set_pixel(r3,c3,true);
				MAX7219_set_pixel(r4,c4,true);
				_delay_ms(2000);
				MAX7219_clear();
				r1++; r2++; r3++; r4++;
				
			}
		}
		
void blocks6() //T piece
		
		{   c1=6; r1=1; //pixel 1 initial position
			c2=5; r2=1; //pixel 2
			c3=5; r3=0; //pixel 3
			c4=4; r4=1; //pixel 4
			
			
			for (int i=0;i<8;i++)
			{
				MAX7219_set_pixel(r1,c1,true);
				MAX7219_set_pixel(r2,c2,true);
				MAX7219_set_pixel(r3,c3,true);
				MAX7219_set_pixel(r4,c4,true);
				_delay_ms(2000);
				MAX7219_clear();
				r1++; r2++; r3++; r4++;
				
			}
		}
		
void blocks7() //Z piece

{   c1=4; r1=0; //pixel 1 initial position
	c2=5; r2=0; //pixel 2
	c3=6; r3=1; //pixel 3
	c4=5; r4=1; //pixel 4
	
	
	for (int i=0;i<8;i++)
	{
		MAX7219_set_pixel(r1,c1,true);
		MAX7219_set_pixel(r2,c2,true);
		MAX7219_set_pixel(r3,c3,true);
		MAX7219_set_pixel(r4,c4,true);
		_delay_ms(2000);
		MAX7219_clear();
		r1++; r2++; r3++; r4++;
		
	}
}
		
void blockgen(){ //display the block according to the generated number 
	USART_Transmit('T'); //sending the serial bus signal to request a random number
	_delay_ms(5000);
	
	text = USART_Receive();
	
	
	if (text == '1'){
		PORTC = 0x01; // display the numbers that RNG MCU generated
		blocks1();
		
	}
	else if (text =='2'){
		PORTC = 0x02;
		blocks2();
	}
	
	else if (text =='3'){
		PORTC = 0x03;
		blocks3();
		
	}
	else if (text =='4'){
		PORTC = 0x04;
		blocks4();
		
	}
	else if (text=='5'){
		PORTC = 0x05;
		blocks5();
		
	}
	else if (text=='6'){
		PORTC = 0x06;
		blocks6();
		
	}
	else if (text=='7'){
		PORTC = 0x07;
		blocks7();
		
	}
	
	
	
	
}	


void GameOver ()
{
		  	MAX7219_set_row(2,0b00111100); //G   7,6,5,4,3,2,1,0
		  	MAX7219_set_row(3,0b00000010);
			MAX7219_set_row(4,0b00110010);
			MAX7219_set_row(5,0b00100010);
			MAX7219_set_row(6,0b00111100);
		  	_delay_ms(5000);
		  	MAX7219_clear();
	
	
			MAX7219_set_row(2,0b00001000); //A   7,6,5,4,3,2,1,0
			MAX7219_set_row(3,0b00010100);
			MAX7219_set_row(4,0b00100010);
			MAX7219_set_row(5,0b00111110);
			MAX7219_set_row(6,0b00100010);
			_delay_ms(5000);
			MAX7219_clear();
			
			MAX7219_set_row(2,0b00100010); //M   7,6,5,4,3,2,1,0
			MAX7219_set_row(3,0b00110110);
			MAX7219_set_row(4,0b00101010);
			MAX7219_set_row(5,0b00100010);
			MAX7219_set_row(6,0b00100010);
			_delay_ms(5000);
			MAX7219_clear();	
			
		MAX7219_set_column(5,0b01000100); //E
		MAX7219_set_column(4,0b01000100);
		MAX7219_set_column(3,0b01010100);
		MAX7219_set_column(2,0b01010100);
		MAX7219_set_column(1,0b01111100);
		_delay_ms(10000);
		MAX7219_clear();
		
	MAX7219_set_row(6,0b00011100); //O
	MAX7219_set_row(5,0b00100010);
	MAX7219_set_row(4,0b00100010);
	MAX7219_set_row(3,0b00100010);
	MAX7219_set_row(2,0b00011100);
	_delay_ms(5000);
	MAX7219_clear();
	
		MAX7219_set_row(2,0b00100010); //V
		MAX7219_set_row(3,0b00100010);
		MAX7219_set_row(4,0b00100010);
		MAX7219_set_row(5,0b00010100);
		MAX7219_set_row(6,0b00001000);
		_delay_ms(5000);
		MAX7219_clear();
		
		MAX7219_set_column(5,0b01000100); //E
		MAX7219_set_column(4,0b01000100);
		MAX7219_set_column(3,0b01010100);
		MAX7219_set_column(2,0b01010100);
		MAX7219_set_column(1,0b01111100);
		_delay_ms(5000);
		MAX7219_clear();
		
		MAX7219_set_row(2,0b00011110); //R
		MAX7219_set_row(3,0b00100010);
		MAX7219_set_row(4,0b00011110);
		MAX7219_set_row(5,0b00100010);
		MAX7219_set_row(6,0b00100010);
		_delay_ms(5000);
		MAX7219_clear();				
		
					
	
}	