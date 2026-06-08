/* Questão 1 */
#include <stdio.h>

#define M 20

/* definicao de tipos */

/* funcoes principais */
void altere(int h[], int i, int n, int k);
void desca(int h[], int i, int n);
int filho_esquerdo(int i);
void insira(int h[], int *n, int k);
int pai(int i);
int extraia(int h[], int *n);
int selecione(int h[], int n);
void suba(int h[], int i);
void troque(int *a, int *b);

/* funcoes auxiliares */
int ler_opcao();
void menu();

int main (int argc, char const *argv[])
{
  int opcao;
  int h[M];
  int n;
  
  // inicialize quantidade de elementos no heap como 0
  n = 0;

  while (1) {
    menu();
    opcao = ler_opcao();
    
    switch(opcao) {
      
      // opcao 1
      // selecao
      case 1: {
        int k;
        
        k = selecione(h, n);
        if (k != -1)
          printf("O elemento de maior prioridade eh %d!\n", k);
      }
      break;
      
      // opcao 2
      // insercao
      case 2: {
        int k;
        
        puts("Entre com o elemento a ser inserido: ");
        scanf("%d%*c", &k);
        insira(h, &n, k);
      }
      break;
      
      // opcao 3
      // remocao
      case 3: {
        int k;
        
        k = extraia(h, &n);
        if (k != -1)
          printf("O elemento de maior prioridade %d foi removido!\n", k);
      }
      break;
      
      // opcao 4
      // alteracao
      case 4: {
        int k, l, i;
        
        puts("Entre com a prioridade que deseja alterar: ");
        scanf("%d%*c", &l);
        
        puts("Entre com a nova prioridade: ");
        scanf("%d%*c", &k);
        
        // encontrando o indice do elemento de prioridade l
        for(i = 0; i < n; ++i) {
          if(h[i] == l)
            break;
        }
        
        altere(h, i, n, k);
      }
      break;
      
      // opcao 9
      case 9: {
        puts("Finalizando programa ..");
        return 0;
      }
      break;
    }
  }
  return 0;
}

// Altere a prioridade do elemento i de h[i] para k
void altere(int h[], int i, int n, int k) {
  if (k > h[i]){
    h[i] = k;
    desca(h, i, n);
  } 
  else {
    h[i] = k;
    suba (h, i);    
  }
}

// Desca por um caminho da arvore
void desca(int h[], int i, int n) {
  int j;

  // recebe o indice do filho esquerdo
  j = filho_esquerdo(i);
  // se elemento j existe
  if (j <= n-1) {
    // se j nao eh o ultimo elemento, entao tem irmao direito
    if (j < n-1) {
      // j recebe o menor entre os dois irmaos
      if (h[j+1] < h[j])
        j = j + 1;
    }
    
    // se elemento i for maior que seu filho j
    if (h[i] > h[j]) {
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
void insira(int h[], int *n, int novo) {
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
int extraia(int h[], int *n) {
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
int selecione(int h[], int n) {
  // se heap nao esta vazio
  if (n != 0) 
    return h[0]; 
  else {
    puts("Heap underflow!");
    return -1;
  }
}

// Suba por um caminho da arvore
void suba(int h[], int i) {
  int j;
  
  // se i tem pai
  if(i > 0) {
    // j recebe o indice do pai
    j = pai(i);
    
    // se i for menor que seu pai j
    if(h[i] < h[j]) {
      // troque i e j
      troque(&h[i], &h[j]);
      // suba j
      suba(h, j);
    }
  }
}

// Troque os elementos a e b
void troque(int *a, int *b) {
  int aux;
  
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