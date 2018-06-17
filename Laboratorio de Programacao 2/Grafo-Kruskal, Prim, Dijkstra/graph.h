/* Laboratório de Programação 2 :  03 - 06/2018
 * Projeto em C com os principais algortimos utilizados para percorrer grafos: DFS, BFS, Kruskal, Prim e Dijkstra
 * Modelo: Grafo orientado representado por lista de adjacências. Heap de arestas. Informações sobre o grafo lidas de arquivo txt.
 * Autor: Jiovana Gomes (gomesjiovana@gmail.com)
*/

#ifndef GRAFO1_GRAPH_H
#define GRAFO1_GRAPH_H

typedef struct aresta{
    int orig;
    int dest; // destino do nodo
    int peso;
    struct aresta *prox;
} Aresta;

typedef struct nodo{
    int chave; //origem
    struct nodo *prox;
    Aresta *adj; // lista de adjacencias
} Nodo;

typedef struct grafo{//descritor
    Nodo *list;// lista de nodos
    int size; //tamanho da lista

} Grafo;

//cria lista de nodos com base na primeira linha do arquivo
void criaNodos(Grafo *g, int nodos);
//insere uma aresta numa lista de um nodo
Aresta *inserirAresta(Aresta *ar, int d, int p, int o);
// criacao e montagem do grafo, lendo informações do arquivo e criando os nodos e arestas
Grafo* criaGrafo(FILE *fp, int* qtda);
//imprime a lista adjacencia
void imprimeGrafo(Grafo *g);
//libera memoria
void liberar(Grafo *g);
//verifica se há nodos no grafo com a chave indicada
Nodo* buscarNodo(Grafo *g, int v);
//verifica se nodo informado já faz parte do vetor resposta
int possuiNodo( int *res, int v, int tam);
//executa uma busca em profundidade no grafo, a partir de um nodo inicial
int* DFS(Grafo *g, int v);
//executa uma busca em largura no grafo, a partir de um nodo inicial
int* BFS(Grafo *g, int v);
//imprime o vetor resposta gerado pelas buscas
void printBusca(int *res, int tam);
//executa o algoritmo de kruskal para criar uma arvore geradora mínima do grafo
void Kruskal(Grafo *g , int qtd);
//executa o algoritmo de prim para criar uma arvore geradora mínima do grafo, com base em um nodo inicial
void Prim(Grafo *g, int n);
//executa o algoritmo de dijkstra para criar uma árvore de menor caminho possível a partir de um nodo inicial
void Dijkstra(Grafo *g, int fnt);
#endif //GRAFO1_GRAPH_H
