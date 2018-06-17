//Implementação de Conjuntos disjuntos para uso no Grafo
#include <stdlib.h>
#include <stdio.h>
#include "cdisj.h"

Conj *constructorConj(int tam){
    Conj *conj = malloc(sizeof(Conj));
    conj->vet = malloc(sizeof(int)*tam);
    conj->tam = malloc(sizeof(int)*tam);
    makeSet(conj, tam);
    return conj;
}

void makeSet(Conj *conj, int tam){
    for (int i = 1; i <= tam; i++) {
        conj->vet[i] = i;
        conj->tam[i] = 1;
    }
}

int root(Conj *conj, int i){
    while(conj->vet[i] != i){ //percorre o vetor ate achar a raiz
        conj->vet[i] = conj->vet[conj->vet[i]];
        i = conj->vet[i];
    }
    return i;
}

int findSet(int i, int j,  Conj *conj){
    if(root(conj,i) == root(conj,j))
        return 1;
    else
        return 0;
}
void mergeSet(int i,int j, Conj *conj){
    int x = root(conj,i); //acha conj de i
    int y = root(conj,j); // acha conj de j

    if(conj->tam[x] < conj->tam[y]){
        conj->vet[x] = conj->vet[y];
        conj->tam[y] += conj->tam[x];
    }else{
        conj->vet[y] = conj->vet[x];
        conj->tam[x] += conj->tam[y];
    }
}

void printSets(Conj *conj, int tam){
    for (int i = 1; i <= tam ; ++i)
        printf("Index %d - Set[%d]\n",i, conj->vet[i]);
}

void liberaSets(Conj *conj){
    free(conj->tam);
    free(conj->vet);
}
