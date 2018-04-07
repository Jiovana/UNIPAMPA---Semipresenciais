#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float soma (float x, float y){
	return x + y;
}
float sub (float x, float y){
	return x - y;
}
float mult (float x, float y){
	return x * y;
}
float divi (float x, float y){
	return x / y;
}

int main(int argc, char *argv[]) {
	int opt;
	float a, b;
	
	do{
	printf("\n\n====CALCULADORA====\nEscolha uma opcao:\n1. Soma\n2. Subtracao\n3. Multiplicacao\n4. Divisao \n5. Sair\n");
	scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Digite dois valores:\n");
				scanf("%f%f",&a,&b);
				printf("Resultado: %.2f\n", soma(a,b));
				break;
			case 2:
				printf("Digite dois valores:\n");
				scanf("%f%f",&a,&b);
				printf("Resultado: %.2f\n", sub(a,b));
				break;
			case 3:
				printf("Digite dois valores:\n");
				scanf("%f%f",&a,&b);
				printf("Resultado: %.2f\n", mult(a,b));
				break;
			case 4:
				printf("Digite dois valores:\n");
				scanf("%f%f",&a,&b);
				printf("Resultado: %.2f\n", divi(a,b));
				break;
		}
	}while(opt!=5);
	return 0;
}
