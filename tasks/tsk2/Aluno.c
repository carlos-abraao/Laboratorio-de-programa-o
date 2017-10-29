#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"

/*
struct aluno{
	int matricula ;
	char nome[50] ;
	char curso[30];
};
*/

/* Aloca e retorna um aluno com os dados passados por parâmetro */
Aluno *novo_a(int matricula, char *nome, char *curso){
	Aluno* alu = (Aluno*) malloc(sizeof(Aluno));

	if (alu == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

	if(matricula < 0 || nome == NULL || curso == NULL || strlen(nome) > 50 || strlen(curso) > 30) return NULL;

	alu->matricula = matricula;

	int i;

	for (i=0; nome[i] != '\0'; i++)	alu->nome[i] = nome[i];	
	
	alu->nome[i] = '\0';

	for (i=0; curso[i] != '\0'; i++) alu->curso[i] = curso[i];	
	
	alu->curso[i] = '\0';
	
	alu->proximo = NULL;
	
	return alu;
}

/* Libera a memória de um aluno previamente criado */
void libera_a(Aluno *aluno){
	
	if(aluno == NULL) return;

	free(aluno);
	aluno->matricula = 0   ;
	aluno->nome[0] 	 = '\0';
	aluno->curso[0]  = '\0';
	aluno->proximo   = NULL;
}

/* Copia os valores de um aluno para as referências informadas */
void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso){
	if(aluno == NULL) return;
	
	*matricula 	= aluno->matricula;

	int i;

	for (i=0; aluno->nome[i] != '\0'; i++) nome[i] = aluno->nome[i];	
	
	nome[i] = '\0';

	for (i=0; aluno->curso[i] != '\0'; i++) curso[i] = aluno->curso[i];	
	
	curso[i] = '\0';

}

/* Atribui novos valores aos campos de um aluno */
void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso){

	if(matricula < 0 || nome == NULL || curso == NULL || strlen(nome) > 50 || strlen(curso) > 30) return;	

	aluno->matricula = matricula;

	int i;

	for (i=0; nome[i] != '\0'; i++) aluno->nome[i] = nome[i];	
	
	aluno->nome[i] = '\0';

	for (i=0; curso[i] != '\0'; i++) aluno->curso[i] = curso[i];	
	
	aluno->curso[i] = '\0';

	aluno->proximo   = NULL;

}

/* Retorna o tamanho em bytes do TAD aluno */
int tamanho_a(){
	int size = 0;

	size += sizeof(int);
	size += 50*sizeof(char);
	size += 30*sizeof(char);
	size += 30*sizeof(Aluno*);

	return size;
}

/* Copia os valores do proximo aluno para as referências informadas */
void acessa_proximo_a(Aluno *aluno, int *matricula, char *nome, char *curso){
	if (aluno->proximo == NULL) return;
	
	acessa_a(aluno->proximo, matricula, nome, curso);
}

/* Atribui novos valores aos campos do proximo aluno */
void atribui_proximo_a(Aluno *aluno, Aluno *proximo){
	if (aluno->proximo == NULL) return;

	else{
		atribui_a(aluno->proximo, proximo->matricula, proximo->nome, proximo->curso);
	}
}

