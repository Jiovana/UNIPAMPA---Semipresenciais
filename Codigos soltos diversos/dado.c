#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void dado(){
	int cont, n, ac[6];
	do{
		n = ((rand()%5)+1);	
		switch (n){
			case 1:
				ac[0]++;
				break;
			case 2:
				ac[1]++;
				break;	
			case 3:
				ac[2]++;
				break;
			case 4:
				ac[3]++;
				break;	
			case 5:
				ac[4]++;
				break;	
			case 6:
				ac[5]++;
				break;
		}
		cont++;
	}while (cont<=1000000);
	
	for(cont=1;cont<=6;cont++){
		printf("O numero %d foi lancado %d vezes.\n", cont,ac[cont-1]);
	}
	
}


int main(int argc, char *argv[]) {
	srand(time(NULL));
	printf("Lancando dado 1 MILHAO DE VEZES... \n\n");
	dado();
	return 0;
}
