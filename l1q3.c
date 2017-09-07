#include <stdio.h>
#include <math.h>

int main(void) {

	//TERCEIRA  QUESTAO

	float seg;

	printf("Questão 3:\n");

	printf("Digite a qtde de segundos(real):\n");

	scanf("%f", &seg);

	int h, m;
	
	h = seg/3600;
	seg -= 3600*h;
	m = seg/60;
	seg -= 60*m;

	printf("tempo em h:m:s %02d %02d %05.2f\n", h, m, seg);

	

	return 0;
}