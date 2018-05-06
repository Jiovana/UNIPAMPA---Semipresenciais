//
// Created by gomes on 27/04/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "disj.h"

Conj *constructorConj(int tam){
    Conj *conj = malloc(sizeof(Conj));
    conj->vet = malloc(sizeof(int)*tam);
    conj->tam = tam;
    makeSet(conj);
    return conj;
}

void makeSet(Conj *conj){
    for (int i = 1; i <= conj->tam; i++) {
        conj->vet[i] = i;
    }
    printf("Sets criados\n");
}

int findSet(int i, Conj *conj){
    if(conj->vet[i] == i) // eh conj dele mesmo
        return i;
    else { // procura recursivamente o conj
        conj->vet[i] = findSet(conj->vet[i], conj);
        return conj->vet[i];
    }
}

void mergeSet(int i,int j, Conj *conj){
    int x = findSet(conj->vet[i],conj); //acha conj de i
    int y = findSet(conj->vet[j],conj); // acha conj de j
    if(x == y) //se sao iguais nao faz nada
        return;
    else { // senao seta o conj como sendo o do primeiro informado
        conj->vet[y] = x;
    }
    printf("Sets unidos\n");
}

void printSets(Conj *conj){
    for (int i = 1; i <= conj->tam ; ++i)
        printf("Index %d - Set[%d]\n",i, conj->vet[i]);
}
