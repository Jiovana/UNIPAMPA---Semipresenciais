typedef struct aluno Aluno;

typedef struct lista Lista;


Lista *criar();

Aluno *inseriraluno();

Lista *inserirlista (int *cont, Lista *lst, Aluno *alu);

Lista *excluir(int *cont, Lista *lst, char nome[80]);

void imprimir_it(Lista *lst);

void imprimir_rec(Lista *lst);

void imprimir_inv_it(Lista *lst);

void imprimir_inv_rec(Lista *lst);

void tamanho(int *cont);

Lista *buscarnome(Lista *lst);

void liberar(Lista *lst);
