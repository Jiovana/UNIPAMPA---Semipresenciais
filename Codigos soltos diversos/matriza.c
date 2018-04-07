#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int mat[10][10], vet[10], x, y, somad, somac; /* x = linha y = coluna */
	
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			printf("Digite valor para matriz: "); /* popular */
			scanf("%i",&mat[x][y]);
			
		}
	}
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			if(x==y){
				printf("Diagonal principal: %i\n", mat[x][y]); 
			}	
		}
	}
	for(x=0;x<10;x++){
		for(y=9;y>0;y--){
			somad = somad + mat[x][y];
		}
	}
	printf("Soma da diagonal secundaria: %i", somad);
	
	for(y=0;y<10;y++){
		for(x=0;x<10;x++){
			vet[y] = mat[y][x]; 
		}
	
	}
	return 0;
}
