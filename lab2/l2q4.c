#include <stdio.h>

#define pi 3.14159

float volume(float r){
	return ((4/3.0)*pi*r*r*r);
}

float area(float r){
	return (pi*r*r);
}

int main(void) {

	printf("-------------Laboratório de programação 2-------------\n\n");
	printf("Questão 4:\n");

	float r;

	printf("Digite o valor do raio de uma esfera(real):\n");
	scanf("%f", &r);
	printf("Volume da esfera = %f\nÁrea da esfera = %f\n", volume(r), area(r));

	return 0;
}
