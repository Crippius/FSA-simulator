
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

typedef struct
{
    configuration config;
    state  final_q;
} move;

typedef move* moves;

typedef struct
{
    configuration config;
    str  output;
} translation;

typedef translation* translations;

typedef struct 
{
    state* Q;
    alphabet  I;
    moves  delta;
    state  q0;
    state* F;
    alphabet  O;
    translations eta;
} FSA;

state*       get_Q(void);
alphabet     get_I(void);
moves        get_delta(void);
state        get_q0(void);
state*       get_F(void);
alphabet     get_O(void);
translations get_eta(void);

FSA create_fsa(void);
void compute_fsa(FSA fsa);

#endif