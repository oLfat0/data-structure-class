#include <stdio.h>
#include <math.h>

#define M 20
//4 70 38 20 8 35 19 30 28 18 25 36 37 26 22

int pai(int i);
int nivel(int i);
void swap(int* a, int* b);
void mostrar_heap(int h[], int size);

int sel_menor(int heap[]);
int sel_maior(int heap[]);
void inserir(int heap[], int* last, int add);
void remover_min(int heap[], int* size);
void remover_max(int heap[], int* size);


void descer(int heap[], int size, int i);
void descer_min(int heap[], int size, int i);
void descer_max(int heap[], int size, int i);

void subir(int heap[], int n);
void subir_min(int heap[], int i);
void subir_max(int heap[], int i);

int main(){
    int heap[M+1] = {0, 4, 70, 38, 20, 8, 35, 19, 30, 28, 18, 25, 36, 37, 26, 22};
    int size=0;
    int zeros=0;

    for(int i=1; i<M+1; i++){
        if(heap[i] != 0){
            size++;  
        }else{
            zeros++;
            if(zeros>=2){
                break;
            } 
        }
    }

    printf("Tamanho: %d\n", size);
   
    printf("Menor Elemento:\n");
    printf("%d\n", sel_menor(heap));

    printf("Maior Elemento:\n");
    printf("%d\n", heap[sel_maior(heap)]);

    printf("Removendo MENOR Elemento: %d\n", sel_menor(heap));
    remover_min(heap, &size);

    printf("Removendo MAIOR Elemento: %d\n", heap[sel_maior(heap)]);
    remover_max(heap, &size);

    printf("INSERINDO: 5\n");
    inserir(heap, &size, 5);

    printf("\nTAMANHO: %d\n\n", size);
    for(int i=1; i<size+1; i++){
        printf("%d ", heap[i]);
    }
    return 0;
}

int pai(int i){
    return i/2;
}

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int nivel(int i){
    return floor(log2(i))+1;
}

void mostrar_heap(int h[], int size){
    for(int i=0; i<size; i++){
        if(h[i] != 0){
            printf("%d ", h[i]);   
        } 
    }
    printf("\n");
}

int sel_menor(int heap[]){
    /* Retorna o PRÓPRIO MENOR ELEMENTO*/
    return heap[1];
}

int sel_maior(int heap[]){
    /* Retorna a POSIÇÃO do Maior elemento*/
    if(heap[2] > heap[3]){          //Estará sempre no primeiro nível máximo
        return 2;
    }else{
        return 3;
    }
}

void remover_max(int heap[], int* size){
    int maior = sel_maior(heap);
    heap[maior] = heap[(*size)];
    heap[(*size)] = 0;

    descer(heap, (*size), maior);
    (*size)--;
}

void remover_min(int heap[], int* size){
    heap[1] = heap[(*size)];    //Raíz agora recebe o último elemento
    heap[(*size)] = 0;       //Último elemento é 'excluído' (Essa linha é apenas visual, pois, com '(*size)--', o último elemento do Heap já é excluído)

    descer(heap, (*size), 1);
    (*size)--;
}

void descer(int heap[], int size, int i){
    if(nivel(i)%2!=0){
        printf("void descer(): DESCER_MIN\n");
        descer_min(heap, size, i);
    }else{
        printf("void descer(): DESCER_MAX:\n");
        descer_max(heap, size, i);
    }
}

int menor_desc(int heap[], int size, int i){
    int filho_e = 2*i, filho_d = 2*i+1;
    int neto1=4*i, neto2=4*i+1, neto3=4*i+2, neto4=4*i+3;

    int desc_posi[6] = {filho_e, filho_d, neto1, neto2, neto3, neto4};
    
    int menor = -1;
    for(int j=0; j<6; j++){
        int idx = desc_posi[j];

        if(idx <= size){
            if(menor == -1 || heap[idx]<heap[menor]){
                printf("%d < %d\n", heap[idx], heap[menor]);
                menor = idx;
            }
        }
    }
    printf("MENOR Desc. de %d: %d\n", heap[i], heap[menor]);
    return menor;
}

int maior_desc(int heap[], int size, int i){
    int filho_e = 2*i, filho_d = 2*i+1;
    int neto1=4*i, neto2=4*i+1, neto3=4*i+2, neto4=4*i+3;

    int desc_posi[6] = {filho_e, filho_d, neto1, neto2, neto3, neto4};
    
    int maior = -1;
    for(int j=0; j<6; j++){
        int idx = desc_posi[j];

        if(idx <= size){
            if(maior == -1 || heap[idx]>heap[maior]){
                printf("%d > %d\n", heap[idx], heap[maior]);
                maior = idx;
            }
        }
    }
    printf("MAIOR Desc. de %d: %d\n", heap[i], heap[maior]);
    return maior;
}

void descer_min(int heap[], int size, int i){
    int m = menor_desc(heap, size, i);
    if(m == -1) return;

    int p = pai(m);

    if(p!=0){                                   //Si TEM DESCENDENTES
        if(p==i){                               //Sm é FILHO de Si
            if(heap[m]<heap[i]){
                swap(&heap[m], &heap[i]);
            }

        }else{                                  //Sm é NETO de Si
            if(heap[m]<heap[i]){  
                swap(&heap[m], &heap[i]);       //Essa troca já deixa a Raíz com o MENOR valor possível

                if(heap[m]>heap[p]){            //Checa se o Sm é MAIOR que seu Pai (Não deveria ser)
                    swap(&heap[m], &heap[p]);
                    descer_min(heap, size, p);
                }else{
                    int f = menor_desc(heap, size, m);
                    if(heap[m]>heap[f]){        //Checa se o Sm é MAIOR que seu menor Filho Sf (Não deveria ser)
                        swap(&heap[m], &heap[f]);
                        descer_min(heap, size, f);
                    }
                } 
            }
        }
    }
    
    return;
}

void descer_max(int heap[], int size, int i){
    int m = maior_desc(heap, size, i);
    if(m == -1) return;

    int p = pai(m);

    if(p!=0){                                   //Si TEM DESCENDENTES
        if(p==i){                               //Sm é FILHO de Si
            if(heap[m]<heap[i]){
                swap(&heap[m], &heap[i]);
            }

        }else{                                  //Sm é NETO de Si
            if(heap[m]>heap[i]){  
                swap(&heap[m], &heap[i]);       //Essa troca já deixa o Filho direto da Raíz com o MAIOR valor possível

                if(heap[m]<heap[p]){            //Checa se o Sm é MENOR que seu Pai (Não deveria ser)
                    swap(&heap[m], &heap[p]);
                    descer_min(heap, size, p);
                }else{
                    int f = maior_desc(heap, size, m);
                    if(heap[m]<heap[f]){        //Checa se o Sm é MENOR que seu menor Filho Sf (Não deveria ser)
                        swap(&heap[m], &heap[f]);
                        descer_min(heap, size, f);
                    }
                } 
            }
        }
    }
    
    return;
}

void subir(int heap[], int i){
    int lvl = nivel(i);
    int p = pai(i);

    if(lvl%2!=0){                                   //Está em Nível MÍNIMO
        printf("void subir(): NIVEL_MINIMO\n");
        if(p>=1 && heap[p]<heap[i]){                //Se o Pai(MÁXIMO) for menor que o Filho(MÍNIMO), eles trocam
            swap(&heap[p], &heap[i]);
            printf("void subir(): SUBIR_MAX\n");
            subir_max(heap, p);
        }else{
            subir_min(heap, p);
        }      
        
    }else{                                          //Está em Nível MÁXIMO
        printf("void subir(): NIVEL_MAXIMO\n");
        if(p>=1 && heap[p]>heap[i]){                //Se o Pai(MÍNIMO) for maior que o Filho(MÁXIMO), eles trocam
            swap(&heap[p], &heap[i]);
            printf("void subir(): SUBIR_MIN\n");
            subir_min(heap, p);
        }else{
            subir_max(heap, p);
        }
    }
}

void subir_min(int heap[], int i){
    if(i==1) return;
    int avo = i/4;
    
    if(avo!=0){             //Se Si TEM AVÔ
        if(heap[i]<heap[avo]){
            swap(&heap[i], &heap[avo]);
            subir_min(heap, avo);
        }
    }
}

void subir_max(int heap[], int i){
    if(i==2 || i==3) return;
    int avo = i/4;

    if(heap[i]>heap[avo]){
        swap(&heap[i], &heap[avo]);
        subir_max(heap, avo);
    }
}

void inserir(int heap[], int* last, int add){
    int i = (*last)+1;

    heap[i] = add;

    subir(heap, i);
    (*last)++;
}
