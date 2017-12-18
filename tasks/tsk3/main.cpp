#include <stdio.h>
#include <stdlib.h>
#include "viagem.h"

int main(void){	

	printf("\e[1;1H\e[2J");

	Viagem *a, *b, *c, *d, *e, *f;

	a = nova_v(10, 5, 2017, "fortaleza", "Brasil", 15);
	b = nova_v(20, 8, 2017, "teresina", "Brasil", 365);
	c = nova_v(25, 12, 2017, "blumenau", "Brasil", 15);
	d = nova_v(10, 5, 2017, "cidaded", "paisd", 15);
	e = nova_v(20, 8, 2017, "cidadee", "paise", 10);
	f = nova_v(25, 12, 2017, "cidadef", "paisf", 36);

	int novodia, novomes, novoano;

	acrescperiodo(f, &novodia, &novomes, &novoano);

	printvig(f);

	printf("nova data: %d/%d/%d\n\n", novodia, novomes, novoano);

	/*
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

	Usuario * u5 = busca_amigo_u(u1, 3);

	adiciona_viagem_u(u1, b);	

	adiciona_viagem_u(u1, a);	

	adiciona_viagem_u(u1, c);

	adiciona_viagem_u(u1, c);	

	adiciona_viagem_u(u2, d);	

	adiciona_viagem_u(u3, e);	

	adiciona_viagem_u(u4, e);

	printvig(u1->viagens);

	printvig(u1->viagens->esquerda);

	printvig(u1->viagens->direita);

	printvig(u2->viagens);

	printvig(u3->viagens);

	printvig(u4->viagens);

	Usuario** T = filtrar_amigos_por_destino_viagem_u(u1, "cidadee","paise");

	printf("Amigos filtrados\n\n");

	for (int i = 0; i < u1->size_a; ++i)
	{
		printusr(T[i]);
	}*/

	//remover_viagem_u(u1, 2);	

	return 0;
}