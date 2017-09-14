#include <stdio.h>
#include <math.h>

int main(void) {

	//TERCEIRA  QUESTAO

	float seg, rad, grau, min, s;
	int h, m;
	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 3:\n");

	printf("Digite a qtde de segundos(real):\n");
	scanf("%f", &seg);
	
	h = seg/3600;
	seg -= 3600*h;
	m = seg/60;
	seg -= 60*m;

	printf("tempo em h:m:s %02d %02d %05.2f\n", h, m, seg);

	printf("Digite o valor de um ângulo em radianos(real):\n");	
	scanf("%f", &rad);
	
	grau = rad*57.2958;
	min = grau - (int) grau; grau = (int) grau;
	min *= 60;
	s = min - (int) min; min = (int) min;
	s *= 60;

	printf("Ângulo convertido: %.0f° %02.0f' %02.0f''\n", grau, min, s);
	

	return 0;
}
