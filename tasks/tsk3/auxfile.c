void	remover_viagem_u(Usuario *usr,	int	id){
	remove_aux(usr->viagens, id);
}

Viagem* VisitaEmOrdem(Viagem * vig, int id){
	if (vig != NULL) {
		VisitaEmOrdem(vig->esquerda, id);
		if(vig->ID == id) return vig;
		VisitaEmOrdem(vig->direita, id);
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

	aux = VisitaEmOrdem(vig, id);

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
		else{		
			Viagem* aux1 = aux->direito;
			free(aux);
			aux = aux1;	
		}
		break;
	case 2: //pussui dois filhos
		Viagem* aux1 = aux, antecessor = maior(aux->esquerdo);
		int dia, mes, ano, periodo; 
		char cidade[80], char pais[30];
		acessa_v(antecessor, &dia, &mes, &ano, &periodo, cidade, pais);
		atribui_v(aux, dia, mes, ano, cidade, pais, periodo);
		antecessor = aux1;
		remove_aux(aux->esquerdo, id);




	}




}
