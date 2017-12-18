#include <stdio.h>
#include <stdlib.h>
#include "viagem.h"
//#include "usuario.h"

int main(void){	

	printf("Hello World!!\n");

	Viagem *a, *b, *c;

	a = nova_v(10, 5, 2017, "fortaleza", "Brasil", 15);
	b = nova_v(20, 8, 2017, "teresina", "Brasil", 10);
	c = nova_v(25, 12, 2017, "blumenau", "Brasil", 15);

	int ID, dia, mes, ano, per;
	char cidade[80], pais[30];
	
	acessa_v(a, &dia, &mes, &ano, &per, cidade, pais);	
	
	atribui_v (a, 15, 7, 2016, "tallinn", "Estonia", 45);	

	//atribui_direita_v(a, b);

	//atribui_esquerda_v(a, c);

	Viagem *d = acessa_esquerda_v(a);

	Usuario * u1 = novo_u(1, "Abraao");	

	int id;
	char teste[30];
	acessa_u(u1, &id, teste);	

	atribui_u(u1, 4, "cabraao");	

	Usuario *u2 = novo_u(2, "ssarah");

	Usuario *u3 = novo_u(3, "gabriel");	

	Usuario *u4 = novo_u(4, "passat");	

	adiciona_amigo_u(u1, u2);

	adiciona_amigo_u(u1, u2);

	adiciona_amigo_u(u1, u3);

	adiciona_amigo_u(u1, u4);

	Usuario * u5 = busca_amigo_u(u1, 3);

	adiciona_viagem_u(u1, b);	

	adiciona_viagem_u(u1, a);	

	adiciona_viagem_u(u1, c);

	adiciona_viagem_u(u1, c);

	printf("size_v : %d\n", u1->size_v);

	printvig(u1->viagens->esquerda);

	printvig(u1->viagens->direita);

	printf("\n\n%d\n", maiorvig(b,c));

	system("pause");

	return 0;
}