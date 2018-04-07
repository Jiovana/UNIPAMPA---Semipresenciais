//
// Created by gomes on 30/11/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif


Arv *criarVazia() {
    return NULL;
};

Arv *insere(Arv *a, int i) {
    if (a == NULL) { // se arvore n existe
        a = (Arv *) malloc(sizeof(Arv));
        a->info = i;
        a->pai = NULL;
        a->dir = NULL;
        a->esq = NULL;
    } else if (i < a->info) {// se nao verifica esq dir
        a->esq = insere(a->esq, i);
        a->esq->pai = a;
    } else  if (i > a->info) {
        a->dir = insere(a->dir, i);
        a->dir->pai = a;
    } else if (i == a->info){
        printf("Valor informado igual a raiz da arvore, digite outro!\n");
        return a;
    }
    return a;
}

Arv *exclui(Arv *a, int i) {
    if (a == NULL)
        return NULL;
    else if (i < a->info)
        a->esq = exclui(a->esq, i);
    else if (i > a->info)
        a->dir = exclui(a->dir, i);
    else { //achou nó
        if (a->esq == NULL && a->dir == NULL) { //nó sem filhos
            free(a);
            return NULL;
        } else if (a->dir == NULL) { //nó com filho a esquerda
            Arv *aux = a;
            a = a->esq;
            free(aux);
        } else if (a->esq == NULL) { // nó com filho a direita
            Arv *aux = a;
            a = a->dir;
            free(aux);
        } else { // nó com dois filhos
            Arv *temp = a->esq;
            while (temp->dir != NULL) { //substituir por maior valor da sae
                temp = temp->dir;
            }
            a->info = temp->info; // troca os dados
            temp->info = i;
            a->esq = exclui(a->esq, i);
        }
    }
    return a;
}

int altura(Arv *a) {
    if (a == NULL) {
        return -1;
    } else {
        return 1 + max(altura(a->esq), altura(a->dir));
    }
}

Arv *libera(Arv *a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

void imprimePre(Arv *a) {
    printf("<");
    if (a != NULL) {
        printf("%d", a->info);
        imprimePre(a->esq);
        imprimePre(a->dir);
    }
    printf(">");
}

void imprimeSim(Arv *a) {
    printf("<");
    if (a != NULL) {

        imprimePre(a->esq);
        printf("%d", a->info);
        imprimePre(a->dir);
    }
    printf(">");
}

void imprimePos(Arv *a) {
    printf("<");
    if (a != NULL) {
        imprimePre(a->esq);
        imprimePre(a->dir);
        printf("%d", a->info);
    }
    printf(">");
}

Arv* buscar(Arv *a, int n){
    if (a == NULL) {
        printf("Arvore vazia ou valor nao encontrado!\n");
    } else {
        if (a->info == n){
            printf("Valor encontrado: %d", n);
        } else if (a->info > n){
            return buscar(a->esq,n);
        } else return buscar(a->dir,n);
    }
}

Arv* minimo(Arv *a){
    while (a->esq != NULL){
        a = a->esq;
    }
    return a;
}

Arv* maximo(Arv *a){
    while (a->dir != NULL){
        a = a->dir;
    }
    return a;
}

void sucessor(Arv *a){
    if(a->dir != NULL){
       printf("Sucessor: %d ", minimo(a->dir));
    }
    Arv *aux = a->pai;
    while( aux != NULL && a == aux->dir){
        a = aux;
        aux = a->pai;
    }
    printf("Sucessor: %d", aux->info);
}

void predecessor(Arv *a){
    if(a->esq != NULL){
       printf("Predecessor: %d", maximo(a->esq));
    }
    Arv *aux = a->pai;
    while( aux != NULL && a == aux->esq){
        a = aux;
        aux = a->pai;
    }
    printf("Predecessor: %d", aux->info);
}