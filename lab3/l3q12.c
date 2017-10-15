#include <stdio.h>
#include <stdlib.h>

void printable(int table[][3]){

	printf("\n\n");
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if(table[i][j] == -1){
				printf(" ");
				if(j != 2)	printf("|");
				else		printf("\n");
			}
			else if(table[i][j] == 0){
				printf("o");
				if(j != 2)	printf("|");
				else		printf("\n");
			}
			else if(table[i][j] == 1){
				printf("x");
				if(j != 2)	printf("|");
				else		printf("\n");
			}

		}
		if (i != 2) printf("-----\n");
	}

	printf("\n");
}

int changetable(int j, int x, int y, int table[][3]){
	if (x > 2 || y > 2 || table[x][y] != -1){
	 return -1;
	}

	table[x][y] = j;
	return 1;

}

int checktable(int table[][3]){
	int aux = 3, over;

	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			over = table[i][j];
			if (over == -1) aux = -1;
		}
	}

	if (aux == 3) return aux;	

	for (int i = 0; i < 3; ++i){
		aux = table[i][0];
		if(table[i][0] == table[i][1] && table[i][0] == table[i][2] && aux != -1) return aux;
	}

	for (int i = 0; i < 3; ++i){
		aux = table[0][i];
		if(table[0][i] == table[1][i] && table[0][i] == table[2][i] && aux != -1) return aux;
	}	

	aux = table[0][0];

	for (int i = 0; i < 3; ++i){
		if(aux != table[i][i]){
				aux = -1;
				break;
		}	
	}

	if(aux != -1) return aux;

	aux = table[0][2];

	if(table[0][2] == table[1][1] && table[0][2] == table[2][0]) return aux;	
	else aux = -1;

	return aux;

}

int main(void) {
	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 12:\n");

	int tabuleiro[3][3], j1, j2, done = -1, x, y, aux;

	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			tabuleiro[i][j] = -1;
		}
	}

	printf("Jogo da velha!:\n0 = O\n1 = X\nJogador 1, escolha seu símbolo:");
	scanf("%d", &j1);
	if (j1 == 1) j2 = 0	;
	else j2 = 1;

	while(1){
		printf("\e[1;1H\e[2J");
		printable(tabuleiro);

		printf("Jogador 1, digite a posição onde colocar seu símbolo:\n");

		scanf("%d%d", &x, &y);

		aux = changetable(j1, x, y, tabuleiro);

		while(aux == -1){
			printf("Jogador1 escolha novamente:\n");
			scanf("%d%d", &x, &y);
			aux = changetable(j1, x, y,tabuleiro);
		}

		done  = checktable(tabuleiro);

		if(done != -1) break;
		printf("\e[1;1H\e[2J");
		printable(tabuleiro);

		printf("Jogador 2, digite a posição onde colocar seu símbolo:\n");

		scanf("%d%d", &x, &y);

		aux = changetable(j2, x, y,tabuleiro);
		while(aux == -1){
			printf("Jogador escolha novamente:\n");
			scanf("%d%d", &x, &y);
			aux = changetable(j2, x, y,tabuleiro);
		}

		done  = checktable(tabuleiro);

		if(done != -1) break;

	}
	printf("\e[1;1H\e[2J");
	printable(tabuleiro);

	if (done == 3) printf("Deu velha!\n");
	else printf("símbolo %d ganhou! \n", done);	

	printf("\n");
	
	return 0;
}
