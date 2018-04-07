#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int idade;
	
	printf("Informe sua idade: ");
	scanf("%d",&idade);
	
	if(idade>=18){
		printf("Voce ja pode consumir bebidas alcoolicas!");
	}else{
		printf("Voce ainda nao pode consumir bebidas alcoolicas!");
	}
	
	return 0;
}
