#include <stdio.h>
#include <stdlib.h>

#define M 27

struct celula{
    int conteudo;
    int estado;                         //Estado vai definir a característica da célula (0: VAZIA; 1: OCUPADA; 2: LIBERADA)
    struct celula *prox, *ant;
};
typedef struct celula Celula;

int hash_aux(int k);                //h(k) -> Método da Divisão (hash base)
int sond_linear(int k, int i);     

void mostrar(Celula* hash[]);
void ins_sond_linear(Celula* hash[], int k);
int buscar_sond_linear(Celula* hash[], int b);
void remove_sond_linear(Celula* hash[], int x);

int main(){
    Celula* tabela[M];
    int k;
    int b;

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

    tabela[10] = nova;          //Se o valor k=10 for adicionado, sua função Hash de Sond. Linear alocariá-lo para a posição 10
    tabela[20] = nova2;

    printf("Qual inserir? ");
    scanf("%d", &k);

    printf("=== Sondagem Linear ===\n");
    ins_sond_linear(tabela, k);

    printf("=== Mostrar Tabela ===\n");
    mostrar(tabela);

    printf("=== Buscar na Tabela ===\n");

    printf("Qual buscar? ");
    scanf("%d", &b);
    buscar_sond_linear(tabela, b);

    printf("=== Remover na Tabela ===\n");

    int x;
    printf("Qual remover? ");
    scanf("%d", &x);
    remove_sond_linear(tabela, x);

    printf("=== Buscar na Tabela ===\n");

    printf("Qual buscar? ");
    scanf("%d", &b);
    buscar_sond_linear(tabela, b);

    printf("=== Mostrar Tabela ===\n");
    mostrar(tabela);

    return 0;
}

int hash_aux(int k){
    return k % M;
}

int sond_linear(int k, int i){
    printf("i: %d\n", i);

    return (hash_aux(k)+i) % M;
}

void ins_sond_linear(Celula* hash[], int v){
    int posi;

    for(int i=0; i<M; i++){
        posi = sond_linear(v, i);

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

int buscar_sond_linear(Celula* hash[], int b){
    int posi;
    for(int i=0; i<M; i++){
        posi = sond_linear(b, i);
        
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
                printf("Posicao %d esta OCUPADA por %d\n", i, hash[posi]->conteudo);
                printf("Pulando...\n");
            }else{
                printf("Posicao %d esta LIBERADA\n", i);   
                printf("Pulando...\n");
            }
            continue;
        }
    }
}

void remove_sond_linear(Celula* hash[], int x){
    int busca = buscar_sond_linear(hash, x);

    if(hash[busca]->conteudo == x){
        printf("Removendo Chave %d (Posi: %d)\n", x, busca);
        hash[busca]->conteudo = NULL;
        hash[busca]->estado = 2;
    }
    else{
        printf("Nao existe Chave %d para ser removida\n", x);
    }
}