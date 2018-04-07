#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char p[100],pa[100],paa[100];
	
	printf("Digite 3 palavras: \n");
	scanf("%s%s%s",&p,&pa,&paa);
	
	if((strlen(p)) > (strlen(pa)) && (strlen(p)) > (strlen(paa))){
		printf("Palavra %s é maior \n", &p);
	}else if((strlen(pa)) > (strlen(p)) && (strlen(pa)) > (strlen(paa))){
		printf("Palavra %s é maior \n", &pa);
	}else{
		printf("Palavra %s é maior \n", &paa);
	}
	
	
	return 0;
}
