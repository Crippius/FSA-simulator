
#ifndef __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * state;
typedef char * alphabet;
typedef char * str;

typedef struct 
{
    state curr_q;
    char  i;
    str   z;
} configuration;

/*typedef struct
{
    configuration config;
    state  final_q;
} move;
*/
// typedef move* moves;

typedef struct
{
    configuration config;
    str  output;
} translation;

typedef translation* translations;

struct el{
    configuration config;
    state  final_q;
    struct el*next;
};

typedef struct 
{
    state* Q;
    alphabet  I;
    int  delta;
    state  q0;
    state* F;
    alphabet  O;
    translations eta;
} FSA;

state*       get_Q(void);
alphabet     get_I(void);
int          get_delta(struct el**L);
state        get_q0(void);
state*       get_F(void);
alphabet     get_O(void);
translations get_eta(void);

FSA create_fsa(struct el**L1);
void compute_fsa(FSA fsa, struct el**L2);

#endif