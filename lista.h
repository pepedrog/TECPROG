#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"

//Implementação conforme a sugestão
typedef struct elo {
	struct elo * next ;
	Elemento * val ;
} Elo ;

typedef struct {
	Elo * cabec ;
} Lista ;


Lista Lcria(void){
	//Instanciando uma lista e alocando o primeiro endereço (cabec)
	Lista s;
	s.cabec = malloc(sizeof(Elo));
	//Definindo o próximo elo vazio (fim da lista)
	s.cabec->next = s.cabec->val = NULL;
	return s;
}

int stringsIguais(char* s1, char* s2)
{
	int i;
	for(i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
	if(s1[i] == '\0' && s2[i] == '\0') return 1;
	return 0;
}

void Ldestroi(Lista lista1){
	//Endereço de elo que percorrerá a lista
	struct elo* crawler = lista1.cabec;
	//Enquanto não chegar no final da lista
	while(crawler != NULL){
		//Salva o endereço do atual
		struct elo* aux = crawler;
		//Avança o crawler (para desalocar o próximo)
		crawler = crawler->next;
		//Limpa o atual
		//Tem erro aqui **************************** free(): invalid pointer *************** :/
		if(aux->val != NULL) printf("Estamos livrando o %s\n",aux->val->nome);
		free(aux->val);
		free(aux);
	}
	printf("livrou uma lista inteira\n");
	return;
}

struct elo* Linsere(Lista lista1, Elemento* val){
	//Percorre a lista até chegar no final (crawler == NULL) ou chegar em alguma posição vazia (crawler->val == NULL)
	struct elo* crawler = lista1.cabec;
	while(crawler != NULL && crawler->val != NULL){
		//Achando o último elemento da lista e inserindo mais um
		if(crawler->next == NULL)
		{
			struct elo* proximo = malloc(sizeof(Elo));
			proximo->val = val;
			proximo->next = NULL;	
			crawler->next = proximo;
			return (crawler->next);
		
		}
		crawler = crawler->next;
	}
	
	//Se achou uma posição sem valor, podemos apenas inserir
	if(crawler != NULL) crawler->val = val;
	return crawler;
}

Elemento* Lbusca(Lista lista1, char* n){
	//Mesma estrutura do insere, percorre a lista até achar ou chegar no final
	struct elo* crawler = lista1.cabec;
	while(crawler != NULL){
		if(crawler->val != NULL && stringsIguais(crawler->val->nome, n)){
			return crawler;
		}
		crawler = crawler->next;
	}
	return NULL;
}

Elemento* Lretira(Lista lista1, Elemento* val){
	//Percorre a lista até encontrar o elemento
	struct elo* crawler = lista1.cabec;
	while(crawler != NULL){
		if(crawler->val == val){
			//Apaga o antigo valor e anula o ponteiro
			free(crawler->val->nome);
			crawler->val = NULL;
			return val;
		}
		crawler = crawler->next;
	}
	return NULL;
}
