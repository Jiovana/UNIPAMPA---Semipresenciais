//Lista 2
//Data:08/09/2017
//Andrelise Nunes Lemos Pinheiro(andrelisenunes@hotmail.com), Eric Dias da Silva Rosso(e-mail:ericdiasrosso@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

struct aluno{
char nome[80];
int nota1, nota2, nota3;	
};typedef struct aluno Aluno;

struct lista{
Aluno *info;
struct lista *prox;	    //ponteiro para o proximo elemento da lista
};typedef struct lista Lista;

Lista *crialista() //criando lista e retornando ela vazia
{
	return NULL;
}

Aluno *criaaluno(){
	Aluno *ind=(Aluno*)malloc(sizeof(Aluno));	//criando uma estrutura alocada dinam para inserir alunos	
	fflush(stdin);
	printf("Digite o nome do aluno:\n");
	gets(ind->nome);
	fflush(stdin);
	printf("\nDigite as notas 1, 2 e 3 do aluno: \n");
	scanf("%d%d%d", &ind->nota1,&ind->nota2,&ind->nota3);
	return ind;
}

Lista *inserirelem(Lista *a, Aluno *indiv){	
	Lista *novo;
	Lista *ant = NULL;
	Lista *proxi = a;
	while(proxi!=NULL && (strcmp(proxi->info->nome, indiv->nome) < 0))
	{
		ant=proxi;
		proxi=proxi->prox;
	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info=indiv;
	if(ant == NULL)
	{
	novo->prox=a;
	a = novo;	
	}
	else
	{
	novo->prox = ant->prox;	
	ant->prox = novo;
	}
return a;

}

void imprimirqnt(Lista *a){
int qnt=0;
 if (a != NULL) 
    {
        Lista *atual = a;
        while (atual != NULL)
        {
            qnt++;
            atual=atual->prox;
        }
    }
		printf("O numero de nos da lista e igual a: %d\n", qnt);
}

void lerordem(Lista *a){
	if(a != NULL)
	{
		puts(a->info->nome);
		printf("Notas=%d,%d,%d\n", a->info->nota1,a->info->nota2,a->info->nota3);
    	lerordem(a->prox);
	}
}

void lerinverso(Lista *a){
	if(a != NULL)
	{
		lerinverso(a->prox);
		puts(a->info->nome);
		printf("Notas=%d,%d,%d\n", a->info->nota1,a->info->nota2,a->info->nota3);
	}
}

Lista *busca(Lista *a){
char nome[80];
Lista *p;
	fflush(stdin);
	printf("Qual o nome do aluno: \n");
	gets(nome);
	for(p=a;p!=NULL;p=p->prox)
	{
		if(strcmp(p->info->nome, nome)==0)
		{
		puts(p->info->nome);
		printf("Notas=%d,%d,%d\n", p->info->nota1,p->info->nota2,p->info->nota3);	
		}	
	}
}
	
Lista *excluir(Lista *lst){
char nome[80];
Lista *ant = NULL; //ponteiro aux
Lista *p=lst; 
	fflush(stdin);
	printf("Qual o nome do aluno:\n");
	gets(nome);
	while(p != NULL && (strcmp(p->info->nome,nome)>0 || strcmp(p->info->nome,nome)<0)){
		ant=p;
		p=p->prox;
	}
	if(p==NULL){
		return lst;
	}
	if(ant==NULL){
	lst=p->prox;
	}else{
		ant->prox=p->prox;
	}
	free(p);
return lst;
}

void liberar(Lista *l){
Lista *p=l;
	while(p!=NULL){
	Lista *s = p->prox;
	free(p);
	p=s;
	}	
}
