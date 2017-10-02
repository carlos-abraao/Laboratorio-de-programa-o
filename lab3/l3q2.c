#include <stdio.h>

int maximo(int a[], int n){
	int M = a[0];
	for (int i = 1; i < n; ++i) 
		if (a[i] > M) M = a[i];
	
	return M;
}

int minimo(int a[], int n){
	int M = a[0];
	for (int i = 1; i < n; ++i)
		 if (a[i] < M) M = a[i];
	
	return M;
}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 2:\n");

	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("Maior valor do vetor: %d\n", maximo(a, 10));
	printf("Menor valor do vetor: %d\n", minimo(a, 10));

	return 0;
}