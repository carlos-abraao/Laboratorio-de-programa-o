#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//DECIMA PRIMEIRA QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 11:\n");

	printf("Verificador de triangulo:\nDigite três valores inteiros:\n");
	
	int a, b, c;
	scanf("%d%d%d", &a,&b, &c);

	if( (abs(b-c) < a && a < (b+c)) && (abs(a-c) < b && b < (a+c)) && (abs(a-b) < c && c < (b+a)) ){
		if(a==b && b==c && a==c) printf("triangulo equilátero.\n");
		else if (a==b || a==c || b==c) printf("triangulo isósceles.\n");
		else{
			printf("triangulo escaleno.\n");
		}		
	}
	else{
		printf("Valores não formam um triangulo\n");
	}	

	return 0;
}