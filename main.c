
#include "header.h"

FSA create_fsa(void)
{
    FSA fsa;
    /* Initialise FSA */
    return fsa;
}

void compute_fsa(FSA fsa)
{
    /* Calculating... */
}

int main()
{
    int decision; 
    FSA my_fsa;
    while (1)
    {
        printf("Cosa vuoi fare?\n1 - Creare FSA\n2 - Utilizzare FSA\n3 - Uscire plz\n");
        scanf("%d", &decision);
        if (decision == 1)
            my_fsa = create_fsa();
        else if (decision == 2)
            compute_fsa(my_fsa);
        else if (decision == 3)
            break;
    }
    return (0);
}