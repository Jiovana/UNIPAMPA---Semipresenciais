#include <time.h>
#include <stdio.h>
#include <stdlib.h>

double tmp_it, tmp_rec;

int fibIt(int n);
int fibRec(int n);

int main(int argc, char *argv[]) {
    clock_t begin, beginn, end, endd;
    struct timeval temp,temp2;
    time_t ini, inii, fim, fimm;
    int num, opt;
    do{
        printf("Digite 1 numero:\n");
        scanf("%d", &num);
        printf("1 - Iterativo\n2 - Recursivo\n3 - Sair\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                //begin = clock();
                mingw_gettimeofday(&temp,0);
                double tempo = temp.tv_sec+(temp.tv_sec/1e6);
                //ini = time(&temp);
                printf("time %lf\n",tempo);
                printf("Resposta iterativa: %d\n", fibIt(num));
                //end = clock()
                //fim = time(&temp);
                mingw_gettimeofday(&temp2,0);
                double tempo2 = temp2.tv_sec+(temp2.tv_sec/1e6);
                printf("time2 %lf\n",tempo2);

                //time_it = (double)(end - begin) / (CLOCKS_PER_SEC/1000);
                tmp_it = difftime(fim, ini);
                printf("Tempo gasto em ms: %lf\n", tempo2-tempo);
                break;
            case 2:
                //beginn = clock();
                inii = time(NULL);
                printf("Resposta recursiva: %d\n", fibRec(num));
                //endd = clock();
                fimm = time(NULL);
                //time_rec = (double)(endd - beginn) / (CLOCKS_PER_SEC/1000);
                tmp_rec = difftime(fimm,inii);
                printf("Tempo gasto em ms: %lf\n", tmp_rec);
                break;
            case 3:
                exit(0);
        }
    }while(opt!=3);

    return 0;
}

int fibIt (int n){
    int a = 0, b = 1, c , i;
    if(n==1||n==2){
        return 1;
    }else {
        for( i = 0; i < n; i++){
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
}

int fibRec (int n){
    if(n==0 || n==1){
        return 1;
    }else {
        return fibRec(n-2) + fibRec(n-1);
    }
}
