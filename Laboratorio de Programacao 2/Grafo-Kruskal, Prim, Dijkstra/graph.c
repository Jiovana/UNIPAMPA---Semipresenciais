/* Laboratório de Programação 2 :  03 - 06/2018
 * Projeto em C com os principais algortimos utilizados para percorrer grafos: DFS, BFS, Kruskal, Prim e Dijkstra
 * Modelo: Grafo orientado representado por lista de adjacências. Heap de arestas. Informações sobre o grafo lidas de arquivo txt.
 * Autor: Jiovana Gomes (gomesjiovana@gmail.com)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "pilhas.h"
#include "filas.h"
#include "cdisj.h"
#include "heap.h"

void criaNodos(Grafo *g, int nodos) {
    for (int i = 0; i < nodos; i++) { //vai criar uma lista encadeada de nodos cujo valor comeca em i+1
        Nodo *novo;
        Nodo *ant = NULL;
        Nodo *prox = g->list;
        while (prox != NULL) {
            ant = prox;
            prox = prox->prox;
        }
        novo = (Nodo *) malloc(sizeof(Nodo));
        novo->chave = i + 1;
        novo->prox = NULL;
        novo->adj = NULL;
        if (ant == NULL) {
            novo->prox = g->list;
            g->list = novo;
        } else {
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
}

Aresta *inserirAresta(Aresta *ar, int d, int p, int o) { // insercao em lista encadeada simples
    Aresta *novo;
    Aresta *ant = NULL;
    Aresta *prox = ar;
    while (prox != NULL) {
        ant = prox;
        prox = prox->prox;
    }
    novo = (Aresta *) malloc(sizeof(Aresta));
    novo->orig = o;
    novo->dest = d;
    novo->peso = p;
    if (ant == NULL) {
        novo->prox = ar;
        ar = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return ar;
}

Grafo *criaGrafo(FILE *fp, int *qtda) {
    int nodos;
    if ((fp = fopen("graph.txt", "rt")) ==
        NULL) { //abrindo o arquivo do grafo para leitura, se da erro, encerra programa
        printf("Erro ao abrir o arquivo!\n");
        exit(0);
    }
    fscanf(fp, "%d\n", &nodos);//vai pegar a primeira linha com a quantidade de nodos

    Grafo *graf = (Grafo *) malloc(sizeof(Grafo)); //cria o descritor e os nodos
    graf->list = NULL;
    graf->size = nodos;
    criaNodos(graf, nodos);

    int i = 0, *o = NULL, *d = NULL, *p = NULL;//vetores para origem, destino, peso
    char linha[50], *res, *tok; //strings pra leitura
    //int qtda=0;
    while (!feof(fp)) {//laço para contar as linhas restantes/quantidade de arestas
        fgets(linha, 50, fp); //ler uma linha de ate 50 caracteres por vez
        (*qtda)++; //ATENÇÃO PARA LINHAS EM BRANCO A MAIS NO FINAL DO ARQUIVO
    }
    //alocando vetores com base na quantidade de linhas
    o = (int *) malloc(sizeof(int) * (*qtda));
    d = (int *) malloc(sizeof(int) * (*qtda));
    p = (int *) malloc(sizeof(int) * (*qtda));

    rewind(fp); //reseta fp para comecar do inicio
    fscanf(fp, "%d\n", &nodos);// le a primeira linha de novo pra deixar ela de fora do while

    while (!feof(fp)) { //laço linha por linha para separar string lida e por nos vetores
        res = fgets(linha, 50, fp);
        if (res)
            tok = strtok(linha, ";"); // inicio: primeira separacao onde tiver ';'
        int j = 0;
        while (tok != NULL) { //enquanto nao acabar a string cortada
            switch (j) {
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
            tok = strtok(NULL, ";"); //separa o restante da string lida por ';', até acabar a string
            j++;
        }
        i++;
    }
    Nodo *nod;
    Aresta *ar;
    for (nod = graf->list; nod != NULL; nod = nod->prox) {//laços para percorrer lista de nodos, comparar com o vetor origem e achar respectivas arestas
        for (int l = 0; l < (*qtda); l++) { //percorre as arestas
            if (l == 0)
                ar = NULL; // nova lista
            else
                ar = nod->adj; //lista existente
            if (nod->chave == o[l]) { //se o nodo é o da aresta, adiciona aresta
                nod->adj = inserirAresta(ar, d[l], p[l], o[l]);
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

void imprimeGrafo(Grafo *g) {
    for (Nodo *n = g->list; n != NULL; n = n->prox) {
        printf("Nodo %d ->", n->chave);
        for (Aresta *a = n->adj; a != NULL; a = a->prox) {
            printf(" [%d]", a->dest);
        }
        printf("\n");
    }
}

void liberar(Grafo *g) {
    for (Nodo *n = g->list; n != NULL; n = n->prox) {
        free(n->adj);
    }
    free(g->list);
    free(g);
}

Nodo *buscarNodo(Grafo *g, int v) {
    for (Nodo *n = g->list; n != NULL; n = n->prox) {
        if (n->chave == v) {
            return n;
        }
    }
    return NULL;
}

int possuiNodo(int *res, int v, int tam) {
    int i = 0;
    while (i < tam) {
        if (res[i] == v) {
            return 1; // true
        }
        i++;
    }
    return 0; //false
}

int *DFS(Grafo *g, int v) {
    int c = 0, aux;
    int *res = (int *) malloc(sizeof(int) * g->size);
    Nodo *n = buscarNodo(g, v);

    for (int i = 0; i < g->size; ++i) {
        res[i] = 0;
    }
    if (n == NULL) {
        return NULL;
    } else {
        Pilha *p = criaPilha();
        pilhaPush(p, n->chave);//coloca primeiro nodo na pilha

        while (p->n > 0) { //enquanto pilha existir
            aux = pilhaPop(p); //desempilha 1 nodo
            n = buscarNodo(g, aux);//procura o nodo desempilhado no grafo
            if (!possuiNodo(res, n->chave, g->size)) { // ve se não esta no vetor res
                res[c] = n->chave; //coloca no vetor
                c++;
            }
            for (Aresta *a = n->adj; a != NULL; a = a->prox) { //percorre lista de adj do nodo atual
                if (!possuiNodo(res, a->dest, g->size)) // se adj nao esta no vetor, empilha
                    pilhaPush(p, a->dest);
            }
        }
        liberaPilha(p);
    }
    return res;
}


int *BFS(Grafo *g, int v) {
    int c = 0, aux;
    int *res = (int *) malloc(sizeof(int) * g->size);
    Nodo *n = buscarNodo(g, v);

    for (int i = 0; i < g->size; ++i) {
        res[i] = 0;
    }
    if (n == NULL) {
        return NULL;
    } else {
        Fila *f = criarFila();
        inserirFila(f, n->chave);
        while (f->n > 0) { //enquanto pilha existir
            aux = retirarFila(f);
            n = buscarNodo(g, aux);
            if (!possuiNodo(res, n->chave, g->size)) { // ve se não esta no vetor res
                res[c] = n->chave; //coloca no vetor
                c++;
            }
            for (Aresta *a = n->adj; a != NULL; a = a->prox) { //percorre lista de adj do nodo atual
                if (!possuiNodo(res, a->dest, g->size))
                    inserirFila(f, a->dest);
            }
        }
        liberarFila(f);
    }
    return res;
}

void printBusca(int *res, int tam) {
    printf("\nResultado da busca: \n");
    for (int i = 0; i < tam; i++) {
        printf("%d\n", res[i]);
    }
    printf("\n");
    free(res);
}

/*Kruskal's Algorithm for Minimum Spanning Tree using Adjacency List Graph, Minimum Heap of Edges (Priority Queue) and Disjoint Sets
 * int qtd = quantidade de arestas do grafo, contada a partir das linhas do arquivo
 */

void Kruskal(Grafo *g, int qtd) {
    int c = 0; //contador para o vetor de arestas do grafo

    Conj *conj = constructorConj(g->size);// cria os conjuntos disjuntos
    makeSet(conj, g->size);

    Aresta *lista = (Aresta *) malloc(sizeof(Aresta) * qtd); //vetor de arestas do grafo
    for (Nodo *aux = g->list; aux != NULL; aux = aux->prox) {//vai preencher vetor lista com todas as arestas do grafo
        for (Aresta *a = aux->adj; a != NULL; a = a->prox) {
            lista[c] = *a;
            c++;
        }
    }

    Heap hep = constructor(); //inicializa e cria heap com base no vetor de arestas
    BuildMinHeap(lista, qtd, &hep);

    c = 0;
    Aresta *res, prox;
    res = malloc(sizeof(Aresta) * (g->size - 1));//vetor resposta com tamanho igual ao numero de nodos -1 pois o menor caminho sempre será o mínimo de arestas possíveis para manter o grafo conectado
    while (hep.tam > 0) { //enquanto existir arestas na heap
        prox = removeMin(&hep); //retira aresta raiz da heap
        if (findSet(prox.orig, prox.dest, conj) == 0) { //testa se os nodos origem e destino já não pertencem ao mesmo conjunto
            res[c] = prox; //coloca aresta na solucao
            c++;
            mergeSet(prox.orig, prox.dest, conj); //une os nodos origem e destino ao mesmo conjunto
        }
    }
    printf("Minimum Spanning Tree (MST) :\n"); //mostra árvore geradora mínima utilizando vetor resposta
    for (int i = 0; i < c; i++) {
        printf("[%d]--%d--[%d]\n", res[i].orig, res[i].peso, res[i].dest);
    }
    free(res);
    free(lista);
    liberaSets(conj);
    deletarHeap(&hep);
}

/*Prim's Algorithm for Minimum Spanning Tree using Adjacency List Graph, Minimum Heap of Edges (Priority Queue) and Disjoint Sets
 * int num = nodo de origem da busca
 */
void Prim(Grafo *g, int num) {
    Nodo *n = buscarNodo(g, num);//busca nodo de inicio

    Conj *conj = constructorConj(g->size);// cria os conjuntos disjuntos
    makeSet(conj, g->size);

    Aresta *res = malloc(sizeof(Aresta) * (g->size - 1));//vetor resposta de arestas

    Heap hep = constructor();//inicializa heap com tamanho 0
    for (Aresta *a = n->adj; a != NULL; a = a->prox) { //adiciona arestas do nodo inicio na heap
        insertHeap(*a, &hep);
    }

    Aresta aux;
    Nodo *nod;
    int e = 0;//contador do vetor resposta
    while (hep.tam > 0) { // enquanto tiver arestas na heap
        aux = removeMin(&hep); //pega primeiro elemento (raiz) da heap
        nod = buscarNodo(g, aux.dest); //busca nodo correspontente ao destino da aresta
        if (findSet(aux.orig, aux.dest, conj) == 0) { //verifica se não faz parte da solução a outra extremidade, se nao faz adiciona o nodo
            for (Aresta *b = nod->adj; b != NULL; b = b->prox) {
                insertHeap(*b, &hep);//adiciona arestas do nodo destino na heap
            }
            mergeSet(aux.orig, aux.dest, conj); // une os nodos origem e destino ao mesmo conjunto
            res[e] = aux; //adiciona aresta na solução
            e++;
        }
    }
    printf("Minimum Spanning Tree (MST) :\n"); //mostra árvore geradora mínima utilizando vetor resposta
    for (int i = 0; i < e; ++i) {
        printf("[%d]--%d--[%d]\n", res[i].orig, res[i].peso, res[i].dest);
    }
    free(res);
    liberaSets(conj);
    deletarHeap(&hep);
}
/*Dijkstra's Algorithm for Shortest Spanning Tree using Adjacency List Graph, Minimum Heap of Edges (Priority Queue) and Disjoint Sets
 * int fnt = nodo de origem da busca
 */
void Dijkstra(Grafo *g, int fnt) {
    Nodo *nod = buscarNodo(g, fnt);//busca nodo origem
    int *pi = malloc(sizeof(int) * (g->size));//vetor pi - pai do nodo respectivo a posição no vetor
    int *sol = malloc(sizeof(int) * g->size); //vetor solucao - ordem do caminho percorrido (nodos)
    int *dist = malloc(sizeof(int)*g->size);//vetor de distancia entre os nodos

    for (int i = 0; i < g->size; i++) { //inicializa os vetores com infinito e null
        dist[i] = INT_MAX;
        pi[i] = 0;
    }
    dist[fnt-1] = 0;//seta a distancia da origem como 0 - necessario diminuir 1 pq o vetor comeca em 0 e o grafo em 1

    for (int i = 0; i < g->size; i++) { //limpa solucao
        sol[i] = 0;
    }

    Heap hep = constructor(); // inicializa heap com tamanho 0
    for (Aresta *a = nod->adj; a != NULL; a = a->prox) { //adiciona arestas do nodo inicial na heap
        insertHeap(*a, &hep);
    }

    int cont = 0; //contador para vetor solução
    while (hep.tam > 0) {
        Aresta ux = removeMin(&hep);//pega aresta raiz da heap
        Nodo *v = buscarNodo(g, ux.dest); //pega nodos destino e
        Nodo *u = buscarNodo(g, ux.orig); // origem da aresta raiz
        if (!possuiNodo(sol, u->chave, g->size)) { //verifica se o nodo origem não está na solução
            sol[cont] = u->chave;
        }
        if (dist[v->chave-1] > (dist[u->chave-1] + ux.peso) && !possuiNodo(sol, v->chave, g->size)) {//verifica se a distancia do nodo destino é maior que a distancia do nodo origem + o peso da aresta entre eles e se o nodo destino ainda não está na solução
            dist[v->chave-1] = dist[u->chave-1] + ux.peso; //seta distancia de nodo destino como distancia de nodo origem + peso da aresta
            pi[v->chave] = u->chave; // o pai do nodo destino sera o nodo origem
            for (Aresta *a = v->adj; a != NULL; a = a->prox) { //adiciona arestas do nodo destino na heap
                insertHeap(*a, &hep);
            }
        }
        cont++;
    }
    printf("Shortest Path Tree (SPT) :\n"); //aqui esta imprimindo a menor distancia necessaria para alcançar todos os nodos a partir da fonte
    for (int i = 0; i < g->size; i++) {
        printf("[%d]--%d--[%d]\n", fnt, dist[i], i + 1);
    }

    //free(sol); //vetores estao dando erro para liberar...
    //free(pi);
    //free(dist);
    deletarHeap(&hep);
}
