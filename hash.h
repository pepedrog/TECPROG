//#include <stdlib.h>
#include <stdio.h>
#include "lista.h"



typedef struct TabSim{
	int size;
	Lista* listas;
} TabSim;

int hash(char* s, int mod){
	//A tabela de hash funcionará transformando a palavra em um número na base 257
	//E depois tirando o modulo do tamanho da tabela

	//Exemplo: P Ã O retornará (P * 257⁰ + Ã * 257¹ + O * 257²) mod(mod)
	long long int out = 0;
	for(int i = 0; s[i] != '\0'; i++){
		out = out*257 + (int) s[i];
		out %= mod;
	}
	return out;
}

TabSim Tcria(int tam){
	//Criando uma tabela com tam listas
	TabSim tabela;
	tabela.listas = malloc(tam*sizeof(Lista));
	tabela.size = tam;
	for(int i = 0; i < tam; i++){
		tabela.listas[i] = Lcria();
	}
	return tabela;
}

void Tdestroi(TabSim t){
	//Percorre a tabela destruindo as listas dela
	for(int i = 0; i < t.size; i++){
		Ldestroi(t.listas[i]);
	}
	free(t.listas);
	return;
}

int Tinsere(TabSim t, char *n, Elemento *val){
	//Calcula o hash do elemento, que é em qual lista ele será inserido
	int hash_val = hash(n, t.size);
	printf("Hash do elemento: %d\n", hash_val);
	return Linsere(t.listas[hash_val], val)==NULL?0:1;
}

Elemento* Tbusca(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	printf("Estamos buscando o elemento %s que tem hash %d\n", n, hash_val);
	return Lbusca(t.listas[hash_val], n);
}

int Tretira(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	struct elo* crawler = t.listas[hash_val].cabec; //Elemento* out = NULL;
	struct elo* last = crawler;
	while(crawler != NULL){
		printf("Fazendo uma busca pelo %s para tentar elimina-lo\n", n);
		if(crawler->val != NULL && stringsIguais(crawler->val->nome, n)){
			printf("Achei o %s e to eliminando\n", n);
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
