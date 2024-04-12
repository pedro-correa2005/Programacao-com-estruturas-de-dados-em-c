/*
 *	Fila:
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct tipoNo{
	int valor;
	struct tipoNo *prox;
}tipoNo;

typedef struct tipoFila{
	struct tipoNo *inicio, *fim;
}tipoFila;

void insereFila(tipoFila *fila, int valor);
int removeFila(tipoFila *fila);

int main(void){
	tipoFila fila;
	int pos, qtd;
	
	fila.inicio = NULL;
	fila.fim = NULL;

	qtd = rand() % 15;
	
	for(pos = 0; pos < qtd; pos++){
		insereFila(&fila, rand() % 101);
	}
	printf("Mostra a fila com %d elementos:\n\n", qtd);
	
	for(pos = 0; pos < qtd; pos++){
		printf("Elemento %d = %d\n", pos + 1, removeFila(&fila));
	}
	
	return 0;
}
void insereFila(tipoFila *fila, int valor){
	tipoNo *novo, *p;
	if(!(novo = malloc(sizeof(tipoFila)))){
		printf("Erro faltou memoria");
		exit(1);
	}
	novo->valor = valor;
	novo->prox = fila->fim;
	fila->fim = novo;
	
	p = fila->fim;
	if(p){
		while(p != NULL && p->prox != NULL){	
			p = p->prox;
		}
		fila->inicio = p;
	}else{
		fila->inicio = novo;
	}
}
int removeFila(tipoFila *fila){
	tipoNo *p;
	int v;
	
	p = fila->fim;
	
	if(p->prox){
		while(p->prox->prox){
			p = p->prox;
		}
	}
	v = fila->inicio->valor;
	free(fila->inicio);
	p->prox = NULL;
	fila->inicio = p;
	
	return v;
}
