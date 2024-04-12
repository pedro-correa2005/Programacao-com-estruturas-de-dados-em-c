/*
 *	R1) Altere o R5 para desenhar um triângulo.
 *		Ex qtd = 3
 *			  *
 *			 * *
 * 			* * *
 */
#include<stdio.h>

int main(void){
	int i, j, k, num;
	
	printf("Insira um numero para desenhar um triangulo: ");
	scanf("%d",&num);
	
	for(i = 1; i <= num; i++){
		
		for(j = num; j >= i; j--){
			printf(" ");
		}
		for(k = 1; k <= i; k++){
			printf("* ");	
		}
		putchar(10);
	}
	putchar(10);
	return 0;
}
