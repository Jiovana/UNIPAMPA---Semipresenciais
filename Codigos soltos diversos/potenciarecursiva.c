#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int pot(int b, int p){
	if(p==0){
		return 1;
	}else{
		return b*pot(b,p-1);
	}
}


int main(int argc, char *argv[]) {
	
	int b, p;
	printf("Digite base e potencia:\n");
	scanf("%d%d",&b,&p);
	
	printf("Resultado: %d",pot(b,p));
	
	return 0;
}
