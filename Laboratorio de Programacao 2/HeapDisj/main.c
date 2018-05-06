#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "disj.h"
int main() {
   int opt, optt, tam=0, x,y;
   Heap *hep = NULL;
   Conj *conj = NULL;

   do{
       printf("===>>Escolha uma opcao:\n1- Conjutos disjuntos\n2- Heap\n3- Sair\n");
       scanf("%d",&opt);
       switch (opt){
           case 1:
               do{
                   printf("\n===========>>Conjuntos Disjuntos:\n1- Make Set\n2- Find Set\n3- Merge Sets\n4- Print Sets\n5 - Voltar\n");
                   scanf("%d", &optt);
                   switch (optt){
                       case 1:
                           printf("Insira quantidade de conjuntos: \n");
                           scanf("%d", &tam);
                           conj = constructorConj(tam);
                           break;
                       case 2:
                           printf("Insira conjunto para achar set: \n");
                           scanf("%d", &x);
                           y = findSet(x,conj);
                           printf("Conjunto %d pertence a set [%d]", x, y);
                           break;
                       case 3:
                           printf("Insira conjuntos para unir:\n");
                           scanf("%d", &x);
                           scanf("%d",&y);
                           mergeSet(x,y,conj);
                           break;
                       case 4:
                           printSets(conj);
                           break;
                       case 5:
                           free(conj->vet);
                           free(conj);
                           printf("Voltando..\n");
                           break;
                   }
               }while(optt != 5);
               break;
           case 2:
               do {
                   printf("\n===========>>Heap:\n0- Construir heap\n1- Inserir\n2- Deletar\n3- Mostrar heap\n4- Mostrar raiz\n5- Voltar\n");
                   scanf("%d",&optt);
                   switch (optt){
                       case 0:
                           printf("Informe tamanho maximo do heap:\n");
                           scanf("%d", &tam);
                           hep = contructor(tam);
                           break;
                       case 1:
                           printf("Informe elemento para inserir:\n");
                           scanf("%d", &x);
                           insertHeap(x,hep);
                           break;
                       case 2:
                           x = removeMin(hep);
                           printf("%d foi deletado\n", x);
                           break;
                       case 3:
                           printHeap(hep);
                           break;
                       case 4:
                           printf("Raiz da heap: %d\n", getRaiz(hep));
                           break;
                       case 5:
                           free(hep->vet);
                           free(hep);
                           printf("Voltando..\n");
                           break;
                   }
               }while (optt!=5);
               break;
           case 3:
               exit(0);
       }
   }while (opt!=3);
    return 0;
}