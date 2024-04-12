/*
 *	Exercício 1)	Escreva um programa para ordenar um vetor de 50 mil 
 *					inteiros. Use a função rand() para popularseu vetor. 
 *					Apresente seu custo computacional usando a notação Big O
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 50000

int main(void){
	clock_t t, ti, tf;
	int vet[TAM], aux, i, j;
	for(i = 0; i < TAM; i++){
		vet[i] = rand();
	}
	
	ti = clock();
	for(i = 0; i < TAM; i++){
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
	/*for(i = 0; i < TAM; i++){
		printf("%d\n", vet[i]);
	}*/
	printf("Tempo de ordenacao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
	return 0;
}

/*
TAMANHO	|	TEMPO
10		|	< 0 ms
100		|	< 0 ms
1 000	|	1 ms
5 000	|	60 ms
10 000	|	250 ms
25 000	|	1700 ms
50 000	|	6287 ms

Complexidade O(n²)
*/
