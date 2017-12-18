void remover_viagem_u(Usuario *usr,	int	id){
	remove_aux(usr->viagens, id);
}

Viagem* EmOrdemId(Viagem * vig, int id){
	if (vig != NULL) {
		EmOrdemId(vig->esquerda, id);
		if(vig->ID == id) return vig;
		EmOrdemId(vig->direita, id);
	}
	else return 0;
}

Viagem * maior(Viagem *vig) {
	if (vig == NULL) return NULL;
		
	if (vig->direita != NULL) return maior(vig->direita);		

	return vig;
}


void remove_aux(Viagem * vig, int id){
	if(vig == NULL) return;

	Viagem* aux;

	aux = EmOrdemId(vig, id);

	if(aux == NULL) return;

	int nfilhos = (aux->esquerdo? 1:0) + (aux->direito? 1:0);

	switch(nfilhos){
	case 0: //folha
		free(aux);
		aux = NULL;
		break;
	case 1: //apenas um filho
		if(aux->esquerdo != NULL){//possui filho esquerdo
			Viagem* aux1 = aux->esquerdo;
			free(aux);
			aux = aux1;
		}
		else{//possui filho esquerdo		
			Viagem* aux1 = aux->direito;
			free(aux);
			aux = aux1;	
		}
		break;
	case 2: //pussui dois filhos		
		// Obter ponteiro para antecessor
		// (antecessor é o maior elemento da subarvore esquerda)

		Viagem* aux1 = aux, antecessor = maior(aux->esquerdo);
		//Trocar os dados entre o atual e o antecessor.
		int dia, mes, ano, periodo;

		char cidade[80], char pais[30];

		aux->ID = antecessor->ID;

		acessa_v(antecessor, &dia, &mes, &ano, &periodo, cidade, pais);

		atribui_v(aux, dia, mes, ano, cidade, pais, periodo);

		antecessor->ID = aux->ID;

		acessa_v(aux1, &dia, &mes, &ano, &periodo, cidade, pais);

		atribui_v(antecessor, dia, mes, ano, cidade, pais, periodo);

		remove_aux(aux->esquerdo, id);
	}

}
