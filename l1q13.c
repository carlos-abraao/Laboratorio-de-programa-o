#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	//DECIMA TERCEIRA QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 13:\n");

	printf("Digite as entradas a, b e c(reais):\n");
	
	float a, b, c, delta, x1, x2;
	scanf("%f%f%f", &a,&b, &c);

	delta = (b*b) - (4*a*c);


	if(delta == 0 ){
		x1 = -b/(2*a);		
		x2 = x1;
		printf("Raizes iguais a %f\n", x1);
	}
	else if(delta > 0){
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);

		printf("Raizes iguais a %f e %f\n", x1, x2);

	}	
	else{
		printf("Não existem raizes reais!\n");
	}

	return 0;
}