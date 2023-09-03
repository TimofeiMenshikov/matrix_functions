#include <stdio.h>
#include "matrix.h"


void print_data_triangle(const char* const data, const size_t size)
{
	size_t char_number = 0;
	const size_t target = size * (size + 1) / 2;

	for (size_t pos_y = 0; pos_y < (size + 1); pos_y++)
	{
		for (size_t pos_x = 0; pos_x < pos_y; pos_x++)
		{
			DEBUG_EXEC(printf("\n printed data[%llu][%llu]: ", pos_x, pos_y));			
			printf("%c ", data[char_number]);
			//printf("data[] is  %d \n", pos_x + (1 + pos_y) / 2);
			char_number++;

			if (char_number == target)
			{
				return; // не пишет последний \n
			}
		}
		printf("\n");
	}
}



int input_data_triangle(char* const data, const size_t size)
{
	const size_t target = size * (size + 1) / 2;

	return input_data(data, target);
}

