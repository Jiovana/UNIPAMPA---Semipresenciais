// Lista 8
// 02/12/2017
// Jiovana Sousa Gomes (gomesjiovana@gmail.com)

#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

typedef struct lista {
    int v;
    struct lista *prox;
}Lista;

typedef struct filal{
    Lista *ini;
    Lista *fim;
} FilaL;

typedef struct grafo{
    int **matriz;
    int vertices;
} Grafo;

typedef struct resultado{
    int *cor;
    int *distancia;
    int *predecessor;
} Resultado;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

FilaL *criarL(){
    FilaL *f = (FilaL*)malloc(sizeof(FilaL));
    f->ini = f->fim = NULL;
    //printf("Fila criada!\n");
    return f;
}

void inserirL(FilaL *f, int  v){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->v = v;
    novo->prox = NULL;
    if(f->fim == NULL && f->ini == NULL){
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    //printf("Elemento inserido!\n");
}

int retirarL(FilaL *f){
    Lista *t;
    int v;
    if (f->fim == NULL && f->ini == NULL){
        //printf("Lista vazia!\n");
    } else {
        t=f->ini;
        v=t->v;
        f->ini = t->prox;
        if(f->ini == NULL)
            f->fim = NULL;
        free(t);
        return v;
    }
}


void liberarL(FilaL *f){
    Lista *q = f->ini;
    while (q != NULL){
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

Grafo *criarGrafo(int v){
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices=v;
    g->matriz = (int**)malloc(sizeof(int*)*v);
    int i;
    for (i = 0;i<v;i++){
        g->matriz[i] = (int*)malloc(sizeof(int)*v);
    }
    int j;
    for (i = 0;i<v;i++){
        for(j=0;j<v;j++){
            g->matriz[i][j]=BRANCO;
        }
    }
    return g;
};

Resultado *criarResultado(int v){
    Resultado *r = (Resultado*)malloc(sizeof(Resultado));
    r->cor = (int*)malloc(sizeof(int)*v);
    r->predecessor = (int*)malloc(sizeof(int)*v);
    r->distancia=(int*)malloc(sizeof(int)*v);
    int i;
    for(i=0;i<v;i++){
        r->cor[i] = BRANCO;
        r->predecessor[i] = -1;
        r->distancia[i] = 0;
    }
    return r;
}

void insereAresta(Grafo* g, int o, int d){
    g->matriz[o][d]= 1 ;
}

void imprimeGrafoLista(Grafo* g){
    int i,j;
    printf("\nVertice -> Lista de Adjacencia\n");
    printf("-------------------------------\n");
    for(i=0;i < g->vertices;i++){
        printf("%7d ->",i);
        for(j=0; j < g->vertices; j++){
            if(g->matriz[i][j] == 1)
                printf(" [%d]",j);
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

void imprimeGrafoMat(Grafo* g){
    int i,j;
    printf("\nMatriz de Adjacencia\n");
    printf("-------------------------------\n");
    for(i=0;i < g->vertices;i++){
        for(j=0; j < g->vertices; j++){
                printf(" [%d]",g->matriz[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

Resultado *BFS(Grafo *g, int origem){
    int adjacente;
    Resultado *r = criarResultado(g->vertices);
    r->cor[origem] = CINZA;
    FilaL *f  =criarL();
    inserirL(f,origem);
    while(f->fim != NULL) {
        int atual = retirarL(f);
        for (adjacente = 0; adjacente < g->vertices; adjacente++) {
            if (g->matriz[atual][adjacente] == 1) {
                if (r->cor[adjacente] == BRANCO) {
                    r->cor[adjacente] = CINZA;
                    inserirL(f, adjacente);
                    r->predecessor[adjacente] = atual;
                    r->distancia[adjacente] = 1 + r->distancia[atual];
                }
            }
        }
        r->cor[atual] = PRETO;
    }
    liberarL(f);
    return r;
}

void imprimeGrafoBFS(Grafo *g, Resultado *r){
    int i;
    printf("\nResultado da BFS:\n");
    printf("-------------------\n");
    for(i = 0; i < g->vertices; i++){
        printf("Vertice [%4d] --> Cor: %7s, Pred: %4d, Dist: %5d\n", i, (r->cor[i]) == PRETO? "Preto" :(r->cor[i]) == CINZA? "Cinza" : "Branco" ,r->predecessor[i], r->distancia[i]);
    }
    printf("\n");
}

void destroi(Grafo *g, Resultado *r) {
    int i;
    for (i = 0; i < g->vertices; i++)
        free(g->matriz[i]);
    free(g->matriz);

    free(r->distancia);
    free(r->predecessor);
    free(r->cor);
    free(r);
}

