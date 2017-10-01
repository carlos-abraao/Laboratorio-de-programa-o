#include <stdio.h>

int main(void) {

	printf("-------------Laboratório de programação 3-------------\n\n");
	printf("Questão 1:\n");

	int a[5] = {2, 4, 6, 8, 10}, b[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(a[i] == b[j]) printf("%d ", a[i]);
		}
	}

	printf("\n");	

	return 0;
}