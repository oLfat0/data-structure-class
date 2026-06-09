#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
typedef enum info{
    TERMINAL,
    NAO_TERMINAL
} Info;
typedef struct no{
    struct no* filhos[M];
    Info info;
}No;


char alfabeto[M] = {'e', 'r', 's'};

No* novo_no();
    /* Questão 2 */
int de_digi_pra_posi(char c);
char de_posi_pra_digi(int p);

    /* Questão 3 */
void percorre(No* pt);

    /* Questão 5 */
No* busca_dig(char* x, No* pt, int* l, int* a);

int main(){
    No* raiz = novo_no();

    /* Questão 1 */
    //Filhos da Raíz
    raiz->filhos[0] = novo_no();        //e
    raiz->filhos[1] = novo_no();        //r
    raiz->filhos[2] = novo_no();        //s

    //Descendentes de filhos[0]
    raiz->filhos[0]->filhos[1] = novo_no(); //er
        raiz->filhos[0]->filhos[1]->filhos[1] = novo_no();  //err
            raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();   //erre
            raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0]->info = TERMINAL;

                raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no();    //erres
                raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2]->info = TERMINAL;


    raiz->filhos[0]->filhos[2] = novo_no(); //es 
    raiz->filhos[0]->filhos[2]->info = TERMINAL; 

        raiz->filhos[0]->filhos[2]->filhos[2] = novo_no();  //ess
            raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0] = novo_no();   //esse
            raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0]->info = TERMINAL;

                raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0]->filhos[2] = novo_no();    //esses
                raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0]->filhos[2]->info = TERMINAL;


    //Descendentes de filhos[1]
    raiz->filhos[1]->filhos[0] = novo_no(); //re
    raiz->filhos[1]->filhos[0]->info = TERMINAL;

        raiz->filhos[1]->filhos[0]->filhos[2] = novo_no();  //res
        raiz->filhos[1]->filhos[0]->filhos[2]->info = TERMINAL;

            raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0] = novo_no();   //rese
            raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0]->info = TERMINAL;

                raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0]->filhos[2] = novo_no();    //reses
                raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0]->filhos[2]->info = TERMINAL;

    //Descendentes de filhos[2]
    raiz->filhos[2]->filhos[0] = novo_no(); //se
    raiz->filhos[2]->filhos[0]->info = TERMINAL;

        raiz->filhos[2]->filhos[0]->filhos[1] = novo_no();  //ser
        raiz->filhos[2]->filhos[0]->filhos[1]->info = TERMINAL;

            raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0] = novo_no();   //sere
                raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0]->filhos[2] = novo_no();    //seres
                raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0]->filhos[2]->info = TERMINAL;

            raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1] = novo_no();   //serr
                raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();    //serre
                raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0]->info = TERMINAL;

                    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no(); //serres
                    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2]->info = TERMINAL;
    

    /* Questão 3 */
    // raiz->filhos[0]->filhos[0] = novo_no();     //ee
    // raiz->filhos[0]->filhos[1] = novo_no();     //er

    // raiz->filhos[1]->filhos[1] = novo_no();     //rr

    // raiz->filhos[2]->filhos[1] = novo_no();     //sr
    // raiz->filhos[2]->filhos[2] = novo_no();     //ss

    percorre(raiz);

    return 0;
}

No* novo_no(){
    No* pt = (No*) malloc(sizeof(No));
    pt->info = NAO_TERMINAL;

    for(int i=0; i<M; i++){
        pt->filhos[i] = NULL;
    }

    return pt;
}

int de_digi_pra_posi(char c){
    for(int i=0; i<M; i++){
        if(alfabeto[i] == c){
            return i;
        }
    }
    return -1;
}

char de_posi_pra_digi(int p){
    return alfabeto[p];
}

void percorre(No* pt){
    if(pt == NULL)
        return;

    for(int i = 0; i < M; i++){
        if(pt->filhos[i] != NULL){
            printf("%c ", alfabeto[i]); 
            percorre(pt->filhos[i]);
        }
    }
}

No* busca_dig(char* x, No* pt, int* l, int* a){
    int k = strlen(x);
    *a = 0;

    if(*l == k){
        if(pt->info == TERMINAL) *a = 1;
        else *a = 0;
        return pt;
    }
    int posi = de_digi_pra_posi(x[*l]);

    if(pt->filhos[posi] != NULL){
        (*l)++;
        return busca_dig(x, pt->filhos[posi], l, a);
    }
    return pt;
}