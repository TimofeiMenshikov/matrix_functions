#include <stdio.h>
#include "matrix.h"

void print_data_rect(const char* const data, const size_t size_x, const size_t size_y)
{
	size_t char_number = 0;
	const size_t target = size_x * size_y; 

	for (size_t pos_y = 0; pos_y < size_y; pos_y++)
	{
		for (size_t pos_x = 0; pos_x < size_x; pos_x++)
		{
			DEBUG_EXEC(printf("\n printed data[%llu][%llu]: ", pos_x, pos_y));			
			printf("%c ", data[char_number]);

			char_number++;

			if (char_number == target)
			{
				return;
			}
		}
		printf("\n");
	}
}


int input_data_rect(char* const data, const size_t size_x, const size_t size_y)
{
	const size_t target = size_x * size_y;

	return input_data(data, target);
}
