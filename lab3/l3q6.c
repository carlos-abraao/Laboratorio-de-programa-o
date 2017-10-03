#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 6:\n");

	int n, k = 0, teste, *v;
	

	printf("Rotina  para ler valores inteiros e armazenar em vetores alocados dinamicamente:\nDigite o tamanho inicial do vetor:\n");
	scanf("%d", &n);	

	v = (int*) malloc(n*sizeof(int));

	if(v == NULL){
		printf("Memoria insuficiente.\n"); 
		exit(1);
	}

	printf("Digite os valores do vetor:\n");
		for(int i = 0; i< n-k; i++){
			scanf("%d", &v[i]);	
	}

	
	do{
		printf("Deseja adicionar mais valores?:\n0 - não\n1 - sim\n");
		scanf("%d", &teste);

		if(teste){
			printf("Quantos valores a mais?\n");
			scanf("%d", &k);
			v = (int*) realloc(v, k*sizeof(int));

			if(v == NULL){
				printf("Memoria insuficiente.\n"); 
				exit(1);
			}

			printf("Digite os valores do vetor:\n");
			for(int i = n; i< n+k; i++)
				scanf("%d", &v[i]);		
			n += k;
			
		}		

	}while(teste == 1 && v != NULL);

	printf("Vetor final: [");

	for(int i = 0; i< n; i++)
		printf(" %d", v[i]);

	printf("]\n");

	free(v);
	
	return 0;
}