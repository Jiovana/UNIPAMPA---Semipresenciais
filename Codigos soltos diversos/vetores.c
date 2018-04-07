#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int vet[10] , x, soma, somai;
	
	for (x=0;x<10;x++){
		printf("Digite Valor: "); /* incluir */
		scanf("%i", &vet[x]);
	}
	for (x=0;x<10;x++){
		printf("Valor posição %i %i \n", x, vet[x]); /* mostrar */
	}
	for (x=0;x<10;x++){
		soma = soma + vet[x]; /* somar */
	}
	printf("Soma = %i", soma);
	for (x=0;x<10;x++){
		if ((vet[x]%2) == 0){
			printf("Par: %i", vet[x]); /* pares */
		}
	}
	for (x=0;x<10;x++){
		if ((x%2) != 0){
			soma = soma + vet[x]  /* soma de impares */
		}
	}
	printf("Soma Impares: %i", somai);
	return 0;
}
