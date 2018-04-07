#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	char nome[10];
	int id;
} Lista;

el = 0;
void inserir(Lista *l, int i, char *n){
	int c, s;
	for(c=0;c<el;c++){
		if(l[c].id != 0){
			s++;
		}
	}
	if(s == e){
		l[el+1].id = i;
		l[el+1].nome = n;
		el++;
	}else{
		l[99].id = i;
		l[99].nome = n;
		el++;
	}
	return;
}

void imprimir(Lista *l, int id, char *n, int p){
	
	if(l[p].id == 0){
		printf("Nao ha elementos nessa posicao.\n");
	}else {
		printf("Posicao %d\n Id: %d \t Nome: %c \n ", p, l.id, l.nome);
	}
	return;
}
void imprimirtd(Lista *l){
	int c;
	for(c=0;c<el;c++){
		if(l[c].id != 0){
			printf(" Id: %d \t Nome: %c \n ", l.id, l.nome);
		}
	}
	return;
}
void remover(Lista *l, int p, int v{
	int c, s;
	for(c=0;c<el;c++){
		if(l[c].id != 0){
			s++;
		}
	}
	if(s == el){
		l[el].id = 0;
	}else{
		printf("A lista n possui elemento nessa posicao");
	}
	return;
}

void tamanho(Lista *l){
	int c, s=0;
	for(c=0;c<100;c++){
		if(l[c].id != 0){
			s++;
		}
	}
	printf("Tamanho da lista: %d", s);
	return;
	
}


int main(int argc, char *argv[]) {
	Lista l[100];
	int n,c, o, p, opt, id;
	char nome[10];
	
	for(c=0,c<100;c++){
		l[c].id = 0;
	}
	
	printf("Escolha uma opcao:\n1.inserir elemento\n2.imprimir elemento\n3.remover elemento\n4.tamanho da lista\n5.imprimir lista\n6.sair");
	scanf("%d",&opt);
	do{

	switch(opt){
		case 1:
			printf("Insira elemento (id/nome):\n");
			scanf("%d%c", &id,nome);
			inserir(&l,id,&nome);
			break;
		case 2: 
			
			
	}
	}while(opt!=6);
	return 0;
}
