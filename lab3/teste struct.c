#include <stdio.h>
#include <stdlib.h>

struct ponto
{
	int x;
	int y;
}Ponto;

typedef struct ponto *PPonto;

int main(void)
{
	Ponto p;

	scanf("%d%d", &p.x, &(p.y));

	printf("%d %d\n", p.x, p.y);
	return 0;
}