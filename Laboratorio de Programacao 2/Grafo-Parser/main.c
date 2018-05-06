//Semipresencial 2 - Modelagem da Estrutura de Grafos - 06/04/18
//Jiovana Gomes (gomesjiovana@gmail.com)
//
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int opt = 0;
    FILE *fp = NULL;
    Grafo *g = NULL;
    do{
        printf("\nEscolha uma opcao:\n1. Criar grafo\n2. Ver lista adjacencia\n3. Sair!\n");
        scanf("%d",&opt);
        setbuf(stdin,NULL);
        switch (opt){
            case 1:
                g=criaGrafo(fp);
                break;
            case 2:
                imprimeGrafo(g);
                break;
            case 3:
                liberar(g);
                break;
            default:
                printf("Wrong option..\n");
                break;
        }
    }while(opt!=3);

    return 0;
}