/*
 * veiculos.c
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

int main(int argc, char **argv)
{	
	char tipo;
	int km;
	
	printf("Informe o tipo de veiculo(A,B ou C):\n");
	scanf("%c",tipo);
	
	printf("Informe a distancia em km\n");
	scanf("%d",&km);
	
	switch(tipo){
		case "A" :
			printf("Consumo: " , km*8);
			break;
		case "B" :
			printf("Consumo: " , km*9);
			break;
		case "C" :
			printf("Consumo: " , km*12);
			break;
		
	};
	
	
	return 0;
}

