//Pesquisa e Classificação de Dados - Atividade Semi-Presencial 02 - 11/04/18
// Jiovana Sousa Gomes - gomesjiovana@gmail.com
//
#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    int *vet = NULL;
    int aux;
    int qtd, opt, optt;
    double t1, t2, t3;
    t1 = t2 = t3 = -1;
    qtd = atoi(argv[1]);
    printf("Quantidade: %d\n", qtd);
    generateNum(fp, qtd);
    do {
        printf("~~SORTS~~\nEscolha opcao:\n1. Mostrar input\n2. Algoritmos\n3. Mostrar tempo de execucao\n4. Alterar quantidade\n5. Sair\n");
        fflush(stdin);
        scanf("%d", &optt);
        switch (optt){
            case 1:
                showVector(fp,qtd,'r');
                break;
            case 2:
                printf("ALGORITMOS DE ORDENAMENTO\nEscolha metodo:\n1. Shell sort\n2. Merge Sort\n3. Quick Sort\n");
                fflush(stdin);
                scanf("%d", &opt);
                switch (opt) {
                    case 1:
                        t1 = sortShell(fp, qtd, vet);
                        printf("Deseja ver os valores na tela(1-S/0-N)?\n");
                        scanf("%d", &aux);
                        if(aux==1){
                            showVector(fp, qtd, 'h');
                        }
                        break;
                    case 2:
                        t2 = sortMergeFull(fp, qtd, vet);
                        printf("Deseja ver os valores na tela(1-S/0-N)?\n");
                        fflush(stdin);
                        scanf("%d", &aux);
                        if(aux==1){
                            showVector(fp, qtd, 'e');
                        }
                        break;
                    case 3:
                        t3 = sortQuick(fp, qtd, vet);
                        printf("Deseja ver os valores na tela(1-S/0-N)?\n");
                        fflush(stdin);
                        scanf("%d", &aux);
                        if(aux==1){
                            showVector(fp, qtd,'u');
                        }
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;
            case 3:
                printf("Tempos (ms):\nShell: %lf\nMerge: %lf\nQuick: %lf\n", t1,t2,t3);
                break;
            case 4:
                printf("Informe a quantidade:\n");
                fflush(stdin);
                scanf("%d", &qtd);
                generateNum(fp, qtd);
                break;
            case 5:
                free(vet);
                exit(0);
            default:
                printf("Opcao invalida\n");
        }
    }while (optt!= 5);
    return 0;
}