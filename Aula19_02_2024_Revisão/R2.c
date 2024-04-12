/*
 *	R2) Altere o R1 para desenhar um losângulo.
 *		Ex qtd = 3
 *			  *
 *			 * *
 * 			* * *
 *			 * *
 *			  *
 */
#include<stdio.h>

int main(void){
	int i, j, k, num;
	
	printf("Insira um numero para desenhar um losangulo: ");
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
	for(i = 1; i <= num - 1; i++){
		
		for(j = 1; j <= i + 1; j++){
			printf(" ");
		}
		
		for(k = num - 1; k >= i; k--){
			printf("* ");	
		}
		putchar(10);
	}
	putchar(10);
	return 0;
}
