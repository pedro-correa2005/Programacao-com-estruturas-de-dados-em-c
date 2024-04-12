/*
 *	Ex. 2)	Escreva um programa que carregue um vetor de 50 mil inteiros e
 *			depois pega um número para o usuário. Veriifique se esse número
 *			existe no vetor usando uma função para busca sequencial e outra
 *			função para busca binária. Lembre-se de ordenar seu vetor antes de
 *			usar a busca binária.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 1000000

#define VAL 1275

int buscaSequencial(int value, int *v);
int buscaBinaria(int value, int *v);
int main(void){
	int vet[TAM], aux, j, i, res, valor = VAL;
	clock_t TiBs, TfBs, TBs, TiBb, TfBb, TBb;
	
	for(i = 0; i < TAM; i++){
		vet[i] = i;
	}
	
	
	/*for(i = 0; i < TAM; i++){
		for(j = i + 1; j < TAM; j++){
			if(vet[i] > vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}*/
	
	TiBs = clock();
	res = buscaSequencial(valor, vet);
	TfBs = clock();
	TBs = TfBs - TiBs;
	if(res >= 0){
		printf("Valor %d encontrado na posicao %d\n", valor, res);
	}else{
		printf("Valor %d nao encontrado no vetor\n", valor);
	}
	printf("Tempo da busca sequencial: %lf\n", ((double)TBs)/(CLOCKS_PER_SEC/1000));
	
	TiBb = clock();
	res = buscaBinaria(valor, vet);
	TfBb = clock();
	
	if(res >= 0){
		printf("Valor %d encontrado na posicao %d\n", valor, res);
	}else{
		printf("Valor %d nao encontrado no vetor\n", valor);
	}
	
	TBb = TfBb - TiBb;
	printf("Tempo da busca binaria: %lf\n", ((double)TBb)/(CLOCKS_PER_SEC/1000));
	
	return 0;
}
int buscaSequencial(int value, int *v){
	int i;
	for(i = 0; i < TAM; i++){
		if(value == v[i]){
			return i;
		}
	}
	return -1;
}
int buscaBinaria(int value, int *v){
	int fim = TAM - 1, inicio = 0, pos = fim / 2;
	
	while(inicio != fim){
		if(v[pos] > value){
			fim = pos - 1;
			pos = (inicio + fim) / 2;
		}else if(v[pos] < value){
			inicio = pos + 1;
			pos = (inicio + fim)/ 2;
		}else{
			return pos;
		}
	}
	return -1;
}
