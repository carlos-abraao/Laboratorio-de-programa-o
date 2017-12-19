///////////////////////////////////////////////////////////////////////////////////////////////////////
//VIAGEM.H
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <stdlib.h>

struct viagem{
	int ID;
	int dia;
	int mes;
	int ano;
	int periodo;
	char cidade[81];
	char pais[31];	
	viagem *direita;
	viagem *esquerda;	
};

typedef	struct	viagem	Viagem;

int vigID = 1;

Viagem	*nova_v(int	dia, int mes, int ano, char *cidade, char *pais, int periodo){
	Viagem* vig = (Viagem*) malloc(sizeof(Viagem));

	if (vig == NULL){
		printf("Memória insuficiente!\n");
		exit(1);
	}
	vig -> ID = vigID++;

	if(dia > 30 || dia < 1 || mes > 12 || mes < 1 || strlen(cidade) > 80 || strlen(pais) > 30) return NULL;

	vig -> dia = dia;
	vig -> mes = mes;
	vig -> ano = ano;
	vig -> periodo = periodo;
	
	int i;

	for (i=0; cidade[i] != '\0'; i++)	vig->cidade[i] = cidade[i];	
	
	vig->cidade[i] = '\0';

	for (i=0; pais[i] != '\0'; i++)	vig->pais[i] = pais[i];	
	
	vig->pais[i] = '\0';
	
	vig->esquerda = NULL;

	vig->direita = NULL;
	
	return vig;
}

void	libera_v(Viagem **viagem){
	if(*viagem == NULL) return;	
	
	free(*viagem);
	*viagem = NULL;
}

void acessa_v(Viagem *vig, int *dia, int *mes, int *ano, int *periodo, char *cidade, char *pais){
	if(vig == NULL) return;	

	*dia	 = vig->dia;
	*mes	 = vig->mes;
	*ano     = vig->ano;
	*periodo = vig->periodo;	

	int i;

	for (i=0; vig->cidade[i] != '\0'; i++) cidade[i] = vig->cidade[i];	
	
	cidade[i] = '\0';

	for (i=0; vig->pais[i] != '\0'; i++) pais[i] = vig->pais[i];	
	
	pais[i] = '\0';

}

void atribui_v(Viagem *vig,	int	dia, int mes, int ano, char	*cidade, char *pais, int periodo){

	if(dia > 30 || dia < 1 || mes > 12 || mes < 1 || strlen(cidade) > 80 || strlen(pais) > 30) return;
	
	vig -> dia		= dia;
	vig -> mes		= mes;
	vig -> ano		= ano;
	vig -> periodo	= periodo;

	int i;

	for (i=0; cidade[i] != '\0'; i++)	vig->cidade[i] = cidade[i];	
	
	vig->cidade[i] = '\0';

	for (i=0; pais[i] != '\0'; i++)	vig->pais[i] = pais[i];	
	
	vig->pais[i] = '\0';
}

void atribui_direita_v(Viagem *vig,	Viagem *dir){
	if(vig == NULL || dir == NULL) return;

	if(vig->direita == NULL) vig->direita = (Viagem*) malloc(sizeof(Viagem));;

	vig->direita->ID = vigID++;
	
	atribui_v(vig -> direita, dir ->dia, dir->mes,	dir->ano, dir->cidade,	dir->pais,	dir->periodo);
}

Viagem	*acessa_direita_v(Viagem *viagem){
	if (viagem == NULL || viagem->direita == NULL) return NULL;

	return viagem->direita;	
}

void	atribui_esquerda_v(Viagem	*vig,	Viagem	*esq){
	if(vig == NULL || esq == NULL) return;

	if(vig->esquerda == NULL) vig->esquerda = (Viagem*) malloc(sizeof(Viagem));

	vig->esquerda->ID = vigID++;
	
	atribui_v(vig -> esquerda, esq ->dia, esq->mes,	esq->ano, esq->cidade,	esq->pais,	esq->periodo);
}

Viagem	*acessa_esquerda_v(Viagem	*viagem){	
	if (viagem == NULL || viagem->esquerda == NULL) return NULL;

	return viagem->esquerda;	
}

int	tamanho_v(){
	int size = 0;
	size += 5+sizeof(int);
	size += 112*sizeof(char);	
	size += 2*sizeof(Viagem*);
	return size;	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//USUARIO.H
///////////////////////////////////////////////////////////////////////////////////////////////////////

struct usuario{
	int ID;
	char nome[81];
	usuario* *amigos;
	int size_a;
	viagem* viagens;
	int size_v;
};

typedef	struct	usuario Usuario;

Usuario *novo_u(int	id,	char *nome){
	Usuario* usr = (Usuario*) malloc(sizeof(Usuario));

	if(strlen(nome) > 80) return NULL;

	usr -> ID = id;

	int i;

	for (i=0; nome[i] != '\0'; i++)	usr->nome[i] = nome[i];	
	
	usr->nome[i] = '\0';

	usr -> amigos = (usuario**) malloc(sizeof(usuario*));

	usr -> size_a = 0;

	usr -> viagens = NULL;

	usr -> size_v = 0;

	return usr;
}

void libera_u(Usuario **usr){
	if(usr == NULL) return;

	free(*usr);
	*usr = NULL;
}

void acessa_u(Usuario *usr,	int	*id, char *nome){
	*id = usr->ID;

	int i;

	for (i=0; usr->nome[i] != '\0'; i++) nome[i] = usr->nome[i];	
	
	nome[i] = '\0';
}

void atribui_u(Usuario *usr, int id, char *nome){
	if(strlen(nome) > 80) return;

	usr ->ID = id;

	int i;

	for (i=0; nome[i] != '\0'; i++)	usr->nome[i] = nome[i];	
	
	usr->nome[i] = '\0';
}

void adiciona_amigo_u(Usuario *usr,	Usuario *amigo){

	if(usr->size_a != 0){
		for(int i = 0; i <usr->size_a; i++){
			if (usr->amigos[i]->ID == amigo->ID){
				printf("Amigo com ID repetido!\n\n");
				return;
			}
		}
	}

	usr->amigos = (Usuario **) realloc(usr->amigos, (usr -> size_a + 2 )*sizeof(usuario) ); //dessa maneira sempre deixo uma posição extra alocada

	usr->amigos[usr->size_a] = amigo;

	usr->size_a++;
}

void remove_amigo_u(Usuario *usr, int id){

	if(usr->size_a == 0) return;

	int test = 0, j=0;

	usuario* *amgs = (usuario**) malloc((usr->size_a + 1)*sizeof(usuario*));

	for(int i = 0; i < usr->size_a; i++){
		if(usr->amigos[i]->ID != id) amgs[j++] = usr->amigos[i];

		else{
			test = 1;
			amgs = (Usuario **) realloc(amgs, (usr -> size_a)*sizeof(usuario));
		} 
	}

	if (test == 1) usr->size_a--;

	usr->amigos = amgs;	
}

Usuario *busca_amigo_u(Usuario *usr, int	id){
	for(int i = 0; i < usr->size_a; i++){
		if(usr->amigos[i]->ID == id) return usr->amigos[i];
	}

	return NULL;
}

Usuario **lista_amigos_u(Usuario *usr){
	if(usr->size_a == 0) return NULL;

	Usuario ** lista = (Usuario**) malloc((usr->size_a)*sizeof(Usuario*));

	for(int i = 0; i < usr->size_a; i++){
		lista[i] = novo_u(usr->amigos[i]->ID, usr->amigos[i]->nome);		
	}

	return lista;
}

int maiorvig(Viagem* vig1, Viagem* vig2){
	if(vig1 == NULL || vig2 == NULL) return -1;

	if(vig1->ano == vig2->ano) {
		if(vig1->mes == vig2->mes) {
			if (vig1->dia == vig2->dia ) return 0;

			else if(vig1->dia > vig2->dia) return 1;

			else return 2;
		}

		else if (vig1->mes > vig2->mes) return 1;

		else return 2;
	}
	else if( vig1->ano > vig2->ano ) return 1;

	else return 2;
	
}

void acrescperiodo(Viagem *vig, int* daux, int* maux, int* aaux){
	int p = vig->periodo;
	int d, m, a;
	d = vig->dia;
	m = vig->mes;
	a = vig->ano;
	
	while(p != 0){
		if(p > 30){			
			m++;
			if (m > 12 ){ 
				m = 1;
				a++;
			}
			p = p - 30;
		}
		else if(d + p > 30){
			d = (d + p) - 30;			
			if (m + 1 > 12 ){ 
				m = 1;
				a++;
			}
			else m++;
			p = 0;
		}
		else{
			d = d + p;
			p = 0;
		} 
	}

	*daux = d;
	*maux = m;
	*aaux = a;
}

int sobreposicao(Viagem* vig1, Viagem* vig2){
	int d1, m1, a1, p1, d2, m2, a2, p2, test;

	acrescperiodo(vig1, &d1, &m1, &a1);

	acrescperiodo(vig2, &d2, &m2, &a2);

	if(a2 >= vig1->ano && a2 <= a1){
		if(m2 >= vig1->mes && m2 <= m1){
			if(d2 >= vig1->dia && d2 <= d1){
				return 1;
			}
		}
	}

	if(vig2->ano >= vig1->ano && vig2->ano <= a1){
		if(vig2->ano >= vig1->mes && vig2->ano <= m1){
			if(vig2->ano >= vig1->dia && vig2->ano <= d1){
				return 1;
			}
		}
	}

	return 0;
}


void inserir(Viagem * &vig1, Viagem* vig2) {
	/* O procedimento de sobreosição, sozinho, está correto. No entanto a chamada dele, dentro da função inserir, se mostrou problemática. Mais especificamente na função de acrescentar
	if (sobreposicao(vig1, vig2) == 1){
		printf("Viagem com sobreposição\n\n");
		return;
	}
	*/
	if (vig1 == NULL){ //cheguei numa folha, que vai rceber o novo valor
		vig1 = (Viagem*) malloc(sizeof(Viagem));
		vig1 = vig2;		
	}
	else if (maiorvig(vig1, vig2) == 1 || (maiorvig(vig1, vig2) == 0)){
		inserir( vig1->esquerda, vig2);
	}
	else if (maiorvig(vig1, vig2) == 2){
		inserir( vig1->direita, vig2);
	}	
}

//percorre a arvore em ordem e retorna de acorda com o id
Viagem * EmOrdemId(Viagem * vig, int id){
	if (vig != NULL) {
		EmOrdemId(vig->esquerda, id);
		if(vig->ID == id) return vig;
		EmOrdemId(vig->direita, id);
	}
	else return NULL;
}

void adiciona_viagem_u(Usuario *usr, Viagem	*vig){
	if (EmOrdemId(usr->viagens, vig->ID) != NULL){
		printf("Viagem com ID repetido!\n\n");
		return;
	}
	if(usr->viagens == NULL){
		usr->viagens = (Viagem*) malloc(sizeof(Viagem));
		usr->viagens = vig;
		usr->size_v = 1;
	}
	else{
		if (maiorvig(usr->viagens, vig) == 1){
			usr->size_v++;
			inserir(usr->viagens->esquerda, vig);
		}
		else if (maiorvig(usr->viagens, vig) == 2){
			usr->size_v++;
			inserir(usr->viagens->direita, vig);
		}
	}		
}

//Retorna um ponteiro para o maior elemento da subávore
Viagem * maiorSub(Viagem *vig) {
	if (vig == NULL) return NULL;
		
	if (vig->direita != NULL) return maiorSub(vig->direita);		

	return vig;
}

void remove_viagem_aux(Viagem * vig, int id){
	if(vig == NULL) return;

	Viagem* aux;

	aux = EmOrdemId(vig, id);

	if(aux == NULL) return;

	int nfilhos = (aux->esquerda? 1:0) + (aux->direita? 1:0);

	switch(nfilhos){
	case 0: //folha
		//Viagem* aux1;
		libera_v(&aux);		
		aux = NULL;
		break;
	case 1: //apenas um filho
		if(aux->esquerda != NULL){//possui filho esquerda
			Viagem* aux1 = aux->esquerda;
			libera_v(&aux);
			aux = aux1;
		}
		else{//possui filho esquerda		
			Viagem* aux1 = aux->direita;
			libera_v(&aux);
			aux = aux1;	
		}
		break;
	case 2: //pussui dois filhos		
		// Obter ponteiro para antecessor
		// (antecessor é o maior elemento da subarvore esquerda)

		Viagem* aux1;

		Viagem* antecessor = maiorSub(aux->esquerda);
		//Trocar os dados entre o atual e o antecessor e depois chamar o procedimento novamente com o atual na nova posição
		int dia, mes, ano, periodo;

		char cidade[80], pais[30];

		aux1->ID = aux->ID;

		acessa_v(aux, &dia, &mes, &ano, &periodo, cidade, pais);

		atribui_v(aux1, dia, mes, ano, cidade, pais, periodo);

		aux->ID = antecessor->ID;

		acessa_v(antecessor, &dia, &mes, &ano, &periodo, cidade, pais);

		atribui_v(aux, dia, mes, ano, cidade, pais, periodo);

		antecessor->ID = aux1->ID;

		acessa_v(aux1, &dia, &mes, &ano, &periodo, cidade, pais);

		atribui_v(antecessor, dia, mes, ano, cidade, pais, periodo);

		remove_viagem_aux(aux->esquerda, id);
	}

}

void remover_viagem_u(Usuario *usr,	int	id){
	//procedimento remover não funcionando corretamente
	remove_viagem_aux(usr->viagens, id);
}

void printvig(Viagem * vig){

	if(vig == NULL){
		printf("Viagem inválida\n\n");
		return;
	}

	printf("vig Id: %d\nVig data: %d/%d/%d\nVig cidade: %s\nvig pais: %s\nvig periodo: %d\n\n", vig->ID, vig->dia,vig->mes,vig->ano, vig->cidade, vig->pais, vig->periodo);
}

void printusr(Usuario * usr){
	if(usr == NULL){
		printf("Usuario inválido\n\n");
		return;
	}
	printf("usr Id: %d\nusr nome: %s\n\n", usr->ID, usr->nome);
}

void printusramgs(Usuario* usr){
	Usuario** lista = lista_amigos_u(usr);

	for (int i = 0; i < usr->size_a; i++)
	{
		printf("id amigo : %d\n", lista[i]->ID);
	}
}

void visita(Viagem* vig){
	printvig(vig);
}

// Efetua um percurso em-ordem
void VemOrdem(Viagem* vig) {
	if (vig != NULL) {
		VemOrdem(vig->esquerda);
		visita(vig);
		VemOrdem(vig->direita);
	}
}

void listar_viagens_u(Usuario *usr){
	//Não consegui retornar uma lista para viagens, esse procedimento apenas as imprime
	VemOrdem(usr->viagens);
}

//percorre a arvore em ordem e retorna de acorda com a data
Viagem * EmOrdemData(Viagem * vig, int	dia,	int	mes,	int	ano){
	if (vig != NULL) {
		EmOrdemData(vig->esquerda, dia, mes, ano);
		if(vig->dia == dia && vig->mes == mes && vig->ano == ano) return vig;
		EmOrdemData(vig->direita, dia, mes, ano);
	}
	else return NULL;
}

Viagem	*buscar_viagem_por_data_u(Usuario	*usr,	int	dia,	int	mes,	int	ano){
	if(usr->size_v == 0) return NULL;

	Viagem* vig;

	vig = EmOrdemData(usr->viagens, dia, mes, ano);

	return vig;
};

//percorre a arvore em ordem e retorna de acorda com o destino
Viagem * EmOrdemDestino(Viagem * vig, char *cidade, char *pais){
	if (vig != NULL) {
		EmOrdemDestino(vig->esquerda,  cidade, pais);
		if( (strcmp(vig->cidade, cidade) == 0) && (strcmp(vig->pais, pais) == 0) ) return vig;
		EmOrdemDestino(vig->esquerda,  cidade, pais);
	}
	else return NULL;
}

Viagem	*buscar_viagem_por_destino_u(Usuario	*usr,	char	*cidade,	char	*pais){
	if(usr->size_v == 0) return NULL;

	Viagem* vig;

	vig = EmOrdemDestino(usr->viagens, cidade, pais);

	return vig;
}

Viagem* *filtrar_viagens_amigos_por_data_u(Usuario *usr,	int	dia,	int	mes,	int	ano){

	if(usr->size_a == 0) return NULL;

	// um vetor de viagem* com tamanho da qtde de amigos do usuario, onde cada posição é uma viagem de um amigo
	Viagem ** lista = (Viagem**) malloc((usr->size_a)*sizeof(Viagem*));

	//para cada amigo de usr, verifico se alguma viagem que atende a restrição de data.
	for(int i = 0; i < usr->size_a; i++){
		lista[i] = buscar_viagem_por_data_u(usr->amigos[i], dia, mes, ano);
	}

	//nova lista que só vai conter valores não nulos
	Viagem ** lista1 = (Viagem**) malloc((usr->size_a)*sizeof(Viagem*));

	int j = 0;

	for(int i = 0; i < usr->size_a; i++){
		if(lista[i] != NULL){
			lista1[j] = lista[i];
			j++;
		}
	}	

	//realocando nova lista para ocupar só o espaço necessário
	lista1 = (Viagem **) realloc(lista1, (j+1)*sizeof(Viagem));

	return lista1;
}

Viagem **filtrar_viagens_amigos_por_destino_u(Usuario *usr,	char	*cidade,	char	*pais){

	if(usr->size_a == 0) return NULL;

	Viagem ** lista = (Viagem**) malloc((usr->size_a)*sizeof(Viagem*));

	for(int i = 0; i < usr->size_a; i++){
		lista[i] = buscar_viagem_por_destino_u(usr->amigos[i], cidade, pais);
	}

	Viagem ** lista1 = (Viagem**) malloc((usr->size_a)*sizeof(Viagem*));

	int j = 0;

	for(int i = 0; i < usr->size_a; i++){
		if(lista[i] != NULL){
			lista1[j] = lista[i];
			j++;
		}
	}	

	lista1 = (Viagem **) realloc(lista1, (j+1)*sizeof(Viagem));

	return lista1;
}

Usuario **filtrar_amigos_por_data_viagem_u(Usuario *usr,	int	dia,	int	mes,	int	ano){
	if(usr->size_a == 0) return NULL;

	Usuario ** lista = (Usuario**) malloc((usr->size_a)*sizeof(Usuario*));

	int j = 0;

	for(int i = 0; i < usr->size_a; i++){
		if(buscar_viagem_por_data_u(usr->amigos[i], dia, mes, ano) != NULL){			
			lista[j++] = novo_u(usr->amigos[i]->ID, usr->amigos[i]->nome);
		}
	}

	lista = (Usuario **) realloc(lista, (j+1)*sizeof(Usuario));

	return lista;
}

Usuario **filtrar_amigos_por_destino_viagem_u(Usuario *usr,	char	*cidade,	char	*pais){
	if(usr->size_a == 0) return NULL;

	Usuario ** lista = (Usuario**) malloc((usr->size_a)*sizeof(Usuario*));

	int j = 0;

	for(int i = 0; i < usr->size_a; i++){
		if(buscar_viagem_por_destino_u(usr->amigos[i], cidade, pais) != NULL){			
			lista[j++] = novo_u(usr->amigos[i]->ID, usr->amigos[i]->nome);
		}
	}

	lista = (Usuario **) realloc(lista, (j+1)*sizeof(Usuario));

	return lista;	
}

int	tamanho_u(){
	int size = 0;
	size += 3+sizeof(int);
	size += 81*sizeof(char);	
	size += sizeof(Viagem*);
	size += sizeof(usuario**);
	return size;
}

