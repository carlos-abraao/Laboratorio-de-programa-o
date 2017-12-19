#include <stdio.h>
#include <stdlib.h>
#include "viagem.h"

int main(void){	

	//printf("\e[1;1H\e[2J");

	Viagem *a, *b, *c, *d, *e, *f;

	a = nova_v(10, 5, 2017, "fortaleza", "Brasil", 15);
	b = nova_v(20, 8, 2017, "teresina", "Brasil", 10);
	c = nova_v(25, 12, 2017, "blumenau", "Brasil", 15);
	d = nova_v(10, 5, 2017, "cidaded", "paisd", 15);
	e = nova_v(20, 8, 2017, "cidadee", "paise", 10);
	f = nova_v(25, 8, 2017, "cidadef", "paisf", 3);	
	
	int ID, dia, mes, ano, per;
	char cidade[80], pais[30];
	
	acessa_v(a, &dia, &mes, &ano, &per, cidade, pais);	
	
	atribui_v (a, 15, 7, 2016, "tallinn", "Estonia", 45);	
	//atribui_direita_v(a, b);
	//atribui_esquerda_v(a, c);	
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
	printf("cheguei aqui 1\n\n");
	adiciona_viagem_u(u1, b);	
	printf("cheguei aqui 2\n\n");
	adiciona_viagem_u(u1, a);	
	printf("cheguei aqui 3\n\n");
	adiciona_viagem_u(u1, c);
	printf("cheguei aqui 4\n\n");
	adiciona_viagem_u(u1, c);
	printf("cheguei aqui 5\n\n");
	adiciona_viagem_u(u1, e);
	printf("cheguei aqui 6\n\n");
	adiciona_viagem_u(u1, f);

	listar_viagens_u(u1);
	


	system("pause");

	return 0;
}