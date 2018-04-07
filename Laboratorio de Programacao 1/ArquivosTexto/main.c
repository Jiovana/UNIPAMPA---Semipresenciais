//Semipresencial 4
// 16/10/2017
//Jiovana Gomes


#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[50];
    char email[100];
    int matricula;
    char telefone[20];
} Aluno;

void inicializar(int n, Aluno **a); //inicializa vetor com null
int inseriraluno(int n, Aluno **alu, int *m);//insere dados em aluno, retorna inteiro (0,1,2)
void atualizar(FILE *fp, Aluno **alu, int m, int aux);//atualiza o arquivo, recebe fp, vetor,  matricula e o retorno de insercao ou remocao
int excluir(int m, Aluno **alu);//exclui da vetor, retorna inteiro (2,1)
void imprimir(FILE *fp);//imprime do arquivo
void liberar(int n, Aluno **a);//libera vetor
FILE * abrir(char m);//abre o arquivo, recebe char da funcao atualizar ou imprimir para definir modo de abertura

int main() {
#define TAM 50 //tamanho do vetor fixo
    Aluno *a[TAM];
    inicializar(TAM, a); //inicializa o vetor
    FILE *fp = NULL;
    int opt, aux = 0,  m=0;//m é a matricula serial, também contador de alunos
    do{
        printf("\nEscolha uma opcao:\n1-Cadastrar aluno\n2-Excluir aluno\n3-Imprimir alunos\n4-Sair\n");
        scanf("%d", &opt);
        setbuf(stdin,NULL); //limpa o buffer
        switch (opt){
            case 1:
                printf("Cadastrando...\n");
                aux = inseriraluno(TAM, a, &m); //aux pega o retorno da funcao e envia pra atualizar, que só atualiza realmente se aux for 2.
                atualizar(fp, a, m, aux);
                break;
            case 2:
                printf("Excluindo...\n");
                aux = excluir(m, a);
                atualizar(fp, a, m, aux);
                break;
            case 3:
                printf("Imprimindo...\n");
                imprimir(fp);
                break;
            case 4:
                printf("Saindo...\n");
                liberar(TAM, a);
                exit(0);
            default:
                printf("Opcao invalida...\n");
                break;
        }
    }while (opt!=4);
    return 0;
}

void inicializar(int n, Aluno **a) { // inicializa o vetor com null em tudp
    int c;
    for (c = 0; c < n; c++) {
        a[c] = NULL;
    }
}

int inseriraluno(int n, Aluno **alu, int *m) {
    int p;
    printf("Insira posicao: \n");
    scanf("%d", &p);

    if (p < 0 || p >= n) { // ver se a posicao existe
        printf("Posicao fora do limite do vetor\n");
        return 0;
    } else if(alu[p] != NULL) { // ver se ja n tem dados na posicao
        printf("Posicao ja possui dados, exclua o aluno de matricula %d antes de inserir novamente\n", alu[p]->matricula);
        return 1;
    }else{ // se esta ok entao insere e retorna 2
        alu[p] = (Aluno*)malloc(sizeof(Aluno));
        (*m)++;
        printf("Digite o nome:\n");
        fflush(stdin);
        gets(alu[p]->nome);
        printf("\nDigite o email: \n");
        fflush(stdin);
        gets(alu[p]->email);
        alu[p]->matricula = *m; //matricula serial
        printf("\nDigite o telefone: \n");
        fflush(stdin);
        gets(alu[p]->telefone);
        printf("Aluno inserido!\n");
        return 2;
    }
}

int excluir(int m, Aluno **alu){ // funcao basica de exclusao de vetor, conforme matricula
    int mat, aux = (-1);
    printf("Insira matricula: \n");
    scanf("%d", &mat);
    for (int c = 0; c < m; c++) {
        if (alu[c]->matricula == mat) { // vai achar a posicao do que eh pra ser excluido
            aux = c;
        }
    }
    if(aux > (-1)){ // se a posicao existe entao exclui e retorna 2
        free(alu[aux]);
        alu[aux] = NULL;
        printf("Aluno excluido!\n");
        return 2;
    }else{ // se nao retorna 1
        printf("Nao ha alunos com essa matricula\n");
        return 1;
    }
}

void atualizar(FILE *fp, Aluno **alu, int m, int aux){
    fp = abrir('w'); // abre o arquivo no modo escrita, destruindo dados anteriores e atualizando com os atuais da lista
    for (int c = 0; c < m; c++) {
        if(alu[c] != NULL && aux == 2) {// verifica se a posicao n ta vazia e foi feita alguma alteracao no vetor
            fprintf(fp, "%d;%s;%s;%s\n", alu[c]->matricula, alu[c]->nome, alu[c]->email, alu[c]->telefone);
        }
    }
    if(aux==2){ // aux so eh 2 se algo foi inserido ou excluido
        printf("Arquivo atualizado!\n");
    }
    fclose(fp);

}

void imprimir(FILE *fp){
    char nome[50], email[100], tel[20]; // variaveis pra guardar as coisas do arquivo
    int mat;
    fp = abrir('r');//abre no modo leitura
    while((fscanf(fp, "%d;%49[^;];%99[^;];%19[^\n]", &mat, nome, email, tel)) != EOF) { // vai ler pulando os ';'
        printf("Mat: %d\tNome: %s\tEmail: %s\tTel: %s\n", mat, nome, email, tel);
    }
    fclose(fp);
}

void liberar(int n, Aluno **a) { //liberar todos alunos alocados no vetor
    int c;
    for (c = 0; c < n; ++c) {
        free(a[c]);
    }
}

FILE *abrir(char m){ // abrir o arquivo , recebe char que vai dizer o modo
    FILE *fp;
    if(m == 'w'){ // se modo for escrita
        fp = fopen("file.txt", "wt");
    }else if(m == 'r'){ // ou leitura
        fp = fopen("file.txt", "rt");
    }
    if(fp==NULL){
        printf("Erro ao abrir o arquivo! Encerrando programa. \n");
        exit(1);
    }
    return fp;
}