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
	struct tpFila fila;
	int pos, qtd;
	fila.inic = NULL;
	fila.fim = NULL;
	qtd = rand() % 100;
	for(pos = 0; pos < qtd; pos++){
		insereFila(&fila, rand() % 999);
	}
	printf("Mostra a afila com %d elementos:\n\n", qtd);
	for(pos = 0; pos < qtd; pos++){
		printf("Elemento %d = %d\n", pos + 1, removeFila(&fila));
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
