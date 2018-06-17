//
// Created by gomes on 20/05/2018.
//
typedef struct aluno{
    long matricula;
    char nome[40];
    int faltas;
    float nota;
}Aluno;

typedef struct lista{
    Aluno *info;
    struct lista *prox;
    int qtd;
}Lista;

Lista *criarLista();
Aluno* inserirAluno( long codigo, char *nome, int faltas, float nota);
Lista *inserirLista(Lista *lst);
void inserirRandom(Lista *lst);
Lista *excluirAluno(Lista *lst);
void imprimirLista(Lista *lst);
void liberarMem(Lista *lst);
Aluno *buscaSequencial(Lista *lst);
Aluno *buscaBinaria(Lista *lst, int ini, int fim);
