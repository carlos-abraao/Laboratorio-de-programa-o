#include <stdio.h>
#include <math.h>


#define pi 3.14159

int main(void) {

	//PRIMEIRA  QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 1:\n");

	double raio;
	float volume;

	printf("Digite o número do raio(real):\n");
	scanf("%lf", &raio);

	double r;
	r = pow(raio,3);

	volume = (4/3)*pi*r;

	printf("O volume da esfera é %f:\n", volume);


	return 0;
}