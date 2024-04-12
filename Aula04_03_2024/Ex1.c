/*
 *	Ex 1) Usando o programa da semana passada, mostre os valores dos nós acima
 * 		da média da lista ligada.
 */
#include<stdio.h>
#include<stdlib.h>

struct tipoNo{   
	int valor;
	struct tipoNo *prox;
};

typedef struct tipoNo tipoNo;

void valoresAcimaMedia(tipoNo *headArg);

int main(void){
	tipoNo *head = NULL, *no;
	int num = 0;
	
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
	
	valoresAcimaMedia(head);
	
	no = head;
	
	while(head != NULL){
		head = head->prox;
		free(no);
		no = head;
	}
	
	return 0;
}

void valoresAcimaMedia(tipoNo *headArg){
	tipoNo *no;
	int s = 0, count = 0;
	float media;
	no = headArg;
	
	while(no != NULL){
		s = s + no->valor;
		no = no->prox;
		count++;
	}
	media = (float)s / (float)count;
	printf("%d\n",s);
	printf("Media = %.2f\n", media);
	no = headArg;
	
	while(no != NULL){
		if(no->valor > media){
			printf("%d\n", no->valor);
		}
		no = no->prox;
	}
	free(no);
}


