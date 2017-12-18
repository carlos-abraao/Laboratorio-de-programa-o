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

	usr -> viagens = NULL;//(Viagem*) malloc(sizeof(Viagem));

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
	
	while(p!=0){
		if(p > 30){			
			if (m + 1 > 12 ) m = 1;
			else m++;
			p = p - 30;
		}
		else if(d + p > 30){
			d = 30 - p - 1;
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
/*
int sobreposicao(Viagem* vig1, Viagem* vig2){
	int d1, m1, a1, p1, d2, m2, a2, p2;
	acrescperiodo(vig1, &d1, &m1, &a1);
	acrescperiodo(vig1, &d2, &m2, &a2);

	

}*/

void inserir(Viagem * &vig1, Viagem* vig2) {	
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

Viagem * VisitaEmOrdem(Viagem * vig, int id){
	if (vig != NULL) {
		VisitaEmOrdem(vig->esquerda, id);
		if(vig->ID == id) return vig;
		VisitaEmOrdem(vig->direita, id);
	}
	else return 0;
}

void adiciona_viagem_u(Usuario *usr, Viagem	*vig){
	if (VisitaEmOrdem(usr->viagens, vig->ID) != NULL){
		printf("\nViagem com ID repetido!\n");
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

void	remover_viagem_u(Usuario *usuario,	int	id){
	

}


Viagem	*listar_viagens_u(Usuario	*usuario);

Viagem	*buscar_viagem_por_data_u(Usuario	*usuario,	int	dia,	int	mes,	int	ano);

Viagem	*buscar_viagem_por_destino_u(Usuario	*usuario,	char	*cidade,	char	*pais);

Viagem *filtrar_viagens_amigos_por_data_u(Usuario *usuario,	int	dia,	int	mes,	int	ano);

Viagem *filtrar_viagens_amigos_por_destino_u(Usuario *usuario,	char	*cidade,	char	*pais);

Usuario *filtrar_amigos_por_data_viagem_u(Usuario *usuario,	int	dia,	int	mes,	int	ano);

Usuario *filtrar_amigos_por_destino_viagem_u(Usuario *usuario,	char	*cidade,	char	*pais);

void printvig(Viagem * vig){
	printf("vig-Id: %d\nVig data: %d/%d/%d\nVig cidade: %s\nvig pais: %s\nvig periodo: %d\n", vig->ID, vig->dia,vig->mes,vig->ano, vig->cidade, vig->pais, vig->periodo);
}

void printusr(Usuario * usr){
	printf("usr-Id: %d\nusr nome: %s\n", usr->ID, usr->nome);
}

void printusramgs(Usuario* usr){
	Usuario** lista = lista_amigos_u(usr);

	for (int i = 0; i < usr->size_a; i++)
	{
		printf("id amigo : %d\n", lista[i]->ID);
	}
}

int	tamanho_u();
