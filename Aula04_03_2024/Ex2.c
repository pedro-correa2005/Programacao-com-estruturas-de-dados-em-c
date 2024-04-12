/*
 *	Ex 2)	Criar função para informar se a lista ligada contém um valor
 *			digitado pelo usuário na função main().
 */
#include<stdio.h>
#include<stdlib.h>

struct tipoNo{
	int valor;
	struct tipoNo *prox;
};

void mostraLista(struct tipoNo *parm);
int somaLista(struct tipoNo *parm);
int contaLista(struct tipoNo *parm);
void mostraAcima(struct tipoNo *parm, float media);
void consultaNaLista(struct tipoNo *parm, int v);

int main(void){
	int soma, qtd, num;
	float media;
	
	struct tipoNo *head = NULL, *no;
	do{
		printf("Insira um numero[0 para parar]: ");
		scanf("%d", & num);
		if(num == 0){
			break;
		}
		if(!(no = malloc(sizeof(struct tipoNo)))){
			printf("Erro! Faltou memoria\n");
			exit(1);
		}
		no->prox = head;
		head = no;
		no->valor = num;
	}while(num != 0);
	
	consultaNaLista(head, 7);
	consultaNaLista(head, 10);
	consultaNaLista(head, 1);
	consultaNaLista(head, 50);
	
	no = head;
	while(head != NULL){
		head = head->prox;
		free(no);
		no = head;
	}
	return 0;
}

int somaLista(struct tipoNo *parm){
	int soma = 0;
	struct tipoNo *aux;
	aux = parm;
	while(aux != NULL){
		soma = soma + aux->valor;
		aux = aux->prox;
	}
	return soma;
}

int contaLista(struct tipoNo *parm){
	int qtd = 0;
	struct tipoNo *aux;
	aux = parm;
	while(aux != NULL){
		qtd = qtd + 1;
		aux = aux->prox;
	}
	return qtd;
}

void mostraLista(struct tipoNo *parm){
	struct tipoNo *aux;
	aux = parm;
	while(aux != NULL){
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
}

void mostraAcima(struct tipoNo *parm, float media){
	struct tipoNo *aux;
	aux = parm;
	
	while(aux != NULL){
		if(aux->valor > media){
			printf("%d\n", aux->valor);
		}
		aux = aux->prox;
	}
}

void consultaNaLista(struct tipoNo *parm, int v){
	struct tipoNo *aux;
	int indice = 0;
	aux = parm;
	while(aux != NULL){
		if(aux->valor == v){
			printf("Valor %d aparece na posicao %d\n", v, contaLista(parm) - (indice + 1));
			break;
			
		}else{
			aux = aux->prox;
			indice++;
			continue;
		}
	}
	if(aux == NULL){
		printf("Valor %d nao aparece na lista\n", v);
	}
}
