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