/*
 * 	Ex 	2) Altere o ex1 para mostrar o conteúdo da lista usando uma função
 */ 
#include<stdio.h>
#include<stdlib.h>

struct tipoNo{   
	int valor;
	struct tipoNo *prox;
};
void mostraListaLigada(struct tipoNo *headArg);
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
	
	mostraListaLigada(head);
	
	no = head;
	
	for(i = 1; i <= 5; i++){
		head = head->prox;
		free(no);
		no = head;
	}
	
	return 0;
}
void mostraListaLigada(struct tipoNo *headArg){
	struct tipoNo *no;
	int i;
	no = headArg;
	
	for(i = 1; i <= 5; i++){
		printf("%d\n", no->valor);
		no = no->prox;
	}
	
	free(no);
}
