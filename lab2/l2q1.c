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
	printf("Questão 1:\n");

	int x, y;

	printf("Digite dois números inteiros:\n");
	scanf("%d%d", &x, &y);
	int a = mdc(x, y);
	printf("O MDC de %d e %d é: %d\n", x, y, a);

	return 0;
}