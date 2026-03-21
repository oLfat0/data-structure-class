/* Exercício em Sala 1
Escreva o código em C para representar um nó de uma árvore binária
*/
#include <stdio.h>

typedef struct no{
    char conteudo;
    struct no *esq, *dir;
} No;
// typedef struct no No;

void preordem(No* p);

int main(){
    No* ptraiz;
    ptraiz = (No*) malloc(sizeof(No));
    
    ptraiz->conteudo = 'A';
    ptraiz->dir = NULL;
    ptraiz->esq = (No*) malloc(sizeof(No));

    ptraiz->esq->conteudo = 'B';
    ptraiz->esq->esq = NULL;
    ptraiz->esq->dir = NULL;
    
    return 0;
}

void preordem(No* p){
    if(p == NULL) return;

    printf("%c ", p->conteudo);
    preordem(p->esq);
    preordem(p->dir);
}
