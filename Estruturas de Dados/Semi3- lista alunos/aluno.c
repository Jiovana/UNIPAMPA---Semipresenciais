// Lista 3
// 22/09/2017
// Jiovana Sousa Gomes, gomesjiovana@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno{
    char nome[80];
    int nota1, nota2, nota3;

}; typedef struct aluno Aluno;

struct lista{
    Aluno *info;
    struct lista *ant;
    struct lista *prox;
}; typedef struct lista Lista;


Lista *criar(){
    return NULL;
}

Aluno *inseriraluno(){
    Aluno *alu = (Aluno*)malloc(sizeof(Aluno));

    printf("Digite um nome:\n");
    fflush(stdin);
    gets(alu->nome);
    printf("\nDigite as 3 notas: \n");
    fflush(stdin);
    scanf("%d%d%d", &alu->nota1,&alu->nota2,&alu->nota3);
    return alu;
}

Lista *inserirlista (int *cont, Lista *lst, Aluno *alu){
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = lst;
    while(p != NULL && (strcmp(p->info->nome, alu->nome) < 0)) {
        ant = p;
        p = p->prox;
    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info=alu;

    if(ant == NULL){
        novo->prox=lst;
        novo->ant=NULL;
        lst = novo;
    }else {
        novo->prox = ant->prox;
        novo->ant = ant;
        ant->prox = novo;
    }

    (*cont)++;
    return lst;
}

Lista *buscarelemento(Lista *lst, char nome[80]){

    Lista *p;
    for(p= lst; p!=NULL; p=p->prox){
        if(strcmp(p->info->nome,nome)==0) {
            return p;
        }
    }
    return NULL;
}

Lista *excluir(int *cont, Lista *lst, char nome[80]){
    Lista *p = buscarelemento(lst, nome);
    Lista *ant = NULL;

    if(p == NULL) {
        printf("Aluno nao encontrado, retornando lista original.\n");
        return lst;
    }
    if(lst == p){ // se for primeiro
        lst = p->prox;
    }else{ // se tiver no meio
        p->ant->prox = p->prox;
    }
    if(p->prox==NULL){ // se for o ultimo
        p->prox->ant = p->ant;
    }
    (*cont)--;
    printf("Aluno excluido!.\n");
    free(p);
    return lst;
}

void imprimir_it(Lista *lst){
    Lista *p;
    for(p=lst; p!= NULL; p = p->prox){
        printf("Nome:%s\t-\tNotas:%d|%d|%d\n",p->info->nome,p->info->nota1,p->info->nota2,p->info->nota3);
    }
}

void imprimir_rec(Lista *lst){
    if(lst!=NULL){
        printf("Nome:%s\t-\tNotas:%d|%d|%d\n",lst->info->nome,lst->info->nota1,lst->info->nota2,lst->info->nota3);
        imprimir_rec(lst->prox);
    }
}

void imprimir_inv_it(Lista *lst){
    Lista *p, *aux = 0;
    for(p=lst;p != NULL;p = p->prox){
        if(p->prox == NULL){
            aux = p;
        }
    }
    while(aux->ant != NULL){
        printf("Nome:%s\t-\tNotas:%d|%d|%d\n",aux->info->nome,aux->info->nota1,aux->info->nota2,aux->info->nota3);
        aux = aux->ant;
    };
}

void imprimir_inv_rec(Lista *lst){
    if(lst!=NULL){
        imprimir_inv_rec(lst->prox);
        printf("Nome:%s\t-\tNotas:%d|%d|%d\n",lst->info->nome,lst->info->nota1,lst->info->nota2,lst->info->nota3);
    }
}

void tamanho(int *cont){
    printf("Tamanho da lista: %d\n", *cont);
}

Lista *buscarnome(Lista *lst){
    char nome[80];
    int c = 0;
    Lista *p;
    fflush(stdin);
    printf("Buscar aluno\nDigite um nome:\n");
    gets(nome);
    for(p= lst; p!=NULL; p=p->prox){
        if(strcmp(p->info->nome,nome)==0){
            printf("Nome: %s \t", p->info->nome);
            printf("-\tNotas: %d|%d|%d\n", p->info->nota1,p->info->nota2,p->info->nota3);
            c++;
        }
    }
    if(c == 0){
        printf("Aluno nao encontrado.\n");
    }
    return lst;
}

void liberar(Lista *lst){
    Lista *p = lst;
    while(p != NULL){
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}



