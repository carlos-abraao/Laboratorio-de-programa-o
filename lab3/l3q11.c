#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* multv(int **mat, int m, int n, int *num){
	int * r, sum = 0;
	r = (int*) malloc(m*sizeof(int*));

	for(int i = 0; i < m; i++){
		for (int j = 0; j < n; ++j)
			sum	 += mat[i][j] * num[j];

		r[i] = sum;
		sum = 0;
	}

	return r;	
}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 11:\n");

	int m, n, **matriz, *num;

	printf("Digite as dimensões da matriz:\n");
	scanf("%d%d", &m, &n);	

	matriz = (int**) malloc(m*sizeof(int*));
	num	   = (int*) malloc(n*sizeof(int*));
	for (int i = 0; i < m; ++i){
		matriz[i] = (int*) malloc(n*sizeof(int));
	}

	printf("Digite os valores da matriz:\n");
	for(int i = 0; i < m; i++){
		for (int j = 0; j < n; ++j)	{
			scanf("%d", &matriz[i][j]);
		}
	}

	printf("Digite os valores do vetor de %d numeros para ser multiplicado com a matriz:\n", n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}		

	int *R;

	 R = multv(matriz, m, n, num);

	printf("Vetor resultado:\n");
	for(int i = 0; i < m; i++){		
		printf("%d\n", R[i]);		
	}
	printf("\n");
	
	return 0;
}