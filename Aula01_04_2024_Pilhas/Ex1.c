/*
 *	Ex 1) Escreva um programa para carregar uma pilha com 10 valores aleatorios.
 *	mostre a pilha e depois crie outra pilha com os elementos da primeira mas
 * ordenados e mostre a nova pilha */
#include<stdio.h>
#include<stdlib.h>

typedef struct tipoNo{
	int valor;
	struct tipoNo *prox;
}tipoNo;

void push(tipoNo **topo, int valor);
int pop(tipoNo **topo);
int consultarTopo(tipoNo *topo);
void mostrarPilha(tipoNo *topo);
void bubbleSort(int vet[], int tam);

int main(void){
	tipoNo *topo1 = NULL, *topo2 = NULL;
	int vet[10], pos;
	
	for(pos = 0; pos < 10; pos++){
		push(&topo1, rand() % 101);
	}
	
	mostrarPilha(topo1);
	
	for(pos = 0; pos < 10; pos++){
		vet[pos] = pop(&topo1);
	}
	putchar(10);
	
	bubbleSort(vet, 10);
	
	for(pos = 0; pos < 10; pos++){
		push(&topo2, vet[pos]);
	}
	
	mostrarPilha(topo2);
	
	for(pos = 0; pos < 10; pos++){
			pop(&topo2);
	}
	
	return 0;
}
void push(tipoNo **topo, int valor){
	tipoNo *novo;
	if(!(novo = malloc(sizeof(tipoNo)))){
		printf("Faltou memoria");
		exit(1);
	}
	novo->prox = *topo;
	novo->valor = valor;
	*topo = novo;
}
int pop(tipoNo **topo){
	tipoNo *p;
	int v;
	if(*topo == NULL){
		printf("Pilha vazia");
		exit(2);
	}
	p = *topo;
	*topo = p->prox;
	v = p->valor;
	free(p);
	return v;
}
int consultarTopo(tipoNo *topo){
	printf("Topo: %d\n", topo->valor);
	return topo->valor;
}
void mostrarPilha(tipoNo *topo){
	while(topo){
		printf("%d\n", topo->valor);
		topo = topo->prox;
	}
}
void bubbleSort(int vet[], int tam){
	int pos, aux, troca = 1;
	while(troca == 1){
		troca = 0;
		for(pos = 0; pos < tam - 1; pos++){
			if(vet[pos] > vet[pos + 1]){
				troca = 1;
				aux = vet[pos];
				vet[pos] = vet[pos + 1];
				vet[pos + 1] = aux;
			}
		}
	}
}
