// Lista 6
// 17/11/2017
// Jiovana Sousa Gomes (gomesjiovana@gmail.com)

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore *dir;
    struct arvore *esq;
    int altura;
} ArvAVL;

ArvAVL *criarVazia();
int retornaAltura(ArvAVL *a);
ArvAVL *rotDireita(ArvAVL *a);
ArvAVL *rotEsquerda(ArvAVL *a);
ArvAVL *rotEsqDir(ArvAVL *a);
ArvAVL *rotDirEsq(ArvAVL *a);
ArvAVL *insere(ArvAVL *a, int i);
ArvAVL *exclui(ArvAVL *a, int i);
int altura(ArvAVL *a);
ArvAVL *libera(ArvAVL *a);
void imprimePre(ArvAVL *a, FILE *fp);
void imprimeSim(ArvAVL *a, FILE *fp);
void imprimePos(ArvAVL *a, FILE *fp);
ArvAVL* buscar(ArvAVL *a, int n);
FILE *abrir(char m);


#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

int main() {
    int opt, optt, v;
    ArvAVL *arv;
    FILE *fp;
    do {
        printf("\nESCOLHA UMA OPCAO\n1. Criar arvore\n2. Inserir elemento\n3. Pesquisar Elemento\n4. Excluir elemento\n5. Imprimir arvore\n6. Liberar e sair\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        switch (opt) {
            case 1:
                arv = criarVazia();
                printf("Arvore criada.\n");
                break;
            case 2:
                printf("Informe valor para inserir:\n");
                scanf("%d", &v);
                arv = insere(arv, v);
                printf("Valor inserido!(Ou igual)\n");
                break;
            case 3:
                printf("Informe valor para buscar:\n");
                scanf("%d", &v);
                buscar(arv, v);
                break;
            case 4:
                printf("Informe valor para excluir:\n");
                scanf("%d", &v);
                arv = exclui(arv, v);
                printf("Valor excluido!\n");
                break;
            case 5:
                printf("Impressao (Relatorios gerados automaticamente)\n1. Pre-ordem\n2. Simetrico\n3. Pos-ordem\n");
                scanf("%d", &optt);
                if (optt == 1) {
                    fp = abrir('a');
                    imprimePre(arv, fp);
                    fclose(fp);
                } else if (optt == 2) {
                    fp = abrir('b');
                    imprimeSim(arv, fp);
                    fclose(fp);
                } else if (optt == 3) {
                    fp = abrir('c');
                    imprimePos(arv, fp);
                    fclose(fp);
                }
                break;
            case 6:
                libera(arv);
                exit(0);
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opt != 6);
    return 0;
}

ArvAVL *criarVazia() {
    return NULL;
};

int retornaAltura(ArvAVL *a) {
    if (a == NULL) {
        return -1;
    } else {
        return a->altura;
    }
}

ArvAVL *rotDireita(ArvAVL *a) {
    ArvAVL *aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a->altura = 1 + max(retornaAltura(a->esq), retornaAltura(a->dir));
    aux->altura = 1 + max(retornaAltura(aux->esq), retornaAltura(aux->dir));
    return aux;
}

ArvAVL *rotEsquerda(ArvAVL *a) {
    ArvAVL *aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a->altura = 1 + max(retornaAltura(a->esq), retornaAltura(a->dir));
    aux->altura = 1 + max(retornaAltura(aux->esq), retornaAltura(aux->dir));
    return aux;
}

ArvAVL *rotEsqDir(ArvAVL *a) {
    a->esq = rotEsquerda(a->esq);
    a = rotDireita(a);
    return a;
}

ArvAVL *rotDirEsq(ArvAVL *a) {
    a->dir = rotDireita(a->dir);
    a = rotEsquerda(a);
    return a;
}

ArvAVL *insere(ArvAVL *a, int i) {
    if (a == NULL) { // se arvore n existe
        a = (ArvAVL *) malloc(sizeof(ArvAVL));
        a->info = i;
        a->dir = NULL;
        a->esq = NULL;
        a->altura = 0;
        return a;
    } else if (i < a->info) {// se nao verifica esq dir
        a->esq = insere(a->esq, i);
        if (retornaAltura(a->esq) - retornaAltura(a->dir) == 2) {
            if (retornaAltura(a->esq->esq) - retornaAltura(a->esq->dir) == 1) {
                a = rotDireita(a);
            } else {
                a = rotEsqDir(a);
            }
        }
    } else if (i > a->info) {
        a->dir = insere(a->dir, i);
        if (retornaAltura(a->esq) - retornaAltura(a->dir) == -2) {
            if (retornaAltura(a->dir->esq) - retornaAltura(a->dir->dir) == -1) {
                a = rotEsquerda(a);
            } else {
                a = rotDirEsq(a);
            }
        }
    } else if (i == a->info) {
        printf("Valor informado igual a raiz da arvore, digite outro. Retornando arvore original\n");
        return a;
    }
    a->altura = 1 + max(retornaAltura(a->esq), retornaAltura(a->dir));
    return a;
}

ArvAVL *exclui(ArvAVL *a, int i) {
    if (a == NULL)
        return NULL;
    else if (i < a->info) {
        a->esq = exclui(a->esq, i);
        if (retornaAltura(a->esq) - retornaAltura(a->dir) == -2) {
            if (retornaAltura(a->dir->esq) - retornaAltura(a->dir->dir) == -1) {
                a = rotEsquerda(a);
            } else {
                a = rotDirEsq(a);
            }
        }
    } else if (i > a->info) {
        a->dir = exclui(a->dir, i);
        if (retornaAltura(a->esq) - retornaAltura(a->dir) == 2) {
            if (retornaAltura(a->esq->esq) - retornaAltura(a->esq->dir) == 1) {
                a = rotDireita(a);
            } else {
                a = rotEsqDir(a);
            }
        }
    } else { //achou nó
        if (a->esq == NULL && a->dir == NULL) { //nó sem filhos
            free(a);
            return NULL;
        } else if (a->dir == NULL) { //nó com filho a esquerda
            ArvAVL *aux = a;
            a = a->esq;
            free(aux);
        } else if (a->esq == NULL) { // nó com filho a direita
            ArvAVL *aux = a;
            a = a->dir;
            free(aux);
        } else { // nó com dois filhos
            ArvAVL *temp = a->esq;
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

int altura(ArvAVL *a) {
    if (a == NULL) {
        return -1;
    } else {
        return 1 + max(altura(a->esq), altura(a->dir));
    }
}

ArvAVL *libera(ArvAVL *a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

void imprimePre(ArvAVL *a, FILE *fp) {
    printf("<");
    fprintf(fp,"<");
    if (a != NULL) {
        printf("%d", a->info);
        fprintf(fp, "%d", a->info);
        imprimePre(a->esq, fp);
        imprimePre(a->dir, fp);
    }
    printf(">");
    fprintf(fp, ">");
}

void imprimeSim(ArvAVL *a, FILE *fp) {
    printf("<");
    fprintf(fp,"<");
    if (a != NULL) {
        imprimePre(a->esq, fp);
        printf("%d", a->info);
        fprintf(fp, "%d", a->info);
        imprimePre(a->dir, fp);
    }
    printf(">");
    fprintf(fp, ">");
}

void imprimePos(ArvAVL *a, FILE *fp) {
    printf("<");
    fprintf(fp,"<");
    if (a != NULL) {
        imprimePre(a->esq, fp);
        imprimePre(a->dir, fp);
        printf("%d", a->info);
        fprintf(fp, "%d", a->info);
    }
    printf(">");
    fprintf(fp, ">");
}

ArvAVL* buscar(ArvAVL *a, int n){
    if (a == NULL) {
        printf("Arvore vazia ou valor nao encontrado!\n");
    } else {
        if (a->info == n){
            printf("Valor encontrado: %d", n);
        } else if (a->info > n){
            return buscar(a->esq,n);
        } else return buscar(a->dir,n);
    }
}

FILE *abrir(char m) { // abrir o arquivo , recebe char que vai dizer o modo
    FILE *fp;
    if (m == 'a') { // ou escrita
        fp = fopen("saidaPreOrdem.txt", "wt");
    } else if (m == 'b') {
        fp = fopen("saidaSimetrica.txt", "wt");
    } else if (m == 'c') {
        fp = fopen("saidaPosOrdem.txt", "wt");
    }
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando programa. \n");
        exit(1);
    }
    return fp;
}
