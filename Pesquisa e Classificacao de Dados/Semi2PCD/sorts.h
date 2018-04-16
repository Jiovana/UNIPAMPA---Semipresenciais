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
double sortShell(FILE *fp, int qtd, int *vet);
void merge(int *vet, int com, int meio, int fim);
void sortMerge( int com, int fim, int *vet);
double sortMergeFull(FILE *fp, int qtd, int *vet);
void trocar(int *a, int *b);
int partir(int *vet, int low, int high);
void quick(int *vet, int low, int high);
void Quick(int *vet, int ini, int fim);
double sortQuick(FILE *fp, int qtd, int *vet);
void showVector(FILE *fp, int qtd, char c);


#endif //SEMI1PCD_SORTS_H
