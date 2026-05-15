#include <stdio.h>
#include <stdlib.h>
#define M 3

enum info_t { 
    TERMINAL, 
    NAO_TERMINAL
};

typedef struct no{
    struct no *filhos[M];
    enum info_t info;
} No;

char alfabeto[] = {'a', 'e', 'i', 'o', 'r', 's'};

No* novo_no();
int de_digito_para_posicao(char c);
char de_posicao_para_digito(int p);

int main(){
    No* raiz;

    // === Exercício 1 ===
    raiz = novo_no();

    // Filhos da Raíz
    raiz->filhos[0] = novo_no();            // ->e
    raiz->filhos[1] = novo_no();            // ->r
    raiz->filhos[2] = novo_no();            // ->s
    
    // Descendentes dos Primogênitos
    raiz->filhos[0]->filhos[1] = novo_no(); // ->er
    raiz->filhos[0]->filhos[2] = novo_no(); // ->es

    raiz->filhos[1]->filhos[0] = novo_no(); // ->re

    raiz->filhos[2]->filhos[0] = novo_no(); // ->se

    //
    raiz->filhos[0]->filhos[1]->filhos[1] = novo_no();                          // ->err
    raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();               // ->erre
    raiz->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no();    // ->erres

    //
    raiz->filhos[0]->filhos[2]->filhos[2] = novo_no();                          // ->ess
    raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0] = novo_no();               // ->esse
    raiz->filhos[0]->filhos[2]->filhos[2]->filhos[0]->filhos[2] = novo_no();    // ->esses

    //
    raiz->filhos[1]->filhos[0]->filhos[2] = novo_no();                          // ->res
    raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0] = novo_no();               // ->rese
    raiz->filhos[1]->filhos[0]->filhos[2]->filhos[0]->filhos[2] = novo_no();    // ->reses


    //
    raiz->filhos[2]->filhos[0]->filhos[1] = novo_no();                                  // ->ser

    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0] = novo_no();                       // ->sere
    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[0]->filhos[2] = novo_no();            // ->seres

    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1] = novo_no();                       // ->serr
    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0] = novo_no();            // ->serre
    raiz->filhos[2]->filhos[0]->filhos[1]->filhos[1]->filhos[0]->filhos[2] = novo_no(); // ->serres


    // === Exercício 2 ===
    int a = de_digito_para_posicao('a');
    int e = de_digito_para_posicao('e');
    int i = de_digito_para_posicao('i');
    

    if(a != -1){
        printf("Digito A - Posi: %d\n", a);
    }else{
        printf("Caractere nao pertence ao alfabeto");
    }

    if(e != -1){
        printf("Digito E - Posi: %d\n", e);
    }else{
        printf("Caractere nao pertence ao alfabeto");
    }
    
    if(i != -1){
        printf("Digito I - Posi: %d\n", i);
    }else{
        printf("Caractere nao pertence ao alfabeto");
    }

    printf("Posicao 3 - Digito: %c\n", de_posicao_para_digito(3));

    return 0;
}

No* novo_no(){
    No* p = (No*) malloc(sizeof(No));

    for(int i=0; i<M; i++){
        p->filhos[i] = NULL;
    }

    return p;
}

int de_digito_para_posicao(char c){
    for(int i=0; i<M; i++){
        if(alfabeto[i] == c){
            return i;
        }
    }
    return -1;
}

char de_posicao_para_digito(int p){
    return alfabeto[p];
}

//Anotações do Professor sobre função de Busca (obrigatório para o encerramento da aula)

No* buscadig(char x[], No *pt, int *l, int *a){
    int posicao;
    if(x[*l]=='\0'){
        *a = (pt->info == TERMINAL);
        return pt;
    }

    posicao = de_digito_para_posicao(x[*l]);
    if(pt->filhos[posicao] == NULL)
        return pt;

    (*l)++;
    return buscadig(x, pt->filhos[posicao], l, a);
}