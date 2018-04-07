#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char n[50], nn[50], nnn[50];
	
	printf("Digite 3 nomes: \n");
	scanf("%s%s%s",&n,&nn,&nnn);
	
	if(strcmp(n,nn) == 1 && strcmp(n,nnn) == 1){
		printf("Palavra %s e maior. \n", n);
	}else if(strcmp(nn,n) == 1 && strcmp(nn,nnn) == 1){
		printf("Palavra %s e maior. \n", nn);
	}else{
		printf("Palavra %s eh maior. \n", nnn);
	}
	
	return 0;
}
