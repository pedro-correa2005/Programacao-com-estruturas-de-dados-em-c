#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 80000

void preenche_vetor(int vet[], int tamanho);
void mostrar_vet( int vet[], int tamanho );
void quick_sort( int vet[], int start, int end );
int partition( int vet[], int start, int end );
void swap( int vet[], int i, int j );
void merge(int vet[], int comeco, int meio, int fim);
void merge_sort(int vet[], int comeco, int fim);
void insertion_sort( int vet[], int tamanho );
void bubble_sort(int vet[], int tamanho);
void selection_sort(int vet[], int tamanho);

int main(void){
	int vet[TAM], i;
	clock_t ti, tf, t;
	
	preenche_vetor(vet, TAM);
	ti = clock();
	quick_sort(vet, 0, TAM - 1 );
	tf = clock();
	t = tf - ti;
	printf("Tempo do quick sort: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	
	preenche_vetor(vet, TAM);
	ti = clock();
	merge_sort(vet, 0, TAM - 1);
	tf = clock();
	t = tf - ti;
	printf("Tempo do merge sort: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	
	preenche_vetor(vet, TAM);
	ti = clock();
	insertion_sort(vet, TAM);
	tf = clock();
	t = tf - ti;
	printf("Tempo do insertion sort: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	
	preenche_vetor(vet, TAM);
	ti = clock();
	bubble_sort(vet, TAM);
	tf = clock();
	t = tf - ti;
	printf("Tempo do bubble sort: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	
	preenche_vetor(vet, TAM);
	ti = clock();
	selection_sort(vet, TAM);
	tf = clock();
	t = tf - ti;
	printf("Tempo do selection sort: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	
	//mostrar_vet(vet, TAM);
	return 0;
}

void preenche_vetor(int vet[], int tamanho){
	int i;
	for(i = 0; i < tamanho - 1; i++){
		vet[i] = rand();
	}
}
void mostrar_vet( int vet[], int tamanho ){
   int pos;
   for( pos = 0; pos < tamanho; pos++ ){
      printf("%d\n", vet[pos] );
   }
   printf("\n");
}
void quick_sort( int vet[], int start, int end ){
   int pivot;

   if( start >= end ){
      return;
   }

   pivot = partition( vet, start, end );

   quick_sort( vet, start, pivot-1 );
   quick_sort( vet, pivot+1, end );
}
int partition( int vet[], int start, int end ){
   int aux, i = start, j;

   for (j = start; j < end; j++) {
      /* Elemento atual menor ou igual ao pivô? */
      if (vet[j] <= vet[end]) {
         swap(vet, i++, j);
      }
   }
   swap(vet, i, end);
   return i;
}
void swap( int vet[], int i, int j ){
   int aux = vet[i];
   vet[i] = vet[j];
   vet[j] = aux;
}
void merge(int vet[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vet[com1] < vet[com2]) {
            vetAux[comAux] = vet[com1];
            com1++;
        } else {
            vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vet[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vet[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vet[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}
void merge_sort(int vet[], int comeco, int fim){
   int meio;
   if (comeco < fim) {
      meio = (fim + comeco) / 2;
      merge_sort(vet, comeco, meio);
      merge_sort(vet, meio+1, fim);
      merge(vet, comeco, meio, fim);
   }
}
void insertion_sort( int vet[], int tamanho ){
// insertion_sort (vet[], tamanho)
//    VARIÁVEIS: ext_N, int_N, aux
//    para ext_N de 1 até (tamanho-1) faça
//       aux recebe vet[ext_N];
//       int_N recebe ext_N-1;
//       enquanto ( int_N >= 0 e aux < vet[j] ) faça
//          vet[int_N+1]:= vet[int_N];
//          int_N recebe int_N-1;
//       fim_enquanto
//       vet[int_N+1] recebe aux;
//    fim_para
//fim

   int ext_N, int_N, aux;
   for (ext_N = 1; ext_N <= tamanho-1; ext_N++){
      aux = vet[ext_N];
      int_N = ext_N-1;
      while( int_N >= 0 && aux < vet[int_N] ) {
         vet[int_N+1] = vet[int_N];
         int_N--;
      }
      vet[int_N+1] = aux;
   }
}
void bubble_sort(int vet[], int tamanho){
   int i, flag_troca = 1;
   while( flag_troca == 1 ){
      flag_troca = 0;
      for(i = 0; i < tamanho-1; i++){
         if(vet[i] > vet[i+1]){
         	flag_troca = 1;
            int aux = vet[i+1];
            vet[i+1] = vet[i];
            vet[i] = aux;
         }
      }
   }
}
void selection_sort(int vet[], int tamanho){
   int ext_N, int_N, aux;

   for( ext_N = 0; ext_N < tamanho-2; ext_N++){
      for( int_N = ext_N+1; int_N < tamanho-1; int_N++){
         if( vet[ext_N] > vet[int_N]){
            aux = vet[ext_N];
            vet[ext_N] = vet[int_N];
            vet[int_N] = aux;
		 }
	  }
   }
}

