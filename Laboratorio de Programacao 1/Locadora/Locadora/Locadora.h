//
// Jiovana Gomes (gomesjiovana@gmail.com)
//


typedef struct filme Filme;

int imprimePorCodigo(Filme **f, int t);
void imprimePorNome(Filme **f, int t);
void imprimePorAno(Filme **f, int t);
void imprimePorGen(Filme **f, int t);
void imprimeTudo(Filme **f, int t);
void locar(Filme **f, int t);
void entregar(Filme **f, int t);
int preencheVetor(FILE *fp, Filme **f, int n);
void liberar(int n, Filme **f);
void relatorioAno(FILE *fp, Filme **f, int n);
void relatorioGenero(FILE *fp, Filme **f, int n);
void acervoCompleto(FILE *fp, Filme **f, int n);


