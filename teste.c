#include "hash.h"

int main(void){
    TabSim hash = Tcria(4);
    int n;
    scanf("%d", &n);
    printf("oi\n");
    printf("%d\n", n);
    Elemento* Elementi = malloc(n*sizeof(Elemento));
    for(int i = 0; i<n; i++){
        char aux[80];
        scanf("%s", aux);
        int j;
        for(j = 0; aux[j] != '\0'; j++) Elementi[i].nome[j] = aux[j];
        Elementi[i].nome[j] = '\0';
        //printf("%d %c\n",i,*aux);
        Tinsere(hash, aux, &Elementi[i]);
    }
    printf("aaa");
    int m;
    scanf("%d",&m);
    for(int i = 0; i<m; i++){
        char aux[80];
        scanf("%s", aux);

        if(Tbusca(hash, aux)==NULL) printf("Não achou\n");
        else printf("Achou\n");
    }

    //Tdestroi(hash);

}
