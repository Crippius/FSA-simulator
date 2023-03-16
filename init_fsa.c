
#include "header.h"

state* get_Q(int *err)
{
    state* Q;
    char   tmp[200];
    int    i;
    int    n;
    int    prompt;

    if (*err == 0)
        return NULL;

    n = 0;
    while (n <= 0)
    {
        printf("Inserire numero di stati: ");
        scanf("%d", &n);
        fflush(stdin);
    }

    Q = (state*) malloc(sizeof(state) * (n + 1));
        if (!Q) {
        *err = 0;
        printf("The Heap Area is full\n");
        return NULL;
    }
    
    for (i = 0; i < n + 1; i++)
        Q[i] = NULL;
    for (i = 0; i < n; i++)
    {
        prompt = 0;
        printf("Stato %d: ", i+1);
        do
        {
            if (prompt == 1)
                printf("Inserire stato valido\n");
            fflush(stdin);
            scanf("%s", tmp);
            prompt = 1;
        } while (str_is_in(tmp, Q) != -1);
        Q[i] = strdup(tmp);
    }
    fflush(stdin);

    return Q;
}

alphabet get_I(int *err)
{
    char tmp[200];
    alphabet I;
    int i, prompt = 0;

    if (*err == 0)
        return NULL;
    
    printf("Ora inserisci l'alfabeto: ");
    do {
        if (prompt == 1)
            printf("Inserire alfabeto valido\n");
        prompt = 0;
        fflush(stdin);
        scanf("%s", tmp);
        for (i = 0; tmp[i + 1] != '\0'; i++)
            if (char_is_in(tmp[i], tmp+i+1) != -1)
                prompt = 1;
    } while (prompt == 1);
    I = strdup(tmp);

    return I;
} 

struct el* get_delta(int *err, state *Q, alphabet I)  //la lista deve nascere qui, cioè dopo che hai preso stati e alfabeto ora qui crei una lista dinamica con tutte
{                            //le configurazioni che lui ti mette 
   struct el*last=NULL;
   struct el*element;
   struct el*L;
   int dec;
   int count = 0;
   int alarm;
   char tmp[200];
   char c;

   if (*err == 0)
       return NULL;
   printf("\nOra inserisci le triple STATO_INIZIALE-INPUT-STATO_FINALE\n1-continuare\n0-terminare\n");
   do {
    scanf("%d", &dec);
   } while ((dec!=1)&&(dec!=0));

   while (dec==1){
        element = (struct el*)malloc(sizeof(struct el));
        if(element==NULL){
            printf("The Heap Area is full\n");
            *err = 0;
            return NULL;
        }
        do {
            fflush(stdin);
            printf("Inserire STATO INIZIALE: ");
            scanf("%s", tmp);
        } while (str_is_in(tmp, Q) == -1);

        element -> config.q = strdup(tmp);
        do {
            fflush(stdin);
            printf("Inserire INPUT: ");
            scanf("%c", &c);
        } while (char_is_in(c, I) == -1);
        element ->config.i = c;
        do {
            fflush(stdin);
            printf("Inserire STATO FINALE: ");
            scanf("%s", tmp);
        } while (str_is_in(tmp, Q) == -1);
        element->final_q = strdup(tmp);
        element->next=NULL;
        if (last==NULL){
            L=element;
            last=element;
        }
        else {
            last->next=element;
            last = element;
        }
        count ++;
        printf("Premere:\n1 - CONTINUARE\n0 - TERMINARE\n");
        do
        {
            scanf("%d", &dec);
        } while ((dec!=1)&&(dec!=0));
        if (dec==0)
            return L;
    }
    *err = 0;
    return NULL;
}


state get_q0(int *err, state *Q)
{
    char  tmp[200];
    state q0;
    int prompt = 0;
    
    if (*err == 0)
        return NULL;
    

    printf("Ora inserisci lo stato iniziale: ");
    do {
        if (prompt == 1)
            printf("Inserire stato iniziale valido\n");
        prompt = 1;

        fflush(stdin);
        scanf("%s", tmp);
    } while (str_is_in(tmp, Q) == -1);

    q0 = strdup(tmp);

    return q0;
}

state* get_F(int *err, state *Q)
{
    state* F;
    char   tmp[200];
    int    i;
    int    n;
    int    prompt;

    if (*err == 0)
        return NULL;
    n = 0;
    while (n <= 0)
    {
        printf("Inserire numero di stati finali: ");
        scanf("%d", &n);
        fflush(stdin);
    }
    F = (state*) malloc(sizeof(state) * (n + 1));
    if (!F)
    {
        *err = 0;
        return NULL;
    }

    for (i = 0; i < n + 1; i++)
        F[i] = NULL;
    for (i = 0; i < n; i++)
    {
        prompt = 0;
        printf("Stato finale %d: ", i+1);
        do {
            if (prompt == 1)
                printf("Inserire stato finale valido\n");
            fflush(stdin);
            scanf("%s", tmp);
            prompt = 1;
        } while (str_is_in(tmp, Q) == -1);
        F[i] = strdup(tmp);
    }
    fflush(stdin);

    return F;
}

alphabet get_O(int *err)
{
    char     tmp[200];
    alphabet O;
    int i, prompt = 0;

    if (*err == 0)
        return NULL;

    printf("Ora inserisci l'alfabeto di output: ");
    do {
        if (prompt == 1)
            printf("Inserire alfabeto valido\n");
        prompt = 0;
        fflush(stdin);
        scanf("%s", tmp);
        for (i = 0; tmp[i + 1] != '\0'; i++)
            if (char_is_in(tmp[i], tmp+i+1) != -1)
                prompt = 1;
    } while (prompt == 1);
    O = strdup(tmp);

    return O;
}

translations get_eta(int *err)
{
    translations tmp = NULL;

    if (*err == 0)
        return NULL;
    // sike
    return tmp;

}

FSA create_fsa()
{
    FSA fsa;
    int err = 1;

    fsa.Q = get_Q(&err);
    fsa.I = get_I(&err);
    fsa.delta = get_delta(&err, fsa.Q, fsa.I);
    fsa.q0 = get_q0(&err, fsa.Q);
    fsa.F = get_F(&err, fsa.Q);
    // fsa.O = get_O(&err); // work in progress
    // fsa.eta = get_eta(&errr);
    if(err == 0)
        printf("\nPROBLEMI, PROBLEMI\n"); 
    return fsa;
}

