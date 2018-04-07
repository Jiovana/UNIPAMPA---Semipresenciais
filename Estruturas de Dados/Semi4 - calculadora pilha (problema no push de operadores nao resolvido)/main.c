#include <stdlib.h>
#include <stdio.h>
#include "calculadora.h"

int main() {
    int opt, aux = 0;
    float n;
    char c;
    Calculadora *calc;
    calc = criaCalc();
    do {
        printf("====ESCOLHA UMA OPCAO====\n1. Empilhar valor real\n2. Empilhar Operando\n3. Realizar Calculo\n4. Imprimir pilhas\n5. Sair\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Digite um numero: \n");
                scanf("%f", &n);
                insereNum(calc, n);
                break;
            case 2:
                printf("Digite um operador (+,-,*,/): \n");
                scanf(" %c", &c);
                while (aux == 0) {
                    if (c == '+' || c == '-' || c == '*' || c == '/') {
                        insereOp(calc, c);
                        aux++;
                    } else {
                        printf("Operador invalido, tente novamente.\n");
                        scanf("%c", &c);
                    }
                }
                break;
            case 3:
                realizaCalculo(calc);
                break;
            case 4:
                imprimeCalc(calc);
                break;
            case 5:
                liberaCalc(calc);
                exit(1);
            default:
                printf("Opcao invalida!!");
                break;
        }
    } while (opt != 5);
}