#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"

typedef struct elo {
	struct elo * next ;
	Elemento * val ;
} Elo ;

typedef struct {
	Elo * cabec ;
} Lista ;

Lista Lcria(void){
	Lista s;
	s->cabec = malloc(sizeof(Elo));
	s->cabec->next = s->cabec->val = NULL;
	return s;
}

void Ldestroi(Lista lista1){
	struct elo* crawler = lista1->cabec;
	while(crawler != NULL){
		struct elo* aux = crawler;
		crawler = crawler->next;
		free(aux->val);
		free(aux);		
	}
	return;
}

Lista Linsere(Lista lista1, Elemento* val){
	struct elo* crawler = lista1->cabec;
	while(crawler != NULL && crawler->val != NULL){
		crawler = crawler->next;		
	}
	if(crawler == NULL) return NULL;
	else{
		crawler->val = val;
		return crawler; 
	}	
}

Elemento* Lbusca(Lista lista1, char* n){
	struct elo* crawler = lista1->cabec;
	while(crawler != NULL){
		if(crawler->val != NULL && crawler->val->nome == n){
			return crawler;
		}
		crawler = crawler->next;		
	}
	return NULL;	
}

Elemento* Lretira(Lista lista1, Elemento* val){
	struct elo* crawler = lista1->cabec;
	while(crawler != NULL){
		if(crawler->val == val){
			crawler->val == NULL;
			return val;
		}
		crawler = crawler->next;		
	}
	return NULL;	
}



















































printf("




































printf("














































printf("

































printf("



























p\n", );\n", );\n", );\n", );
