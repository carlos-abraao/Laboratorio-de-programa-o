#include <stdio.h>
#include <math.h>

int main(void) {

	//SEGUNDA  QUESTAO

	printf("Questão 2:\n");

	float pgalao, taxad;

	printf("Digite o preço do galão de gasolina nos EUA em dólares(real):\n");
	scanf("%f", &pgalao);
	printf("Digite o valor da taxa de converção dólar-real(real):\n");
	scanf("%f", &taxad);

	float valorc;

	valorc = pgalao/3.7854;
	valorc = valorc*taxad;

	printf("O valor do litro da gasolina em reais é %f\n", valorc);


	return 0;
}