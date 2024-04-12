/*
 *	R2) Reescreva R5 com apenas um comando de repetição
 *	*1
 *	**3
 *	***6
 *	****10
 *
**/
#include<stdio.h>

int main(void){
	int num, i, j, k, s;
	//usuario insere numero de linhas
	printf("Insira um numero para desenhar um triangulo: ");
	scanf("%d",&num);
	//descobre-se o total de asteriscos
	s = (int)(((float)(1 + num) / 2.0) * num);
	
	//variavel j para acompanhar numero de asteriscos por linha
	j = 0;
	//variavel k para guardar o numero de asteriscos da linha anterior
	k = 0;
	//i variando de 1 a s(total de asteriscos)
	for(i = 1; i <= s; i++){
		//a cada asterisco impresso nessa linha j incrementa 1
		printf(" |\\");
		j++;
		//se o numero de asteriscos dessa linha for igual ao da linha anterior mais um
		if( j == k + 1 ){
			//pula linha
			printf("\n");
			//k guarda o numero de asteriscos dessa linha(que na proxima iteração será o numero de asteriscos da linha anterior)
			k = j;
			//j zera para contar o numero de asteriscos da proxima linha
			j = 0;
		}
	}
	return 0;
}
