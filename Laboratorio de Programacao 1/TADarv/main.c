#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    int opt, optt, v;
    Desc_Arv *desc;
    Arv *arv, *aux;
    desc->raiz = arv;
    do{
        printf("\nESCOLHA UMA OPCAO\n1. Criar arvore\n2. Inserir elemento\n3. Excluir elemento\n4. Buscar elemento\n5. Imprimir arvore\n6. Minimo\n7. Maximo\n8. Sucessor\n9. Predecessor\n10. Liberar e sair\n");
        scanf("%d", &opt);
        setbuf(stdin, NULL);
        switch (opt){
            case 1:
                arv = criarVazia();
                printf("Arvore criada.\n");
                break;
            case 2:
                printf("Informe valor para inserir:\n");
                scanf("%d",&v);
                arv = insere(arv, v);
                printf("Valor inserido! (Ou igual)\n");
                break;
            case 3:
                printf("Informe valor para excluir:\n");
                scanf("%d",&v);
                arv = exclui(arv, v);
                printf("Valor excluido!\n");
                break;
            case 4:
                printf("Informe valor para buscar:\n");
                scanf("%d", &v);
                buscar(arv, v);
                break;
            case 5:
                printf("Impressao\n1. Pre-ordem\n2. Simetrico\n3. Pos-ordem\n");
                scanf("%d", &optt);
                if(optt == 1){
                    imprimePre(arv);
                }else if(optt == 2){
                    imprimeSim(arv);
                }else if(optt == 3){
                    imprimePos(arv);
                }
                break;
            case 6:
                aux =  minimo(arv);
                printf("Minimo: %d", aux->info);
                break;
            case 7:
                aux = maximo(arv);
                printf("Maximo: %d", aux->info);
                break;
            case 8:
                printf("Nao funciona!\n");
                //sucessor(arv);
                break;
            case 9:
                printf("Nao funciona!\n");
                //predecessor(arv);
                break;
            case 10:
                libera(arv);
                exit(0);
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(opt!=10);
    return 0;
}