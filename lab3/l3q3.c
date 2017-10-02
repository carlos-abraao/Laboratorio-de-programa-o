#include <stdio.h>

#define N 10

int volta;

float maximo(float a[]){
	float M = a[0];
	volta = 1;
	for (int i = 1; i < N; ++i) 
		if (a[i] > M){
			M = a[i];
			volta = i+1;
		} 
	
	return M;
}

float minimo(float a[]){
	float M = a[0];
	volta = 1;
	for (int i = 1; i < N; ++i)
		if (a[i] < M){
			M = a[i];
			volta = i+1;
		}
	
	return M;
}

float media(float a[]){
	float media = 0;
	for (int i = 0; i < N; ++i) media += a[i];

	return media/N;
}	


int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 3:\n");

	float a[N];
	printf("Digite os %d tempos de voltas\n", N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%f", &a[i]);
	}

	printf("Melhor tempo: %0.2f\n", minimo(a));
	printf("Melhor mais rápida: %d\n", volta);
	printf("Pior tempo: %0.2f\n", maximo(a));
	printf("Melhor mais lenta: %d\n", volta);
	printf("Media do tempo de volta: %f\n", media(a));

	return 0;
}