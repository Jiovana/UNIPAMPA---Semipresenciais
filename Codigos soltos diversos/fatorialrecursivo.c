#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fact(int n){
	if(n==0){
		return 1;
	}else{
		return n*fact(n-1);
	}
}


int main(int argc, char *argv[]) {
	
	int n;
	printf("Digite n:\n");
	scanf("%d",&n);
	
	printf("Resultado: %d",fact(n));
	
	return 0;
}
