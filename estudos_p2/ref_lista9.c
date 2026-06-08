#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20

/* Questão 2 */
typedef struct no{
    int simbolo;
    int freq;
    struct no *esq, *dir;
} No;

No* novo_no();
/* Questão 3 */
No* oplus(No* t1, No* t2);

/* Questão 5 */
// Adicionando funções do heap_min
    /* funcoes principais */
void altere(No* h[], int i, int n, int k);
void desca(No* h[], int i, int n);
int filho_esquerdo(int i);
void insira(No* h[], int *n, No* novo);
int pai(int i);
int extraia(No* h[], int *n);
int selecione(No* h[], int n);
void suba(No* h[], int i);
void troque(No *a, No *b);

/* Questão 6 */
void alg_huffman();


int main(){
    /* Questão 4 */
    int s[M] = {1, 2, 3, 4, 5};   //Vetor para armazenar os símbolos
    int f[M] = {3, 4, 9, 3, 2};   //Vetor para armazenar as frequências
    int n = 5;      //Quantidade de Simbolos


    return 0;
}

No* novo_no(){
    No* pt = (No*) malloc(sizeof(No));
    pt->simbolo = 0;
    pt->freq = 0;
    pt->esq = NULL;
    pt->dir = NULL;

    return pt;
}

No* oplus(No* t1, No* t2){
    No* tx = novo_no();
    tx->esq = t1;
    tx->dir = t2;
    tx->freq = (t1->freq) + (t2->freq);

    return tx;
}

// Altere a prioridade do elemento i de h[i] para k
void altere(No* h[], int i, int n, int k) {
  if (k > h[i]->freq){
    h[i]->freq = k;
    desca(h, i, n);
  } 
  else {
    h[i]->freq = k;
    suba (h, i);    
  }
}

// Desca por um caminho da arvore
void desca(No* h[], int i, int n) {
  int j;

  // recebe o indice do filho esquerdo
  j = filho_esquerdo(i);
  // se elemento j existe
  if (j <= n-1) {
    // se j nao eh o ultimo elemento, entao tem irmao direito
    if (j < n-1) {
      // j recebe o menor entre os dois irmaos
      if (h[j+1]->freq < h[j]->freq)
        j = j + 1;
    }
    
    // se elemento i for maior que seu filho j
    if (h[i]->freq > h[j]->freq) {
      // troque os valores i e j
      troque(&h[i], &h[j]);
      // chama recursivamente desca no elemento j
      desca(h, j, n);
    }
  }
}

// Calcule e retorna o indice do filho esquerdo de i
int filho_esquerdo(int i) {
  return (i*2)+1;;
}

// Insira um novo elemento de prioridade novo
void insira(No* h[], int *n, No* novo) {
  // se existe espaco no heap
  if (*n < M) {
    // adiciono novo elemento ao final do heap
    h[*n] = novo;
    *n += 1;
    // subo esse novo elemento
    suba(h, *n-1);
  } else
    puts("Heap overflow!");
}

int pai(int i) {
  return (i-1)/2;
}

// Remova o elemento de maior prioridade
int extraia(No* h[], int *n) {
  int aux;
  
  // se heap nao esta vazio
  if (*n > 0) {
    // copie o elemento que esta na primeira posicao
    aux = h[0];
    // copie o ultimo elemento na primeira posicao
    h[0] = h[*n-1];
    // subtraia meu quantitativo n
    *n -= 1;
    // desca o elemento da primeira posicao
    desca(h, 0, *n);
    // retorne a copia do elemento removido
    return aux;
  } else {
    puts("Heap underflow!");
    return -1;
  }
}

// Selecao do elemento de maior prioridade
int selecione(No* h[], int n) {
  // se heap nao esta vazio
  if (n != 0) 
    return h[0]; 
  else {
    puts("Heap underflow!");
    return -1;
  }
}

// Suba por um caminho da arvore
void suba(No* h[], int i) {
  int j;
  
  // se i tem pai
  if(i > 0) {
    // j recebe o indice do pai
    j = pai(i);
    
    // se i for menor que seu pai j
    if(h[i]->freq < h[j]->freq) {
      // troque i e j
      troque(&h[i], &h[j]);
      // suba j
      suba(h, j);
    }
  }
}

// Troque os elementos a e b
void troque(No *a, No *b) {
  No aux;
  
  aux = *a;
  *a = *b;
  *b = aux;
}

int minimo(int F[], int n){ // Pega o menor valor em um vetor de inteiros
    int menor = F[0];
    for(int i=0; i<n; i++){
        if(F[i] < menor){
            menor = F[i];
        }
    }   
    return menor;
}

void remover(int F[], int posi);

void alg_huffman(int F[], int n){

}
