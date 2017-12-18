/*
 * Universidade Federal do Ceara, 2014.2
 * Estruturas de Dados (CK0109)
 * Implementacao rudimentar de arvores binarias
 * Tiberius O. Bonates.
 */
#include <iostream>
using namespace std;

// Registro que armazena um valor (chave) e ponteiros para filhos do no
struct NoAB {
	int chave;     // Informacao relevante para a aplicacao
	NoAB *fe; // Filho esquerdo
	NoAB *fd; // Filho direito
};

bool ehFolha(NoAB *p) {
	if (p != NULL)
		return (p->fe == NULL) && (p->fd == NULL);
	else
		return false; // Se a arvore e' vazia, retornamos 'false'
}

int numFolhas(NoAB *p) {
	if (p == NULL)
		return 0;
	else {
		if (ehFolha(p))
			return 1;
		return numFolhas(p->fe) + numFolhas(p->fd);
	}
}

int max(int a, int b) { return (a>b)? a : b; }

int h(NoAB *p) {	//altura
	if (p == NULL)
		return -1;
	else {
		if (ehFolha(p))
			return 0;
		else
			return max(h(p->fe), h(p->fd)) + 1;
	}
}

int main(void) {

	NoAB raiz;
	raiz.chave = 5;
	raiz.fe = NULL;
	raiz.fd = NULL;
	//---------------------
	raiz.fd = new NoAB;
	raiz.fd->chave = 2;
	raiz.fd->fe = NULL;
	raiz.fd->fd = NULL;

	raiz.fe = new NoAB;
	raiz.fe->chave = 10;
	raiz.fe->fe = NULL;
	raiz.fe->fd = NULL;

	raiz.fd->fe = new NoAB;
	raiz.fd->fe->chave = 16;
	raiz.fd->fe->fe = NULL;
	raiz.fd->fe->fd = NULL;

	raiz.fd->fd = new NoAB;
	raiz.fd->fd->chave = 4;
	raiz.fd->fd->fe = NULL;
	raiz.fd->fd->fd = NULL;

	cout << "Numero de folhas eh: " << numFolhas( &raiz ) << endl;
	cout << "A altura eh: " << h( &raiz ) << endl;

	getchar();
	return 0;
}