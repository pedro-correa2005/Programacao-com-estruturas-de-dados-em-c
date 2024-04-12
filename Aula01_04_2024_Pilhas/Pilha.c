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

int main(void){
	tipoNo *topo = NULL;
	int qtd, pos;
	
	qtd = rand() % 51;
	
	for(pos = 0; pos < qtd; pos++){
		push(&topo, rand() % 101);
	}
	
	mostrarPilha(topo);
	
	while(topo != NULL){
			printf("Topo = %d\n", pop(&topo));
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

