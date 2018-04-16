//Pesquisa e Classificação de Dados - Atividade Semi-Presencial 02 - 11/04/18
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
    }else if (m == 's'){
        fp = fopen("shell.txt", "wt");
    }else if(m == 'm'){
        fp = fopen("merge.txt", "wt");
    }else if (m == 'q'){
        fp = fopen("quick.txt", "wt");
    }else if(m == 'h'){
        fp = fopen("shell.txt", "rt");
    }else if (m == 'e'){
        fp = fopen("merge.txt", "rt");
    }else if(m =='u'){
        fp = fopen("quick.txt","rt");
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


double sortShell(FILE *fp, int qtd, int *vet){
    vet = readVector(fp,qtd,'r');
    clock_t t;
    int  i , j , aux;
    int gap =1;
    printf("Sorteando...\n");
    t = clock();
    while (gap<qtd){
        gap = 3*gap+1;
    }
    while (gap >1){
        gap /=3;
        for (i = gap; i < qtd; i++) {
            aux = vet[i];
            j = i;
            while (j >= gap && aux < vet[j-gap]){
                vet[j] = vet[j-gap];
                j = j - gap;
            }
            vet[j] = aux;
        }
    }
    t = clock() - t;
    writeOutput(fp, qtd, vet, 's');
    printf("Salvo!\n");
    free(vet);
    return ((double)t/(CLOCKS_PER_SEC/1000));
}

void merge(int *vet, int com, int meio, int fim){
    int com1 = com, com2 = meio+1,comAux = 0, tam = fim-com+1;
    int *vetAux;
    vetAux = (int*)malloc(tam* sizeof(int));
    while (com1 <= meio && com2 <= fim){
        if(vet[com1] < vet[com2]){
            vetAux[comAux] = vet[com1];
            com1++;
        }else{
            vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }
    while(com1 <= meio){
        vetAux[comAux] = vet[com1];
        comAux++;
        com1++;
    }
    while (com2 <= fim){
        vetAux[comAux] = vet[com2];
        comAux++;
        com2++;
    }
    for(comAux = com;comAux <= fim; comAux++){
        vet[comAux] = vetAux[comAux - com];
    }
    free(vetAux);
}

void sortMerge( int com, int fim, int *vet){
    if(com < fim){
        int meio = (fim+com)/2;
        sortMerge(com, meio,vet);
        sortMerge(meio+1,fim,vet);
        merge(vet,com,meio,fim);
    }
}

double sortMergeFull(FILE *fp, int qtd, int *vet){
    vet = readVector(fp,qtd,'r');
    clock_t t;
    printf("Sorteando...\n");
    t = clock();
    sortMerge(0,qtd-1,vet);
    t = clock() - t;
    writeOutput(fp, qtd, vet, 'm');
    printf("Salvo!\n");
    free(vet);
    return ((double)t/(CLOCKS_PER_SEC/1000));
}
void Quick(int *vet, int ini, int fim){
    int i, j, pivo, aux;
    i = ini;
    j = fim;
    pivo = vet[(ini + fim)/2];
   do{
        while (vet[i] < pivo && i < fim){
            i++;
        }
        while (vet[j] > pivo && j > ini ){
            j--;
        }
        if(i<=j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    } while(i <= j);
    if(ini < j){
        Quick(vet,ini,j);
    }
    if(i < fim){
        Quick(vet, i, fim);
    }
}
double sortQuick(FILE *fp, int qtd, int *vet){
    vet = readVector(fp,qtd,'r');
    clock_t t;
    printf("Sorteando...\n");
    t = clock();
    Quick(vet,0,qtd);
    t = clock() - t;
    writeOutput(fp, qtd, vet, 'q');
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
