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


int main(){
    int x = 20;
    int a = 1000, b = 2;

    printf("Divisao Inteira: %d // %d = %d\n", a, b, a/b);
    printf("MOD Normal: %d mod %d = %d\n", a, b, a%b);
    printf("Hash Duplo de %d: Posi = %d\n", x, hash_duplo(x, 1));
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