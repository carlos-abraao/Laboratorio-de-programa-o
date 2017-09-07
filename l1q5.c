#include <stdio.h>

int main(void) {

	//QUINTA QUESTAO
	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 5:\n");

	int n1, n2, n3, aux;

	printf("Digite três números inteiros:\n");

	scanf("%d%d%d", &n1, &n2, &n3);

	int ordem[3] = {n1, n2, n3};

	for(int i = 0; i < 3; i++){		//bubble sort
		for(int j = i+1; j < 3; j++){
			if (ordem[i] > ordem[j]){
				aux  = ordem[i];
				ordem[i] = ordem[j];
				ordem[j] = aux;
			}
		}
	}

	printf("Maior número é: %d \n\n", ordem[2]);
	printf("Números em ordem crescente: %d %d %d \n", ordem[0], ordem[1], ordem[2]);


	

	return 0;
}