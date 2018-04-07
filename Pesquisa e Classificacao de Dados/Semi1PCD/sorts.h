//Pesquisa e Classificação de Dados - Atividade Semi-Presencial 01 - 26/03/18
// Jiovana Sousa Gomes - gomesjiovana@gmail.com
//
#include <stdio.h>

#ifndef SEMI1PCD_SORTS_H
#define SEMI1PCD_SORTS_H

FILE *Open(char m);
void generateNum(FILE *fp, int qtd);
int* readVector(FILE *fp,int qtd, char c);
void writeOutput(FILE *fp, int qtd, int *vet, char c);
double sortBubble(FILE *fp, int qtd, int *vet);
double sortSelect(FILE *fp, int qtd, int *vet);
double sortInsert(FILE *fp, int qtd, int *vet);
void showVector(FILE *fp, int qtd, char c);


#endif //SEMI1PCD_SORTS_H
