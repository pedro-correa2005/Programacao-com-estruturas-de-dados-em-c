/*
 *	R5) Altere o R4 para desenhar um triângulo.
 *		Ex qtd = 3
 *			*
 *			**
 * 			***
 */
#include<stdio.h>

int main(void){
	int num, i, j;
	
	printf("Insira um numero para desenhar o triangulo: ");
	scanf("%d",&num);
	
	for(i = 1; i <= num; i++){
		for(j = 1; j <= i; j++){
			printf("* ");
		}
		putchar(10);
	}
	return 0;
}
