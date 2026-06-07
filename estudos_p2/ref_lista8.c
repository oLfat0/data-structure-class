#include <stdio.h>
#include <stdlib.h>

#define M 3

typedef struct no{
    struct no* filhos[M];
}No;

char alfabeto[M] = {'e', 'r', 's'};

No* novo_no();
    /* Questão 2 */
int de_digi_pra_posi(char c);
char de_posi_pra_digi(int p);

    /* Questão 3 */
void percorre(No* pt, int p);

int main(){
    No* raiz = novo_no();

    /* Questão 1 */
    //Filhos da Raíz
    raiz->filhos[0] = novo_no();        //e
    raiz->filhos[1] = novo_no();        //r
    raiz->filhos[2] = novo_no();        //s

    //Descendentes de filhos[0]
    // raiz->filhos[0]->filhos[1] = novo_no(); //er
    //     raiz->filhos[0]->filhos[1]->filhos[1] = novo_no();  //err
    //         raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();   //erre
    //             raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no();    //erres


    // raiz->filhos[0]->filhos[2] = novo_no(); //es 
    //     raiz->filhos[0]->filhos[2]->filhos[2] = novo_no();  //ess
    //         raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0] = novo_no();   //esse
    //             raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0]->filhos[2] = novo_no();    //esses

    // //Descendentes de filhos[1]
    // raiz->filhos[1]->filhos[0] = novo_no(); //re
    //     raiz->filhos[1]->filhos[0]->filhos[2] = novo_no();  //res
    //         raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0] = novo_no();   //rese
    //             raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0]->filhos[2] = novo_no();    //reses

    // //Descendentes de filhos[2]
    // raiz->filhos[2]->filhos[0] = novo_no(); //se
    //     raiz->filhos[2]->filhos[0]->filhos[1] = novo_no();  //ser

    //         raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0] = novo_no();   //sere
    //             raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0]->filhos[2] = novo_no();    //seres

    //         raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1] = novo_no();   //serr
    //             raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();    //serre
    //                 raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no(); //serres
    

    /* Questão 3 */
    raiz->filhos[0]->filhos[0] = novo_no();     //ee
    raiz->filhos[0]->filhos[1] = novo_no();     //er

    raiz->filhos[1]->filhos[1] = novo_no();     //rr

    raiz->filhos[2]->filhos[1] = novo_no();     //sr
    raiz->filhos[2]->filhos[2] = novo_no();     //ss

    percorre(raiz, 0);

    return 0;
}

No* novo_no(){
    No* pt = (No*) malloc(sizeof(No));
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

void percorre(No* pt, int p){
    if(pt == NULL)
        return;

    for(int i = 0; i < M; i++){
        if(pt->filhos[i] != NULL){
            printf("%c ", alfabeto[i]); 
            percorre(pt->filhos[i], i);
        }
    }
}
