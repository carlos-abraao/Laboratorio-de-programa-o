#include <stdio.h>

int main(void) {

	//NONA QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 9:\n");

	float s0,v0, a, t, v, s;

	printf("Digite o s0(real): ");
	scanf("%f", &s0);
	printf("Digite o v0(real): ");
	scanf("%f", &v0);
	printf("Digite o a(real): ");
	scanf("%f", &a);
	printf("Digite o t(real): ");
	scanf("%f", &t);

	s = s0 + v0 + (a*t*t)/2;
	v = v0 + a*t;

	printf("Valor de s: %f\nValor de v: %f\n",s, v);

	return 0;
}