#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int repeticoes(int **mat, int m, int n, int num){
	int rep = 0;
	for(int i = 0; i < m; i++){
		for (int j = 0; j < n; ++j)	{
			if(mat[i][j] == num)
				rep++;
		}
	}
	return rep;	
}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 7:\n");

	int m, n, **matriz, num;

	printf("Digite as dimensões da matriz:\n");
	scanf("%d%d", &m, &n);	

	matriz = (int**) malloc(m*sizeof(int*));
	for (int i = 0; i < m; ++i){
		matriz[i] = (int*) malloc(n*sizeof(int));
	}

	printf("Digite os valores da matriz:\n");
	for(int i = 0; i < m; i++){
		for (int j = 0; j < n; ++j)	{
			scanf("%d", &matriz[i][j]);
		}
	}

	printf("Digite um número a ser buscado na matriz:\n");
	scanf("%d", &num);

	int rep = repeticoes(matriz, m, n, num);

	printf("O número %d aparece %d vezes na matriz\n", num, rep);
	
	return 0;
}
