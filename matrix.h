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
/* matrix.cpp */

/* rect_matrix.cpp*/
void print_data_rect(const char* const data, const size_t size_x, const size_t size_y);
int input_data_rect(char* const data, const size_t size_x, const size_t size_y);
/* rect_matrix.cpp*/

/*triangle_matrix.cpp*/
void print_data_triangle(const char* const data, const size_t size);
int input_data_triangle(char* const data, const size_t size);
/*triangle_matrix.cpp*/