//Lista 4
//13/10/2017
//Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {

    int opt;
    float v;
    FilaL *fila;

    do {
        printf("\n==ESCOLHA UMA OPCAO==\n1- Criar fila\n2- Inserir elemento\n3- Retirar elemento\n4- Imprimir fila\n5- Liberar e sair\n");
        scanf(" %d", &opt);
        switch (opt) {
            case 1:
                printf("Criando fila\n");
                fila = criarL();
                break;
            case 2:
                printf("Inserir elemento\nInforme um numero: \n");
                scanf("%f", &v);
                inserirL(fila, v);
                break;
            case 3:
                printf("Retirar elemento\n");
                v = retirarL(fila);
                printf("O elemento %.2f foi excluido\n", v);
                break;
            case 4:
                printf("Imprimir fila\n");
                imprimirL(fila);
                break;
            case 5:
                printf("Saindo!\n");
                liberarL(fila);
                exit(0);
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while (opt != 5);

    return 0;
}