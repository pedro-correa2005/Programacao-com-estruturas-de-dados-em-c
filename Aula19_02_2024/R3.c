/*
 *	R2) Reescreva R5 com apenas um comando de repetição
 	*
 	**
 	***
 	****
 	1-3-6-10
 	4
 */
#include<stdio.h>

int main(void){
	int num, i, j = 0;
	
	printf("Insira um numero para desenhar um triangulo: ");
	scanf("%d",&num);
	
	num = (1 + num) / 2 * num;
	
	for(i = 1; i <= num; i++){
		printf(" *");
		j++;
		if((j % i) == 0){
			printf("\n");
			j = -1;
		}else{
			printf("A");
		}
	}
	return 0;
}
