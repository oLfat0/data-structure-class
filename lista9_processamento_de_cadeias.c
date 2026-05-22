#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct no{
    int simbolo;
    int frequencia;
    struct no *esq, *dir;
}No;

No* novo_no();
No* oplus(No* t1, No* t2);

int main(){
    int s[N] = {1, 2, 3, 4, 5};   //vetor p/ armazenar símbolos
    int f[N] = {3, 4, 9, 3, 2};   //vetor p/ armazenar frequências
    int n = 5;      //quantidade de símbolos



    return 0;
}

No* oplus(No* t1, No* t2){
    No* tx = novo_no();

    tx->esq = t1;
    tx->dir = t2;
    tx->frequencia = (t1->frequencia)+(t2->frequencia);

    return tx;
}

No* novo_no(){
    No* p = (No*) malloc(sizeof(No));

    p->simbolo = 0;
    p->frequencia = 0;
    p->esq = NULL;
    p->dir = NULL;

    return p;
}