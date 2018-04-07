// Lista 5
// 30/10/2017
// Jiovana Sousa Gomes (gomesjiovana@gmail.com)

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore *dir;
    struct arvore *esq;
} Arv;

Arv *criarVazia();
Arv *insere(Arv *a, int i);
Arv *exclui(Arv *a, int i);
int altura(Arv *a);
Arv *libera(Arv *a);
void imprimePre(Arv *a);
void imprimeSim(Arv *a);
void imprimePos(Arv *a);


#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

int main() {
    int opt, optt, v;
    Arv *arv;
    do{
        printf("\nESCOLHA UMA OPCAO\n1. Criar arvore\n2. Inserir elemento\n3. Excluir elemento\n4. Imprimir arvore\n5. Liberar e sair\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        switch (opt){
            case 1:
                arv = criarVazia();
                printf("Arvore criada.\n");
                break;
            case 2:
                printf("Informe valor para inserir:\n");
                scanf("%d",&v);
                arv = insere(arv, v);
                printf("Valor inserido! (Ou igual)\n");
                break;
            case 3:
                printf("Informe valor para excluir:\n");
                scanf("%d",&v);
                arv = exclui(arv, v);
                printf("Valor excluido!\n");
                break;
            case 4:
                printf("Impressao\n1. Pre-ordem\n2. Simetrico\n3. Pos-ordem\n");
                scanf("%d", &optt);
                if(optt == 1){
                    imprimePre(arv);
                }else if(optt == 2){
                    imprimeSim(arv);
                }else if(optt == 3){
                    imprimePos(arv);
                }
                break;
            case 5:
                libera(arv);
                exit(0);
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(opt!=5);
    return 0;
}

Arv *criarVazia() {
    return NULL;
};

Arv *insere(Arv *a, int i) {
    if (a == NULL) { // se arvore n existe
        a = (Arv *) malloc(sizeof(Arv));
        a->info = i;
        a->dir = NULL;
        a->esq = NULL;
    } else if (i < a->info) {// se nao verifica esq dir
        a->esq = insere(a->esq, i);
    } else  if (i > a->info) {
        a->dir = insere(a->dir, i);
    } else if (i == a->info){
        printf("Valor informado igual a raiz da arvore, digite outro!\n");
        return a;
    }
    return a;
}

Arv *exclui(Arv *a, int i) {
    if (a == NULL)
        return NULL;
    else if (i < a->info)
        a->esq = exclui(a->esq, i);
    else if (i > a->info)
        a->dir = exclui(a->dir, i);
    else { //achou nó
        if (a->esq == NULL && a->dir == NULL) { //nó sem filhos
            free(a);
            return NULL;
        } else if (a->dir == NULL) { //nó com filho a esquerda
            Arv *aux = a;
            a = a->esq;
            free(aux);
        } else if (a->esq == NULL) { // nó com filho a direita
            Arv *aux = a;
            a = a->dir;
            free(aux);
        } else { // nó com dois filhos
            Arv *temp = a->esq;
            while (temp->dir != NULL) { //substituir por maior valor da sae
                temp = temp->dir;
            }
            a->info = temp->info; // troca os dados
            temp->info = i;
            a->esq = exclui(a->esq, i);
        }
    }
    return a;
}

int altura(Arv *a) {
    if (a == NULL) {
        return -1;
    } else {
        return 1 + max(altura(a->esq), altura(a->dir));
    }
}

Arv *libera(Arv *a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

void imprimePre(Arv *a) {
    printf("<");
    if (a != NULL) {
        printf("%d", a->info);
        imprimePre(a->esq);
        imprimePre(a->dir);
    }
    printf(">");
}

void imprimeSim(Arv *a) {
    printf("<");
    if (a != NULL) {

        imprimePre(a->esq);
        printf("%d", a->info);
        imprimePre(a->dir);
    }
    printf(">");
}

void imprimePos(Arv *a) {
    printf("<");
    if (a != NULL) {
        imprimePre(a->esq);
        imprimePre(a->dir);
        printf("%d", a->info);
    }
    printf(">");
}
