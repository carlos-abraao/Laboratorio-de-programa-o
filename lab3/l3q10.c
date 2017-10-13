#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mult(int **mat, int m, int n, int num){
	
	for(int i = 0; i < m; i++)
		for (int j = 0; j < n; ++j)
			mat[i][j] *= num;
	
}
int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 10:\n");

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

	printf("Digite um número para multiplicar com a matriz:\n");
	scanf("%d", &num);

	mult(matriz, m, n, num);

	printf("matriz multiplicada:\n");
	for(int i = 0; i < m; i++){
		for (int j = 0; j < n; ++j)	{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}