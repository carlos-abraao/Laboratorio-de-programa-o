#include <stdio.h>
#include <math.h>

double delta(int a, int b, int c){

	return ((b*b)-(4*a*c));
}

int raizes(double a, double b, double c, double *px1, double *px2){
	double D = delta(a, b ,c);

	if (D==0){
		*px2 = -b/(2*a);
		*px1 = *px2;		
		return 1;
	}
	else if (D > 0){
		*px1 = (-b +sqrt(D))/(2*a);
		*px2 = (-b -sqrt(D))/(2*a);
		return 2;
	}
	else{
		return 0;
	}

}

int main(void) {

	printf("-------------Laboratório de programação 2-------------\n\n");
	printf("Questão 6:\n");

	double a, b ,c, px1, px2;
	printf("Digite os valores da equação de segundo grau na seguinte ordem:[a b c] onde a!=0(reais)\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	int r = raizes(a, b, c, &px1, &px2);

	if(r==0){
		printf("Sem raízes reais\n");
	}
	else if (r==1){
		printf("Quantidade de raízes: %d\nraíz 1 = raiz 2 = %lf\n", r, px1);
	}
	else{
		printf("Quantidade de raízes: %d\nraíz 1 = %f\nraiz 2 = %lf\n", r, px1, px2);	
	}	

	return 0;
}
