#include <stdio.h>
#include <stdbool.h>

#define N 8
int seqf[N+1];

void sequencia(int seq1[], int seq2[]){	
	bool carry;
	for (int i = 0; i <= N; ++i){
		seqf[i] = 0;
	}
	for (int i = N-1, j = N; i >=0; --i, --j){
		if ((seq1[i] + seq2[i]) >= 10) carry = 1;
		else carry = 0;
		
		if(carry == 1){
			seqf[j] += seq2[i] + seq1[i] - 10;
			seqf[j-1] += 1;
		}
		else{
			seqf[j] += seq1[i] + seq2[i];
		}
	}
}

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 5:\n");

	int a[N] = {8, 2, 4, 3, 4, 2, 5, 1}, b[N] = {3, 3, 7, 5, 2, 3, 3, 7};
	
	for (int i = 0; i < N; ++i){
		printf(" %d", a[i]);
	}
	printf("\n+\n");
	for (int i = 0; i < N; ++i){
		printf(" %d", b[i]);
	}
	printf("\n=\n");
	sequencia(a, b);
	for (int i = 0; i <= N; ++i){
		printf("%d ", seqf[i]);
	}

	printf("\n");
	
	return 0;
}