//
// Created by gomes on 04/10/2017.
//

#ifndef SEMI4_CALCULADORA_H
#define SEMI4_CALCULADORA_H

typedef struct lista  Lista;
typedef struct pilhaop PilhaOp;
typedef struct pilhafloat PilhaFloat;
typedef struct calc Calculadora;

PilhaOp *criaPilhaOp();
void pilhaOpPush (PilhaOp *p, char c);
int pilhaOpvazia(PilhaOp *p);
char pilhaOpPop (PilhaOp *p);
void liberaPilhaOp(PilhaOp *p);
void imprimePilhaOp(PilhaOp *p);

PilhaFloat *criaPilhaFloat();
int pilhaFloatvazia(PilhaFloat *p);
void pilhaFloatPush (PilhaFloat *p, float v);
float pilhaFloatPop (PilhaFloat *p);
void liberaPilhaFloat(PilhaFloat *p);
void imprimePilhaFloat(PilhaFloat *p);

Calculadora *criaCalc();
void imprimeCalc(Calculadora *calc);
void insereOp(Calculadora *calc, char c);
void insereNum(Calculadora *calc, float v);
void realizaCalculo(Calculadora *calc);
void liberaCalc (Calculadora *c);



#endif //SEMI4_CALCULADORA_H
