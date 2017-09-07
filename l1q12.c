#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//DECIMA SEGUNDA QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 12:\n");

	printf("Calculadora simples\n");
	
	float a, b;
	char op;

	printf("Digite a operação na seguinte ordem: <operando> <operador> <operando>\n");
	scanf("%f%c%f", &a, &op, &b);

	switch (op){
	   case '+':
	     a = a + b;
	     printf("Resultado: %f\n", a);
	   break;

	   case '-':
	     a = a - b;
	     printf("Resultado: %f\n", a);
	   break;

	   case '*':
	     a = a * b;
	     printf("Resultado: %f\n", a);
	   break;

	   case '/':
	   	if (b!=0){
	   		a = a + b;
		    printf("Resultado: %f\n", a);
	   	}
	   	else{
	   		printf("Divisão por 0!\n");
	   	}
		     
	   break;

	   default:
	     printf("Operador inválido\n");
	}	

	return 0;
}