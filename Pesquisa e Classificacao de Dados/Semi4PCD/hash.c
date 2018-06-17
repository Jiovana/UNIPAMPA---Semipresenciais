// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 04
// 08/06/2018
// Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

#define MAX 60

int funcaoHash(int cod){
    return (cod % MAX);
}

Lista* Construir(){
    Lista *lst = malloc(sizeof(Lista)*MAX);
    lst->tamanho = 0;
    for (int i = 0; i < MAX ; i++) {
        lst[i].inicio = NULL;
        lst[i].fim = NULL;
    }
    return lst;
}

int Buscar(Nodo *lst, int cod){
    int cont = 0;
    for (Nodo *aux = lst; aux != NULL ; aux = aux->prox) {
        if(aux->codigo == cod){
            return cont;
        }
        cont++;
    }
    return -1;
}

void Consultar(Lista *vet){
    int i=0, cod, index, codBusca;
    printf("Informe o codigo do produto: ");
    scanf("%d",&cod);

    index = funcaoHash(cod);

    Nodo *lista = vet[index].inicio;
    codBusca = Buscar(lista,cod);
    if(codBusca == -1){
        printf("O item pesquisado nao se encontra na tabela.\n");
    }else{
        Nodo *aux = lista;
        while(i != codBusca){
            aux = aux->prox;
            i++;
        }
        printf("Item encontrado:\n");
        printf("Codigo: %d - Nome: %s - Valor: %.2f\n", aux->codigo, aux->descricao, aux->valor);
    }
}
void Inserir(Lista *vet){
    int cod, index;
    char desc[40];
    float val;
    printf("Informe o codigo do produto: ");
    scanf("%d",&cod);
    fflush(stdin);
    printf("Informe a descricao do produto: ");
    gets(desc);
    fflush(stdin);
    printf("Informe o valor do produto: ");
    scanf("%f",&val);
    fflush(stdin);

    index = funcaoHash(cod); //acha indice correspondente na tabela
    printf("index %d\n", index);
    Nodo *lista = vet[index].inicio; //acha a lista correspondente ao indice

    Nodo *novo = malloc(sizeof(Nodo));
    novo->codigo = cod;
    strcpy(novo->descricao,desc);
    novo->valor = val;
    novo->prox = NULL;

    if(lista == NULL){ //se nao ha nada ainda naquela posicao do vetor
        vet[index].inicio  = novo;
        vet[index].fim = novo;
        vet->tamanho++;
    }else{
        int codBusca = Buscar(lista,cod);
        if(codBusca == -1){ // se ja ha itens na lista dessa posicao do vetor, inserir no final
            vet[index].fim->prox = novo;
            vet[index].fim = novo;
            vet->tamanho++;
        }else{
            printf("Chave ja existente na tabela!\n");
        }
    }
    printf("Qtd de elementos: %d\n",vet->tamanho);
}

void Excluir(Lista *vet){
    int cod, index, codBusca;
    printf("Informe o codigo do produto: ");
    scanf("%d",&cod);

    index = funcaoHash(cod);

    Nodo *lista = vet[index].inicio;

    if(lista == NULL){
        printf("Não há itens com o codigo informado. \n");
    }else{
        codBusca = Buscar(lista, cod);
        if(codBusca == -1){
            printf("Não há itens com o codigo informado. \n");
        }else{
            Nodo *aux = lista;
            if(aux->codigo == cod){
                vet[index].inicio = aux->prox;
                vet->tamanho--;
                printf("Item removido\n");
                return;
            }
            while (aux->prox->codigo != cod){
                aux = aux->prox;
            }
            if(vet[index].fim == aux->prox){
                aux->prox = NULL;
                vet[index].fim =  aux;
            }else{
                aux->prox = aux->prox->prox;
            }
            vet->tamanho--;
            printf("Item removido\n");
        }
    }
}
void ExibirTudo(Lista *vet){
    for (int i = 0; i < MAX; i++) {
        Nodo *aux = vet[i].inicio;
        if(aux == NULL){
            printf("Posicao [%d] -> \n", i);
        }else{
            printf("Posicao [%d] -> \n", i);
            while (aux != NULL){
                printf("Codigo: %d - Nome: %s - Valor: %.2f\n", aux->codigo, aux->descricao, aux->valor);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
    printf("Fator de carga da tabela: %.2f\n",((float)vet->tamanho/MAX) );
}

void Encerrar(Lista *vet){
    for (int i = 0; i < MAX; i++) {
        Nodo *aux = vet[i].inicio;
        if(aux != NULL){
            while (aux != NULL){
                Nodo *temp = aux;
                 aux = aux->prox;
                 free(temp);
            }
        }
        vet[i].inicio = NULL;
    }
}