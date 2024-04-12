/*
 *	Ex 2) Modifique o programa anterior para empilhar a fila de pares e mostre essa pilha.
 */
#include<stdio.h>
#include<stdlib.h>

struct tpNo{
	int valor;
	struct tpNo *prox;
};
struct tpPilha{
	struct tpNo *topo;
};
struct tpFila{
	struct tpNo *inic, *fim;
};

void push(struct tpPilha *pPilha, int pValor);
int pop(struct tpPilha *pPilha);
void insereFila(struct tpFila *pFila1, int pValor);
int removeFila(struct tpFila *pFila);

int main(void){
	struct tpFila filaPares, filaImpares;
	struct tpPilha pilhaPares;
	int pos, qtd, num;
	
	pilhaPares.topo = NULL;
	
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
		num = removeFila(&filaPares);
		push(&pilhaPares, num);
		printf("Elemento %d = %d\n", pos + 1, num);
		pos++;
	}
	
	printf("\nMostra a fila de impares:\n\n");
	pos = 0;
	while(filaImpares.inic != NULL && filaImpares.fim != NULL){
		printf("Elemento %d = %d\n", pos + 1, removeFila(&filaImpares));
		pos++;
	}
	
	printf("\nMostra a pilha de pares:\n\n");
	pos = 0;
	while(pilhaPares.topo != NULL){
		printf("Elemento %d = %d\n", pos + 1, pop(&pilhaPares));
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
void push(struct tpPilha *pPilha, int pValor){
	struct tpNo *aux;
	if(!(aux = malloc(sizeof(struct tpNo)))){
		printf("Faltou memoria");
		exit(3);
	}
	aux->valor = pValor;
	aux->prox = pPilha->topo;
	pPilha->topo = aux;
}
int pop(struct tpPilha *pPilha){
	int valor;
	struct tpNo *aux;
	valor = pPilha->topo->valor;
	aux = pPilha->topo;
	pPilha->topo = aux->prox;
	free(aux);
	return valor;
}
