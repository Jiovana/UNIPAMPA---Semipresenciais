#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int fibIt(int n);
int fibRec(int n);

int main(int argc, char *argv[]) {
	double tempo;
	clock_t ini = 0, fim=0;
	int num, opt, res;
	
	do{
		printf("\nDigite uma posicao:\n");
		scanf("%d", &num);
		printf("1 - Iterativo\n2 - Recursivo\n3 - Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				ini = clock();
				res = fibIt(num);
				fim = clock();
				tempo = (double)((fim - ini) / (CLOCKS_PER_SEC/1000000));
				
				printf("Resposta iterativa para posicao %d : %d\n", num, res);
				printf("Tempo gasto em ms: %f\n", tempo);
				break;
			case 2:
				ini = clock();
				res = fibRec(num);
				fim = clock();
				tempo = (double)((fim - ini) / (CLOCKS_PER_SEC/1000000));
				
				printf("Resposta recursiva para posicao %d : %d\n", num, res );
				printf("Tempo gasto em ms: %f\n", tempo);
				break;
			case 3:
				exit(0);
		}
	}while(opt!=3);

	return 0;
}

int fibIt (int n){	
	int a = 0, b = 1, c , i;
	if(n==1||n==2){
		return 1;
	}else {
		for( i = 0; i < n; i++){
			c = a+b;
			a=b;
			b=c;
		}
		return c;
	}
}

int fibRec (int n){
	if(n==0 || n==1){
		return 1;
	}else {
		return fibRec(n-2) + fibRec(n-1);
	}
}





