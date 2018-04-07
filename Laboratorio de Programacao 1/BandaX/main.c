//
// Created by gomes on 11/09/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum tipo {
    rock = 1, pop = 2, metal = 3, folk = 4
} Tipo;

typedef struct banda {
    char nome[81];
    Tipo genero;
    int numero;
    int posicao;
} Banda;

void inicializar(int n, Banda **b) {
    int c;
    for (c = 0; c < n; c++) {
        b[c] = NULL;
    }
}

void inserir(int n, Banda **b, int p) {

    if (p < 0 || p >= n) {
        printf("Posicao fora do limite do vetor\n");
    } else {
        b[p] = (Banda *) (malloc(sizeof(Banda)));

        printf("Digite o nome:\n");
        scanf(" %80[^\n]", &b[p]->nome);
        printf("Digite o genero:\n rock = 1\n  pop = 2\n metal = 3\n folk = 4\n");
        scanf("%d", &b[p]->genero);
        printf("Digite o numero de integrantes: \n");
        scanf("%d", &b[p]->numero);
        printf("Posicao no ranking (1 - 5)\n");
        scanf("%d", &b[p]->posicao);
    }
}

void imprimir(Banda **b, int c) {
    printf("Nome: %s\t", b[c]->nome);
    printf("Genero: ");
    switch (b[c]->genero) {
        case rock:
            printf(" rock\t");
            break;
        case pop:
            printf(" pop\t");
            break;
        case metal:
            printf(" metal\t");
            break;
        case folk:
            printf(" folk\t");
            break;
    }
    printf("Integrantes: %d\t", b[c]->numero);
    printf("Posicao no ranking: %d\n\n", b[c]->posicao);
}

void imprimirtudo(int n, Banda **b) {
    int c;
    printf("Bandas:\n");
    for (c = 0; c < n; c++) {
        imprimir(b, c);
    }
}

void imprimeranking(Banda **b, int num) {
    int n, c;
    printf("Informe um numero de 1 a 5: \n");
    scanf("%d", &n);
    for (c = 0; c < num; c++) {
        if (b[c]->posicao == n) {
            imprimir(b, c);
        }
    }
}

void imprimetipo(Banda **b, int num) {
    int n, c;
    printf("Digite o tipo:\n rock = 1\n  pop = 2\n metal = 3\n folk = 4\n");
    scanf("%d", &n);
    for (c = 0; c < num; c++) {
        if (b[c]->genero == n) {
            imprimir(b, c);
        }
    }
}

void verificafav(Banda **b, int n) {
    char nome[81];
    int c, aux1 = 0;// contador aux1 para verificar se sao iguais

    printf("Informe o nome da banda: \n");
    scanf(" %80[^\n]", nome);
    for (c = 0; c < n; c++) {
        if (strcasecmp(b[c]->nome, nome) == 0) {
            aux1++; // devia incrementar aux1 apenas se sao iguais
        }
    }
    if (aux1 > 0) {
        printf("Banda eh favorita!\n\n");
    } else { // se n tem nenhuma igual aux1 sempre sera 0
        printf("Banda nao eh favorita!\n\n");
    }
}

void liberar(int n, Banda **b) {
    int c;
    for (c = 0; c < n; c++) {
        free(b[c]);
    }
    free(b);
}

int main() {
#define TAM 5
    Banda *banda[TAM];
    int opt, c;
    do {
        printf("\n===BANDAS FAVORITAS===\nEscolha uma opcao:\n0 - Sair\n1 - Inserir bandas\n2 - Mostrar bandas\n3 - Pesquisa Ranking\n4 - Pesquisa tipo\n5 - Verificar favorita\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nInserir\n");
                inicializar(TAM, banda);
                for (c = 0; c < TAM; ++c) {
                    printf("Banda %d\n", c + 1);
                    inserir(TAM, banda, c);
                }
                break;
            case 2:
                printf("\nMostrar bandas\n");
                imprimirtudo(TAM, banda);
                break;
            case 3:
                printf("\nPesquisa Ranking\n");
                imprimeranking(banda, TAM);
                break;
            case 4:
                printf("\nPesquisa Tipo\n");
                imprimetipo(banda, TAM);
                break;
            case 5:
                printf("\nVerificar favorita\n");
                verificafav(banda, TAM);
                break;
            case 0:
                liberar(TAM, banda);
                exit(0);
            default:
                printf("Opcao invalida!");
        }
    } while (opt != 0);
    return 0;
}
