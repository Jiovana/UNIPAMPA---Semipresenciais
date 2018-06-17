//Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03 - 21/05/18
// Jiovana Sousa Gomes - gomesjiovana@gmail.com
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include <time.h>

Lista *criarLista() {
    Lista *l = malloc(sizeof(Lista));
    l->qtd = 0;
    l->info = malloc(sizeof(Aluno));
    l->prox = NULL;
    printf("Lista criada.\n");
    return l;
}

Aluno *inserirAluno(long codigo, char *nome, int faltas, float nota) {
    Aluno *alu = (Aluno *) malloc(sizeof(Aluno));
    alu->matricula = codigo;
    strcpy(alu->nome, nome);
    alu->faltas = faltas;
    alu->nota = nota;
    return alu;
}

Lista *inserirLista(Lista *lst) {
    long codigo;
    int faltas;
    char nome[40];
    float nota;
    printf("Informe o codigo:\n");
    scanf("%ld", &codigo);
    for (Lista *l = lst; l != NULL; l = l->prox) {
        if (codigo == l->info->matricula) {
            printf("Matricula ja existente. Insercao cancelada.\n");
            return lst;
        }
    }
    fflush(stdin);
    printf("Informe o nome:\n");
    gets(nome);
    fflush(stdin);
    printf("Informe a qtd de faltas:\n");
    scanf("%d", &faltas);
    fflush(stdin);
    printf("Informe a nota:\n");
    scanf("%f", &nota);

    clock_t t = clock();

    Lista *novo, *ant = NULL, *atual = lst;
    novo = (Lista *) malloc(sizeof(Lista));
    novo->info = inserirAluno(codigo, nome, faltas, nota);
    novo->prox = NULL;

    while (atual != NULL && atual->info->matricula <= novo->info->matricula) {
        ant = atual;
        atual = atual->prox;
    }
    if (ant == NULL) {
        novo->prox = lst;
        lst = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    t = clock() - t;
    lst->qtd++;
    printf("Tempo gasto em ms: %.3f\n", (double) t / (CLOCKS_PER_SEC / 1000));
    printf("Aluno inserido.\n");
    return lst;
}

Lista *inserirRandom(Lista *lst) {
    int tam, tam_nome;
    char *nome = (char*)malloc(sizeof(char));
    char *letras = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printf("Informe a quantidade de elementos:\n");
    scanf("%d", &tam);

    srand(time(NULL));
    clock_t t = clock();

    printf("For\n");
    for (int i = 0; i < tam; i++) {
        Lista *novo = (Lista *) malloc(sizeof(Lista));
        novo->info = (Aluno*)malloc(sizeof(Aluno));
        printf("Alocou\n");

        novo->info->matricula = i + 1;
        tam_nome = 3 + (rand() % 36);
        for (int j = 0; j < tam_nome; j++) {
            nome[j] = letras[ rand() % strlen(letras)];
        }
        strcpy(novo->info->nome, nome);
        novo->info->faltas = rand() % 60;
        novo->info->nota = (float)(rand() / (RAND_MAX / 10.00));

        printf("Aluno novo preenchido\n");

        Lista *ant = NULL;
        Lista *prox = lst;

        while (prox != NULL) {
            ant = prox;
            prox = prox->prox;
        }
        if (ant == NULL) {
            novo->prox = lst;
            lst = novo;
        } else {
            novo->prox = ant->prox;
            ant->prox = novo;
        }
        lst->qtd++;
    }
    t = clock() - t;

    printf("Tempo gasto em ms: %.3f\n", (double) t / (CLOCKS_PER_SEC / 1000));
    return lst;
}

Lista *excluirAluno(Lista *lst) {
    long codigo;
    int count = 0;
    printf("Informe o codigo:\n");
    scanf("%ld", &codigo);

    Lista *ant = NULL;
    Lista *l = lst;

    clock_t t = clock();

    while (l != NULL && (codigo != l->info->matricula)) {
        ant = l;
        l = l->prox;
    }
    int opt;
    if (l == NULL) {
        printf("Aluno nao encontrado\n");
        return lst;
    } else {
        printf("Aluno %s encontrado.Deseja excluir? (S-1/N-0)\n", l->info->nome);
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Exclusao confirmada.\n");
        } else {
            printf("Exclusao anulada.\n");
            return lst;
        }

        if (ant == NULL) {
            lst = l->prox;
        } else {
            ant->prox = l->prox;
        }
    }
    t = clock() - t;

    lst->qtd--;
    printf("Tempo gasto em ms: %.3f\n", (double) t / (CLOCKS_PER_SEC / 1000));
    printf("Aluno excluido.\n");
    free(l);
    return lst;
}

void imprimirLista(Lista *lst) {
    Lista *aux = lst;
    while (aux != NULL) {
        printf("Codigo[%ld]-->Nome:%s\tNota:%.2f\tFaltas:%d\n", aux->info->matricula, aux->info->nome, aux->info->nota,
               aux->info->faltas);
        aux=aux->prox;
    }
}

void liberarMem(Lista *lst) {
    Lista *p = lst;
    while (p != NULL) {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

Aluno *buscaSequencial(Lista *lst) {
    long codigo;
    printf("Informe o codigo:\n");
    scanf("%ld", &codigo);
    Aluno *a = NULL;
    int count = 0, count2 = 0;
    clock_t t = clock();
    for (Lista *p = lst; p != NULL; p = p->prox) {
        if (codigo == p->info->matricula) {
            printf("Codigo[%ld]-->Nome:%s\tNota:%.2f\tFaltas:%d\n", p->info->matricula, p->info->nome, p->info->nota,
                   p->info->faltas);
            a = p->info;
            count++;
        }
        count2++;
    }
    t = clock() - t;
    if (count == 0) {
        printf("O item pesquisado nao se encontra na tabela.\n");
    }
    if (a == NULL) {
        return NULL;
    }
    printf("Numero de comparacoes realizadas: %d\n", count2);
    printf("Tempo gasto em ms: %.3f\n", (double) t / (CLOCKS_PER_SEC / 1000));
    return a;
}

Aluno *buscaBinaria(Lista *lst, int ini, int fim) {
    long codigo, cod;
    printf("Informe o codigo:\n");
    scanf("%ld", &codigo);

    Lista *aux = lst, *atual;
    Aluno *al;
    int c1 = 0, c2 = 0, c3 = 0, meio = 0;
    clock_t t = clock();
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        atual = lst;
        c1 = 0;
        while (c1 != meio) {
            atual = atual->prox;
            c1++;
        }
        if (atual->info->matricula == codigo) {
            printf("Codigo[%ld]-->Nome:%s\tNota:%.2f\tFaltas:%d\n", atual->info->matricula, atual->info->nome,
                   atual->info->nota,
                   atual->info->faltas);
            al = atual->info;
            c2++;
            break;
        } else if (atual->info->matricula > codigo) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
        c3++;
        aux = aux->prox;
    }
    t = clock() - t;
    if (c2 == 0) {
        printf("O item pesquisado nao se encontra na tabela.\n");
        return NULL;
    }
    printf("Numero de comparacoes realizadas: %d\n", c3);
    printf("Tempo gasto em ms: %.3f\n", (double) t / (CLOCKS_PER_SEC / 1000));
    return al;
}

