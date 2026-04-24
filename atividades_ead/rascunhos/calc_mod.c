/* 
Tava precisando saber o cálculo do mod de alguns números, aí fiz esse """código""" simples só pra ver
o que dava cada resultado ¯\_(ツ)_/¯
*/
#include <stdio.h>
#define M 27
#define Mx 26

int hash_aux1(int k);
int hash_aux2(int k);
int hash_duplo(int k, int i);

int divi_binaria(int k);

int main(){
    int x;
    int h;
    int a;

    // printf("Divisao Inteira: %d // %d = %d\n", a, b, a/b);
    // printf("MOD Normal: %d mod %d = %d\n", a, b, a%b);
    printf("O que fazer?\n");
    printf("1: Hash Duplo | 2: Divisao Binaria\n");
    scanf("%d", &x);

    switch(x){
        case 1:
            printf("Hash Duplo:\n");
            scanf("%d", &h);
            printf("Hash Duplo de %d: Posi = %d\n", h, hash_duplo(h, 0));
            break;
        case 2:
            while(1){
                printf("Divisoes Binarias:\n");
                scanf("%d", &a);
                if(a!=0){
                    printf("Inteiro | Resto\n");
                    divi_binaria(a);
                }
                else{
                    break;
                }
            }   
            
        default:
            printf("Opcao invalida :(\n");
    }
    
    return 0;
}

int hash_aux1(int k){
    return k % M;
}

int hash_aux2(int k){
    return 1 + (k % Mx);
}

int hash_duplo(int k, int i){
    return (hash_aux1(k) + i*hash_aux2(k)) % M;
}

int divi_binaria(int k){
    if(k==0) return 0;

    printf("%5d   ", k);
    printf("%5d\n", k%2);
    divi_binaria(k/2);
}