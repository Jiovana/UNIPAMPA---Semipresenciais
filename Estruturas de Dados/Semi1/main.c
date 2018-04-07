//Lista 2
//Data:08/09/2017
//Andrelise Nunes Lemos Pinheiro(andrelisenunes@hotmail.com), Eric Dias da Silva Rosso(e-mail:ericdiasrosso@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

int main ()
{
int e=0,ee=0;
Lista *atual;//variavel do tipo lista que indicará os elementos da lista
Aluno *ind;//variavel do tipo aluno que indicará nome e notas da struct	
while(e!=8)
 {
  printf("\n(1)CRIAR NOVA LISTA\n(2)INSERIR NOVO ELEMENTO\n(3)EXCLUIR ELEMENTO\n(4)IMPRIMIR LISTA\n(5)IMPRIMIR NUMERO DE NOS\n(6)BUSCAR ALUNO\n(7)LIMPAR LISTA\n(8)SAIR\n");
  scanf("%i",&e);
  ee=0;
  switch(e)
  {
   case 1:
   {
   	atual=crialista();
   	printf("Lista criada com sucesso!!");
   }
   break;
   case 2:
   	{
	ind=criaaluno();
	atual=inserirelem(atual, ind);
    }
   	break;
   case 3 :
	{	
   	atual=excluir(atual);
	}
   break;
 	case 4 :
  	{
  	 while(ee!=3)
   	{	
    printf("\n(1)EM ORDEM\n(2)AO INVERSO\n(3)VOLTAR\n");
    scanf("%i",&ee);	
    switch(ee)
    {
    case 1 :
	{
	lerordem(atual);
	}break;
	case 2 :
    {
	lerinverso(atual);
	}break;	
    }
    }	
    }break;
   case 5 :
   	{
   	imprimirqnt(atual);	
	}break;
   case 6 :
   {
   busca(atual);
   }
   break;
  
   case 7 :
   {
   	liberar(atual);
   }
   break;  
   case 8:
   {
   }break;
   default :
   {
   	printf ("Valor invalido!\n");
   }
  }
 }		
}
