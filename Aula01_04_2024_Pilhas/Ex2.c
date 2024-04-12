/*
 *	Ex 2) Escreva um programa para ler uma expressão digitaga pelo usuário  que
 *	contenha apenas as 4 operações, (+, -, *, e /) e mostre o resultado.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoNo{
	char valor;
	struct tipoNo *prox;
}tipoNo;

void push(tipoNo **topo, char valor);
char pop(tipoNo **topo);
char consultarTopo(tipoNo *topo);
void mostrarPilha(tipoNo *topo);
int converte(char v);
char converte2(int v);

int main(void){
	tipoNo *topo = NULL, *numeros;
	char string[50];
	int i, v1, v2;
	
	printf("Insira a expressão: ");
	scanf("%s", string);
	
	for(i = 0; i < strlen(string); i++){
		push(&topo, string[i]);
		switch(string[i]){
			case '*':
				v1 = pop(&topo);
				v2 = pop(&topo);
				push(&topo,converte2(converte(v1) * converte(v2)));
				break;
			case '+':
				v1 = pop(&topo);
				v2 = pop(&topo);
				push(&topo,converte2(converte(v1) + converte(v2)));
				break;
			case '-':
				v1 = pop(&topo);
				v2 = pop(&topo);
				push(&topo, converte2(converte(v1) - converte(v2)));
				break;
			case '/':
				v1 = pop(&topo);
				v2 = pop(&topo);
				push(&topo, converte2(converte(v1) / converte(v2)));
				break;
			default:
				push(&numeros, string[i]);
				break;
		}
	}
	
	mostrarPilha(topo);
	
	while(topo != NULL){
			//printf("Topo = %c\n", pop(&topo));
			pop(&topo);
	}
	
	return 0;
}
void push(tipoNo **topo, char valor){
	tipoNo *novo;
	if(!(novo = malloc(sizeof(tipoNo)))){
		printf("Faltou memoria");
		exit(1);
	}
	novo->prox = *topo;
	novo->valor = valor;
	*topo = novo;
}
char pop(tipoNo **topo){
	tipoNo *p;
	char v;
	if(*topo == NULL){
		printf("Pilha vazia");
		exit(2);
	}
	p = *topo;
	*topo = p->prox;
	v = p->valor;
	free(p);
	return v;
}
char consultarTopo(tipoNo *topo){
	printf("Topo: %c\n", topo->valor);
	return topo->valor;
}
void mostrarPilha(tipoNo *topo){
	while(topo){
		printf("%c\n", topo->valor);
		topo = topo->prox;
	}
}
int converte(char v){
	switch(v){
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case '0':
			return 0;
	}
}
char converte2(int v){
	switch(v){
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 0:
			return '0';
	}
}
