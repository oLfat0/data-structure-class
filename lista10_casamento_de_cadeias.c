#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int bruto(char x[], char y[]);
void vetor_d();
  
int main(){
    char X[] = {"abaeabaeaae"};
    char Y[] =   {"baeaae"};

    if(bruto(X, Y) != -1){
        printf("L = %d\n", bruto(X, Y));
    }else{
        printf("Y nao eh subcadeia de X\n");
    }

    return 0;
}

int bruto(char x[], char y[]){
    int size_x = strlen(x);
    int size_y = strlen(y);

    int l=0;

    for(int i=0; i<size_x; i++){
        int k = i;
        for(int j=0; j<size_y; j++){

            if(j==size_y-1 && y[j] == x[k]){
                return l;
            }

            else if(y[j] != x[k]){
                l++;
                break;
            }
            else{
                k++;
            }
        }
    }
    return -1;
}

void vetor_d(char x[]){
    const int size_x = strlen(x);
    // int d[size_x];

    for(int i=0; i<size_x; i++){

    }
}