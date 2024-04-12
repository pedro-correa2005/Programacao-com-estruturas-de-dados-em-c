/*
 *	R4)	Escreva um programa que pede um numero para o usuário e desenha um
 *		retângulo com a quantidade de linhas digitadas pelo usuário.
 *		Exemplo: num = 3
 *			* * *
 *			* * *
 *			* * *
 */
#include<stdio.h>
 
int main(void){
	int num, i, j;

	printf("Insira um numero para desenhar o retangulo: ");
	scanf("%d",&num);

	for(i = 0; i < num; i++){
		for(j = 0; j < num; j++){
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}
