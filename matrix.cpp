#include <stdio.h>
#include "matrix.h"


int main()
{
	const size_t SIZE_X = 4;
	const size_t SIZE_Y = 2;
	const size_t SIZE = 3;

	char data[SIZE_X * SIZE_Y] = {};

	//input_data_triangle(data, SIZE);

	//print_data_triangle(data, SIZE);

	input_data_rect(data, SIZE_X, SIZE_Y);

	print_data_rect(data, SIZE_X, SIZE_Y); 
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


int input_data(char* const data, const size_t target)
{
	char symbol;

	size_t scanned_number = 0;

	while (scanned_number < target)
	{
		//проверять на пробелы и другие символы
		// если \0, то аварийное завершение 
		// цикл, пока не цифра или символ

		symbol = scan_char();

		if (symbol == NOT_SCANNED)
		{
			return NOT_SCANNED;
		} 

		data[scanned_number] = symbol;

		scanned_number++;
	}

	return SCANNED;
}



