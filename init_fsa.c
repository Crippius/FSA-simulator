
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

int get_delta(struct el**L)  //la lista deve nascere qui, cioè dopo che hai preso stati e alfabeto ora qui crei una lista dinamica con tutte
{                            //le configurazioni che lui ti mette 
   struct el*last=NULL;
   struct el*element;
   int dec;
   int count = 0;
   int alarm;
   char tmp[200];
   char c;

   if(*L != NULL){
    return 0;
   }
   printf("\nOra inserisci le triple STATO_INIZIALE-INPUT-STATO_FINALE\n1-continuare\n0-terminare\n");
   do
   {
    scanf("%d", &dec);
   } while ((dec!=1)&&(dec!=0));

   while (dec==1){
    element = (struct el*)malloc(sizeof(struct el));
    if(element==NULL){
        printf("\nThe Heap Area is full");
        return 0;
    }
    printf("\nInserire STATO %d: ",count);
    gets(tmp); //qui bisognerebbe controllare che lo stato appartenga all'insieme degli stati messi prima
    strcpy(element -> config.curr_q, tmp);
    fflush(stdin);
    printf("\nInserire INPUT: ");
    scanf("%c", &c); //qui bisognerebbe controllare che l'input appartenga all'alfabeto messo prima
    element ->config.i = c;
    fflush(stdin);
    printf("\nInserire STATO FINALE: ");
    gets(tmp); //qui bisognerebbe controllare che lo stato appartenga all'insieme degli stati messi prima
    strcpy(element->final_q, tmp);
    element->next=NULL;
    if (last==NULL){
        *L=element;
        last=element;
    }
    else {
        last->next=element;
        last = element;
    }
    count ++;
    printf("\nPremere:\n1-CONTINUARE\n0-TERMINARE");
    do
    {
        scanf("%d", &dec);
    } while ((dec!=1)&&(dec!=0));
    if (dec==0)
        alarm = 1;
   }
   if(alarm==1)
    return 1;
   else
    return 0;
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

FSA create_fsa(struct el**L1)
{
    FSA fsa;
    fsa.Q = get_Q();
    fsa.I = get_I();
    fsa.delta = get_delta(L1);
    if(fsa.delta==0)
        printf("\nPROBLEMI, PROBLEMI");     
    fsa.q0 = get_q0();
    fsa.F = get_F();
    fsa.O = get_O();
    fsa.eta = get_eta();

    return fsa;
}

void compute_fsa(FSA fsa, struct el**L2){
    /*Rodri passati pure LIST che è il puntatore alla testa della lista
    così poi la puoi scandire col puntatore a LIST*/
}