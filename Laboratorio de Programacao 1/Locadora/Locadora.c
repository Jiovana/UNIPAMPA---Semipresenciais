//
// Jiovana Gomes (gomesjiovana@gmail.com)
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Locadora.h"

// total de filmes = 41
typedef struct filme {
    int codigo;
    char titulo[100];
    int ano;
    int quantidade;
    int locados;
    char genero[10];
} Filme;
//busca a posicao com base no codigo do filme, recebe a struct e o tamanho
int buscaPosCod(Filme **f, int t) {
    int cod, aux = (-1); // aux -1 para verificação nos ifs, já que o for inicia em 0
    printf("Insira codigo do filme: \n");
    scanf("%d", &cod);
    for (int c = 0; c < t; c++) {
        if (f[c]->codigo == cod) { // compara valor do vetor com o inserido pelo usuario para achar a posicao
            aux = c;
        }
    }
    if (aux > (-1)) { // se a posicao existe, retorna ela
        return aux;
    } else { // se nao retorna -1
        printf("Nao ha filmes com esse codigo\n");
        return (-1);
    }
}
// imprime as informações de uma posicao do vetor
void imprimir(Filme **f, int p) {
    printf("Codigo: %d - ", f[p]->codigo);
    printf("Titulo: %s\t", f[p]->titulo);
    printf("Ano: %d\t", f[p]->ano);
    printf("Quantidade: %d\t", f[p]->quantidade);
    printf("Genero: %s\n", f[p]->genero);
}
//imprime buscando atraves de um codigo
int imprimePorCodigo(Filme **f, int t) {
    int aux = 0;
    aux = buscaPosCod(f, t);
    if (aux == (-1)) {
        return 1;
    } else {
        printf("Resultados da busca: \n");
        imprimir(f, aux);
        return 0;
    }
}
//imprime comparando se existe um nome de um filme
void imprimePorNome(Filme **f, int t) {
    char nome[100];
    int aux = 0; //verificador de comparacao
    printf("Insira o nome do filme: \n");
    scanf("%100[^\n]", nome);
    printf("Resultados da busca: \n");
    for (int c = 0; c < t; c++) {
        if (strcasecmp(f[c]->titulo, nome) == 0) { //comparacao entre nome no vetor e nome inserido para achar a posicao
            imprimir(f, c);
            aux++;
        }
    }
    if (aux == 0) { //sera 0 se n existirem filmes com o nome
        printf("Nao ha filmes com esse nome.\n");
    }
}
//imprime buscando os filmes que pertencem ao ano informado
void imprimePorAno(Filme **f, int t) {
    int aux = 0, ano;
    printf("Insira o ano do filme: \n");
    scanf("%d", &ano);
    printf("Resultados da busca: \n");
    for (int c = 0; c < t; c++) {
        if (f[c]->ano == ano) { // vai achar a posicao
            imprimir(f, c);
            aux++;
        }
    }
    if (aux == 0) {
        printf("Nao ha filmes com esse ano.\n");
    }
}
//imprime buscando os filmes que pertencem ao genero informado
void imprimePorGen(Filme **f, int t) {
    char gen[10];
    int aux = 0;
    printf("Insira o genero do filme: \n");
    scanf("%10[^\n]", gen);
    printf("Resultados da busca: \n");
    for (int c = 0; c < t; c++) {
        if (strcasecmp(f[c]->genero, gen) == 0) { // vai achar a posicao
            imprimir(f, c);
            aux++;
        }
    }
    if (aux == 0) {
        printf("Nao ha filmes com esse genero.\n");
    }
}
//imprime todas posições do vetor
void imprimeTudo(Filme **f, int t) {
    printf("Filmes:\n");
    for (int c = 0; c < t; c++) {
        imprimir(f, c);
    }
}
//aluga um filme, diminuindo sua quantidade
void locar(Filme **f, int t) {
    int aux = buscaPosCod(f, t); // busca o codigo do filme a ser locado
    printf("Locar %s\n", f[aux]->titulo);
    if (f[aux]->quantidade == 0) { // verificacao se existem filmes no estoque
        printf("Numero de copias esgotado.\n");
    } else {
        (f[aux]->quantidade)--; // diminui a quantidade de filmes no estoque
        (f[aux]->locados)++; // e aumenta a quantidade de filmes locados
        printf("Filme locado com sucesso.\n");
    }

}
// funcao inversa a anterior, entrega um filme locado
void entregar(Filme **f, int t) {
    int aux = buscaPosCod(f, t); // busca o cod do filme  a ser entregue
    printf("Entregar %s\n", f[aux]->titulo);
    if (f[aux]->locados == 0) { // verificacao se os filmes ja estao todos em estoque
        printf("Todas copias disponiveis ja estao no estoque.\n");
    } else {
        (f[aux]->quantidade)++; //aumenta a quantidade de filmes em estoque
        (f[aux]->locados)--; // e diminui a quantidade de filmes locados
        printf("Filme devolvido com sucesso.\n");
    }

}
//abre o arquivo recebendo um char que dira as especificacoes de abertura
FILE *abrir(char m) {
    FILE *fp;
    if (m == 'r') { // se modo for leitura - preenche vetor
        fp = fopen("entrada.txt", "rt");
    } else if (m == 'a') { // ou escrita - relatorio ano
        fp = fopen("relatorioAno.txt", "wt");
    } else if (m == 'g') { // ou escrita - relatorio genero
        fp = fopen("relatorioGenero.txt", "wt");
    } else if (m == 'c') { // ou escrita - acervo completo
        fp = fopen("acervo_completo_atual.txt", "wt");
    }
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando programa. \n");
        exit(1);
    }
    return fp;
}

//inicializa e aloca o vetor, prenchendo alguns campos da struct com valores
void inicializar(int n, Filme **f) {
    int c;
    for (c = 0; c < n; c++) {
        f[c] = NULL;
    }
    for (c = 0; c < n; c++) {
        f[c] = (Filme *) malloc(sizeof(Filme));
        f[c]->codigo = c; // codigo começa em 0 e eh incrementado a cada laço
        f[c]->locados = 0; // inicia com 0 locados em todos filmes
    }
}
//libera o vetor
void liberar(int n, Filme **f) {
    int c;
    for (c = 0; c < n; ++c) {
        free(f[c]);
    }
    //free(f);
}

int retornaQtd(FILE *fp){
    int qtd;

    fp = abrir('r'); // abre o arquivo no modo r
    fscanf(fp, "%d\n", &qtd);//pega primeira linha contendo quantidade
    fclose(fp);

    printf("Quantidade de filmes: %d!\n", qtd);
    return qtd; //retorna quantidade
}
//passa o conteudo do arquivo para um vetor
void preencheVetor(FILE *fp, Filme **f) {
    int i = 0, aux = 0, b = 0, qtd;
    char linha[255], *res, *tok, *tok2;

    fp = abrir('r'); // abre o arquivo no modo r
    fscanf(fp, "%d\n", &qtd);//pega primeira linha contendo quantidade

    inicializar(qtd, f); // inicializa e aloca vetor

    while (!feof(fp) && i < qtd) { //enquanto n for eof ou do tamanho do vetor, fica no while
        res = fgets(linha, 255, fp); // pega uma linha
        if (res) // se não é NULL
            tok = strtok(linha, ";"); //se fgets dá certo, vai fazer primeira separacao
        int j = 0; // reinicializa o j para funcionar dentro do while seguinte
        while (tok != NULL) { // neste while vai fragmentar a string e colocar nos locais corretos de cada struct
            switch (j) {
                case 0: //primeira parte, nome
                    strcpy(f[i]->titulo, tok);
                    break;
                case 1: //segunda parte, ano
                    f[i]->ano = atoi(tok);
                    break;
                case 2: //terceira parte, quantidade
                    f[i]->quantidade = atoi(tok);
                    break;
                case 3: // quarta parte, genero
                    tok2 = strtok(tok,"\n"); // para retirar o /n presente no final de cada linha
                    strcpy(f[i]->genero, tok2);
                    break;
                default:
                    printf("Erro\n");
                    break;
            }
            tok = strtok(NULL, ";"); // vai dividir o restante
            j++;
        }
        i++;
    }
    fclose(fp);
    printf("Vetor preenchido!\n");
}

//relatorio buscando filmes com o ano informado
void relatorioAno(FILE *fp, Filme **f, int n) {
    int aux = 0, ano;
    printf("Insira o ano do filme: \n");
    scanf("%d", &ano);

    fp = abrir('a'); // abre o arquivo no modo escrita
    fprintf(fp, "Lista de filmes de %d\n", ano);
    for (int c = 0; c < n; c++) {
        if (f[c]->ano == ano) {
            fprintf(fp, "Codigo: %d Titulo: %s Ano: %d Copias: %d Genero: %s\n", f[c]->codigo, f[c]->titulo, f[c]->ano,
                    f[c]->quantidade, f[c]->genero); // escreve no arquivo as informacoes
            aux++;
        }
    }
    if (aux == 0) {
        fprintf(fp, "Nao ha filmes com esse ano.\n");
    }
    printf("Relatorio criado!\n");
    fclose(fp);
}
//relatorio buscando filmes com o genero informado
void relatorioGenero(FILE *fp, Filme **f, int n) {
    char gen[10];
    int aux = 0;
    printf("Insira o genero do filme: \n");
    scanf("%10[^\n]", gen);

    fp = abrir('g'); // abre o arquivo no modo escrita
    fprintf(fp, "Lista de filmes de %s\n", gen);
    for (int c = 0; c < n; c++) {
        if (strcasecmp(f[c]->genero, gen) == 0) {
            fprintf(fp, "Codigo: %d Titulo: %s Ano: %d Copias: %d Genero: %s\n", f[c]->codigo, f[c]->titulo, f[c]->ano,
                    f[c]->quantidade, f[c]->genero); // escreve no arquivo as informacoes
            aux++;
        }
    }
    if (aux == 0) {
        fprintf(fp, "Nao ha filmes com esse genero.\n");
    }
    printf("Relatorio criado!\n");
    fclose(fp);
}

//relatorio buscando todos os filmes com os valores do momento em que eh chamado
void acervoCompleto(FILE *fp, Filme **f, int n) {
    fp = abrir('c'); // abre o arquivo no modo escrita
    fprintf(fp, "Acervo completo\n");
    for (int c = 0; c < n; c++) {
        fprintf(fp, "Codigo: %d Titulo: %s Ano: %d Copias: %d Genero: %s\n", f[c]->codigo, f[c]->titulo, f[c]->ano,
                f[c]->quantidade, f[c]->genero); // escreve no arquivo as informacoes
    }
    printf("Relatorio criado!\n");
    fclose(fp);
}