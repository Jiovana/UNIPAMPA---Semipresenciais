//Lista 2
//Data:08/09/2017
//Andrelise Nunes Lemos Pinheiro(andrelisenunes@hotmail.com), Eric Dias da Silva Rosso(e-mail:ericdiasrosso@gmail.com)
typedef struct aluno Aluno;
typedef struct lista Lista;
Lista *crialista();
Lista *inserirelem(Lista *a, Aluno *indiv);
Aluno *criaaluno();
void imprimirqnt(Lista *a);
void lerordem(Lista *a);
void lerinverso(Lista *a);
Lista *busca(Lista *a);
Lista *excluir(Lista *lst);
void liberar(Lista *l);
