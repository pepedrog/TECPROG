//#include <stdlib.h>
#include <stdio.h>
#include "lista.h"



typedef struct TabSim{
	int size;
	Lista* listas;
} TabSim;

int hash(char* s, int mod){
	long long int out = 0; int prime = 2;
	for(int i = 0; s[i] != '\0'; i++){
		int aux = s[i];
		out = out*256 + aux;
		out %= mod;
	}
	return out;
}

TabSim Tcria(int tam){
	TabSim tabela;
	tabela.listas = malloc(tam*sizeof(Lista));
	tabela.size = tam;
	for(int i = 0; i < tam; i++){
		tabela.listas[i].cabec = malloc(sizeof(Elo));
		tabela.listas[i].cabec->next = NULL;
		tabela.listas[i].cabec->val = NULL;
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
	return Linsere(t.listas[hash_val], val)==NULL?0:1;	
}

Elemento* Tbusca(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	return Lbusca(t.listas[hash_val], n); 
}

int retira(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	struct elo* crawler = t.listas[hash_val].cabec; Elemento* out = NULL;
	struct elo* last = crawler;
	while(crawler != NULL){
		if(crawler->val != NULL && crawler->val->n == n){
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

int main(){
	
	return 0;
}











