#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct tpNo{
	int valor;
	struct tpNo *dir, *esq;	
}No;

typedef struct{
	struct tpNo *raiz;
}Arvore;

void passeio_pre_ordem(No *raiz);
void passeio_em_ordem(No *raiz);
void passeio_pos_ordem(No *raiz);
void limpar_arvore(No *raiz);
int contagem(No *raiz);

int main(void){
	Arvore ar;
	ar.raiz = NULL;
	No *novo, *aux;
	
	if(!(novo = malloc(sizeof(No)))){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	
	novo->esq = NULL;
	novo->dir = NULL;
	novo->valor = 5;
	ar.raiz = novo;
	
	if(!(novo = malloc(sizeof(No)))){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	
	novo->esq = NULL;
	novo->dir = NULL;
	novo->valor = 3;
	ar.raiz->esq = novo;
	
	if(!(novo = malloc(sizeof(No)))){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	
	novo->esq = NULL;
	novo->dir = NULL;
	novo->valor = 7;
	ar.raiz->dir = novo;
	
	if(!(aux = malloc(sizeof(No)))){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	
	aux->esq = NULL;
	aux->dir = NULL;
	aux->valor = 6;
	novo->esq = aux;
	
	if(!(aux = malloc(sizeof(No)))){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	
	aux->esq = NULL;
	aux->dir = NULL;
	aux->valor = 8;
	novo->dir = aux;
	
	printf("Passeio em pre ordem:\n");
	passeio_pre_ordem(ar.raiz);
	printf("Passeio em ordem: \n");
	passeio_em_ordem(ar.raiz);
	printf("Passeio em pos ordem: \n");
	passeio_pos_ordem(ar.raiz);
	
	printf("Quantidade de nos: %d\n", contagem(ar.raiz));
	
	limpar_arvore(ar.raiz);
	return 0;
}

void passeio_pre_ordem(No *raiz){
	if(raiz == NULL){
		return;
	}
	printf("Valor: %d\n", raiz->valor);
	passeio_pre_ordem(raiz->esq);
	passeio_pre_ordem(raiz->dir);
}

void passeio_em_ordem(No *raiz){
	if(raiz == NULL){
		return;
	}
	passeio_em_ordem(raiz->esq);
	printf("Valor: %d\n", raiz->valor);
	passeio_em_ordem(raiz->dir);
}

void passeio_pos_ordem(No *raiz){
	if(raiz == NULL){
		return;
	}
	passeio_pos_ordem(raiz->esq);
	passeio_pos_ordem(raiz->dir);
	printf("Valor: %d\n", raiz->valor);
}

void limpar_arvore(No *raiz){
	if(raiz == NULL){
		return;
	}
	limpar_arvore(raiz->esq);
	limpar_arvore(raiz->dir);
	free(raiz); 
}

int contagem(No *raiz){
	int qtd = 0;
	if(raiz == NULL){
		return 0;
	}
	qtd += contagem(raiz->esq);
	qtd++;
	qtd += contagem(raiz->dir);
	return qtd;
}
