#include <stdio.h>

#define M 20

/* definicao de tipos */

/* funções de huffman*/
typedef struct no{
    int simbolo;
    int frequencia;
    struct no *esq, *dir;
}No;

No* novo_no();
No* oplus(No* t1, No* t2);

No* algoritmo_huffman(No* h[], int freq, int n);

/* funcoes principais */
void altere(No* h[], int i, int n, int k);
void desca(No* h[], int i, int n);
int filho_esquerdo(int i);
void insira(No* h[], int *n, int k);
int pai(int i);
No* extraia(No* h[], int *n);
No* selecione(No* h[], int n);
void suba(No* h[], int i);
void troque(No* *a, No* *b);

/* funcoes auxiliares */
int ler_opcao();
void menu();

int main(){
    int s[M] = {1, 2, 3, 4, 5};   //vetor p/ armazenar símbolos
    int f[M] = {3, 4, 9, 3, 2};   //vetor p/ armazenar frequências
    int n = 5;                    //quantidade de símbolos
    No* heap[5];

    for(int i=0; i<n; i++){
        No* new = novo_no();
        new->simbolo = s[i];
        new->frequencia = f[i];

        heap[i] = new;
    }

    return 0;
}

No* algoritmo_huffman(No* h[], int freq, int n){
    No* t1;
    No* t2;
    No* tx;
    int size = n;

    for(int i=1; i<size-1; i++){
        
      t1 = extraia(h, &n);
      t2 = extraia(h, &n);
      tx = novo_no();
      tx->frequencia = (t1->frequencia)+(t2->frequencia);
      insira(tx, &n, tx->frequencia);
    }
    return extraia(h, &n);
}


No* oplus(No* t1, No* t2){
    No* tx = novo_no();

    tx->esq = t1;
    tx->dir = t2;
    tx->frequencia = (t1->frequencia)+(t2->frequencia);

    return tx;
}

No* novo_no(){
    No* p = (No*) malloc(sizeof(No));

    p->simbolo = 0;
    p->frequencia = 0;
    p->esq = NULL;
    p->dir = NULL;

    return p;
}

// Altere a prioridade do elemento i de h[i] para k (ALTERADO PARA NÓS)
void altere(No* h[], int i, int n, int k) {
  if (k > h[i]->frequencia){
    h[i]->frequencia = k;
    desca(h, i, n);
  } 
  else {
    h[i]->frequencia = k;
    suba (h, i);    
  }
}

// Desca por um caminho da arvore (ALTERADO PARA NÓS)
void desca(No* h[], int i, int n) {
  int j;

  // recebe o indice do filho esquerdo
  j = filho_esquerdo(i);
  // se elemento j existe
  if (j <= n-1) {
    // se j nao eh o ultimo elemento, entao tem irmao direito
    if (j < n-1) {
      // j recebe o menor entre os dois irmaos
      if (h[j+1]->frequencia < h[j]->frequencia)
        j = j + 1;
    }
    
    // se elemento i for maior que seu filho j
    if (h[i]->frequencia > h[j]->frequencia) {
      // troque os valores i e j
      troque(&h[i], &h[j]);
      // chama recursivamente desca no elemento j
      desca(h, j, n);
    }
  }
}

// Calcule e retorna o indice do filho esquerdo de i
int filho_esquerdo(int i) {
  return (i*2)+1;
}

// Insira um novo elemento de prioridade novo
void insira(No* h[], int *n, int novo) {
  // se existe espaco no heap
  if (*n < M) {
    // adiciono novo elemento ao final do heap

    h[*n] = novo_no();
    h[*n]->frequencia = novo;

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
No* extraia(No* h[], int *n) {
  No* aux;
  
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
    return NULL;
  }
}

// Selecao do elemento de maior prioridade
No* selecione(No* h[], int n) {
  // se heap nao esta vazio
  if (n != 0) 
    return h[0]; 
  else {
    puts("Heap underflow!");
    return NULL;
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
    if(h[i]->frequencia < h[j]->frequencia) {
      // troque i e j
      troque(&h[i], &h[j]);
      // suba j
      suba(h, j);
    }
  }
}

// Troque os elementos a e b (Adaptado para Nós)
void troque(No* *a, No* *b) {
  No* aux;
  
  aux = *a;
  *a = *b;
  *b = aux;
}

//////////////////////////////////////////////////////////////////////////
// ENTRE OPCAO
//
// faz a leitura da opcao do usuario
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int ler_opcao() {
  int opcao;
  
  puts("Entre com a sua opcao: ");
  scanf("%d%*c", &opcao);

return opcao;
}

//////////////////////////////////////////////////////////////////////////
// MENU
//
// funcao responsavel por imprimir o menu principal
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void menu() {
  printf("\n// ----- // ----- // HEAP // ----- // ----- //\n"
    "1 - Selecao\n"
    "2 - Insercao\n"
    "3 - Remocao\n"
    "4 - Alteracao\n"
    "9 - Finalizar\n"
    "~~~~~~~~~~~~~~~\n");
}