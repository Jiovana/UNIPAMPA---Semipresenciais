//Lista 4
//13/10/2017
//Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct lista {
    float v;
    struct lista *prox;
}Lista;

typedef struct filal{
    Lista *ini;
    Lista *fim;
} FilaL;

FilaL *criarL(){
    FilaL *f = (FilaL*)malloc(sizeof(FilaL));
    f->ini = f->fim = NULL;
    printf("Fila criada!\n");
    return f;
}

void inserirL(FilaL *f, float v){
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
    printf("Elemento inserido!\n");
}

float retirarL(FilaL *f){
    Lista *t;
    float v;
    if (f->fim == NULL && f->ini == NULL){
        printf("Lista vazia!\n");
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

void imprimirL (FilaL *f){
    Lista *q;
    for (q = f->ini; q != NULL ; q = q->prox) {
        printf("%.2f\n", q->v);
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