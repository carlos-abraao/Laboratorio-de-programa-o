#include <stdio.h>

void misterio(int *p, int *q){
	int temp;
	temp = *p;
	printf("%d\n",*temp );
	*p = *q;
	*q = temp;
}

int main(void) {

	printf("-------------Laboratório de programação 2-------------\n\n");
	printf("Questão 5:\n");

	int i=6, j=10;
	printf("Antes de mistério:\ni = %d\nj = %d\n", i, j);
	misterio(&i, &j);
	printf("Depois de mistério:\ni = %d\nj = %d\n", i, j);

	return 0;
}
