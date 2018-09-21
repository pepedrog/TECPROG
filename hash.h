//#include <stdlib.h>
#include <stdio.h>
#include "lista.h"



typedef struct TabSim{
	int size;
	Lista* listas;
} TabSim;

int hash(char* s, int mod){
	long long int out = 0;
	for(int i = 0; s[i] != '\0'; i++){
		out = out*257 + (int) s[i];
		out %= mod;
	}
	return out;
}

TabSim Tcria(int tam){
	TabSim tabela;
	tabela.listas = malloc(tam*sizeof(Lista));
	tabela.size = tam;
	for(int i = 0; i < tam; i++){
		tabela.listas[i] = Lcria();
	}
	return tabela;
}

void Tdestroi(TabSim t){
	for(int i = 0; i < t.size; i++){
		Ldestroi(t.listas[i]);
	}
	free(t.listas);
	return;
}

int Tinsere(TabSim t, char *n, Elemento *val){
	int hash_val = hash(n, t.size);
	printf("Hash do elemento: %d\n", hash_val);
	return Linsere(t.listas[hash_val], val)==NULL?0:1;
}

Elemento* Tbusca(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	return Lbusca(t.listas[hash_val], n);
}

int Tretira(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	struct elo* crawler = t.listas[hash_val].cabec; Elemento* out = NULL;
	struct elo* last = crawler;
	while(crawler != NULL){
		if(crawler->val != NULL && crawler->val->nome == n){
			last->next = crawler->next;
			free(crawler->val);
			free(crawler);
			return 1;
		}
		last = crawler;
		crawler = crawler->next;
	}
	return 0;
}
