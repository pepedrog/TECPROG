#include "hash.h"

int main(void){
    int n;
    printf("Qual será o tamanho da Tabela de Símbolos? ");
    scanf("%d", &n);
    TabSim hash = Tcria(n);
    
    printf("Quantos elementos deseja inserir? ");
    scanf("%d", &n);
    Elemento* Elementi = malloc(n*sizeof(Elemento));
    for(int i = 0; i<n; i++){
        char aux[80];
	printf("Nome do elemento: ");
        scanf("%s", aux);
        int j;
	//Guardando o nome digitado no Elementi[i]
        for(j = 0; aux[j] != '\0'; j++) Elementi[i].nome[j] = aux[j];
        Elementi[i].nome[j] = '\0';

	//Insere o elemento na lista correspondente (posição na tabela de símbolos)
        Tinsere(hash, aux, &Elementi[i]);
    }

    int m;
    printf("Quantos elementos deseja buscar? ");
    scanf("%d",&m);
    for(int i = 0; i<m; i++){
        char aux[80];
	printf("Nome do procurado: ");
        scanf("%s", aux);
        if(Tbusca(hash, aux)==NULL) printf("Não achou!\n");
        else printf("Achou!\n");
    }
    char retirado[80];

    printf("Teste do retira ");
    scanf("%s", retirado);
    Tretira(hash, retirado);
    printf("Busca ai o q voce retirou\n");
    scanf("%s", retirado);
    if(Tbusca(hash, retirado) == NULL) printf("Funfou\n");
    

    Tdestroi(hash);

}
