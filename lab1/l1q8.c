#include <stdio.h>
#include <math.h>

int main(void) {

	//OITAVA QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 8:\n");

	float r, a, x, y;

	printf("Conversão de coordenadas polares:\n");
	printf("Digite o raio(real): ");
	scanf("%f", &r);
	printf("Digite o ângulo(real): ");
	scanf("%f", &a);

	x = cos(a)*r;
	y = sin(a)*r;

	printf("Coordenadas cartesianas correspondentes: x = %f y = %f\n", x, y);

	return 0;
}