#ifndef MATRIX_H
#define MATRIX_H

enum is_scanned
{
	SCANNED = 1,
	NOT_SCANNED = 0
};

#ifdef INPUT_DEBUG
    #define DEBUG_EXEC(function)    \
        do                          \
        {                           \
            function;               \
        }                           \
        while(0);                   
#else                           
    #define DEBUG_EXEC(function)
#endif /* INPUT_DEBUG */ 

/* matrix.cpp */
char scan_char();
int input_data(char* const data, const size_t target);
void print_one_element(size_t pos_x, size_t pos_y, char symbol);
/* matrix.cpp */

#endif /* MATRIX_H */