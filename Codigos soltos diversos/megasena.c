#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int c, d, temp, op, ap1[6], ap2[6], ap3[6], res[6], ac1,ac2,ac3;
	ac1=0;
	ac2=0;
	ac3=0;
	srand(time(NULL) );

	printf("Quantas apostas voce quer fazer? (limite = 3)\n");
	scanf("%d",&op);
	printf("\n[...digite numeros inteiros de 1 a 60...]\n\n");
	switch(op){
		case 1: 
			printf("Digite sua aposta: \n");
			printf("1 numero: ");
			scanf("%d",&ap1[0]);
			for(c=1;c<6;c++){
					printf("%d numero: ",c+1);
					scanf("%d",&temp);
						for(d=0;d<c;d++){
							if(temp==ap1[d]){
								c--;
								printf("Voce ja digitou esse numero, escolha outro!\n");
							}else{
								ap1[c] = temp;	
							}
						}						
			}	
			printf("\nResultado do sorteio:\n");
			for(c=0;c<6;c++){
				res[c] = (rand() % 59)+1;
				printf("valor: %d \n", res[c]);
				}
			for(c=0;c<6;c++){
				for(d=0;d<6;d++){
					if(ap1[c]==res[d]){
						ac1++;
					}
				}
			}
			printf("Numero de acertos: %d", ac1);
			break;
		case 2:
			printf("Digite sua primeira aposta: \n");
			printf("1 numero: ");
			scanf("%d",&ap1[0]);
			for(c=1;c<6;c++){
					printf("%d numero: ",c+1);
					scanf("%d",&temp);
						for(d=0;d<c;d++){
							if(temp==ap1[d]){
								c--;
								printf("Voce ja digitou esse numero, escolha outro!\n");
							}else{
								ap1[c] = temp;	
							}
						}						
			}
			printf("\nDigite sua segunda aposta: \n");
			printf("1 numero: ");
			scanf("%d",&ap2[0]);
			for(c=1;c<6;c++){
					printf("%d numero: ",c+1);
					scanf("%d",&temp);
						for(d=0;d<c;d++){
							if(temp==ap2[d]){
								c--;
								printf("Voce ja digitou esse numero, escolha outro!\n");
							}else{
								ap2[c] = temp;	
							}
						}						
			}	
			printf("\nResultado do sorteio:\n");
			for(c=0;c<6;c++){
				res[c] = (rand() % 59)+1;
				printf("valor: %d \n", res[c]);
			}
			for(c=0;c<6;c++){
				for(d=0;d<6;d++){
					if(ap1[c]==res[d]){
						ac1++;
					}
					if(ap2[c]==res[d]){
						ac2++;
					}
				}
			}
			printf("Numero de acertos da primeira tentativa: %d\n", ac1);
			printf("Numero de acertos da segunda tentativa: %d\n", ac2);
			break;
		case 3:
			printf("Digite sua primeira aposta: \n");
			printf("1 numero: ");
			scanf("%d",&ap1[0]);
			for(c=1;c<6;c++){
					printf("%d numero: ",c+1);
					scanf("%d",&temp);
						for(d=0;d<c;d++){
							if(temp==ap1[d]){
								c--;
								printf("Voce ja digitou esse numero, escolha outro!\n");
							}else{
								ap1[c] = temp;	
							}
						}						
			}	
			printf("\nDigite sua segunda aposta: \n");
			printf("1 numero: ");
			scanf("%d",&ap2[0]);
			for(c=1;c<6;c++){
					printf("%d numero: ",c+1);
					scanf("%d",&temp);
						for(d=0;d<c;d++){
							if(temp==ap2[d]){
								c--;
								printf("Voce ja digitou esse numero, escolha outro!\n");
							}else{
								ap2[c] = temp;	
							}
						}						
			}	
			printf("Digite sua terceira aposta: \n");
			printf("1 numero: ");
			scanf("%d",&ap3[0]);
			for(c=1;c<6;c++){
					printf("%d numero: ",c+1);
					scanf("%d",&temp);
						for(d=0;d<c;d++){
							if(temp==ap3[d]){
								c--;
								printf("Voce ja digitou esse numero, escolha outro!\n");
							}else{
								ap3[c] = temp;	
							}
						}						
			}	
			printf("\nResultado do sorteio:\n");
			for(c=0;c<6;c++){
				res[c] = (rand() % 59)+1;
				printf("valor: %d \n", res[c]);
			}	
			for(c=0;c<6;c++){
				for(d=0;d<6;d++){
					if(ap1[c]==res[d]){
						ac1++;
					}
					if(ap2[c]==res[d]){
						ac2++;
					}
					if(ap3[c]==res[d]){
						ac3++;
					}
				}
			}
			printf("Numero de acertos da primeira tentativa: %d\n", ac1);
			printf("Numero de acertos da segunda tentativa: %d\n", ac2);
			printf("Numero de acertos da terceira tentativa: %d\n", ac3);
			break;
	}
	return 0;
}
