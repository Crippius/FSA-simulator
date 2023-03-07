
#include "header.h"

state* get_Q(void)
{
    state* Q;
    char   tmp[200];
    int    i;
    int    n;

    n = 0;
    while (n <= 0)
    {
        printf("Inserire numero di stati: ");
        scanf("%d", &n);
        fflush(stdin);
    }
    Q = (state*) malloc(sizeof(state) * (n + 1));
    printf("Ora inserisci gli stati: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        Q[i] = strdup(tmp);
    }
    fflush(stdin);
    Q[i] = NULL;

    return Q;
}

alphabet get_I(void)
{
    char tmp[200];
    alphabet I;

    printf("Ora inserisci l'alfabeto: ");
    scanf("%s", tmp);
    I = strdup(tmp);
    fflush(stdin);

    return I;
} 

moves get_delta(void)
{
    moves tmp = NULL;

    // sike
    return tmp;
}

state get_q0(void)
{
    char  tmp[200];
    state q0;

    printf("Ora inserisci lo stato iniziale: ");
    scanf("%s", tmp);
    fflush(stdin);
    q0 = strdup(tmp);

    return q0;
}

state* get_F(void)
{
    state* F;
    char   tmp[200];
    int    i;
    int    n;

    n = 0;
    while (n <= 0)
    {
        printf("Inserire numero di stati finali: ");
        scanf("%d", &n);
        fflush(stdin);
    }
    F = (state*) malloc(sizeof(state) * (n + 1));
    printf("Ora inserisci gli stati: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        F[i] = strdup(tmp);
    }
    fflush(stdin);
    F[i] = NULL;

    return F;
}

alphabet get_O(void)
{
    char     tmp[200];
    alphabet O;

    printf("Ora inserisci l'alfabeto di output: ");
    scanf("%s", tmp);
    O = strdup(tmp);
    fflush(stdin);

    return O;
}

translations get_eta(void)
{
    translations tmp = NULL;

    // sike
    return tmp;

}

FSA create_fsa(void)
{
    FSA fsa;
    
    fsa.Q = get_Q();
    fsa.I = get_I();
    fsa.delta = get_delta(); 
    fsa.q0 = get_q0();
    fsa.F = get_F();
    fsa.O = get_O();
    fsa.eta = get_eta();

    return fsa;
}