//Implementação de estrutura de heap mínimo para controlar as arestas do grafo com base em seus pesos
#include "graph.h"
void swap(Aresta *x, Aresta *y);


typedef struct heap{
    int tam;//tamanho atual do vetor
    Aresta *vet;
}Heap;

Aresta getRaiz(Heap *heap);
void printHeap(Heap *heap);
Aresta removeMin(Heap *hep);
void MinHeapify(int i, Heap *hep);
void insertHeap(Aresta x, Heap *hep);
Heap constructor();
int dir(int i);
int esq(int i);
int pai(int i);
void BuildMinHeap(Aresta *input, int tam, Heap *hep);//usar com vetor pronto
void deletarHeap(Heap *hep);