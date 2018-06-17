//Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03 - 21/05/18
// Jiovana Sousa Gomes - gomesjiovana@gmail.com
//

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"


int main() {

    Lista *lst;
    int opt;
    do{
        printf("Escolha opcao:\n0- Sair\n1- Criar Lista\n2- Inserir Aluno\n3- Inserir Entradas Aleatorias\n4- Excluir Aluno\n5- Busca Sequencial\n6- Busca Binaria\n7- Imprimir\n");
        scanf("%d", &opt);
        switch (opt){
            case 1:
                lst = criarLista();
                break;
            case 2:;
                lst = inserirLista(lst);
                break;
            case 3:
                lst = inserirRandom(lst);
                break;
            case 4:
                lst = excluirAluno(lst);
                break;
            case 5:
                buscaSequencial(lst);
                break;
            case 6:
                buscaBinaria(lst,0,lst->qtd);
                break;
            case 7:
                imprimirLista(lst);
                break;
            case 0:
                liberarMem(lst);
        }
    }while (opt!=0);
    return 0;
}