#include <stdio.h>

int mdc(int x, int y){
	int r=1;
	while(1){
		r = x%y;
		if(r==0) return y;
		else{
			x = y;
			y = r;
		}
	}
}

int main(void) {

	printf("-------------Laboratório de programação 2-------------\n\n");
	printf("Questão 3:\n");

	int x, y, z;

	printf("Digite três números inteiros:\n");
	scanf("%d%d%d", &x, &y, &z);
	int a = mdc(mdc(x, y), z);
	printf("O MDC de %d, %d e %d é: %d\n", x, y, z, a);

	return 0;
}
