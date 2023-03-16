
#include "header.h"

// gcc *.c

int main()
{
    int decision;
    FSA my_fsa;

    while (1)
    {
        printf("Cosa vuoi fare?\n1 - Creare FSA\n2 - Utilizzare FSA\n3 - Uscire plz\n");
        do{
            fflush(stdin);
            scanf("%d", &decision);
        }while((decision != 1)&&(decision != 2)&&(decision != 3));
        if (decision == 1){
            printf("\n1 - RICONOSCITORE\n2 - TRADUTTORE\n");
            do{
                fflush(stdin);
                scanf("%d", &decision);
            }while((decision != 1)&&(decision != 2));
            my_fsa = create_fsa(decision);
        }
        else if (decision == 2){
            printf("\n1 - RICONOSCITORE\n2 - TRADUTTORE\n");
            do{
                fflush(stdin);
                scanf("%d", &decision);
            }while((decision != 1)&&(decision != 2));
            compute_fsa(my_fsa);
            if (decision == 2)
                translate_fsa(my_fsa);
        }
           
        else if (decision == 3)
            break;
    }
    return (0);
}
