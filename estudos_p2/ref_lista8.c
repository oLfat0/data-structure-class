#include <stdio.h>
#include <stdlib.h>

#define M 3

typedef struct no{
    struct no* filhos[M];
}No;

No* novo_no();

int main(){
    No* raiz = novo_no();

    //Filhos da Raíz
    raiz->filhos[0] = novo_no();        //e
    raiz->filhos[1] = novo_no();        //r
    raiz->filhos[2] = novo_no();        //s

    //Descendentes de filhos[0]
    raiz->filhos[0]->filhos[1] = novo_no(); //er
        raiz->filhos[0]->filhos[1]->filhos[1] = novo_no();  //err
            raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();   //erre
                raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no();    //erres


    raiz->filhos[0]->filhos[2] = novo_no(); //es 
        raiz->filhos[0]->filhos[2]->filhos[2] = novo_no();  //ess
            raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0] = novo_no();   //esse
                raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0]->filhos[2] = novo_no();    //esses

    //Descendentes de filhos[1]
    raiz->filhos[1]->filhos[0] = novo_no(); //re
        raiz->filhos[1]->filhos[0]->filhos[2] = novo_no();  //res
            raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0] = novo_no();   //rese
                raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0]->filhos[2] = novo_no();    //reses

    //Descendentes de filhos[2]
    raiz->filhos[2]->filhos[0] = novo_no(); //se
        raiz->filhos[2]->filhos[0]->filhos[1] = novo_no();  //ser

            raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0] = novo_no();   //sere
                raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0]->filhos[2] = novo_no();    //seres

            raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1] = novo_no();   //serr
                raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();    //serre
                    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no(); //serres




    return 0;
}

No* novo_no(){
    No* pt = (No*) malloc(sizeof(No));
    for(int i=0; i<M; i++){
        pt->filhos[i] = NULL;
    }

    return pt;
}