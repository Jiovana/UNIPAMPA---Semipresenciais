//
// Created by gomes on 19/03/2018.
//

#ifndef REVISAOLP2_PILHA_H
#define REVISAOLP2_PILHA_H

typedef struct InformacoesAlunos{
    int matricula;
    char nome[50];
    float media;
    struct InformacoesAlunos* prox;
} infoAlunos;

typedef struct descritorPilha{
    int quantidade;
    int maximo;
    infoAlunos* topo;
} descPilha;


descPilha *criaPilha(int m);
void pilhaPush(descPilha *p);
char* pilhaPop(descPilha *p);
void liberaPilha(descPilha *p);
void imprimePilha(descPilha *p);
void retornaTamanho(descPilha *p);
void buscarAluno(descPilha *p);

#endif //REVISAOLP2_PILHA_H
