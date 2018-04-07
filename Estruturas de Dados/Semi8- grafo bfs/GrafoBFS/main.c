// Lista 8
// 02/12/2017
// Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    int opt, optt, v, vv;
    Grafo *g;
    Resultado *r;
    do {
        printf("\nESCOLHA UMA OPCAO\n1. Criar grafo\n2. Inserir aresta\n3. Imprimir grafo\n4. Realizar BFS\n5. Liberar e sair\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        switch (opt) {
            case 1:
                printf("Informe numero de vertices:\n");
                scanf("%d", &v);
                g = criarGrafo(v);
                printf("Grafo criado.\n");
                break;
            case 2:
                printf("Informe origem e destino da aresta:\n");
                scanf("%d", &v);
                scanf("%d", &vv);
                insereAresta(g,v, vv);
                printf("Aresta inserida!\n");
                break;
            case 3:
                printf("Impressao \n1. Matriz adj\n2. Lista adj\n");
                scanf("%d", &optt);
                if (optt == 1) {
                    imprimeGrafoMat(g);
                } else if (optt == 2) {
                    imprimeGrafoLista(g);
                }
                break;
            case 4:
                printf("Informe origem da busca:\n");
                scanf("%d", &v);
                r = BFS(g, v);
                imprimeGrafoBFS(g, r);
                break;
            case 5:
                destroi(g, r);
                exit(0);
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opt != 6);
    return 0;
}