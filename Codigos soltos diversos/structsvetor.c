#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct ponto{
	float x;
	float y;
}; typedef struct ponto Ponto;

Ponto centro(int n, Ponto* p ){
	Ponto c;
	float somax, somay;
	int x;
	
	for (x=0;x<5;x++){
		somax += p[x].x;
		somay += p[x].y;
	}	
	c.x = somax / n;
	c.y = somay / n;
	
	return c;
}

int main(int argc, char *argv[]) {
	
	Ponto p[5];
	int c;
	float d;
	
	for (c=0;c<5;c++){
		printf("Informe x e y do ponto %d:\n", c+1);
		scanf("%f%f",&p[c].x,&p[c].y);
	}
	
	Ponto cg = centro(5,&p);
	printf("O centro geometrico esta localizado em x: %.1f e  y: %.1f\n", cg.x,cg.y);
	
	
	return 0;
}

