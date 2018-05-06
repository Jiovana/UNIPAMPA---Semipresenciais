//
// Created by gomes on 27/04/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


void printHeap(Heap *heap){
    printf("Imprimindo heap: \n");
    for (int i = 0; i < heap->tam ; i++)
        printf("%d\n", heap->vet[i]);

}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int getRaiz(Heap *heap){
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

Heap* contructor(int cap){
    Heap *hep = malloc(sizeof(Heap));
    hep->tam = 0;
    hep->cap = cap;
    hep->vet =  malloc(sizeof(int)*cap);
    for (int i = 0; i < cap; i++) {
        hep->vet[i] = 0;
    }
    return hep;
}

void insertHeap(int x, Heap *hep){
    if(hep->tam == hep->cap){
        printf("Heap cheio!");
        return;
    }else{
        hep->vet[hep->tam] = x;
        hep->tam++;
        siftUp(hep->tam-1,hep);
        printf("Inserido!\n");
    }
}

void MinHeapify(int i, Heap *hep){
    int e = esq(i);
    int d = dir(i);
    int menor = i;
    if(e < hep->tam && hep->vet[e] < hep->vet[i])
        menor  = e;
    if(d < hep->tam && hep->vet[d] < hep->vet[menor])
        menor = d;
    if(menor != i){
        swap(&hep->vet[i], &hep->vet[menor]);
        MinHeapify(menor,hep);
    }
}

int removeMin(Heap *hep){
   if(hep->tam == 0){
       printf("Heap vazio!\n");

   }else{
       int raiz = hep->vet[0];
       hep->vet[0] = hep->vet[hep->tam -1];
       hep->tam--;
       if(hep->tam > 0){
           siftDown(0,hep);
       }
       return raiz;
   }
}

void BuildMinHeap(int *input, int cap){
   Heap  *hep = contructor(cap);
    for (int i = 0; i < hep->cap ; i++) {
        hep->vet[i] = input[i];
        hep->tam++;
    }
    for (int j = (hep->tam-1)/2; j >= 0 ; j--) {
        MinHeapify(j,hep);
    }
}

void siftDown(int i, Heap *hep){
    int min;
    int e = esq(i);
    int d = dir(i);
    if(d >= hep->tam ){
        if(e >= hep->tam)
            return;
        else
            min = e;
    }else{
        if(hep->vet[e] <= hep->vet[d])
            min = e;
        else
            min = d;
    }
    if(hep->vet[i] > hep->vet[min]){
        swap(&hep->vet[min],&hep->vet[i]);
        siftDown(min,hep);
    }
}

void siftUp(int i, Heap *hep){
    int p;
    if(i != 0){
        p = pai(i);
        if(hep->vet[p] > hep->vet[i]){
            swap(&hep->vet[p],&hep->vet[i]);
            siftUp(p,hep);
        }
    }
}


