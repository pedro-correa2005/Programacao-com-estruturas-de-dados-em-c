/*
 *	R4)	Escreva um programa que pede um numero para o usu�rio e desenha um
 *		ret�ngulo com a quantidade de linhas digitadas pelo usu�rio.
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
