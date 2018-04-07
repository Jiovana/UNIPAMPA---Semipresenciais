#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main() {
	float altura, peso, imc;
	
	printf("Informe seu peso e altura: ");
	scanf("%f%f",&peso,&altura);
	
	imc = peso / (altura*altura);
	
	printf("Seu imc : %f", imc);

}
