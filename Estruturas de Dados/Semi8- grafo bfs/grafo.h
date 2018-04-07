//
// Created by gomes on 30/11/2017.
//

#ifndef SEMI8_GRAFO_H
#define SEMI8_GRAFO_H

typedef struct lista Lista;
typedef struct filal FilaL;
FilaL *criarL();
void inserirL(FilaL *f, int v);
int retirarL(FilaL *f);
void liberarL(FilaL *f);

typedef struct grafo Grafo;
typedef struct resultado Resultado;
Grafo *criarGrafo(int v);
Resultado *criarResultado(int v);
void insereAresta(Grafo* g, int o, int d);
void imprimeGrafoLista(Grafo* g);
void imprimeGrafoMat(Grafo* g);
Resultado *BFS(Grafo *g, int origem);
void imprimeGrafoBFS(Grafo *g, Resultado *r);
void destroi(Grafo *g, Resultado *r);


#endif //SEMI8_GRAFO_H
