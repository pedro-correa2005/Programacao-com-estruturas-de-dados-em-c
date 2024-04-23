//funcoes_de_ordenacao.c
//Autor: Oclair Prado

void mostrar_vet( int vet[], int tamanho ){
   int pos;
   for( pos = 0; pos < tamanho; pos++ ){
      printf("%d, ", vet[pos] );
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
//   flag_troca = true
//   enquanto( ocorrer troca (flag_troca == true) )
//      flag_troca = false
//      para(n variando de inic a fim-1 do vetor)
//	       se v[n] > v[n+1] entao
//		      flag_troca = true
//		      troca v[n] com v[n+1]
//		   fim_se
//      fim_para		 
//   fim_enquanto
   int i, flag_troca = True;
   //while(ocorre_troca(vet, tamanho) == 1){
   while( flag_troca == True ){
      flag_troca = False;
      for(i = 0; i < tamanho-1; i++){
         if(vet[i] > vet[i+1]){
         	flag_troca = True;
            int aux = vet[i+1];
            vet[i+1] = vet[i];
            vet[i] = aux;
         }
      }
   }
}

void selection_sort(int vet[], int tamanho){
//      para( ext_N variando de inic a fim-1 do vetor )
//         para( int_N variando de ext_N+1 a fim do vetor)
//	          se v[ext_N] > v[int_N] entao
//		         troca v[ext_N] com v[int_N]
//		      fim_se
//         fim_para
//      fim_para	

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

