//Semipresencial 2 - Modelagem da Estrutura de Grafos - 06/04/18
//Jiovana Gomes (gomesjiovana@gmail.com)
//
#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
#include "graph.h"

int main() {
    int opt = 0, v, *res;
    FILE *fp = NULL;
    Grafo *g = NULL;
    do{
        printf("\nEscolha uma opcao:\n1. Criar grafo\n2. Ver lista adjacencia\n3. DFS\n4. BFS\n5. Sair!\n");
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
                printf("Informe o nodo de origem do caminho: \n");
                scanf("%d", &v);
                res = DFS(g,v);
                printBusca(res,g->size);
                break;
            case 4:
                printf("Informe o nodo de origem do caminho: \n");
                scanf("%d", &v);
                res = BFS(g,v);
                printBusca(res,g->size);
                break;
            case 5:
                liberar(g);
                break;
            default:
                printf("Wrong option..\n");
                break;
        }
    }while(opt!=5);

    return 0;
}