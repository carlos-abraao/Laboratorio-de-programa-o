#include <stdio.h>

int main(void) {

	//QUARTA  QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 4:\n");


	int valor, menorN, nCem=0, nCinq=0, nVint=0, nDez=0, ncinc=0, nDois=0, nUm=0;

	printf("Digite um valor en reais R$(inteiro):\n");
	scanf("%d", &valor);
	menorN = 0;

	while(valor != 0){

		if(valor >= 100){
			menorN += valor/100; nCem = valor/100;
			valor -= 100*nCem;
			continue;
		}
		else if (valor>= 50){
			menorN += valor/50; nCinq = valor/50;
			valor -= 50*nCinq;
			continue;
		}
		else if (valor>= 20){
			menorN += valor/20; nVint = valor/20;
			valor -= 20*nVint;
			continue;
		}
		else if (valor>= 10){
			menorN += valor/10; nDez = valor/10;
			valor -= 10*nDez;
			continue;
		}
		else if (valor>= 5){
			menorN += valor/5; ncinc = valor/5;
			valor -= 5*ncinc;
			continue;
		}
		else if (valor>= 2){
			menorN += valor/2; nDois = valor/2;
			valor -= 2*nDois;
			continue;
		}
		else if (valor>= 1){
			menorN += valor/1; nUm = valor/1;
			valor -= 1*nUm;
			continue;
		}

	}

	printf("O menor númeor de notas para trocar esse valor é %d:\n", menorN);
	printf("Serão necessárias %d notas de 100| %d notas de 50| %d notas de 20| %d notas de 10| %d notas de 5| %d notas de 2| %d notas de 1:\n", nCem, nCinq, nVint, nDez, ncinc, nDois, nUm);


	return 0;
}