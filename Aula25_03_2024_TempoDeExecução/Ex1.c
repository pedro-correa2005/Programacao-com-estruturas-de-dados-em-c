/*
 * 	Ex 1) Escreva um programa para mostrar o tempo necessario para o algoritmo
 *	Selection Sort ordenar um vetor de 50 mil inteiros carregado com a função
 *	rand() da stdlib.h
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 50000

int main(void){
	int vet[TAM];
	register int i, j, aux;
	clock_t ti, tf, t;
	
	for(i = 0; i < TAM; i++){
		vet[i] = rand();
	}
	
	ti = clock();
	for(i = 0; i < TAM - 1; i++){
		for(j = i + 1; j < TAM; j++){
			if(vet[i] > vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	tf = clock();
	t = tf - ti;
/*	for(i = 0; i < TAM; i++){
		printf("%d\n",vet[i]);
	}
*/	printf("Tempo: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	return 0;
}
