#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {

	//DECIMA QUESTAO

	printf("-------------Laboratório de programação 1-------------\n\n");
	printf("Questão 10:\n");

	int p, pc;
	bool draw = 0;

	srand( (unsigned)time(NULL) );

	printf("Pedra, papel ou tesoura!\n0 - pedra\n1 - papel\n2 - tesoura\n");

	do{
		do{
			printf("Escolha uma das opções acima: ");
			scanf("%d", &p);

		}while(p < 0 || p > 2);

		pc = rand()%3;

		printf("Computador escolheu: %d \n", pc );

		if(p==0){

			if(pc==1){
				printf("computador ganhou.\n");
				return 0;
			}
			else if(pc==2){
				printf("Usuário ganhou!\n");	
				return 0;
			}
			else{
				printf("Empate.\nEscolha novamente\n");
				draw = 1;
			}
		}else if(p==1){

			if(pc==2){
				printf("computador ganhou.\n");
				return 0;
			}
			else if(pc==0){
				printf("Usuário ganhou!\n");	
				return 0;
			}
			else{
				printf("Empate.\nEscolha novamente\n");
				draw = 1;
			}
		}else if(p==2){

			if(pc==0){
				printf("computador ganhou.\n");
				return 0;
			}
			else if(pc==1){
				printf("Usuário ganhou!\n");	
				return 0;
			}
			else{
				printf("Empate.\nEscolha novamente\n");
				draw = 1;
			}

		}
	}while(draw==1);
}