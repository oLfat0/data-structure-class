#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Questão 1 */
int forca_bruta(char* x, char* y, int n, int m);
/* Questão 2 */
int* vetor_d(char* y, int m);
/* Questão 4 */
int alg_kmp(char* x, char* y, int* d, int n, int m);

int main(){
    char x[] = "bababaeabaeabaeaabaeabaeaaeba";
    char y[] = "abaeabaeaae";

    int n = strlen(x);
    int m = strlen(y);

    printf("Tamanho de X: %d\n", n);
    printf("Tamanho de Y: %d\n\n", m);
    printf("Casamento por Forca Bruta:\n");
    forca_bruta(x, y, n, m);

    printf("\nVetor D de Y:\n");
    int* d = vetor_d(y, m);
    
    for(int i=0; i<m; i++){
        printf("%d ", d[i]);
    }

    printf("\n\nCasamento por KMP:\n");
    alg_kmp(x, y, d, n, m);

    return 0;
}

int forca_bruta(char* x, char* y, int n, int m){
    for(int l=0; l<n; l++){
        int i = 0;
        int flag = 1;       //True

        while(i<m && flag==1){
            if(x[l+i] == y[i]){
                i++;
            }else{
                flag = 0;   
            }
        }
        if(flag == 1){
            printf("Casamento encontrado! Y eh subcadeia de X!\n");
            printf("Posicao de X: %d\n", l);
            return l;
        }else{
            continue;
        }
    }
    printf("Y NAO eh subadeia de X");
    return -1;
}

int* vetor_d(char* y, int m){
    int* d = (int*) malloc(m*sizeof(int));
    d[0] = 0;

    int i = 1;
    int j = 0;

    while(i < m){
        if(y[j] == y[i]){
            j++;
            d[i] = j;
            i++;
        }else{
            if(j != 0){
                j = d[j-1];
            }else{
                d[i] = 0;
                i++;
            }
        }
    }
    return d;
}

int alg_kmp(char* x, char* y, int* d, int n, int m){
    int i = 0;
    int j = 0;

    while(i-j <= n-m){
        int flag = 1;
        while(j < m && flag){   
            if(y[j] == x[i]){
                i++;
                j++;
            }else{
                if(j == 0){
                    i++;
                }else{
                    j = d[j-1];
                }
                flag = 0;
            }
        }
        if(flag == 1){
            printf("Houve casamento na posicao %d de X!\n", i-m);
            return i-m;
        }
    }
    printf("Nao ha casamento\n");
    return -1;
}
