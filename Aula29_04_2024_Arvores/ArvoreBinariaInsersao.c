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
void inserir(Arvore *ar, int valor);

int main(void){
	Arvore ar;
	ar.raiz = NULL;
	
	inserir(&ar, 5);
	inserir(&ar, 3);
	inserir(&ar, 7);
	inserir(&ar, 6);
	inserir(&ar, 8);
	
	passeio_em_ordem(ar.raiz);
	
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
