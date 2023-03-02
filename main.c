
#include "header.h"

FSA create_fsa(void)
{
    FSA fsa;
    FILE *fp;
    char tmp = 'a';
    int i;
    int alarm = 0;
    
    fp = fopen("file", "a"); //I used the mode append, but I think it's useful to create a new file for every single different AFS
    if (fp==NULL){
        printf("\nErrore nell'apertura del file, il file non esiste");
        return 0;
    }
    printf("Inserisci gli stati dell'automa: (\invio per terminare");
    while(tmp != '\n'){
        do{
            scanf("%c", &tmp);
            fseek(fp, 0, SEEk_SET); //rewind(fp);
            while ((!feof(fp))&&(alarm==0)){
                
        }while(
        fputc(tmp, fp);
    }
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
        do{
            scanf("%d", &decision);
        }while((decision != 1)&&(decision != 2)&&(decision != 3));
            if (decision == 1)
            my_fsa = create_fsa();
            else if (decision == 2)
                compute_fsa(my_fsa);
            else if (decision == 3)
                break;
    }
    return (0);
}
