#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int mat[5][5], x, y; /* x = linha y = coluna */
	
	for(x=0;x<5;y++){
		for(y=0;y<5;y++){
			printf("Digite valor: "); /* popular */
			scanf("%i",&mat[x][y]);
		}
	}
	return 0;
}
