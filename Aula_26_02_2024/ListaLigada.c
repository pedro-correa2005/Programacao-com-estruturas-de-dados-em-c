/*
 *	Lista ligada
 */

#include<stdio.h>
#include<stdlib.h>

struct tipoNo{
	int valor;
	struct tipoNo *prox;
};
int main(void){
	struct tipoNo *head = NULL, *no;
	int qtd = 1;
	
	while(qtd>0){
		printf("digite o valor:");
		scanf("%d", &qtd);
		if(!(no = malloc(sizeof(struct tipoNo)))){
			printf("Faltou memoria!\n");
			exit(1);
		}
		no->prox = head;
		head = no;
		no->valor = qtd;
	}
	printf("\nFim da criacao da lista\n");
	printf("\nMostrar a lista:\n");
	
	//no = head;
	while(no != NULL){
		printf("Valor = %d\n", no->valor);
		no = no->prox;
	}
	printf("Destruindo a lista:\n");
	no = head;
	while(no != NULL){
		head = head->prox;
		free(no);
		no = head;
	}
	return 0;
}
