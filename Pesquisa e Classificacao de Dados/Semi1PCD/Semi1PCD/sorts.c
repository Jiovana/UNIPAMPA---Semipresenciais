//Pesquisa e Classificação de Dados - Atividade Semi-Presencial 01 - 26/03/18
// Jiovana Sousa Gomes - gomesjiovana@gmail.com
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

FILE *Open(char m){
    FILE *fp;
    if(m == 'g'){
        fp = fopen("input.txt", "wt");
    }else if(m =='r'){
        fp = fopen("input.txt","rt");
    }else if (m == 'b'){
        fp = fopen("bubble.txt", "wt");
    }else if(m == 's'){
        fp = fopen("selection.txt", "wt");
    }else if (m == 'i'){
        fp = fopen("insertion.txt", "wt");
    }else if(m == 'u'){
        fp = fopen("bubble.txt", "rt");
    }else if (m == 'e'){
        fp = fopen("selection.txt", "rt");
    }else if(m =='n'){
        fp = fopen("insertion.txt","rt");
    }

    if(fp == NULL){
        printf("Erro ao abrir o arquivo. Encerrando.\n");
        exit(1);
    }
    return fp;
}

void generateNum(FILE *fp, int qtd){
    int *vet;
    vet = (int*) malloc(sizeof(int)*qtd);
    srand(time(NULL));
    for (int i = 0; i < qtd; i++) {
        vet[i] = rand()%(qtd*2);
    }
    fp = Open('g');
    for (int j = 0; j < qtd; j++) {
        fprintf(fp, "%d\t", vet[j]);
    }
    printf("Numeros gerados!\n");
    fclose(fp);
    free(vet);
}

int* readVector(FILE *fp,int qtd, char c){
    int *vet;
    vet = (int*)malloc(sizeof(int)*qtd);
    int i = 0;
    fp = Open(c);
    while(!feof(fp)){
        fscanf(fp,"%d", &vet[i]);
        i++;
    }
    fclose(fp);
    return vet;
}

void writeOutput(FILE *fp, int qtd, int *vet, char c){
    fp = Open(c);
    for (int j = 0; j < qtd; j++) {
        fprintf(fp, "%d\t", vet[j]);
    }
    fclose(fp);
}


double sortBubble(FILE *fp, int qtd, int *vet){
    vet = readVector(fp,qtd,'r');
    clock_t t;
    int aux;
    printf("Sorteando...\n");
    t = clock();
    for (int i = 0; i < qtd-1; i++) {
        for (int j = i+1; j < qtd ; ++j) {
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    t = clock() - t;
    writeOutput(fp, qtd, vet, 'b');
    printf("Salvo!\n");
    free(vet);
    return ((double)t/(CLOCKS_PER_SEC/1000));
}

double sortSelect(FILE *fp, int qtd, int *vet){
    vet = readVector(fp,qtd,'r');
    clock_t t;
    printf("Sorteando...\n");
    int aux, min;
    t = clock();
    for (int i = 0; i < qtd-1; i++) {
        min = i;
        for (int j = i+1; j < qtd; j++) {
            if(vet[j] < vet[min]){
                min = j;
            }

        }
        aux = vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
    }
    t = clock() - t;
    writeOutput(fp, qtd, vet, 's');
    printf("Salvo!\n");
    free(vet);
    return ((double)t/(CLOCKS_PER_SEC/1000));
}

double sortInsert(FILE *fp, int qtd, int *vet){
    vet = readVector(fp,qtd,'r');
    clock_t t;
    printf("Sorteando...\n");
    int aux;
    t = clock();
    for (int i = 1; i < qtd; i++) {
        aux = vet[i];
        int j = i-1;
        while(j >=0 && vet[j] > aux){
            vet[j+1] = vet[j];
            j = j-1;
        }
        vet[j+1] = aux;
    }
    t = clock() - t;
    writeOutput(fp, qtd, vet, 'i');
    printf("Salvo!\n");
    free(vet);
    return ((double)t/(CLOCKS_PER_SEC/1000));
}

void showVector(FILE *fp, int qtd, char c){
    int *vet = readVector(fp, qtd,  c);
    for (int i = 0; i < qtd; i++) {
        printf("%d\t", vet[i]);
    }
    printf("\n");
    free(vet);
}
