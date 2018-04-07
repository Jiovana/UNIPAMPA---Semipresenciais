#include <stdio.h>
#include <stdlib.h>


void main() {
	float preco,media, soma;
	int qtd, c;
	printf("Informe a quantidade de produtos comprados: \n");
	scanf("%d",&qtd);
	for(c=0;c<=qtd;c++){
		printf("Informe preco do produto : \n" );
		scanf("%f",&preco);
		soma = soma + preco;
		c++;
	}
	
	media = soma / qtd;
	
	printf("Media do preco dos produtos: %f", media);
	
}
