#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include "matrix.h"
const size_t MAXSIZE = 256;
const size_t n_rows = 3;

#define matrix_offset(text, n_col, n_row, n_cols) text + n_row * n_cols + n_col

static void input_text3(FILE* const stream, const size_t n_rows, char** const text);
static void print_text3(const size_t n_rows, char** const text);

static void input_text1(FILE* const stream, const size_t n_rows, const size_t n_cols, char* const text);
static void print_text1(const size_t n_rows, const size_t n_cols, char* const text);

int main()
{
	FILE* inputfile = fopen("input.txt", "r");
	assert(inputfile);

	//char* text3[] = {};  //text version 3.0
	//char** text4 = (char**) calloc(n_rows, sizeof(char*)); //text version 4.0
	//char text1[n_rows * MAXSIZE] = {}; // text version 1.0
	char* text2 = (char*) calloc(n_rows * MAXSIZE, sizeof(char)); // text version 2.0
	//assert(text4);
	//input_text3(inputfile, n_rows, text4);
	//print_text3(n_rows, text4);

	input_text1(inputfile, n_rows, MAXSIZE, text2);
	print_text1(n_rows, MAXSIZE, text2);

	return 0;
}

static void input_text3(FILE* const stream, const size_t n_rows, char** const text)
{
	char buf[MAXSIZE] = {};
	for (size_t n_row = 0; n_row < n_rows; n_row++)
	{
		fgets(buf, MAXSIZE, stream);
		char* row = (char*) calloc(strlen(buf), sizeof(char));
		assert(row);
		strncpy(row, buf, strlen(buf));
		text[n_row] = row;
	}	
}

static void print_text3(const size_t n_rows, char** const text)
{
	for (size_t n_row = 0; n_row < n_rows; n_row++)
	{
		printf("%s", text[n_row]);
	}
}

static void input_text1(FILE* const stream, const size_t n_rows, const size_t n_cols, char* const text)
{
	for (size_t n_row = 0; n_row < n_rows; n_row++)
	{
		fgets(matrix_offset(text, 0, n_row, n_cols), n_cols, stream);
	}
}

static void print_text1(const size_t n_rows, const size_t n_cols, char* const text)
{
	for (size_t n_row = 0; n_row < n_rows; n_row++)
	{
		for (size_t n_col = 0; (n_col < n_cols) && (*matrix_offset(text, n_col, n_row, n_cols)); n_col++)
		{
			putchar(*matrix_offset(text, n_col, n_row, n_cols));
		}
	}
}