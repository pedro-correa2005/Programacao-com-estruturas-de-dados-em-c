/*
 *	Ex 1) Escreva um programa que crie uma quantidade aleatória de valores inteiros e coloque
 *	estes valores em uma fila de pares e em outra de ímpares. Mostre as filas.
 */
#include<stdio.h>
#include<stdlib.h>

struct tpNo{
	int valor;
	struct tpNo *prox;
};
struct tpFila{
	struct tpNo *inic, *fim;
};

void insereFila(struct tpFila *pFila, int pValor);
int removeFila(struct tpFila *pFila);

int main(void){
	struct tpFila filaPares, filaImpares;
	int pos, qtd, num;
	
	filaPares.inic = NULL;
	filaPares.fim = NULL;
	filaImpares.inic = NULL;
	filaImpares.fim = NULL;
	
	qtd = rand() % 15;
	
	for(pos = 0; pos < qtd; pos++){
		num = rand() % 999;
		if((num % 2) == 0){
			insereFila(&filaPares, num);
		}else{
			insereFila(&filaImpares, num);
		}
	}
	printf("Mostra a fila de pares:\n\n");
	pos = 0;
	while(filaPares.inic != NULL && filaPares.fim != NULL){
		printf("Elemento %d = %d\n", pos + 1, removeFila(&filaPares));
		pos++;
	}
	
	printf("\nMostra a fila de impares:\n\n");
	pos = 0;
	while(filaImpares.inic != NULL && filaImpares.fim != NULL){
		printf("Elemento %d = %d\n", pos + 1, removeFila(&filaImpares));
		pos++;
	}
	return 0;
}
void insereFila(struct tpFila *pFila, int pValor){
	struct tpNo *aux;
	if(!(aux = malloc(sizeof(struct tpNo)))){
		printf("Faltou memoria");
		exit(1);
	}
	aux->valor = pValor;
	aux->prox = NULL;
	if(pFila->inic == NULL){
		pFila->inic = aux;
		pFila->fim = aux;
	}else{
		pFila->fim->prox = aux;
		pFila->fim = aux;
	}
}
int removeFila(struct tpFila *pFila){
	int num;
	struct tpNo *aux;
	if(pFila->inic == NULL){
		printf("Fila vazia");
		exit(2);
	}
	aux = pFila->inic;
	num = aux->valor;
	pFila->inic = aux->prox;
	if(pFila->inic == NULL){
		pFila->fim = NULL;
	}
	free(aux);
	return num;
}
