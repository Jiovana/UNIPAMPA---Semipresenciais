#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct end{
	char rua [50];
	int num;
}; 
typedef struct end End;

struct aluno{
	int mat;
	char nome[80];
	End* endereco;
	char tel[20];
};
typedef struct aluno Aluno;

void inicializa (int n, Aluno** a){
	int i;
	for(i=0;i<n;i++){
		a[i] = NULL;
	}
}
void preenche(int n, Aluno** a, int i){
	if(i< 0||i>n){
		printf("Indice fora dos limites do vetor.\n");
		exit(1);
	}
	if(a[i] != NULL){
		printf("Posicao ja cadastrada.\n");
		return;
	}else{
		a[i] =(Aluno*)malloc(sizeof(Aluno));
		a[i]->endereco=(End*)malloc(sizeof(End));
		printf("Matricula:");
		scanf("%d",&a[i]->mat);
		printf("Nome:");
		scanf("%80[^\n]",&a[i]->nome);
		printf("Rua:");
		scanf("%50[^\n]",&a[i]->endereco->rua);
		printf("Numero:");
		scanf("%d",&a[i]->endereco->num);
		printf("Telefone:");
		scanf("%20[^\n]",&a[i]->tel);
	}
}
void retira (int n, Aluno** a, int i){
	if(i<0 || i > n){
		printf("Indice fora dos limites do vetor.\n");
		exit(1);
	}
	if(a[i] != NULL){
		free(a[i]->endereco);
		free(a[i]);
		a[i]=NULL;
	}
} 





int main(int argc, char *argv[]) {
	return 0;
}
