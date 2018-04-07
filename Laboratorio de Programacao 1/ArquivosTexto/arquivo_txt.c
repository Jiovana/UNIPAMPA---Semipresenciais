//Semipresencial 4
// 16/10/2017
//Jiovana Gomes


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[50];
    char email[100];
    int matricula;
    char telefone[20];
} Aluno;



void inicializar(int n, Aluno **a);
void inseriraluno(int n, Aluno **alu, int p, int *m);//insere dados em aluno
void atualizar(FILE *fp, Aluno **alu, int n);//atualiza o arquivo
void excluir(int n, Aluno **alu, int m);//exclui da vetor
void imprimir(FILE *fp);//imprime do arquivo
void liberar(int n, Aluno **a);//libera vetor
FILE * abrir(void);//abre o arquivo
void fechar(FILE *fp, Aluno **a, int n);//fecha o arquivo e libera a vetor

int main() {
#define TAM 50
    Aluno *a[TAM];
    inicializar(TAM, a);
    FILE *fp=NULL;
    int opt, aux,  m=0;//m é a matricula serial
    do{
        printf("\nEscolha uma opcao:\n1-Cadastrar aluno\n2-Excluir aluno\n3-Imprimir alunos\n4-Sair\n");
        scanf("%d", &opt);
        setbuf(stdin,NULL);
		
        switch (opt){
            case 1:
                printf("Cadastrando...\nInsira posicao: \n");
                scanf("%d", &aux);
				setbuf(stdin,NULL);
		        inseriraluno(TAM, a, aux, &m);
                atualizar(fp, a, m);
                break;
            case 2:
                printf("Excluindo...\nInsira matricula: \n");
                scanf("%d", &aux);
                excluir(TAM, a, aux);
                atualizar(fp, a, TAM);
                break;
            case 3:
                printf("Imprimindo...\n");
                imprimir(fp);
                break;
            case 4:
                printf("Saindo...\n");
                fechar(fp, a, TAM);
                exit(0);
            default:
                printf("Opcao invalida...\n");
                break;
        }
    }while (opt!=4);

    return 0;
}

void inicializar(int n, Aluno **a) {
    int c;
    for (c = 0; c < n; c++) {
        a[c] = NULL;
    }
}

void inseriraluno(int n, Aluno **alu, int p, int *m) {

    if (p < 0 || p >= n) {
        printf("Posicao fora do limite do vetor\n");
    } else {
        alu[p] = (Aluno*)malloc(sizeof(Aluno));
        (*m)++;
        printf("Digite o nome:\n");
        fflush(stdin);
        gets(alu[p]->nome);
        fflush(stdin);
        setbuf(stdin,NULL);
        printf("\nDigite o email: \n");
        fflush(stdin);
        gets(alu[p]->email);
        setbuf(stdin,NULL);
        alu[p]->matricula = *m; //matricula serial
        printf("\nDigite o telefone: \n");
        fflush(stdin);
        gets(alu[p]->telefone);
        setbuf(stdin,NULL);
        printf("Aluno inserido!\n");
    }
}

void atualizar(FILE *fp, Aluno **alu, int n){ // nao funciona
	printf("total de alunos cadastrados %d\n",n);
    fp = abrir(); // devia abrir o arquivo no modo w+, destruindo dados anteriores e atualizando com os atuais da lista
    /*fp = fopen("file.txt","w");
    if(fp == NULL)
		printf("erro ao abrir o arquivo\n");
		**/
    for (int c = 0; c < n; c++) {
        printf("%d %s %s %s\n",alu[c]->matricula,alu[c]->nome,alu[c]->email,alu[c]->telefone);
        fprintf(fp,"%d %s %s %s\n",alu[c]->matricula,alu[c]->nome,alu[c]->email,alu[c]->telefone);
    }
    fclose(fp);
    printf("Arquivo atualizado\n");
}

void excluir(int n, Aluno **alu, int m){
    for (int c = 0; c < n; c++) {
        if (alu[c]->matricula == m) {
            free(alu[c]);
            alu[c] = NULL;
            printf("Aluno excluido!\n");
        }else{
            printf("Nao ha alunos com essa matricula\n");
        }
    }
}

void imprimir(FILE *fp){ //nao funciona
    char c, nome[50], email[100], tel[20], linha[200];
    int mat;
    fp = abrir();

    while(fgets(linha, 200, fp)){
        int n = sscanf(linha, "%c %d %s %s %s", &c, &mat, nome, email, tel);
        if (n > 0){
            switch(c){
                case '#':
                    break;
                default:
                    printf("%c - Matricula: %d\tNome: %s\tEmail: %s\tTelefone: %s\n", c, mat, nome, email, tel);
                    break;
            }
        }
    }
    fclose(fp);
}

void liberar(int n, Aluno **a) {
    int c;
    for (c = 0; c < n; ++c) {
        free(a[c]);
    }
    free(a);
}

FILE *abrir(){
    FILE *fp = fopen("file.txt", "w+");
    if(fp==NULL){
        printf("Erro ao abrir o arquivo! Encerrando programa. \n");
        exit(1);
    }
    return fp;
}

void fechar(FILE *fp, Aluno **a, int n){
    fclose(fp);
    liberar(n, a);
}










