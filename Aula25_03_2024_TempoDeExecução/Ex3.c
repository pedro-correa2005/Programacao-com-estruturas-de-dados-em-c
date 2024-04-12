/*
 *	Ex 3) Altere seus programas para mostrar os tempos de ordenação com os
 *	valores desordenados e também depois de ordenados.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 50000

int main(void){
	int vet1[TAM], vet2[TAM], troca = 1;
	register int i, j, aux;
	clock_t ti, tf, t;
	
	for(i = 0; i < TAM; i++){
		vet1[i] = rand();
	}
	
	//BUBBLE
	ti = clock();
	while(troca == 1){
		troca = 0;
		for(i = 0; i < TAM - 1; i++){
			if(vet1[i] > vet1[i + 1]){
				troca = 1;
				aux = vet1[i];
				vet1[i] = vet1[i + 1];
				vet1[i + 1] = aux;
			}
		}
	}
	tf = clock();
	t = tf - ti;
	
	printf("Tempo bubble desordenado: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	
	ti = clock();
	while(troca == 1){
		troca = 0;
		for(i = 0; i < TAM - 1; i++){
			if(vet1[i] > vet1[i + 1]){
				troca = 1;
				aux = vet1[i];
				vet1[i] = vet1[i + 1];
				vet1[i + 1] = aux;
			}
		}
	}
	tf = clock();
	t = tf - ti;
	
	printf("Tempo bubble ordenado: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));

	//SORT
	for(i = 0; i < TAM; i++){
		vet2[i] = rand();
	}
	
	ti = clock();
	for(i = 0; i < TAM - 1; i++){
		for(j = i + 1; j < TAM; j++){
			if(vet2[i] > vet2[j]){
				aux = vet2[i];
				vet2[i] = vet2[j];
				vet2[j] = aux;
			}
		}
	}
	tf = clock();
	t = tf - ti;

	printf("Tempo sort desordenado: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));	
	
	ti = clock();
	for(i = 0; i < TAM - 1; i++){
		for(j = i + 1; j < TAM; j++){
			if(vet2[i] > vet2[j]){
				aux = vet2[i];
				vet2[i] = vet2[j];
				vet2[j] = aux;
			}
		}
	}
	tf = clock();
	t = tf - ti;
	
	printf("Tempo sort ordenado: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));	
	return 0;
}
