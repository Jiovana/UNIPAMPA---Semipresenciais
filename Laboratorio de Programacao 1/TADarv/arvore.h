
typedef struct descritor_arvore  {
    int tamanho;
    struct arvore *raiz;
}Desc_Arv;

typedef struct arvore {
    int info;
    struct arvore *pai;
    struct arvore *dir;
    struct arvore *esq;
}Arv;

Arv *criarVazia();
Arv *insere(Arv *a, int i);
Arv *exclui(Arv *a, int i);
int altura(Arv *a);
Arv *libera(Arv *a);
void imprimePre(Arv *a);
void imprimeSim(Arv *a);
void imprimePos(Arv *a);
Arv* buscar(Arv *a, int n);
Arv *minimo(Arv *a);
Arv *maximo(Arv *a);
void sucessor(Arv *a);
void predecessor(Arv *a);

