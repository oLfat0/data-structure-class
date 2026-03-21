/* Tabela Hash */
#include <stdio.h>
#include <stdlib.h>
#define M 23

struct celula{
    int conteudo;
    struct celula *prox, *ant;
};
typedef struct celula Celula;


int h(int k);
void inserir(Celula* hash[], int k);
void mostrar(Celula* hash[]);
int busca(Celula* hash[], int v);
void remover(Celula* hash[], int r);

int main(){
    /* ### Exercício 1 ### */
    // int k;

    // scanf("%d", &k);
    // printf("Posicao de %d: %d\n", k, h(k));


    /* ### Exercício 2 ### */
    Celula* t[M];

    for(int i=0; i<M; i++){
        t[i] = NULL;
    }

    printf("Inserir:\n");

    for(int i=0; i<7; i++){
        int k;
        scanf("%d", &k);
        inserir(t, k);
    }
    mostrar(t);
    
    printf("Buscar:\n");
    int j;
    scanf("%d", &j);

    if(busca(t, j) != -1){
        printf("Valor Encontrado em: %d\n", busca(t, j));
    }else{
        printf("Nenhum Valor Encontrado [NULL]\n");
    }

    printf("Removendo: %d\n", 55);
    remover(t, 55);
    mostrar(t);

    return 0;
}

int h(int k){
    return k % M;
}

void inserir(Celula* hash[], int v){
    int posi = h(v);
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->conteudo = v;

    if(hash[posi]==NULL){
        hash[posi] = nova;
        nova->prox = NULL;
        nova->ant = NULL;
    }else{
        nova->prox = hash[posi];
        nova->ant = NULL;
        hash[posi]->ant = nova;
        hash[posi] = nova;
    }
}

void mostrar(Celula* hash[]){
    Celula* p;
    for(int i=0; i<M; i++){
        p = hash[i];
        printf("%2d: ", i);
        
        if(p==NULL) printf("\n");

        while(p != NULL){
            if(p->prox==NULL){
                printf("%d\n", p->conteudo);
            }else{
                printf("%d -> ", p->conteudo);
            }
            p = p->prox;
        }
    }
}

int busca(Celula* hash[], int v){
    int posi = h(v);
    Celula* p;
    
    if(hash[posi] != NULL){
        int i=0;
        p = hash[posi];

        while(p != NULL){
            if(p->conteudo == v) return i;
            p = p->prox;
            i++;
        }
        return -1;
    }
    return -1;
}

void remover(Celula* hash[], int r){
    int bus = busca(hash, r);
    int posi = h(r);
    Celula* p;

    if(bus != -1){
        p = hash[posi];

        while(p->conteudo != r){
            p = p->prox;
        }
        if(p->prox==NULL){              //Eliminar o ÚLTIMO elemento da fila
            p->ant->prox = NULL;
        }
        else if(p->ant != NULL){        //Eliminar um elemento do MEIO da fila
            p->ant->prox = NULL;
            p->prox->ant = NULL;
        }
        else{
            p->prox->ant = NULL;        //Eliminar o 1º elemento da fila
        }   
        free(p);
    }       
}