//#include "Aluno.h"
#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

struct fila {
	Aluno *alus;
	int frente, fim, tamanho;
};

int maxsize;

/* Aloca e retorna uma fila de tamanho informado */
Fila *nova_f(int tamanho){
	if(tamanho <= 0) return NULL;

	maxsize = tamanho;

	Fila *line = (Fila*) malloc(sizeof(Fila));

	line->alus    = (Aluno*) malloc(maxsize*sizeof(Aluno));
	line->tamanho = 0;
	line->frente  = 0;
	line->fim 	  = 0;

	return line;
}

/* Libera a memória de uma fila previamente criada */
void destroi_f(Fila *fila){
	if(fila == NULL) return;
	fila->tamanho = 0;
	fila->frente  = 0;
	fila->fim 	  = 0;		
	free(fila->alus);
	fila->alus = NULL;
	free(fila);
	fila = NULL;
}

/* Adiciona um aluno na fila. Retorna 1 se der certo e 0 caso contrário */
int adiciona_f(Fila *fila, Aluno *aluno){
	if(fila == NULL || aluno == NULL || cheia_f(fila) ) return 0;

	fila->tamanho++;

	fila->alus[fila->fim] = *aluno;

	fila->fim = (fila->fim+1) % maxsize;

	return 1;
}

/* Remove um aluno na fila. Retorna 1 se der certo e 0 caso contrário */
int retira_f(Fila *fila){
	if(fila == NULL || fila->tamanho == 0) return 0;

	fila->tamanho--;
	fila->frente = (fila->frente+1) % maxsize;

	return 1;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se der certo e NULL
caso contrário */
Aluno *busca_f(Fila *fila, int matricula){
	if(fila == NULL || fila->tamanho == 0) return NULL;
	
	for(int i = 0; i < maxsize; i++){
		if(fila->alus[i].matricula == matricula) return &fila->alus[i];
	}

	return NULL;
}

/* Retorna 1 se a fila estiver cheia e 0 caso contrário */
int cheia_f(Fila *fila){
	if(fila == NULL) return 0;
	
	if (fila->tamanho == maxsize) return 1;
	else return 0;	
}
