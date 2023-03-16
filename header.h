
#ifndef __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * state;
typedef char * alphabet;

typedef struct 
{
    state q;
    char  i;
    char o;
} configuration;

/*typedef struct
{
    configuration config;
    state  final_q;
} move;
*/
// typedef move* moves;

/*typedef struct
{
    configuration config;
    char *output;
} translation;

typedef translation* translations;
*/

struct el{
    configuration config;
    state  final_q;
    struct el*next;
};

typedef struct 
{
    state* Q;
    alphabet  I;
    struct el* delta;
    state  q0;
    state* F;
    alphabet  O; 
    //struct el* eta;
} FSA;

state*       get_Q(int *err);
alphabet     get_I(int *err);
struct el*   get_delta(int *err, state *Q, alphabet I);
state        get_q0(int *err, state *Q);
state*       get_F(int *err, state *Q);
alphabet     get_O(int *err);
void         get_eta(int *err, struct el*header, alphabet O);

FSA  create_fsa();
void compute_fsa(FSA fsa);
void translate_fsa(FSA fsa);

int char_is_in(char c, char *str);
int str_is_in(char *str, char **arr);

#endif