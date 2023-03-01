
typedef char * state;

typedef struct 
{
    state q;
    char  i;
} config;

typedef struct
{
    config c;
    state  q;
} dict_elem;

typedef dict_elem* dict;

typedef struct 
{
    state* Q;
    char*  I;
    dict   delta;
    state  initial_state;
    state* F;
    char*  O;
    dict   eta;
} FSA;