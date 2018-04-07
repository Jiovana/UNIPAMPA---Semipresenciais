//Lista 4
//13/10/2017
//Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdlib.h>
#include <stdio.h>
#include "filas.h"

#define N 10

typedef struct filav{
    float vet[N];
    int n, ini;
}FilaV;

typedef struct pilhafloat{
    float vet[N];
    int n;
} PilhaFloat;

PilhaFloat *criaPilhaFloat(){
    PilhaFloat *p = (PilhaFloat*)malloc(sizeof(PilhaFloat)); // aloca a pilha dinamicamente
    p->n = 0; // inicializa com 0 elementos
    return p;
}

int pilhaFloatvazia(PilhaFloat *p){
    return (p->n == 0);
}

void pilhaFloatPush (PilhaFloat *p, float v){ // inserir na pilha
    if(p->n == N ){
        printf(" Capacidade esgotada! \n");
    } else { // insere no topo
        p->vet[p->n] = v;
        p->n++;
        printf("Push!");
    }
}

float pilhaFloatPop (PilhaFloat *p){ // retirrar da pilha
    float v;
    if(pilhaFloatvazia(p)){
        printf("Pilha vazia, não dá pra excluir!! \n");
    }else { // retira elemento do topo
        v = p->vet[p->n-1];
        p->n--;
        return  v;
    }
}

FilaV *inverterV(FilaV *f){
    PilhaFloat *p = criaPilhaFloat();
    FilaV *inv = criarV();
    for (int i = f->ini; i < f->n ; i++) {
        pilhaFloatPush(p,f->vet[(f->ini + i)%N]);
    }
    for (int j = -9; j < p->n ; j++) { // problema aqui - inverte mas o valor innicial de j tem q ser fixo, o que não é bom
        inserirV(inv,pilhaFloatPop(p));
    }
    printf("Fila invertida!\n");
    return inv;
}

FilaV* criarV(){
    FilaV *f = (FilaV*)malloc(sizeof(FilaV));
    f->n = 0;
    f->ini = 0;
    printf("Fila criada!\n");
    return f;
}

void inserirV(FilaV *f, float v){
    int fim;
    if(f->n != N){
        fim = (f->ini +f->n)%N;
        f->vet[fim] = v;
        f->n++;
        printf("Elemento inserido!\n");
    } else {
        printf("Fila cheia!\n");
    }
}

float retirarV (FilaV *f){
    float v;
    if(f->n != 0){
        v= f->vet[f->ini];
        f->n--;
        f->ini = (f->ini +1)%N;
        return v;
    } else {
        printf("Fila vazia!\n");
    }
}

void imprimirV (FilaV *f){
    for (int i = 0; i < f->n ; i++) {
        printf("%f\t", f->vet[(f->ini + i)%N]);
    }
}

void liberarV (FilaV *f){
    free(f);
}