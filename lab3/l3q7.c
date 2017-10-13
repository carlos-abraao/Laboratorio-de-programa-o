#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int busca(int numero,int* sequencia, int n){
	int indice = -1;
	for(int i = 0; i < n; i++){
		if(sequencia[i] == numero){
			indice = i;
			break;
		}
	}
	return indice;	
}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 7:\n");

	int n, *seq;

	printf("Digite o tamanho inicial do vetor:\n");
	scanf("%d", &n);
	seq = (int*) malloc(n*sizeof(int));

	printf("Digite os valores do vetor:\n");
	for(int i = 0; i< n; i++){
		scanf("%d", &seq[i]);	
	}
	int num;
	printf("Digite um núemro para ser buscado:\n");
	scanf("%d", &num);

	int ind = busca(num, seq, n);
	if(ind == -1){
		printf("Número não se encontra na sequência!\n");
	}
	else
		printf("Número encontrado na posição %d da sequência!\n", ++ind);
	
	return 0;
}
