#include <stdio.h>
#include <stdlib.h>

#define M 27
#define Mx 26

struct celula{
    int conteudo;
    int estado;                         //Estado vai definir a característica da célula (0: VAZIA; 1: OCUPADA; 2: LIBERADA)
    struct celula *prox, *ant;
};
typedef struct celula Celula;

int hash_aux1(int k);                   //Método da divisão (hash base)
int hash_aux2(int k);                   
int hash_duplo(int k, int i);

void mostrar(Celula* hash[]);
void ins_hash_duplo(Celula* hash[], int k);
int buscar_hash_duplo(Celula* hash[], int b);
void remover_hash_duplo(Celula* hash[], int x);

int main(){
    Celula* tabela[M];

    int k;
    int b;
    int x;

    for(int i=0; i<M; i++){
        tabela[i] = NULL;           //Limpar lixo de memória
    }

    // Alocar Células fixas para teste de Colisão
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->conteudo = 5;
    nova->prox = NULL;
    nova->ant = NULL;
    nova->estado = 1;

    Celula* nova2 = (Celula*) malloc(sizeof(Celula));
    nova2->conteudo = 47;
    nova2->prox = NULL;
    nova2->ant = NULL;
    nova2->estado = 1;

    tabela[10] = nova;          
    tabela[20] = nova2;         //Se o valor k=20 for adicionado, sua função Hash de Dupla alocariá-lo para a posição 24(Pois a 20 já está ocupada por 'nova2')

    printf("Qual inserir? ");
    scanf("%d", &k);

    printf("=== Hash Duplo ===\n");
    ins_hash_duplo(tabela, k);

    printf("=== Mostrar Tabela ===\n");
    mostrar(tabela);

    printf("=== Buscar na Tabela ===\n");

    printf("Qual buscar? ");
    scanf("%d", &b);
    buscar_hash_duplo(tabela, b);

    printf("=== Remover na Tabela ===\n");

    printf("Qual remover? ");
    scanf("%d", &x);
    remover_hash_duplo(tabela, x);

    printf("=== Buscar na Tabela ===\n");

    printf("Qual buscar? ");
    scanf("%d", &b);
    buscar_hash_duplo(tabela, b);

    printf("=== Mostrar Tabela ===\n");
    mostrar(tabela);

    return 0;
}

int hash_aux1(int k){
    return k % M;
}

int hash_aux2(int k){
    return 1 + (k % (Mx));
}

int hash_duplo(int k, int i){
    printf("i: %d\n", i);
    return (hash_aux1(k) + i*hash_aux2(k)) % M;
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

void ins_hash_duplo(Celula* hash[], int v){
    int posi;

    for(int i=0; i<M; i++){
        posi = hash_duplo(v, i);

        if(hash[posi] != NULL){
            continue;
        }

        else{
            Celula* nova = (Celula*) malloc(sizeof(Celula));
            nova->conteudo = v;

            hash[posi] = nova;
            nova->prox = NULL;
            nova->ant = NULL;
            nova->estado = 1;

            break;
        }
    }
}

int buscar_hash_duplo(Celula* hash[], int b){
    int posi;

    for(int i=0; i<M; i++){
        posi = hash_duplo(b, i);
        
        if(hash[posi] == NULL){
            printf("Nao existe Chave %d na Tabela\n", b);
            return posi;
        }

        else if(hash[posi]->conteudo == b){
            printf("Chave %d encontrada (Posi: %d) | Iteracao: %d\n", b, posi, i);
            return posi;
        }

        else if(hash[posi] != NULL || hash[posi]->estado == 2){
            if(hash[posi]->estado == 1){
                printf("Posicao %d(iteracao: %d) esta OCUPADA por %d\n", posi, i, hash[posi]->conteudo);
                printf("Pulando...\n");
            }else{
                printf("Posicao %d esta LIBERADA\n", i);   
                printf("Pulando...\n");
            }
            continue;
        }
    }
}

void remover_hash_duplo(Celula* hash[], int x){
    int busca = buscar_hash_duplo(hash, x);

    if(hash[busca]->conteudo == x){
        printf("Removendo Chave %d (Posi: %d)\n", x, busca);
        hash[busca]->conteudo = NULL;
        hash[busca]->estado = 2;
    }
    else{
        printf("Nao existe Chave %d para ser removida\n", x);
    }
}
