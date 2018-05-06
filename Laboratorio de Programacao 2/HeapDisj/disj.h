//biblioteca de conjuntos disjuntos

typedef struct conj{
    int *vet;
    int tam;
}Conj;
//funcao para inicializar o vetor dos conjuntos
void makeSet(Conj *conj);

//funcao para encontrar elementos dos conjuntos
int findSet(int i, Conj *conj);

//funcao para unir conjuntos
void mergeSet(int i,int j,Conj *conj);

//funcao para imprimir todos conjuntos
void printSets(Conj *conj);

Conj *constructorConj(int tam);

