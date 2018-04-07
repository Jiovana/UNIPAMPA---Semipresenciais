#include <stdio.h>
#include <stdlib.h>
#include "Locadora.h"

int main() {

    FILE *fp = NULL;
    int qtd = retornaQtd(fp);

    int opt, aux;
    Filme *f[qtd];
    preencheVetor(fp,f); // preenche o vetor com o arquivo e armazena a quantidade lida
    printf("LOCADORA - TOTAL DE FILMES: %d", qtd);
    do{ // menu
        printf("\n====Escolha uma opcao====\n1-Locar filme\n2-Entregar Filme\n3-Buscar Filme\n4-Criar Relatorio\n5-Sair\n");
        scanf("%d", &opt);
        setbuf(stdin,NULL); //limpa o buffer
        switch (opt){
            case 1:
                locar(f,qtd);
                break;
            case 2:
                entregar(f,qtd);
                break;
            case 3:
                printf("Buscar Filme - Selecione Opcao:\n1. Buscar Todos Filmes\n2. Buscar por codigo\n3. Buscar por nome\n4. Buscar por ano\n5. Buscar por genero\n");
                scanf("%d", &aux);
                setbuf(stdin,NULL); //limpa o buffer
                switch (aux){
                    case 1:
                        imprimeTudo(f, qtd);
                        break;
                    case 2:
                        imprimePorCodigo(f, qtd);
                        break;
                    case 3:
                        imprimePorNome(f, qtd);
                        break;
                    case 4:
                        imprimePorAno(f,qtd);
                        break;
                    case 5:
                        imprimePorGen(f,qtd);
                        break;
                    default:
                        printf("Opcao invalida, tente novamente");
                        break;
                }
                break;
            case 4:
                printf("Criar Relatorio - Selecione Opcao:\n1. Acervo Completo\n2. Relatorio por ano\n3. Relatorio por genero\n");
                scanf("%d", &aux);
                setbuf(stdin,NULL); //limpa o buffer
                switch (aux){
                    case 1:
                        acervoCompleto(fp,f,qtd);
                        break;
                    case 2:
                        relatorioAno(fp,f,qtd);
                        break;
                    case 3:
                        relatorioGenero(fp,f,qtd);
                        break;
                    default:
                        printf("Opcao invalida, tente novamente");
                        break;
                }
                break;
            case 5:
                liberar(qtd, f);
                exit(0);
            default:
                printf("Opcao invalida...\n");
                break;
        }
    }while (opt!=5);
    return 0;
}