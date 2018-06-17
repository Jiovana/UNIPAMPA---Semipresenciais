// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 04
// 08/06/2018
// Jiovana Sousa Gomes (gomesjiovana@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
   int opt;
   Lista *vetor;
   vetor = Construir();
   do{
       printf("\n========Tabela Hash com Encadeamento========\n");
       printf("1. Inserir item\n2. Excluir item\n3. Consultar tabela\n4. Exibir Registros\n0. Encerrar programa\n");
       printf("Escolha uma opcao >>>");
       scanf("%d", &opt);
       switch (opt){
           default:
               printf("Opcao errada!\n");
               break;
           case 1:
               printf("Inserir item\n\n");
               Inserir(vetor);
               break;
           case 2:
               printf("Excluir item\n\n");
               Excluir(vetor);
               break;
           case 3:
               printf("Consultar tabela:\n");
               Consultar(vetor);
               break;
           case 4:
               printf("Exibir Registros:\n");
               ExibirTudo(vetor);
               break;
           case 0:
               printf("Encerrando...\n");
               Encerrar(vetor);
       }
   }while (opt != 0);
    return 0;
}

