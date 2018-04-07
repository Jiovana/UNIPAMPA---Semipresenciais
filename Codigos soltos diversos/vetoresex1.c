#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int cont, a[5], b[5], c[5], somaa, somapar;
	
	for (cont=0;cont<5;cont++){
		printf("Digite valor para a: ");
		scanf("%i", &a[cont]);
		printf("Digite valor para b: ");
		scanf("%i", &b[cont]);
		
	}
	
	for (cont=0;cont<5;cont++){
		somaa = somaa + a[cont];
		c[cont] = a[cont] + b[cont];
	}
	for (cont=0;cont<5;cont++){
			if(a[cont]%2 == 0 && c[cont]%2 == 0){
				somapar = somapar + a[cont] + b[cont];
			}
	}
	printf("Soma de A: %i \n", somaa);
	printf("Soma dos pares de A e C: %i", somapar);
	return 0;
}
