//Biblioteca Heap
void swap(int *x, int *y);

typedef struct heap{
    int tam;//tamanho atual do vetor
    int cap;//capacidade total do heap
    int *vet;
}Heap;

int getRaiz(Heap *heap);
void printHeap(Heap *heap);
int removeMin(Heap *hep);
void MinHeapify(int i, Heap *hep);
void insertHeap(int x, Heap *hep);
Heap* contructor(int cap);
int dir(int i);
int esq(int i);
int pai(int i);
void siftDown(int i, Heap *hep);
void BuildMinHeap(int *input, int cap);//usar com vetor pronto
void siftUp(int i, Heap *hep);