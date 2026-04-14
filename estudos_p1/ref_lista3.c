#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *esq, *dir;
    char info;
}No;

No* novo_no(char info);

int main(){
    No* ptraiz = novo_no('1');

    ptraiz->esq = novo_no('7');
    ptraiz->dir = novo_no('9');

    ptraiz->esq->esq = novo_no('2');
    ptraiz->esq->dir = novo_no('6');

    ptraiz->esq->dir->esq = novo_no('5');
    ptraiz->esq->dir->dir = novo_no('11');

    ptraiz->dir->dir = novo_no('9');
    ptraiz->dir->dir->esq = novo_no('5');
    
    pre_ordem(ptraiz);

    return 0;
}

No* novo_no(char info){
    No* novo = (No*) malloc(sizeof(No));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
}

void pre_ordem(No* raiz){
    if(raiz==NULL) return;

    printf("%c ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}