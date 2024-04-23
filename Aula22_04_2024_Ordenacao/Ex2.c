#include<stdio.h>
#define TAM 200000

void swap( int vet[], int i, int j ){
   int aux = vet[i];
   vet[i] = vet[j];
   vet[j] = aux;
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

int main(void){
	int vet[TAM];
	FILE *f1, *f2, *f1_b, *f2_b, *arqSaida;
	f1 = fopen("f1.txt", "r");
	int n1, n2;
	//Leitura do arquivo 1
	
	int pos = 0;
	
	while (fscanf(f1, "%d", &vet[pos]) == 1) {
       pos++;
       if (pos >= TAM) {
           printf("Limite máximo de tamanho do vetor atingido.\n");
           break;
       }
    }
	fclose(f1);
	
	//Ordenação do vetor
	
	mostrar_vet(vet, 20);
	quick_sort(vet, 0, TAM);
	mostrar_vet(vet, 20);
	
	f1_b = fopen("f1_b.txt", "w");
	
	for(pos = 0; pos < TAM; pos++){
		fprintf(f1_b, "%d\n", vet[pos]);
	}
	
	fclose(f1_b);
	
	//Leitura do arquivo 2
	
	f2 = fopen("f2.txt", "r");
	
	pos = 0;
	
	while (fscanf(f2, "%d", &vet[pos]) == 1) {
       pos++;
       if (pos >= TAM) {
           printf("Limite máximo de tamanho do vetor atingido.\n");
           break;
       }
    }
	fclose(f2);
	
	//Ordenação do vetor
	
	mostrar_vet(vet, 20);
	quick_sort(vet, 0, TAM);
	mostrar_vet(vet, 20);
	
	f2_b = fopen("f2_b.txt", "w");
	
	for(pos = 0; pos < TAM; pos++){
		fprintf(f2_b, "%d\n", vet[pos]);
	}
	
	fclose(f2_b);
	
	f1_b = fopen("f1_b.txt", "r");
	f2_b = fopen("f2_b.txt", "r");
	arqSaida = fopen("arqSaida.txt", "w");
	
	fscanf(f1_b, "%d", &n1);
	fscanf(f2_b, "%d", &n2);
	
	while(!feof(f1_b) && !feof(f2_b)){
		if(n1 < n2){
			fprintf(arqSaida, "%d\n", n1);
			fscanf(f1_b, "%d", &n1);
		}else{
			fprintf(arqSaida, "%d\n", n2);
			fscanf(f2_b, "%d", &n2);
		}
	}
	
	while(!feof(f1_b)){
		fprintf(arqSaida, "%d\n", n1);
		fscanf(f1_b, "%d", &n1);
	}
	
	while(!feof(f2_b)){
		fprintf(arqSaida, "%d\n", n2);
		fscanf(f2_b, "%d", &n2);
	}
	
	fclose(f1_b);
	fclose(f2_b);
	fclose(arqSaida);
	return 0;
}
