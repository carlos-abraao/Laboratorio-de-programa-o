#include <stdio.h>

#define N 10

float pescalar(float a[], float b[]){
	float p = 0;
	for (int i = 0; i < N; ++i)
	{
		p += a[i]*b[i];
	}
	return p;
}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 4:\n");

	float a[N];
	printf("Digite os %d valores do vetor a:\n", N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%f", &a[i]);
	}

	float b[N];
	printf("Digite os %d valores do vetor b:\n", N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%f", &b[i]);
	}

	printf("Produto escalar dos vetores: %f\n", pescalar(a, b));
	
	return 0;
}