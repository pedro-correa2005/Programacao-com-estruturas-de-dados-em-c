/*	
 *	R1) Elabore um programa para ler dois números, um inteiro e outro fracionário
 * 		Informe qual deles é o maior.
 */
#include<stdio.h> 

int main(void){
	int n1;
	float n2;

	printf("Insira um numero: ");
	scanf("%d",&n1);
	printf("Insira outro numero: ");
	scanf("%f",&n2);
	if(n1 > n2){
		printf("Maior: %d",n1);
	}else if(n2 > n1){
		printf("Maior: %.2f", n2);
	}else{
		printf("Os numeros sao iguais");
	}
	return 0;
}
