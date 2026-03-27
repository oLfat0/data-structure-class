/* Árvores */
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *esq, *dir;
    char info;
} No;

No* novo_no(char n);
void pre_ordem(No* raiz);
void pos_ordem(No* raiz);
void ordem_simetrica(No* raiz);

int main(){
    No* raiz = (No*) malloc(sizeof(No));

    /* Exercícios 1 - 6 */
    raiz = novo_no('A');
    
    //Filhos de A
    raiz->esq = novo_no('B');
    raiz->dir = novo_no('C');

    //Descendentes de B
    raiz->esq->esq = novo_no('D');
    raiz->esq->esq->dir = novo_no('G');

    //Descendentes de C
    raiz->dir->esq = novo_no('E');
    raiz->dir->esq->esq = novo_no('H');
    raiz->dir->esq->dir = novo_no('I');
    raiz->dir->dir = novo_no('F');

    printf("Funcao Pre-Ordem:\n");
    pre_ordem(raiz);
    printf("\n\n");

    printf("Funcao Ordem Simetrica:\n");
    ordem_simetrica(raiz);
    printf("\n\n");

    printf("Funcao Pos-Ordem:\n");
    pos_ordem(raiz);

    /* Exercício 7 */
    // raiz = novo_no('+');

    // //Filhos de '+'
    // raiz->esq = novo_no('a');
    // raiz->dir = novo_no('*');

    // //Descendentes de '*'
    // raiz->dir->esq = novo_no('b');
    // raiz->dir->dir = novo_no('-');
    // raiz->dir->dir->esq = novo_no('/');
    // raiz->dir->dir->dir = novo_no('e');
    // raiz->dir->dir->esq->esq = novo_no('c');
    // raiz->dir->dir->esq->dir = novo_no('d');

    // pre_ordem(raiz);

    return 0;
}

No* novo_no(char n){
    No* p = (No*) malloc(sizeof(No));

    p->info = n;
    p->esq = NULL;
    p->dir = NULL;

    return p;
}

void pre_ordem(No* raiz){
    if(raiz == NULL) return;

    printf("%c ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void ordem_simetrica(No* raiz){
    if(raiz == NULL) return;

    ordem_simetrica(raiz->esq);
    printf("%c ", raiz->info);
    ordem_simetrica(raiz->dir);
}

void pos_ordem(No* raiz){
    if(raiz == NULL) return;

    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%c ", raiz->info);

}

