#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 13:\n");

	char provas[4][11];
	int matriculas[3], notas[3] = {0, 0, 0};
	float aprov = 0;

	printf("Programa para correção de provas:\nEntre com o gabarito:\n");

	for (int i = 0; i < 10; i++) scanf(" %c", &provas[0][i]);

	for (int i = 0; i < 3; i++){

		printf("Digite sua matricula: ");
		scanf("%d", &matriculas[i]);
		printf("Digite suas respostas, itens de a - e: ");

		for (int j = 0; j < 10; ++j){
			scanf(" %c", &provas[i+1][j]);
		}

		printf("\n");

	}

	for (int i = 1; i < 4; ++i){
		for (int j = 0; j < 11; ++j){
			if(provas[i][j] == provas[0][j]) notas[i-1]++;
		}
	}	

	for (int i = 1; i < 4; ++i){
		printf("Aluno %d, respostas:\n[", matriculas[i-1]);
		for (int j = 0; j < 10; ++j){
			printf(" %c", provas[i][j]);
		}
		printf(" ]\nNota: %d\n\n", notas[i-1]);
		if (notas[i-1] >= 7) aprov = aprov + 33.3;
	}

	printf("Percentual de aprovação: %f\n", aprov);
	
	return 0;
}
