#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *esq, *dir;
    int info;
} No;

void mostrar_arvore(No* raiz);

No* novo_no(int n);
// void busca_arvore(No* raiz, int x);
No* busca_arvore(No* pt, int *f, int x);
void insere(No* pt, int f, int x);

int main(){
    No* raiz = novo_no(3);  

    raiz->esq = novo_no(1);
    raiz->dir = novo_no(7);

    //Descendentes de 1:
    raiz->esq->dir = novo_no(2);

    //Descendentes de 7:
    raiz->dir->esq = novo_no(5);
        
        //Filhos de 5:
        raiz->dir->esq->esq = novo_no(4);
        raiz->dir->esq->dir = novo_no(6);


    int f=0;
    // No* pt;

    // for(int i=0; i<10; i++){
    //     printf("Procurando: %d\n", i);

    //     pt = busca_arvore(raiz, &f, i);
    //     printf("f: %d\n", f);
    //     printf("pt -> %p\n", pt);
    //     printf("Info -> %d\n", pt->info);
    // }

    mostrar_arvore(raiz);
    // insere(raiz, &f, 27);



    return 0;
}

void mostrar_arvore(No* raiz){
    if(raiz == NULL) return;

    printf("%d ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}


No* novo_no(int n){
    No* p = (No*) malloc(sizeof(No));

    p->info = n;
    p->esq = NULL;
    p->dir = NULL;

    return p;
}

// void busca_arvore(No* raiz, int x){
//     if(raiz == NULL) return;

//     if(raiz->info == x){
//         printf("Chave %d encontrada em No %p\n", x, raiz);
//     }
    
//     busca_arvore(raiz->esq, x);
//     busca_arvore(raiz->dir, x);
// }

No* busca_arvore(No* pt, int *f, int x){
    if(pt == NULL){
        *f = 0;
        return pt; 

    }else if(pt->info == x){
        *f = 1;  
        return pt;

    }else{
        if(x < pt->info){
            if(pt->esq == NULL){
                *f = 2;
                return pt; 

            }else{
                return busca_arvore(pt->esq, f, x);
            }

        }else{
            if(pt->dir == NULL){
                *f = 3;
                return pt;
            }else{
                return busca_arvore(pt->dir, f, x);
            }
        }
    }

}

void insere(No* pt, int *f, int x){
    No* pt = busca_arvore(pt, f, x);

    if(f==0){
        pt = novo_no(x);
    }
    else if(f==1) return;

    else{
        if(f==2){
            pt->esq = x;
        }else{
            pt->dir = x;
        }
    }
}
