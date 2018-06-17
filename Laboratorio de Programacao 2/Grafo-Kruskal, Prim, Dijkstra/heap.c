//Implementação de estrutura de heap mínimo para controlar as arestas do grafo com base em seus pesos
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


void printHeap(Heap *heap){
    printf("Imprimindo heap: \n");
    for (int i = 0; i < heap->tam ; i++)
        printf("%d\n", heap->vet[i].peso);

}

void swap(Aresta *x, Aresta *y) {
    Aresta temp = *x;
    *x = *y;
    *y = temp;
}
Aresta getRaiz(Heap *heap){
    return heap->vet[0];
}

int pai(int i){
    return (i-1)/2;
}
int esq(int i){
    return (2*i +1);
}
int dir(int i){
    return (2*i +2);
}

Heap constructor(){
    Heap hep;
    hep.tam = 0;
    return hep;
}

void insertHeap(Aresta x, Heap *hep){
    if(hep->tam){
        hep->vet = realloc(hep->vet,(hep->tam+1)* sizeof(Aresta));
    }else{
        hep->vet = malloc(sizeof(Aresta));
    }
    Aresta a;
    a.peso = x.peso;
    a.orig = x.orig;
    a.dest = x.dest;
    a.prox = x.prox;
    int i = (hep->tam)++;
    while(i && a.peso < hep->vet[pai(i)].peso){
        hep->vet[i] = hep->vet[pai(i)];
        i = pai(i);
    }
    hep->vet[i] = a;
    MinHeapify(x.peso,hep);
}

void MinHeapify(int i, Heap *hep){
    int e = esq(i), d = dir(i);
    int menor = (e < hep->tam && hep->vet[e].peso < hep->vet[i].peso) ? e : i;
    if(d < hep->tam && hep->vet[d].peso < hep->vet[menor].peso){
        menor  = d;
    }
    if(menor != i){
        swap(&(hep->vet[i]), &(hep->vet[menor]));
        MinHeapify(menor,hep);
    }
}

Aresta removeMin(Heap *hep){
    if(hep->tam){
        Aresta raiz = hep->vet[0];
        hep->vet[0] = hep->vet[--(hep->tam)];
        hep->vet = realloc(hep->vet,hep->tam* sizeof(Aresta));
        MinHeapify(0,hep);
        return raiz;
    } else{
        printf("Heap vazio!\n");
        free(hep->vet);
    }
}

void BuildMinHeap(Aresta *input, int tam, Heap *hep){
    for (int i = 0; i < tam ; i++) {
        if(hep->tam){
            hep->vet = realloc(hep->vet, (hep->tam+1)* sizeof(Aresta));
        }else{
            hep->vet = malloc(sizeof(Aresta));
        }
        Aresta a;
        a.peso = input[i].peso;
        a.orig = input[i].orig;
        a.dest = input[i].dest;
        a.prox = input[i].prox;
        hep->vet[(hep->tam++)] = a;
    }
    for (int j = (hep->tam-1)/2; j >= 0 ; j--) {
        MinHeapify(j,hep);
    }
}

void deletarHeap(Heap *hep){
    free(hep->vet);
}


