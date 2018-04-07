#include <stdio.h>
#include <stdlib.h>
#include "Locadora.h"

int main() {
#define TAM 41 //tamanho do vetor fixo
    Filme *f[TAM];
    FILE *fp = NULL;
    int opt, aux;

    int qtd = preencheVetor(fp,f,TAM); // preenche o vetor com o arquivo e armazena a quantidade lida
    printf("LOCADORA - TOTAL DE FILMES: %d", qtd);
    do{ // menu
        printf("\n====Escolha uma opcao====\n1-Locar filme\n2-Entregar Filme\n3-Buscar Filme\n4-Criar Relatorio\n5-Sair\n");
        scanf("%d", &opt);
        setbuf(stdin,NULL); //limpa o buffer
        switch (opt){
            case 1:
                locar(f,TAM);
                break;
            case 2:
                entregar(f,TAM);
                break;
            case 3:
                printf("Buscar Filme - Selecione Opcao:\n1. Buscar Todos Filmes\n2. Buscar por codigo\n3. Buscar por nome\n4. Buscar por ano\n5. Buscar por genero\n");
                scanf("%d", &aux);
                setbuf(stdin,NULL); //limpa o buffer
                switch (aux){
                    case 1:
                        imprimeTudo(f, TAM);
                        break;
                    case 2:
                        imprimePorCodigo(f, TAM);
                        break;
                    case 3:
                        imprimePorNome(f, TAM);
                        break;
                    case 4:
                        imprimePorAno(f,TAM);
                        break;
                    case 5:
                        imprimePorGen(f,TAM);
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
                        acervoCompleto(fp,f,TAM);
                        break;
                    case 2:
                        relatorioAno(fp,f,TAM);
                        break;
                    case 3:
                        relatorioGenero(fp,f,TAM);
                        break;
                    default:
                        printf("Opcao invalida, tente novamente");
                        break;
                }
                break;
            case 5:
                liberar(TAM, f);
                exit(0);
            default:
                printf("Opcao invalida...\n");
                break;
        }
    }while (opt!=5);
    return 0;
}