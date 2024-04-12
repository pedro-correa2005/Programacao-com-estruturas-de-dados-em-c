/*
 *	R2)	Elabore um programa para ler 10 números inteiros pares.
 */
#include<stdio.h>

int main(void){
	int vet[10], i = 0;
	
	while(i < 10){
		
		printf("Preencher vetor na posicao %2d com um numero inteiro par: ", i);
		scanf("%d", &vet[i]);
		
		if(vet[i] % 2 == 0){
			i++;
		}
	}
	
	for(i = 0; i < 10; i++){
		printf("Vet[%d] = %2d\n", i, vet[i]);
	}
	
	return 0;
}
