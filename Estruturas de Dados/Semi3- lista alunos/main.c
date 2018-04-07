// Lista 3
// 22/09/2017
// Jiovana Sousa Gomes, gomesjiovana@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"


int main(){
    Lista *lista;
    Aluno *aluno;
    int cont = 0;
    int opt, optt;
    char nome[80];

    do{
        printf("\n======ESCOLHA UMA OPCAO=======\n 1) Criar uma lista\n 2) Inserir um elemento na Lista\n 3) Excluir um elemento da Lista\n 4) Imprimir os conteudos da Lista\n 5) Imprimir o numero de alunos da Lista\n 6) Buscar um aluno na Lista\n 7) Liberar a Lista e sair\n ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                lista = criar();
                printf("Lista criada!");
                break;
            case 2:
                printf("Insercao\n");
                aluno = inseriraluno();
                lista = inserirlista(&cont, lista, aluno);
                break;
            case 3:
                printf("Exclusao\nDigite um nome:\n");
                scanf(" %80[^\n]", nome);
                lista = excluir(&cont, lista, nome);
                break;
            case 4:
                printf("Impressao - Escolha 1 opcao:\n1.Em ordem (iterativa)\n2.Em ordem(recursiva)\n3.Ao inverso (iterativa)\n4.Ao inverso (recursiva)\n");
                scanf("%d",&optt);
                if(optt==1){
                    imprimir_it(lista);
                }else if(optt==2){
                    imprimir_rec(lista);
                }else if(optt=3){
                    imprimir_inv_it(lista);
                }else{
                    imprimir_inv_rec(lista);
                }
                break;
            case 5:
                tamanho(&cont);
                break;
            case 6:
                lista = buscarnome(lista);
                break;
            case 7:
                liberar(lista);
                printf("Lista liberada!");
                exit(0);
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(opt!=7);
    return 0;
}
