/* Laboratório de Programação 2 :  03 - 06/2018
 * Projeto em C com os principais algortimos utilizados para percorrer grafos: DFS, BFS, Kruskal, Prim e Dijkstra
 * Modelo: Grafo orientado representado por lista de adjacências. Heap de arestas. Informações sobre o grafo lidas de arquivo txt.
 * Autor: Jiovana Gomes (gomesjiovana@gmail.com)
*/
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int opt = 0, *res, qtda = 0, nod;
    FILE *fp = NULL;
    Grafo *g = NULL;
    printf("====GRAFOS====\n");
    do{
        printf("\nEscolha uma opcao:\n1. Criar grafo\n2. Ver lista adjacencia\n3. DFS\n4. BFS\n5. Kruskal\n6. Prim\n7. Djikstra\n8. Sair!\nOPCAO>>>");
        scanf("%d",&opt);
        setbuf(stdin,NULL);
        switch (opt){
            case 1:
                g=criaGrafo(fp,&qtda);
                break;
            case 2:
                imprimeGrafo(g);
                break;
            case 3:
                printf("Informe o nodo de origem do caminho: \n");
                scanf("%d", &nod);
                res = DFS(g,nod);
                printBusca(res,g->size);
                break;
            case 4:
                printf("Informe o nodo de origem do caminho: \n");
                scanf("%d", &nod);
                res = BFS(g,nod);
                printBusca(res,g->size);
                break;
            case 5:
                Kruskal(g,qtda);
                break;
            case 6:
                printf("Informe o nodo de inicio:\n");
                scanf("%d",&nod);
                Prim(g,nod);
                break;
            case 7:
                printf("Informe o nodo de inicio:\n");
                scanf("%d",&nod);
                Dijkstra(g,nod);
                break;
            case 8:
                liberar(g);
                break;
            default:
                printf("Wrong option..\n");
                break;
        }
    }while(opt!=8);
    return 0;
}