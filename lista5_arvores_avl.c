//NÃO FINALIZADO

#include <stdio.h>
#include <stdlib.h>

#define M 25

typedef struct no{
    struct no *esq, *dir;
    char info;
} No;

No* novo_no(char info);
void imprima_estrutura(No* raiz, int nivel);
void padding(char ch, int n);

No* rotacao_direita(No* p);
No* rotacao_esquerda(No* p);

int main(){
    No* raiz = novo_no('g');

    //Descendentes de 'g'
    raiz->esq = novo_no('e');
    raiz->dir = novo_no('j');

    //Descendentes de 'e'
    raiz->esq->esq = novo_no('c');
    raiz->esq->dir = novo_no('f');

    raiz->esq->esq->esq = novo_no('b');
    raiz->esq->esq->dir = novo_no('d');

    raiz->esq->esq->esq->esq = novo_no('a');

    //Descendentes de 'j'
    raiz->dir->dir = novo_no('k');
    printf("Arvore OG:\n");
    imprima_estrutura(raiz, 0);

    printf("Aplicando Rotacao-Direita (Left-Left)\n");
    raiz->esq = rotacao_direita(raiz->esq);     //Nó 'e'

    imprima_estrutura(raiz, 0);

    return 0;
}

No* novo_no(char info){
    No* novo = (No*) malloc(sizeof(No));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void padding(char ch, int n){
    for(int i=0; i<n; i++)
        putchar(ch);
}

void imprima_estrutura(No* raiz, int nivel){
    if(raiz == NULL){
        padding('\t', nivel);
        puts("~");
    }else{
        imprima_estrutura(raiz->dir, nivel+1);
        padding('\t', nivel);
        printf("%c \n", raiz->info);
        imprima_estrutura(raiz->esq, nivel+1);
    }
}

No* rotacao_direita(No* p){
    /* Left-Left */
    No* pt = p->esq;

    p->esq = pt->dir;
    pt->dir = p;

    return pt;
}

No* rotacao_esquerda(No* p){
    /* Right-Right */
    No* pt = p->dir;

    p->dir = pt->esq;
    pt->esq = p;

    return pt;
}

No* rotacao_dupla_dir(No* p){
    /* Left-Right */
    p->esq = rotacao_esquerda(p->esq);
    p = rotacao_direita(p);

    return p;
}

No* rotacao_dupla_esq(No* p){
    /* Right-Left */

    p->dir = rotacao_direita(p->dir);
    p = rotacao_esquerda(p);

    return p;
}