/*
 * 	Ex 	1) Escreva um programa em linguagem c para criar e mostrar uma lista encadeada
 *		com 5 elementos
 */ 
#include<stdio.h>
#include<stdlib.h>

struct tipoNo{
	int valor;
	struct tipoNo *prox;
};
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
	
	for(i = 1; i <= 5; i++){
		printf("%d\n", no->valor);
		no = no->prox;
	}
	
	no = head;
	
	for(i = 1; i <= 5; i++){
		head = head->prox;
		free(no);
		no = head;
	}
	
	return 0;
}
