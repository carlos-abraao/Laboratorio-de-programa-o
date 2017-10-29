//#include "Aluno.h"
#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

struct fila {
	Aluno *inicio, *final;
	int tamanho;
};

int maxsize;

/* Aloca e retorna uma fila de tamanho informado */
Fila *nova_f(int tamanho){
	if(tamanho <= 0) return NULL;

	maxsize = tamanho;

	Fila *line = (Fila*) malloc(sizeof(Fila));

	line->inicio  = NULL;
	line->final	  = NULL;
	line->tamanho = 0;

	return line;
}

/* Libera a memória de uma fila previamente criada */
void destroi_f(Fila *fila){
	if(fila == NULL) return;
	fila->tamanho = 0;

	free(fila->inicio);
	fila->inicio = NULL;

	free(fila->final);
	fila->final = NULL;

	free(fila);
	fila = NULL;
}

/* Adiciona um aluno na fila. Retorna 1 se der certo e 0 caso contrário */
int adiciona_f(Fila *fila, Aluno *aluno){
	if(fila == NULL || aluno == NULL || cheia_f(fila) ) return 0;

	if (fila->tamanho == 0){
		fila->inicio = aluno;
		fila->final  = aluno;
		fila->final->proximo = NULL;
	}
	else{		
		fila->final->proximo = aluno;
		fila->final = fila->final->proximo;
		fila->final->proximo = NULL;
	}
	
	fila->tamanho++;

	return 1;
}

/* Remove um aluno na fila. Retorna 1 se der certo e 0 caso contrário */
int retira_f(Fila *fila){
	if(fila == NULL || fila->tamanho == 0) return 0;

	Aluno *aux = (Aluno*) malloc(sizeof(Aluno));

	aux = fila->inicio;	

	fila->inicio = aux->proximo;

	free(aux);	
	
	fila->tamanho--;

	return 1;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se der certo e NULL
caso contrário */
Aluno *busca_f(Fila *fila, int matricula){
	if(fila == NULL || fila->tamanho == 0) return NULL;

	Aluno *aux = (Aluno*) malloc(sizeof(Aluno));

	aux = fila->inicio;

	while(aux != NULL){
		if(aux->matricula == matricula) return aux;

		aux = aux->proximo;
	}	

	return NULL;
}

/* Retorna 1 se a fila estiver cheia e 0 caso contrário */
int cheia_f(Fila *fila){
	if(fila == NULL) return 0;
	
	if (fila->tamanho == maxsize) return 1;
	else return 0;	
}
