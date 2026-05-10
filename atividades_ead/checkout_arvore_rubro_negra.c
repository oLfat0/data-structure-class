#include <stdio.h>
#include <stdlib.h>

/* Definicoes de tipo */
enum cor_e { VERMELHO, PRETO };
typedef enum cor_e cor_e;

struct no {
    int chave;
    cor_e cor;
    struct no *esq, *dir;
};
typedef struct no  no;

/* Prototipos */
no* crie_no(int chave, cor_e cor);
int verifique_altura_preta(no* node);
int verifique_propriedades_rubro_negra(no* raiz);
int verifique_raiz_preta(no* raiz);
int verifique_vermelho(no* node);

/* Main */
// int main() {
//     /*
//         Exemplo de árvore rubro-negra válida:

//                 10(B)
//                /     \
//            5(R)      15(R)
//            /  \      /   \
//         NIL  NIL  NIL   NIL
//     */

//     no* raiz = crie_no(10, PRETO);
//     raiz->esq = crie_no(5, VERMELHO);
//     raiz->dir = crie_no(15, VERMELHO);

//     if (verifique_propriedades_rubro_negra(raiz))
//         printf("Arvore rubro-negra valida.\n");
//     else
//         printf("Arvore rubro-negra invalida.\n");

//     return 0;
// }

/* Main */
int main() {

    /* =====================================================
       Caso 1: Árvore rubro-negra válida
       
                10(B)
               /     \
           5(R)      15(R)
           /  \      /   \
        NIL  NIL  NIL   NIL
       ===================================================== */
    no* t1 = crie_no(10, PRETO);
    t1->esq = crie_no(5, VERMELHO);
    t1->dir = crie_no(15, VERMELHO);

    printf("Caso 1 (valida): %s\n",
           verifique_propriedades_rubro_negra(t1) ?
           "OK" : "ERRO");


    /* =====================================================
       Caso 2: Violacao da propriedade 2 (raiz nao preta)
       
                10(R)
               /     \
           5(B)      15(B)
       ===================================================== */
    no* t2 = crie_no(10, VERMELHO);
    t2->esq = crie_no(5, PRETO);
    t2->dir = crie_no(15, PRETO);

    printf("Caso 2 (raiz nao preta): %s\n",
           verifique_propriedades_rubro_negra(t2) ?
           "OK" : "ERRO");


    /* =====================================================
       Caso 3: Violacao da propriedade 4
       (no vermelho com filho vermelho)
       
                10(B)
               /
           5(R)
           /
        2(R)
       ===================================================== */
    no* t3 = crie_no(10, PRETO);
    t3->esq = crie_no(5, VERMELHO);
    t3->esq->esq = crie_no(2, VERMELHO);

    printf("Caso 3 (vermelho com filho vermelho): %s\n",
           verifique_propriedades_rubro_negra(t3) ?
           "OK" : "ERRO");


    /* =====================================================
       Caso 4: Violacao da propriedade 5
       (alturas pretas diferentes)
       
                10(B)
               /     \
           5(B)      15(B)
           /
        2(B)
       ===================================================== */
    no* t4 = crie_no(10, PRETO);
    t4->esq = crie_no(5, PRETO);
    t4->dir = crie_no(15, PRETO);
    t4->esq->esq = crie_no(2, PRETO);

    printf("Caso 4 (altura preta invalida): %s\n",
           verifique_propriedades_rubro_negra(t4) ?
           "OK" : "ERRO");

    return 0;
}

/* Implementação Funções */
no* crie_no(int chave, cor_e cor) {
    no* n = (no*) malloc(sizeof(no));
    n->chave = chave;
    n->cor = cor;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

int verifique_altura_preta(no* node) {    //Feito por mim(Otávio) em cima do esqueleto do código disponibilizado pelo professor

    if(node == NULL)
        return 1;

    int altura_esq = verifique_altura_preta(node->esq);
    int altura_dir = verifique_altura_preta(node->dir);

    if(altura_esq == 0 || altura_dir == 0)
        return 0;

    if(altura_esq != altura_dir)
        return 0;

    if(node->cor == PRETO)
        return altura_esq + 1;

    return altura_esq;
}

int verifique_propriedades_rubro_negra(no* raiz) {
    if (!verifique_raiz_preta(raiz)) {
        printf("Violacao: A raiz nao e preta.\n");
        return 0;
    }
        

    if (!verifique_vermelho(raiz)){
        printf("Violacao: No vermelho tem filho vermelho.\n");
        return 0;
    }
        

    if (verifique_altura_preta(raiz) == 0) {
        printf("Violacao: Alturas pretas diferentes em algum caminho.\n");
        return 0;
    }
        
    return 1;
}

int verifique_raiz_preta(no* raiz) {   //Feito por mim(Otávio) em cima do esqueleto do código disponibilizado pelo professor
    if(raiz->cor==PRETO) return 1;     
    return 0;
}

int verifique_vermelho(no* node) {     //Feito por mim(Otávio) em cima do esqueleto do código disponibilizado pelo professor
    if(node == NULL) return 1;

    if(node->cor == VERMELHO){

        if(node->esq!=NULL){           // Caso haja filho esquerdo
            if(node->esq->cor == VERMELHO) return 0;
    
            if(node->dir!=NULL){       // Caso  haja filho direito
                if(node->dir->cor == VERMELHO) return 0;
    
                return 1;              // Caso não haja filho direito
            }
    
            return 1;                  // Caso não haja filho esquerdo
        }
    }

    return verifique_vermelho(node->esq) && verifique_vermelho(node->dir);   //Passa por todas as subárvores direita e esquerda
}