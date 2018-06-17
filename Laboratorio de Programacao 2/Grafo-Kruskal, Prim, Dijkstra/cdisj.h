//Implementação de Conjuntos disjuntos para uso no Grafo

typedef struct conj{
    int *vet;
    int *tam;
}Conj;

//funcao para inicializar o vetor dos conjuntos com cada conjunto pertencendo a ele mesmo
void makeSet(Conj *conj, int tam);

//funcao para ver se elementos pertencem ao mesmo conjunto ou não
int findSet(int i, int j, Conj *conj);

//funcao para unir conjuntos
void mergeSet(int i,int j,Conj *conj);

//funcao para imprimir todos conjuntos
void printSets(Conj *conj, int tam);

//funcao para alocar memoria para a struct
Conj *constructorConj(int tam);

//funcao para buscar a raiz de dado conjunto
int root(Conj *conj, int i);

//funcao para liberar memoria alocada
void liberaSets(Conj *conj);

