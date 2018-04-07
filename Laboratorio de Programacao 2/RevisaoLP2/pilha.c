//
// Created by gomes on 19/03/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

descPilha *criaPilha(int m){
    descPilha *p = (descPilha*)malloc(sizeof(descPilha));
    p->topo = NULL;
    p->maximo = m;
    p->quantidade = 0;
    return p;
}

void pilhaPush(descPilha *p){
    int mat;
    char nome[50];
    float med;

    if(p->quantidade < p->maximo){
        infoAlunos *al = (infoAlunos*)malloc(sizeof(infoAlunos));
        printf("Informe a  matricula:\n");
        scanf("%d", &mat);
        al->matricula = mat;
        printf("Informe o nome:\n");
        scanf("%s", nome);
        strcpy(al->nome,nome);
        printf("Informe a media:\n");
        scanf("%f",&med);
        al->media = med;

        al->prox = p->topo;
        p->topo = al;
        p->quantidade++;
        printf("Inserido!\n");
    }else{
        printf("Pilha cheia!\n");
    }
}

char* pilhaPop(descPilha *p){
    infoAlunos *a;
    char *nome = "";
    if(p->topo == NULL){
        printf("Pilha vazia!\n");
    } else{
        a = p->topo;
        strcpy(nome, a->nome);
        p->topo = a->prox;
        p->quantidade--;
        free(a);
        return nome;
    }
}

void liberaPilha(descPilha *p){
    infoAlunos *a = p->topo;
    while (a!=NULL){
        infoAlunos *al = a->prox;
        free(a);
        a = al;
    }
    free(p);
}

void imprimePilha(descPilha *p){
    printf("Pilha:\n");
    infoAlunos *a;
    for (a = p->topo; a!=NULL ; a = a->prox) {
        printf("Matricula: %d\n", a->matricula);
        printf("Nome: %s\n",a->nome);
        printf("Media: %f\n\n",a->media);
    }
}

void retornaTamanho(descPilha *p){
    printf("Tamanho da pilha atual: %d\n", p->quantidade);
}

void buscarAluno(descPilha *p){ //por nome
    char nome[20];
    int aux = 0;
    printf("Informe o nome do aluno: \n");
    scanf("%s", nome);
    infoAlunos *a;
    for (a = p->topo; a!=NULL ; a = a->prox) {
        if(strcasecmp(nome,a->nome)==0){
            printf("Matricula: %d\n", a->matricula);
            printf("Nome: %s\n",a->nome);
            printf("Media: %f\n",a->media);
            aux++;
        }
    }
    if(aux > 0)
        printf("Encontrado!\n");
    else
        printf("Não encontrado.\n");
}

void buscarAlunoo(descPilha *p){ //por matricula
    int aux = 0, mat;
    printf("Informe matricula do aluno: \n");
    scanf("%d", &mat);
    infoAlunos *a;
    for (a = p->topo; a!=NULL ; a = a->prox) {
        if(a->matricula == mat){
            printf("Matricula: %d\n", a->matricula);
            printf("Nome: %s\n",a->nome);
            printf("Media: %f\n",a->media);
            aux++;
        }
    }
    if(aux > 0)
        printf("Encontrado!\n");
    else
        printf("Não encontrado.\n");


}