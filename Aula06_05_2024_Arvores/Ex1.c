#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

/*
 *	Ex 1) Escreva uma função para somar os conteúdos dos nós de uma árvore
 */

typedef struct tpNo{
	int valor;
	struct tpNo *dir, *esq;	
}No;

typedef struct{
	No *raiz;
}Arvore;

void passeio_pre_ordem(No *raiz);
void passeio_em_ordem(No *raiz);
void passeio_pos_ordem(No *raiz);
void limpar_arvore(No *raiz);
void inserir(Arvore *ar, int valor);
int contagem(No *raiz);
int somarValores(No *raiz);

int main(void){
	Arvore ar;
	ar.raiz = NULL;
	
	inserir(&ar, 5);
	inserir(&ar, 3);
	inserir(&ar, 7);
	inserir(&ar, 6);
	inserir(&ar, 8);
	
	printf("Pre-ordem:\n");
	passeio_pre_ordem(ar.raiz);
	printf("Em ordem:\n");
	passeio_em_ordem(ar.raiz);
	printf("Pos ordem:\n");
	passeio_pos_ordem(ar.raiz);
	
	printf("Quantidade de nos: %d\n", contagem(ar.raiz));
	
	printf("Soma: %d\n", somarValores(ar.raiz));
	
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

void inserir(Arvore *ar, int valor){
	No *novo, *aux;
	
	if(!(novo = malloc(sizeof(No)))){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	
	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if(ar->raiz){
		aux = ar->raiz;
		while(aux->esq || aux->dir){
			if(aux->valor < valor){
				if(aux->dir){
					aux = aux->dir;
				}else{
					break;
				}
			}else{
				if(aux->esq){
					aux = aux->esq;
				}else{
					break;
				}
			}
		}
		if(aux->valor > valor){
			aux->esq = novo;
		}else{
			aux->dir = novo;
		}
	}else{
		ar->raiz = novo;
	}
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

int somarValores(No *raiz){
	int soma = 0;
	if(raiz == NULL){
		return 0;
	}
	soma += somarValores(raiz->esq);
	soma += raiz->valor;
	soma += somarValores(raiz->dir);
	return soma;
}
