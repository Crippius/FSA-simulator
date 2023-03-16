
#include "header.h"

void compute_fsa(FSA fsa){
    int accetto, i, j;
    char input[300];
    state * finali;
    struct el * header;
    configuration attuale;

    //preparo la stringa degli stati finali
    finali = fsa.F;

    //prendo configurazione iniziale uguale a q0
    attuale.q = fsa.q0;

    //prendo la testa della lista di delta
    header = fsa.delta;

    accetto = 0;

    //prendo input da verificare finchè la sua lunghezza non è maggiore di 0
    do{
        scanf("%s", input);
        fflush(stdin);
    } while(strlen(input) <= 0);

    for(i = 0; input[i] != '\0' && accetto == 0; i++){
        header = fsa.delta;
        for(header; header != NULL && accetto == 0; header = header -> next){
            //nel prossimo if vedo se lo stato tra l'attuale e quello del delta è lo stesso e se il carattere in input è lo stesso
            if(strcmp(attuale.q, header -> config.q) == 0 && input[i] == header -> config.i){
                attuale.q = strdup(header -> final_q);
                break;
            }
        }
        if (header == NULL)
        {
            printf("La stringa non e' accettata\n");
            return;
        }
    }
    for(j = 0; finali[j] != NULL && accetto == 0; j++){
        if(strcmp(attuale.q, finali[j]) == 0)
             accetto = 1;
    }
    if(accetto == 1){
        printf("La stringa e' accettata!\n");
    } else {
        printf("La stringa non e' accettata\n");
    }
}
