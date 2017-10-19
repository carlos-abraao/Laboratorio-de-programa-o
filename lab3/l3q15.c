#include <stdio.h>
#include <stdlib.h>

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

void remover(char *string, char caractere){
	int j = 0, i;
	char aux[comprimento(string)+1];
	for (i = 0; string[i] != '\n'; i++){
		if (string[i] != caractere){
			aux[j] = string[i];
			j++;
		}
	}
	aux[j] = '\0';


	for (i = 0; string[i] != '\0'; i++) string[i] = aux[i];

}

char* duplica(char* s){
	int n = comprimento(s);

	char* d = (char*) malloc ((n+1)*sizeof(char));

	copia(s,d);

	return d;
}

void inverte(char *string){

	int j = comprimento(string)-1;
	
	char aux;

	for (int i = 0; i < j; ++i, --j){
		aux = string[j];		
		string[j] = string[i];
		string[i] = aux;
	}
}

int compara (char* s1, char* s2){
	int i;
	
	for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
		if (s1[i] < s2[i])	return -1;
		else if (s1[i] > s2[i])	return 1;
	}
	
	if (s1[i]==s2[i]) return 0;         
	
	else if (s2[i] != '\0') return -1;        

	else return 1;         
	
}

int palindromo(char *string){

	char *ginrts;
	int aux;

	remover(string, ' ');	

	ginrts = duplica(string);

	inverte(ginrts);

	aux = compara(string, ginrts);

	if(aux == 0) return 1;
	else return 0;

}


int main(void) {
	printf("\e[1;1H\e[2J");
	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 15:\n");

	char *string = (char*) malloc ((256)*sizeof(char));

	if (string == NULL) {
        printf ("Sem memória\n");
        return 1;
    }

	int test;

	printf("Digite uma string com até 255 caracteres:\n");

	fgets(string, 256, stdin);

	test = palindromo(string);

	if (test == 1) printf("É palindromo!\n");
	
	else printf("Não é palindromo.\n");	
	
	return 0;
}
