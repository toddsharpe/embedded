#include "../../../Inc/SoC.h"
#include <string.h>
#include "printf.h"

void uart_write(const uint8_t *buffer, size_t length);
void spi_write(const uint8_t *buffer, size_t length);

void _putchar(char character)
{
	while (UART->txdata.full) {};
	UART->txdata.data = character;
}

void main()
{
	//Uart test
	uart_write("Hello, world!\r\n", 15);

	//SPI test
	spi_write("Hello, world!\r\n", 15);

	//GPIO test
	GPIO1->dir = 0x1;
	GPIO1->data_out = 0x1;

	//Printf test
	printf("Cycles: 0x%x, Freq: 0x%x\r\n", SOC_BLOCK->cycles, SOC_BLOCK->freq);
	printf("i=%d\r\n", 123);

	//LED loop
	uint32_t value = 0;
	while (1)
	{
		if (IO_BLOCK->switches & 0x1)
		{
			// Count down
			value--;
		}
		else
		{
			// Count up
			value++;
		}

		// Display
		IO_BLOCK->led_display = value;
		IO_BLOCK->led_bar = value;

		//Delay
		for (volatile int i = 0; i < 50000; i++)
			__asm("nop");
	}

	__asm("ebreak");
}

void uart_write(const uint8_t *buffer, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		while (UART->txdata.full) {};
		UART->txdata.data = buffer[i];
	}
	while (UART->txdata.full) {};
}

void spi_write(const uint8_t *buffer, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		while (UART->txdata.full) {};
		SPI1->txdata.data = buffer[i];
	}
	while (SPI1->txdata.full) {};
}
