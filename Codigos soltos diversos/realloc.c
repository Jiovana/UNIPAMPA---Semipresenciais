/*
 * realloc.c
 * 
 * Copyright 2017 gomes <gomes@JIOVANA-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int *v, tam, c;
	
	printf("Infome tamanho do vetor: ");
	scanf("%d",&tam);
	
	v = (int *) malloc (tam * sizeof(int));
	
	printf(" Escreva valores para o vetor:\n");
	for(c=0;c<tam;c++){
		scanf("%d", &v[c]);
	}
	
	printf("Infome novo tamanho para o vetor: ");
	scanf("%d",&tam);
	v = (int*) realloc (v, tam*sizeof(int));
	
	printf("Novos Valores do vetor:\n");
	for(c=0;c<tam;c++){
		printf("%d\n", v[c]);
	}
	free(v);
	
	return 0;
}
