#include <stdio.h>
#include <math.h>

double pot(double x, int k){
	if(k == 0){
		return 1;
	}
	else if (k==1){
		return x;
	}
	else{
		return x*pot(x, k-1);
	}
	
}

int main(void) {

	printf("-------------Laboratório de programação 2-------------\n\n");
	printf("Questão 7:\n");

	double x;
	int k;

	printf("Digite um número real elevado a um inteiro:\n");
	scanf("%lf^%d", &x, &k);
	double poti = pot(x, k);
	double potm = pow(x, k);
	printf("Potenciação implementada: %lf\n", poti);
	printf("Potenciação math.h: %lf\n", potm);
	
	return 0;
}
