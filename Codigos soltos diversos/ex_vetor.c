#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int x, y, aux, vetAt[100];
	
	for(x=0;x<100;x++){
		printf("Insira o %d numero: ", x+1);
		scanf("%d",&vetAt[x]);
	}
	for(x=0;x<100;x++){
		for(y=x+1;y<100;y++){
			if(vetAt[x]>vetAt[y]){
				aux = vetAt[x];
				vetAt[x] = vetAt[y];
				vetAt[y] = aux;
			}
		}
	}
	printf("Em ordem crescente: \n");
	for(x=0;x<100;x++){
		printf("%d \n",vetAt[x]);
	}

	return 0;
}
