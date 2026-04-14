#include <stdio.h>
#include <stdlib.h>

#define M 20

int pai(int i);
void swap(int* a, int* b);
void subir(int heap[], int k);
void mostrar_heap(int heap[], int size);

int selecionar(int heap[]);
void inserir(int heap[], int* size, int n);

// {100, 19, 36, 17, 3, 25, 1, 2, 7}
int main(){
    int heap[M] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    int n;
    int size = 0;

    for(int i=0; i<M; i++){
        if(heap[i]!=NULL){
            size++;
        }else{
            break;
        }
    }

    printf("Heap OG:\n");
    mostrar_heap(heap, size);

    printf("=== INSERIR ===\n");
    printf("Qual inserir? ");
    scanf("%d", &n);
    inserir(heap, &size, n);

    printf("Novo Heap:\n");
    mostrar_heap(heap, size);

    return 0;
}

void mostrar_heap(int heap[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int selecionar(int heap[]){
    return heap[0];
}

int pai(int i){
    return (i-1)/2;
}

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}   

void subir(int heap[], int k){
    int p = pai(k);

    if(p>=0){
        if(heap[p] < heap[k]){
            swap(&heap[p], &heap[k]);
            subir(heap, p);
        }
    }
}

void descer(int heap[], int size, int k){
    int filho_e, filho_d;
    filho_e = 2*k+1;
    filho_d = 2*k+2;

    if(filho_e >= size) return;

    if(heap[filho_e]>heap[filho_d]){
        if(heap[filho_e]>heap[k]){
            swap(&heap[filho_e], &heap[k]);
            descer(heap, size, filho_e);
        }
    }
    else{
        if(heap[filho_d]>heap[k]){
            swap(&heap[filho_d], &heap[k]);
            descer(heap, size, filho_d);            
        }
    }
}

void inserir(int heap[], int* size, int n){
    heap[*size] = n;
    subir(heap, *size);

    printf("Size aumentou de %d para %d\n", *size, (*size)+1);
    (*size)++;
}

void remover(int heap[], int* size, int r){
    heap[0] = r;
    descer(heap, *size, 0);
    (*size)--;
}