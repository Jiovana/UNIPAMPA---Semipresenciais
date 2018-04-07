#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n,t, c, p, i, ci;
	float m;

	for(c=0;c<20;c++){
		printf("Informe n: ");
		scanf("%d",&n);
		t=t+n;
		if(n%2==0){
			p = p+n;
		}else{
			i=i+n;
			ci++;
		}
	}
	m=i/ci;
	printf("Resultado total: %d \nResultado par: %d \nMedia impar: %f", t,p,m );
	
	return 0;
}
