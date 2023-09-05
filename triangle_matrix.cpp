#include <stdio.h>
#include "matrix.h"


void print_data_triangle(const char* const data, const size_t size)
{
	size_t char_number = 0;
	const size_t target = size * (size + 1) / 2;

	for (size_t pos_y = 0; pos_y < (size + 1); pos_y++) // TODO: size + 1???
	{
		for (size_t pos_x = 0; pos_x < pos_y; pos_x++)
		{
			print_one_element(pos_x, pos_y, data[char_number]);
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


void print_data_triangle_mod(const char* const data)
{
	const size_t size = data[0];
	
	print_data_triangle(data + 1, size);
}

int input_data_triangle(char* const data, const size_t size)
{
	const size_t target = size * (size + 1) / 2;

	return input_data(data, target);
}

