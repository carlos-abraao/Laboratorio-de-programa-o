#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0;

    int vetAux[fim-comeco+1];


    while(com1<=meio && com2<=fim){

        if(vetor[com1] <= vetor[com2]){

            vetAux[comAux] = vetor[com1];

            com1++;

        }else{

            vetAux[comAux] = vetor[com2];

            com2++;

        }

        comAux++;

    }


    while(com1<=meio){  //Caso ainda haja elementos na primeira metade

        vetAux[comAux] = vetor[com1];

        comAux++;com1++;

    }


    while(com2<=fim){   //Caso ainda haja elementos na segunda metade

        vetAux[comAux] = vetor[com2];

        comAux++;com2++;

    }


    for(comAux=comeco;comAux<=fim;comAux++){    //Move os elementos de volta para o vetor original

        vetor[comAux] = vetAux[comAux-comeco];

    }

}


void mergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim) {

        int meio = (fim+comeco)/2;


        mergeSort(vetor, comeco, meio);

        mergeSort(vetor, meio+1, fim);

        merge(vetor, comeco, meio, fim);

    }

}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 8:\n");

	int n, *seq;

	printf("Digite o tamanho inicial do vetor:\n");
	scanf("%d", &n);
	seq = (int*) malloc(n*sizeof(int));

	printf("Digite os valores do vetor:\n");
	for(int i = 0; i< n; i++)
		scanf("%d", &seq[i]);			

	printf("Vetor pré ordenação:\n");
	for(int i = 0; i< n; i++)
		printf(" %d ", seq[i]);

	printf("\nVetor pós ordenação:\n");

	mergeSort(seq, 0, n-1);

	for(int i = 0; i< n; i++)
		printf(" %d ", seq[i]);

	printf("\n");	
	
	return 0;
}
