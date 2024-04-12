/*
 *	Ex 3) Altere o exercício anterior criando uma função que devolve a soma dos valores
 		da lista ligada
 */
#include<stdio.h>
#include<stdlib.h>

struct tipoNo{   
	int valor;
	struct tipoNo *prox;
};
int somaListaLigada(struct tipoNo *headArg);
int main(void){
	struct tipoNo *head = NULL, *no;
	int num, i;
	
	for(i = 1; i <= 5; i++){
		printf("Insira um numero: ");
		scanf("%d", & num);
		if(!(no = malloc(sizeof(struct tipoNo)))){
			printf("Erro! Faltou memoria\n");
			exit(1);
		}
		no->prox = head;
		head = no;
		no->valor = num;
	}
	
	printf("soma: %d\n", somaListaLigada(head));
	
	no = head;
	
	for(i = 1; i <= 5; i++){
		head = head->prox;
		free(no);
		no = head;
	}
	
	return 0;
}
int somaListaLigada(struct tipoNo *headArg){
	struct tipoNo *no;
	int i;
	int s = 0;
	no = headArg;
	
	for(i = 1; i <= 5; i++){
		s = s + no->valor;
		no = no->prox;
	}
	
	free(no);
	
	return s;
}
