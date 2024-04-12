/*
 *	R3)	Elabore um programa para ler dois números e mostre sua soma sem usar
 *		variáveis convencionais. Use apenas alocação dinâmica de memória.
 */
#include<stdio.h>
#include<stdlib.h>

int main(void){
	int *p1, *p2;

	if(!(p1 = malloc(sizeof(int)))){
		printf("ERRO! Faltou memória.");
		exit(1);
	}

	if(!(p2 = malloc(sizeof(int)))){
		printf("ERRO! Faltou memória.");
		exit(2);
	}

	printf("Insira um numero: ");
	scanf("%d", p1);
	printf("Insira outro numero: ");
	scanf("%d", p2);

	printf("Soma: %d\n", *p1 + *p2);

	free(p1);
	free(p2);

	return 0;
}
