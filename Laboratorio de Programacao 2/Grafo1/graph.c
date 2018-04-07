//Semipresencial 2 - Modelagem da Estrutura de Grafos - 06/04/18
//Jiovana Gomes (gomesjiovana@gmail.com)
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

void criaNodos(Grafo *g, int nodos){
    for (int i = 0; i < nodos; i++) { //vai criar uma lista encadeada de nodos cujo valor comeca em i+1
        Nodo *novo;
        Nodo *ant = NULL;
        Nodo *prox = g->list;
        while(prox != NULL) {
            ant = prox;
            prox = prox->prox;
        }
        novo = (Nodo*) malloc(sizeof(Nodo));
        novo->orig = i+1;
        novo->prox = NULL;
        novo->adj = NULL;
        if(ant==NULL){
            novo->prox = g->list;
            g->list = novo;
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
}

Aresta *inserirAresta(Aresta *ar, int d, int p){ // insercao em lista encadeada simples
    Aresta *novo;
    Aresta *ant = NULL;
    Aresta *prox = ar;
    while(prox != NULL) {
        ant = prox;
        prox = prox->prox;
    }
    novo  = (Aresta*)malloc(sizeof(Aresta));
    novo->dest = d;
    novo->peso = p;
    if(ant == NULL){
        novo->prox=ar;
        ar = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return ar;
}

Grafo *criaGrafo(FILE *fp){
    int nodos;
    if((fp = fopen("graph.txt", "rt")) == NULL){ //abrindo o arquivo do grafo para leitura, se da erro, encerra programa
        printf("Erro ao abrir o arquivo!\n");
        exit(0);
    }
    fscanf(fp,"%d\n",&nodos);//vai pegar a primeira linha com a quantidade de nodos

    Grafo *graf = (Grafo*)malloc(sizeof(Grafo)); //cria o descritor e os nodos
    graf->list= NULL;
    graf->size= nodos;
    criaNodos(graf, nodos);
    printf("Nodos criados.\n");

    int i =0,*o=NULL, *d=NULL, *p=NULL;//vetores para origem, destino, peso
    char linha[50], *res, *tok; //strings pra leitura
    int qtda=0;
    while(!feof(fp)){//laço para contar as linhas restantes/quantidade de arestas
        fgets(linha,50,fp); //ler uma linha de ate 50 caracteres por vez
        qtda++;
    }
    printf("Total de ligacoes : %d\n", qtda);
    //alocando vetores com base na quantidade de linhas
    o = (int*)malloc(sizeof(int)*qtda);
    d = (int*)malloc(sizeof(int)*qtda);
    p = (int*)malloc(sizeof(int)*qtda);

    rewind(fp); //reseta fp para comecar do inicio
    fscanf(fp,"%d\n",&nodos);// le a primeira linha de novo pra deixar ela de fora do while

    while(!feof(fp)){ //laço linha por linha para separar string lida e por nos vetores
        res = fgets(linha,50,fp);
        printf("%s\n", res);
        if(res)
            tok = strtok(linha,";"); // inicio: primeira separacao onde tiver ';'
        int j = 0;
        while(tok != NULL){ //enquanto nao acabar a string cortada
            switch (j){
                case 0: // primeira parte, origem
                    o[i] = atoi(tok);// atoi converte string para int
                    break;
                case 1: // segunda parte, destino
                    d[i] = atoi(tok);
                    break;
                case 2: // terceira parte, peso
                    p[i] = atoi(tok);
                    break;
                default:
                    printf("Erro\n");
                    break;
            }
            tok = strtok(NULL,";"); //separa o restante da string lida por ';', até acabar a string
            j++;
        }
        i++;
    }
    printf("Vetores preenchidos.\n");
    Nodo *nod;
    Aresta *ar;
    printf("Inserindo arestas...\n");
    for(nod = graf->list; nod != NULL; nod = nod->prox){//laços para percorrer lista de nodos, comparar com o vetor origem e achar respectivas arestas
        printf("Nodo %d\n",nod->orig);
        for (int l = 0; l < qtda ; l++) { //percorre as arestas
            if(l == 0){
                ar = NULL; // nova lista
            }else{
                ar = nod->adj; //lista existente
            }
            if(nod->orig == o[l]){ //se o nodo é o da aresta, adiciona aresta
                nod->adj = inserirAresta(ar,d[l], p[l]);
                printf("Aresta para %d\n",d[l]);
            }
        }
    }
    
    fclose(fp);//fecha o arquivo
    free(o);//libera os vetores
    free(d);
    free(p);
    printf("Grafo criado.\n");
    return graf;
}

void imprimeGrafo(Grafo *g){
    for (Nodo *n  = g->list; n != NULL ; n = n->prox) {
        printf("Nodo %d ->", n->orig);
        for (Aresta *a = n->adj; a != NULL ; a = a->prox) {
            printf(" [%d]",a->dest);
        }
        printf("\n");
    }
}

void liberar(Grafo *g){
    for (Nodo *n  = g->list; n != NULL ; n = n->prox) {
        free(n->adj);
    }
    free(g->list);
    free(g);
 }