#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>

int main() {
    int opt,tam;
    char* nome;
     descPilha *p;

    printf("Informe o tamanho da pilha:\n");
    scanf("%d",&tam);
    p = criaPilha(tam);
    do{
        printf("ESCOLHA UMA OPCAO:\n1.Inserir\n2.Excluir\n3.Tamanho\n4.Buscar\n5.Listar\n6.Sair\n");
        scanf("%d",&opt);
        switch (opt){
            case 1:
                pilhaPush(p);
                break;
            case 2:
                strcpy(nome,pilhaPop(p));
                printf("Aluno %s excluido da pilha\n", nome);
                break;
            case 3:
                retornaTamanho(p);
                break;
            case 4:
                buscarAluno(p);
                break;
            case 5:
                imprimePilha(p);
                break;
            case 6:
                liberaPilha(p);
                exit(0);
            default:
                printf("Nada.\n");
        }
    }while (opt != 6);
    return  0;
}