#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct nodo_t {
	int chave;
	struct nodo_t *prox;
};
typedef struct nodo_t Nodo;



int main(int argc, char *argv[]) {

	
	Nodo *ptLista=NULL;
	Nodo *novo;
	Nodo *ant = NULL;
	Nodo *ptaux = ptLista;
	novo = (Nodo*)malloc(sizeof(Nodo));
	novo->chave = 1;
	while((ptaux!=NULL) && (str))
	
		return 0;
}

TipoPtNo* insere_ord (TipoPtNo* ptLista, TipoInfoNo dados)
{
TipoPtNo *novo; //novo elemento
TipoPtNo *ant = NULL; //ponteiro auxiliar para a posição anterior
TipoPtNo *ptaux = ptLista; //ponteiro auxiliar para percorrer a lista
novo = (TipoPtNo*) malloc(sizeof(TipoInfoNo)); /*aloca um novo nodo */
novo->info = dados; /*insere a informação no novo nodo*/
/*procurando a posição de inserção*/
while ((ptaux!=NULL) && (strcmp(ptaux->info.titulo,dados.titulo)<0))
//se info.titulo < dados.titulo então strcmp retorna um valor menor que zero
{
ant = ptaux;
ptaux = ptaux->prox;
}
/*encaeia o elemento*/
if (ant == NULL) /*o anterior não existe, insere na primeira posição*/
{
novo->prox = ptLista;
ptLista = novo;
}
else /*elemento inserido no meio da lista*/
{
novo->prox = ant->prox;
ant->prox = novo;
}
return ptLista;
}
