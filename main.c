
#include "header.h"

FSA create_fsa(void)
{
    FSA fsa;
    FILE *fp;
    char c, stiz;
    char tmp = 'a';
    int i, pos, z;
    int alarm = 0;
    
    fp = fopen("file", "a"); //I used the mode append, but I think it's useful to create a new file for every single different AFS
    if (fp==NULL){
        printf("\nErrore nell'apertura del file, il file non esiste");
        return 0;
    }
    printf("Inserisci gli stati dell'automa: (\invio per terminare");
    while(tmp != '\n'){
            scanf("%c", &tmp);
            pos = ftell(fp);
            fseek(fp, 0, SEEk_SET); //rewind(fp); //obviously this should change everytime we change the set
            while ((!feof(fp))&&(alarm==1)){
                c = fgetc(fp);
                if (c==tmp){
                    printf("\nHai già inserito questo stato!");
                    alarm = 1;
                }
            } 
        fseek(fp, pos, SEEK_SET);
        fputc(tmp, fp);
    }
    alarm = 0;
    printf("\nIndica lo stato iniziale: ");
    do{
        scanf("%c", &stiz);
        fseek(fp, 0, SEEk_SET);
        while((!feof(fp))&&(alarm==1)){
            c = fgetc(fp);
            if(c==stiz){
                alarm = 1;
            }
        if(alarm == 0)
            printf("\nStato non valido!");
    }while(alarm == 0);
    printf("\nStato registrato con successo!");
    alarm = 0;
    tmp = 'a';
    z = pos;
    printf("Inserisci le lettere dell'alfabeto: (\invio per terminare);
    while(tmp != '\n'){
        scanf("%c", &tmp);
            pos = ftell(fp); 
            fseek(fp, z, SEEK_SET)
            while ((!feof(fp))&&(alarm==1)){
                c = fgetc(fp);
                if (c==tmp){
                    printf("\nHai già inserito questa lettera!");
                    alarm = 1;
                }
            } 
        fseek(fp, pos, SEEK_SET);
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
