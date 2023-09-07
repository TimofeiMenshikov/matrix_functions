#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
const size_t MAXSIZE = 256;
const size_t n_rows = 3;


static void input_text3(FILE* const stream, const size_t n_rows, char** const text);
static void print_text3(const size_t n_rows, char** const text);
int main()
{


	FILE* inputfile = fopen("input.txt", "r");
	assert(inputfile);

	//char* text3[] = {};  //text version 3.0
	char** text4 = (char**) calloc(n_rows, sizeof(char*)); //text version 4.0
	assert(text4);
	input_text3(inputfile, n_rows, text4);
	print_text3(n_rows, text4);

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