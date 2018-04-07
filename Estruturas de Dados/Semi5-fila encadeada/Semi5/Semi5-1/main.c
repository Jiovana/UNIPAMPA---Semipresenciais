//Lista 4
//13/10/2017
//Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

int main() {

    int opt;
    float v;
    FilaV *fila;

    do {
        printf("\n==ESCOLHA UMA OPCAO==\n1- Criar fila\n2- Inserir elemento\n3- Retirar elemento\n4- Inverter a fila\n5- Imprimir fila\n6- Liberar e sair\n");
        scanf(" %d", &opt);
        switch (opt) {
            case 1:
                printf("Criando fila\n");
                fila = criarV();
                break;
            case 2:
                printf("Inserir elemento\nInforme um numero: \n");
                scanf("%f", &v);
                inserirV(fila, v);
                break;
            case 3:
                printf("Retirar elemento\n");
                v = retirarV(fila);
                printf("O elemento %.2f foi excluido\n", v);
                break;
            case 4:
                printf("Inverter fila\n");
                fila = inverterV(fila);
                break;
            case 5:
                printf("Imprimir fila\n");
                imprimirV(fila);
                break;
            case 6:
                printf("Saindo!\n");
                liberarV(fila);
                exit(0);
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while (opt != 6);

    return 0;
}