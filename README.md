# ATmega328P-Chip-Based-Tetris-Game
<div style="text-align:center">
<img src="https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/blob/main/tetris%20circuit.jpg" alt="Example Image" width="600" height="400">
</div>

# Project Introduction
In this project we have to create a single player arcade game called Tetris using AVR 
microcontrollers. Tetris is a puzzle video game created by Soviet software engineer Alexey Pajitnov in 1984. In Tetris, players complete lines by moving differently shaped pieces (tetrominoes), which descend onto the playing field. The completed lines disappear and grant the player points, and the player can proceed to fill the vacated spaces. The game ends when the playing field is filled. The longer the player can delay this outcome, the higher their score will be.
This is a simulation project that runs on computers using Proteus simulator software. Proteus is a computer software used to simulate, design and drawing electronic circuits. For program the microcontroller and other components we have used Atmel studio software.The Atmel Studio 7 is user friendly environment to write, build, and debug applications written in C/C++ or assembly code. It also connects seamlessly to the debuggers, programmers, and development kits that support AVR and SAM devices.

# Tetrominoes
These are the building blocks of the game. There 7 pieces that player can see inside the game.Player can move these pieces laterally to acsend them into desired place in the matrix.

![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/a7940b3d-c98c-47cf-8572-7115a3e79070)

# Objectives
Used various AVR Microcontroller functions to understand the design process and build the project.
Demonstrate how to interact between various AVR related electronic components andachieve final results.

# Components
- CPU – AVR MCU (Atmega328p) / Arduino UNO
- 8x8 matrix led display 
- BCD 7-segment display
- MAX7219 driver 
- Buttons
- Indicator led
- Secondary MCU to generate random numbe

# Functions
- UART (Universal Asynchronous Receiver/Transmitter.) library files
- MAX7219 driver library files
- GPIO function
- Timer /counter interrupts
- Memory functions

# Game Logic Implementation 
- Display the game letter by letter on the 8x8 display.
- When requested from main MCU, the 2nd MCU will generate a random number 
between 1-7 that each number represent a specific Tetris block.
- establish connection between two MCU using UART to communicate and decide 
which random block should be displayed next.
- In our game we have to send the letter "T" to the 2nd MCU to generate a random 
number and blink indicator LED.
- Once we received the random number it will display on a BCD 7 segment display.
- Tetris blocks descend from the top of the field. During this descent, the player can 
move the pieces laterally and rotate them until they touch the bottom of the field or 
land on a piece that had been placed before it.
- Also, player can use control buttons to laterally move the blocks, rotate them and 
place.
- When a line is completed, it disappears, and the blocks placed above fall one line down. And 
the score will be incremented by +1.

# External interrupts using ISR
In this game we wanted 4 control buttons and have to set them as external pin interrupts.Since there are only two INT pins (INT0, INT1) to use as interrupts we moved to use other pins to set control buttons.According to the atmega328p datasheet we observed that there are 23 PCINT pins and we have followed its instruction. 
- changed PCIE2 bit of Pin Change Interrupt Control Register (PCICR).
-  Configured Pin Change Mask Register (PCMSK) as follows.
![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/56b1ef52-57ac-4df2-b1d8-ab5301213ab9)

## UART (Universal Asynchronous Receiver/Transmitter)
![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/3c52af79-e427-4319-879c-a9c7b358fdd8)

We have used 02 MCU for this project. 01 is for generate a random number and other one for running the main game functions. For this we had to use UART to establish serial transfer between 02 MCUs.A UART is usually an individual or part of an integrated circuit (IC) used for serial communications over a computer or peripheral device serial port. One or more UART peripherals are commonly integrated in microcontroller chips.Before establish the connection between 2 MCUs we have to change some registers values in Main MCU.We have followed the below mentioned steps.

## Initializing UART
The first thing was we have to decide the baud rate. baud rate is the rate in bits per second that will be transmitted. There are common number of standards rates1200,2400,4800,9600,19200,38400,57600,115200. For most microcontroller projects where speed is not a huge concern therefore, we have used 9600.We can write to UBRR0H and UBRR0L registers to set baud rate and following formula used to calculate the UBRRn value.

![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/044b2f09-32f8-4bd4-89f2-ceb62b0517d8)

## Enabling the transmitter and receiver
the UART rx/tx pins on the microcontroller will behave as standard I/O pins. To do this, we need to set the RXEN0 and TXEN0 bits to 1 in the UCSR0B register.

![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/4c9399ab-c9ad-4627-9553-7f3a611a0e06)

## Writing an initialization function
![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/3ea1e8f9-5986-4d80-908e-c1ab575452fa)

## Transmitting a Character
UDRE0 is in the USART Control and Status Register 0 A (UCSR0A), and its value can be obtained by masking UCSR0A with (1 << UDRE0). We are waiting for this value to be 0.

![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/bd1e16c8-c9ed-434e-a4e1-e3dbe6281ae3)

We were required to send character “T” in order to receive a random number and display a tetriminoes in the LED matrix. Therefore, we have called this function like this.
USART_Transmit('T');

## Receiving over UART
Receiving characters over UART is very similar to transmitting them. In this case, we just needed to poll the UCSR0A register until the RXC0 bit is set. Then, we could return the received character from UDR0.

![image](https://github.com/Dulajay/ATmega328P-Chip-Based-Tetris-Game/assets/151004273/be1d73df-eac7-4455-b575-b67508c832d3)

# Conclusion
- We were able to completed almost every function of the project but there are few more functions to be developed to finish up the project.
- We have done self-studies and learned many new concepts from YouTube and some web sites during this project such as UART, MAX7219, etc. also we learned how to read a datasheet and configure registers as we want was a big advantage to develop this project.
- In addition to that we have learned that divide the whole project into sub systems and add them all together in the end was the best approach to develop the project.

# Acknowledgments

Special thanks to the following individuals who contributed to this project:
- My awesome team members for their hard work and dedication.
- Supportive friends who provided valuable feedback and encouragement.
- Lecturers for their guidance and insights throughout the development process.

Your contributions have made this project possible, and I appreciate your commitment and support.








