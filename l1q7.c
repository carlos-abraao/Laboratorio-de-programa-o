#include <stdio.h>

int main(void) {

	//SÉTIMA  QUESTAO
	
	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 7:\n");

	float p1, p2, p3, nota, maior;

	printf("Digite as duas primeira notas(real):\n");

	scanf("%f%f", &p1, &p2);

	nota = (p1 + p2)/2;
	maior = p1;

	if(p2 > p1){
		maior = p2;
	}

	if(nota >=5 && p1>=3 && p2>= 3){
		printf("Aprovação direta!\n");
	}
	else{
		printf("Entre com o valor da terceira nota(float)\n");
		scanf("%f", &p3);
		nota = (maior + p3)/2;
		if (nota >=5)
		{
			printf("Aprovação!\n");
		}
		else{
			printf("Reprovadi.\n");
		}
	}

	return 0;
}