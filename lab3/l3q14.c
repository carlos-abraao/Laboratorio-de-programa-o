#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comprimento (char* s){	
	int n = 0;

	for (int i = 0; s[i] != '\0'; i++)	n++;

	return n;	
}

void copia(char *orgin, char *desti){	
	int i;

	for (i = 0; orgin[i] != '\0'; i++)	desti[i] = orgin[i];
	
	desti[i] = '\0';
}

void concatena(char* dest, char* orig){
	int i = 0, j;	
	
	while (dest[i] != '\0')	i++;	

	for (j=0; orig[j] != '\0'; j++, i++) dest[i] = orig[j];
	
	dest[i] = '\0';
}

int compara (char* s1, char* s2){
	int i;
	
	for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
		if (s1[i] < s2[i])	return -1;
		else if (s1[i] > s2[i])	return 1;
	}
	
	if (s1[i]==s2[i]) return 0;         
	
	else if (s2[i]!= '\0') return -1;        

	else return 1;         
	
}

char* duplica(char* s){
	int n = comprimento(s);

	char* d = (char*) malloc ((n+1)*sizeof(char));

	strcpy(d,s);

	return d;
}

	void troca(char *string){

		for (int i = 0; string[i] != '\0'; i++){	

			if (string[i] >= 65 && string[i] <= 90) string[i] = string[i] + 32;

			else if (string[i] >= 97 && string[i] <= 122) string[i] = string[i] - 32;
		}
	}

int ocorrencia(char *string, char carac){

	int aux = 0;

	for (int i = 0; string[i] != '\0'; i++)
		if (string[i] == carac) aux++;

	return aux;

}

void remove(char *string, char caractere){
	int j = 0;
	char aux[strlen(string)];
	for (int i = 0; string[i] != '\0'; i++){
		if (string[i] != caractere){
			aux[j] = string[i];
			j++;
		}
	}

	for (int i = 0; string[i] != '\0'; i++) string[i] = aux[i];

}

void titulo(char *string){		

	if (string[0] >= 97 && string[0] <= 122) string[0] = string[0] - 32;	
}

void inverte(char *string){

	int j = comprimento(string)-1;
	
	char aux;

	for (int i = 0; i < comprimento(string)/2; ++i, --j){
		aux = string[j];		
		string[j] = string[i];
		string[i] = aux;
	}

}

int main (void){
	printf("\e[1;1H\e[2J");
	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 14:\n");
	
	char cidade[] = "RIO dE JaneIrO";

	printf("Antes da troca: \"%s\"\n", cidade);

	troca(cidade);

	printf("Depois da troca: \"%s\"\n", cidade);

	int oc = ocorrencia(cidade, 'i');

	printf("O caractere 'i' ocorre %d vezes em \"%s\"\n", oc, cidade);

	remove(cidade, ' ');

	printf("Após remoção de espaçõs: \"%s\"\n", cidade);

	titulo(cidade);

	printf("Após titulação: \"%s\"\n", cidade);

	inverte(cidade);

	printf("Após inversão: \"%s\"\n", cidade);	

	return 0;
}