#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int cont, cod[5], qtd[5];
	float vlru[5], vlrit[5], vt;
	
	for (cont=0;cont<5;cont++){
		printf("Digite cod: ");
		scanf("%i", &cod[cont]);
		printf("Digite qtd: ");
		scanf("%i", &qtd[cont]);
		printf("Digite valor unitario: ");
		scanf("%f", &vlru[cont]);
		vlrit[cont] = qtd[cont] + vlru[cont];
		vt = vt + vlrit[cont];
	}
	for(cont=0;cont<5;cont++){
		printf("Cod: %d | Qtd: %d | Valor: %.2f | Total: %.2f\n", cod[cont], qtd[cont], vlru[cont], vlrit[cont]);	
	}
	printf("Total geral: %.2f", vt);
	return 0;
}
