/*
 *	Ex 2) Escreva  um programa em c para mostrar o tempo necessário para o
 *	algoritmo BUBBLE ordenar um vetor de 50 mil inteiros
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 50000

int main(void){
	int vet[TAM],troca = 1;
	register int i, aux;
	clock_t ti, tf, t;
	
	for(i = 0; i < TAM; i++){
		vet[i] = rand();
	}
	
	ti = clock();
	while(troca == 1){
		troca = 0;
		for(i = 0; i < TAM - 1; i++){
			if(vet[i] > vet[i + 1]){
				troca = 1;
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}
		}
	}
	tf = clock();
	t = tf - ti;
	
	/*for(i = 0; i < TAM; i++){
		printf("%d\n", vet[i]);
	}*/
	
	printf("Tempo: %f ms\n", (double)t/(CLOCKS_PER_SEC/1000));
	return 0;
}
