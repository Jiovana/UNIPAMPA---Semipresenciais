//
// Created by gomes on 13/10/2017.
//
typedef struct lista Lista;
typedef struct filal FilaL;
FilaL *criarL();
void inserirL(FilaL *f, float v);
float retirarL(FilaL *f);
void imprimirL (FilaL *f);
void liberarL(FilaL *f);
