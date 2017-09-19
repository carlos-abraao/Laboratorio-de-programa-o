#include <stdio.h>
#include <math.h>

int primo(int n){

	if(n==2){
		return 1;
	}
	else if ( n<2 || ( (n%2)==0 ) ) return 0;
	else{
		
		int lim = (int) sqrt(n);
		for(int i=3;i <= lim; i+=2){
			if(n%i == 0) return 0;
		}

		return 1;
	}
}

int Doisa(int x){
	printf("\n");
	printf("Números primos menores que %d: [", x);
	for(int i=1; i<x;i++)
		if(primo(i)==1) printf(" %d", i);
	printf(" ]\n\n");		
	
}

int Doisb(int n){
	printf("\n");
	printf("Primeiros %d numeros primos: [", n);
	int i = 0, cont = 0;
	while(cont < n){
		if(primo(i)==1){
			printf(" %d", i);
			cont++;
		}
		i++;
	}
	printf(" ]\n\n");			
}

int main(void) {

	printf("-------------Laboratório de programação 2-------------\n\n");
	printf("Questão 2:\n");

	int var;

	printf("Digite um núemro para o item a: ");
	scanf("%d", &var);
	Doisa(var);

	printf("Digite um núemro para o item b: ");
	scanf("%d", &var);
	Doisb(var);

	return 0;
}
