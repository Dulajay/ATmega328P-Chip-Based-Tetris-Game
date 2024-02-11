#ifndef _ATTINY_MAX7219_H_
#define _ATTINY_MAX7219_H_

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/delay.h>

#ifndef	MAX7219_DIN_PIN
# define	MAX7219_DIN_PIN		PB0
#endif	/* !MAX7219_DIN_PIN */

#ifndef	MAX7219_CLK_PIN
# define	MAX7219_CLK_PIN		PB1
#endif	/* !MAX7219_CLK_PIN */

#ifndef	MAX7219_CS_PIN
# define	MAX7219_CS_PIN		PB2
#endif	/* !MAX7219_CS_PIN */

/**
 * Initialize display driver.
 * Clock pin, data pin and chip select pin
 * are defined at the top of this file.
 */
void MAX7219_init(void);

/**
 * Set status of a single pixel.
 * @param row: row number from range <0, 7>
 * @param col: column number from range <0, 7>
 */
void MAX7219_set_pixel(uint8_t row, uint8_t col, bool value);

/**
 * Set all 8 LEDs in a row.
 * @param row: row number from range <0, 7>
 * @param value: row value (each bit represents a LED in a row, i.e. 0b00001111)
 */
void MAX7219_set_row(uint8_t row, uint8_t value);

/**
 * Set all 8 LEDs in a column.
 * @param column: column number from range <0, 7>
 * @param value: column value (each bit represents a LED in a column, i.e. 0b00001111)
 */
void MAX7219_set_column(uint8_t column, uint8_t value);

/**
 * Set brightness of the display.
 * @param value: intensity from range <0, 15>
 */
void MAX7219_set_intensity(uint8_t value);

/**
 * Clear display. 
 */
void MAX7219_clear(void);

#define MAX7219_REG_NOOP                (0x00)
#define MAX7219_REG_DIGIT0              (0x01)
#define MAX7219_REG_DIGIT1              (0x02)
#define MAX7219_REG_DIGIT2              (0x03)
#define MAX7219_REG_DIGIT3              (0x04)
#define MAX7219_REG_DIGIT4              (0x05)
#define MAX7219_REG_DIGIT5              (0x06)
#define MAX7219_REG_DIGIT6              (0x07)
#define MAX7219_REG_DIGIT7              (0x08)
#define MAX7219_REG_DECODEMODE		(0x09)
#define MAX7219_REG_INTENSITY		(0x0A)
#define MAX7219_REG_SCANLIMIT		(0x0B)
#define MAX7219_REG_SHUTDOWN		(0x0C)
#define MAX7219_REG_DISPLAYTEST		(0x0F)

#define MAX7219_DIN_HIGH()              (PORTB |= _BV(MAX7219_DIN_PIN))
#define MAX7219_DIN_LOW()               (PORTB &= ~_BV(MAX7219_DIN_PIN))
#define MAX7219_CLK_HIGH()              (PORTB |= _BV(MAX7219_CLK_PIN))
#define MAX7219_CLK_LOW()               (PORTB &= ~_BV(MAX7219_CLK_PIN))
#define MAX7219_CS_HIGH()               (PORTB |= _BV(MAX7219_CS_PIN))
#define MAX7219_CS_LOW()                (PORTB &= ~_BV(MAX7219_CS_PIN))

static uint8_t MAX7219_state[8] = {0, 0, 0, 0, 0, 0, 0, 0};

static void
MAX7219_write(uint8_t value)
{
	uint8_t i;

	__asm("nop");
	for (i = 0; i < 8; ++i, value <<= 1) {
		MAX7219_CLK_LOW();
		__asm("nop");
		if (value & 0x80) {
			MAX7219_DIN_HIGH();
			} else {
			MAX7219_DIN_LOW();
		}
		MAX7219_CLK_HIGH();
	}
}

static void
MAX7219_send(uint8_t reg, uint8_t data)
{

	MAX7219_CS_HIGH();
	MAX7219_write(reg);
	MAX7219_write(data);
	MAX7219_CS_LOW();
	__asm("nop");
	MAX7219_CS_HIGH();
}

void
MAX7219_init(void)
{

	DDRB |= _BV(MAX7219_DIN_PIN)|_BV(MAX7219_CLK_PIN)|_BV(MAX7219_CS_PIN);
	MAX7219_send(MAX7219_REG_DECODEMODE, 0x00);
	MAX7219_send(MAX7219_REG_SCANLIMIT, 0x07);
	MAX7219_send(MAX7219_REG_INTENSITY, 0x0f);
	MAX7219_send(MAX7219_REG_DISPLAYTEST, 0x00);
	MAX7219_send(MAX7219_REG_SHUTDOWN, 0x01);
}

void
MAX7219_set_pixel(uint8_t row, uint8_t col, bool value)
{
	uint8_t data;

	if (row > 7 || col > 7)
	return;

	data = 1 << col;
	if (value) {
		MAX7219_state[row] |= data;
		} else {
		MAX7219_state[row] &= ~data;
	}

	MAX7219_send(row + 1, MAX7219_state[row]);
}

void
MAX7219_set_row(uint8_t row, uint8_t value)
{

	if (row > 7)
	return;

	MAX7219_state[row] = value;
	MAX7219_send(row + 1, value);
}

void
MAX7219_set_column(uint8_t column, uint8_t value)
{
	uint8_t i;

	if (column > 7)
	return;

	for (i = 0; i < 8; ++i) {
		MAX7219_set_pixel(i, column, !!((value >> i) & 0x01));
	}
}

void
MAX7219_set_intensity(uint8_t value)
{

	if (value > 15)
	return;

	MAX7219_send(MAX7219_REG_INTENSITY, value);
}

void
MAX7219_clear(void)
{
	uint8_t i;

	for (i = 0; i < 8; ++i) 
	{
		if (MAX7219_state[i]) 
		{
			MAX7219_state[i] = 0;
		    MAX7219_send(i + 1, 0);
		}
	}
}

void allclc(){ //clear display
	for (int x=0; x<8;x++)
	{
		for (int y=0; y<8; y++)
		{
			MAX7219_set_pixel(x, y,false);
		}
	}
}
void alllight(){ //clear display
	for (int x=0; x<8;x++)
	{
		for (int y=0; y<8; y++)
		{
			MAX7219_set_pixel(x, y,true);
		}
	}
}


#endif  /* !_ATTINY_MAX7219_H_ */

