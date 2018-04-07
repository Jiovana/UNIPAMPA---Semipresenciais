//
// Created by gomes on 04/10/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include "calculadora.h"

typedef struct lista  {
    char info;
    struct lista *prox;
} Lista;

typedef struct pilhaop{
    Lista *prim;
    int n;
} PilhaOp;

#define N 20

typedef struct pilhafloat{
    float vet[N];
    int n;
} PilhaFloat;

typedef struct calc{
    PilhaFloat *valores;
    PilhaOp *operadores;
} Calculadora;

PilhaOp *criaPilhaOp(){
    PilhaOp *p = (PilhaOp*)malloc(sizeof(PilhaOp)); // cria a pilha
    p->prim = NULL;
    p->n = 0;
    return  p;
}

void pilhaOpPush (PilhaOp *p, char c){
    Lista *n = (Lista*)malloc(sizeof(Lista)); // aloca cada operando
    n->info = c;
    n->prox = p->prim; // o proximo vai ser o topo
    p->prim = n; // o topo vai ser o atual
    p->n++;
}

int pilhaOpvazia(PilhaOp *p){
    return (p->prim == NULL);
}

char pilhaOpPop (PilhaOp *p){
    Lista *t;
    char c;
    if(pilhaOpvazia(p)){
        printf("Pilha vazia!!\n");
    } else {
        t = p->prim;
        c = t->info;
        p->prim = t->prox; // o topo vai ser o prox
        p->n--;
        free(t); // liberando a posicao
        return c;
    }
}

void liberaPilhaOp(PilhaOp *p){
    Lista *q = p->prim;
    while(q!= NULL){
        Lista *t  = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void imprimePilhaOp(PilhaOp *p){
    printf("Pilha de operadores: \n");
    Lista *q;
    for (q = p->prim; q != NULL ; q = q->prox) {
        printf("%c\n", q->info);
    }
}

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

void liberaPilhaFloat(PilhaFloat *p){
    free(p);
}

void imprimePilhaFloat(PilhaFloat *p){
    printf("Pilha de valores: \n");
    for (int i = p->n-1; i >=0 ; i--) {
        printf("%.2f \n", p->vet [i]);
    }
}

Calculadora *criaCalc(){
    Calculadora *c = (Calculadora*)malloc(sizeof(Calculadora));
    c->operadores = criaPilhaOp();
    c->valores = criaPilhaFloat();
    printf("Calculadora criada\n");
    return c;
}

void imprimeCalc(Calculadora *calc){
    printf("Imprimindo calculadora: \n");
    imprimePilhaFloat(calc->valores);
    imprimePilhaOp(calc->operadores);
}

void insereOp(Calculadora *calc, char c){
    pilhaOpPush(calc->operadores, c);
    printf("Operador inserido!\n");
}

void insereNum(Calculadora *calc, float v){
    pilhaFloatPush(calc->valores, v);
    printf("Operando inserido!\n");
}

void realizaCalculo(Calculadora *calc){
    if(calc->valores->n < 2 || calc->operadores->n < 1){
        printf("Numero de operandos insuficiente\n");
    }else{
        float a, b, r;
        char op;
        a = pilhaFloatPop(calc->valores);
        b = pilhaFloatPop(calc->valores);
        op = pilhaOpPop(calc->operadores);

        switch(op){ // faz operacao
            case '+' : r = a + b; break;
            case '-' : r = a - b; break;
            case '*' : r = a * b; break;
            case '/' : r = a / b; break;
        }

        pilhaFloatPush(calc->valores, r); // empilha resultado
        printf("Calculo realizado!\n");
    }
}

void liberaCalc (Calculadora *c){
    liberaPilhaFloat(c->valores);
    liberaPilhaOp(c->operadores);
    free(c);
}