/* Heap */
#include <stdio.h>
#define M 20

int pai(int i);
void swap(int* a, int* b);
void subir(int h[], int posi);
void descer(int h[], int posi, int size);
void mostrar_heap(int h[], int size);

int selecionar(int h[]);
void inserir(int h[], int* size, int add);
void remover(int h[], int* size);
void alterar(int h[], int posi, int new, int size);

int main(){
    int heap[M] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    int size=0;
    int zeros=0;

    for(int i=0; i<M; i++){
        if(heap[i] != 0){
            size++;  
        }else{
            zeros++;
            if(zeros>=2){
                break;
            } 
        }
    }

    printf("Heap Original: \n");
    mostrar_heap(heap, size);
    printf("=========================");

    printf("\n=== Insere ===\n");
    inserir(heap, &size, 111);

    printf("\n=== Selecionar Maior Prioridade ===\n");
    printf("%d\n", selecionar(heap));

    printf("=== Alterado 1 ===\n");
    for(int i=0; i<size; i++){
        if(heap[i]==100){
            alterar(heap, i, 27, size);
        }
    }
    mostrar_heap(heap, size);

    printf("=== Alterado 2 ===\n");
    for(int i=0; i<size; i++){
        if(heap[i]==25){
            alterar(heap, i, 85, size);
        }
    }
    mostrar_heap(heap, size);
    
    return 0;
}

void mostrar_heap(int h[], int size){
    for(int i=0; i<size; i++){
        if(h[i] != 0){
            printf("%d ", h[i]);   
        } 
    }
    printf("\n");
}

int pai(int i){
    return (i-1)/2;
}

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void subir(int h[], int posi){
    int j;

    if(posi>0){             //Caso o elemento NÃO seja a raíz da árvore:
        j = pai(posi);

        if(h[posi] > h[j]){            
            swap(&h[posi], &h[j]);
            subir(h, j);
        }
    }
}

void descer(int h[], int posi, int size){
    int filho_e = 2*posi+1, filho_d = 2*posi+2;

    if(filho_e >= size) return;

    if(h[posi] < h[filho_e] || h[posi] < h[filho_d]){
        if(h[filho_e] > h[filho_d]){
            swap(&h[filho_e], &h[posi]);
            descer(h, filho_e, size);
        }else{
            swap(&h[filho_d], &h[posi]);
            descer(h, filho_d, size);
        }
    }
    return;
}

void alterar(int h[], int posi, int new, int size){
    printf("%d [%d] -> %d\n", h[posi], posi, new);
    int old = h[posi];
    h[posi] = new;

    if(posi==0){
        descer(h, posi, size);
    }else{
        if(new > old){
            subir(h, posi);
        }else{
            descer(h, posi, size);
        }
    }   
}

int selecionar(int h[]){
    return h[0];
}

void inserir(int h[], int* size, int add){
    /*
        Params: 
            h[] -> Heap Array;
            *size -> Posição  onde será inserido o novo elemento(última posição do array);
            add -> Prioridade do novo elemento
    */
    h[*size] = add;     //Novo elemento é adicionado na última posição do array        
    subir(h, *size);    //Organiza o novo elemento dentro da árvore binária
    (*size)++;          //Aumenta a contagem de elementos dentro do array
    printf("%d ", add);
}

void remover(int h[], int* size){
    h[0] = h[(*size)-1];    //Raíz agora recebe o último elemento
    h[(*size)-1] = 0;       //Último elemento é 'excluído' (Apenas visual, pois, com '(*size)--', o último elemento do Heap já é excluído)

    descer(h, 0, *size);
    (*size)--;
}