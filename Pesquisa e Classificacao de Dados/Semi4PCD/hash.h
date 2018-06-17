
typedef struct nodo{
    int codigo;
    char descricao[40];
    float valor;
    struct nodo *prox;
} Nodo;

typedef struct lista{
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
}Lista;

Lista* Construir();
void Inserir(Lista *vet);
void Excluir(Lista *vet);
int Buscar(Nodo *lst, int cod);
void Consultar(Lista *vet);
void ExibirTudo(Lista *vet);
void Encerrar(Lista *vet);

int funcaoHash(int cod);
