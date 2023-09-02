#include <stdio.h>
#include "matrix.h"


void print_data(const char* const data, const size_t size_x, const size_t size_y)
{
	for (size_t pos_y = 0; pos_y < size_y; pos_y++)
	{
		for (size_t pos_x = 0; pos_x < size_x; pos_x++)
		{
			DEBUG_EXEC(printf("\n printed data[%llu][%llu]: %c", pos_x, pos_y, data[pos_y * size_x + pos_x]));			
		}
		printf("\n");
	}
}


char scan_char() 
{
	char symbol;

	while (((symbol = getchar()) == ' ') || (symbol == '\n'))
	{
		if (symbol == '\0')
		{
			return NOT_SCANNED;
		}
	}

	return symbol;
}


int input_data(char* const data, const size_t size_x, const size_t size_y)
{
	size_t scanned_number = 0;

	const size_t target = size_x * size_y;

	char symbol;

	while (scanned_number < target)
	{
		//проверять на пробелы и другие символы
		// если \0, то аварийное завершение 
		// цикл, пока не цифра или символ

		symbol = scan_char();

		/*if ((symbol = scan_char()) == NOT_SCANNED)
		{
			return NOT_SCANNED;
		} */

		data[scanned_number] = symbol;

		scanned_number++;
	}

	return SCANNED;
}


int main()
{
	const size_t SIZE_X = 4;
	const size_t SIZE_Y = 2;

	char data[SIZE_X * SIZE_Y] = {};
	input_data(data, SIZE_X, SIZE_Y);	

	print_data(data, SIZE_X, SIZE_Y); 
}