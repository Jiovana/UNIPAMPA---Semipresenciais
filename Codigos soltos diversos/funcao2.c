#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 double ano = 0;
double ferias;
double Ferias(double x){
	ferias = (x * 1.3);
	return ferias;
}
double Anual(double y){
	ano = (y * 12) + ferias;
	return ano;
}
void Mostra(z){
	printf("Salario anual: %.2f", ano);
}

int main(int argc, char *argv[]) {
	 double salario;
	
	printf("Informe o salario mensal: ");
	scanf("%lf",&salario);
	
	Ferias(salario);
	Anual(salario);
	Mostra(ano);
	return 0;
}


