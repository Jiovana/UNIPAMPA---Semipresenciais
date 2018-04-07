#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float mat[20][4],h, w, imc;
	int opt, x, y, cod;
	
	do{
		printf("\n=== SISTEMA DE IMC ===\nEscolha uma opcao:\n1. Cadastro de dados;\n2. Consultar dados por codigo;\n3. Listar codigos por peso > x;\n4. Listar codigos por altura < x;\n5. Listar codigo e imc de todos cadastrados.\n6. Sair\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("===Cadastro de dados=== \nInsira codigo do individuo, altura e peso:\n");
				for(x=0;x<20;x++){
					for(y=0;y<4;y++){
						if(y==0){
							printf("\n%d individuo: codigo: ", x+1);
							scanf("%f",&mat[x][y]);
						}else if(y==1){
							printf("\n%d individuo: altura: ", x+1);
							scanf("%f",&mat[x][y]);
						}else if(y==2){
							printf("\n%d individuo: peso: ", x+1);
							scanf("%f",&mat[x][y]);
						}else if(y==3){
							imc = mat[x][2] / (mat[x][1] * mat[x][1]);
							mat[x][y] = imc;
						}		
					}
				}
				break;
			case 2:
				printf("===Consultar dados por codigo=== \nInsira codigo do individuo: ");
				scanf("%d",&cod);
				for(x=0;x<20;x++){
					if(mat[x][0]==cod){
						printf("\nDados do individuo %d :\n peso: %.2f | altura: %.2f | imc: %.2f\n", cod, mat[x][2], mat[x][1], mat[x][3]);
					}
				}
				break;
			case 3:
				printf("===Listar codigos por peso > x=== \nInsira o peso: ");
				scanf("%f",&w);
				printf("Individuos com peso > %.2f:\n",w);
				for(x=0;x<20;x++){
					if(mat[x][2]>w){
						printf("%.0f\n",mat[x][0]);
					}
				}
				break;
			case 4:
				printf("===Listar codigos por altura < x=== \nInsira a altura: ");
				scanf("%f",&h);
				printf("Individuos com altura < %.2f:\n",h);
				for(x=0;x<20;x++){
					if(mat[x][1]<h){
						printf("%.0f\n",mat[x][0]);
					}
				}
				break;
			case 5:
				printf("===Listar codigo e imc de todos cadastrados=== \n");
				for(x=0;x<20;x++){
					printf(" Codigo: %.0f | IMC: %.2f\n",mat[x][0],mat[x][3]);
				}
				break;
		}
	}while(opt!=6);
	return 0;
}
