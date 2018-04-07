#include <stdio.h>
#include <stdlib.h>

int main(){
	int q, c;
	float s, v, vm, vmm;
	
	printf("Informa a quantidade de itens: ");
	scanf("%d",&q);
	
	while(c<q){
		printf("Item n %d\nInforme o valor do item: ", c);
		scanf("%f",&v);
		s = s + v;
		c++;
		if(v>vmm){
			vmm = v;
		}
	}
	vm = s / q;
	printf("Valor medio: %f \n " , vm);
	printf("Maior valor: %f \n " , vmm);
}
