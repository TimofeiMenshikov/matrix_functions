#include <stdio.h>
#include <ctype.h>
#include "matrix.h"
#include "rect_matrix.h"

void print_data_rect(const char* const data, const size_t size_x, const size_t size_y)
{
	size_t char_number = 0;
	const size_t target = size_x * size_y; 

	for (size_t pos_y = 0; pos_y < size_y; pos_y++)
	{
		for (size_t pos_x = 0; pos_x < size_x; pos_x++)
		{
			print_one_element(pos_x, pos_y, data[char_number]);

			char_number++;

			if (char_number == target)
			{
				return;
			}
		}
		printf("\n");
	}
}



void print_data_rect_mod(const char* const data) // в массиве первый элемент - размер по y, второй элемент - размер по x
{
	const size_t size_y = data[0];
	const size_t size_x = data[1];
	
	print_data_rect(data + 2, size_x, size_y);
}


int input_data_rect(char* const data, const size_t size_x, const size_t size_y)
{
	const size_t target = size_x * size_y;

	return input_data(data, target);
}
