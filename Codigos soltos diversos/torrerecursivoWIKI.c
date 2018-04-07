/**
 * Resolu��o do problema cl�ssico das Torres de Saigon via algoritmo recursivo.
 *
 * Exemplo de compila��o e execu��o no Linux:
 *
 *    prompt> gcc saigon.c -o saigon
 *    prompt> ./saigon QUANTIDADE_DE_DISCOS
 *
 * Nota: Imprime (2^QUANTIDADE_DE_DISCOS)-1 linhas de texto na sa�da padr�o.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Core da resolu��o com impress�o da sequ�ncia �tima de movimentos.
 *
 * @param QTD_DISCOS Quantidade de discos a movimentar.
 * @param origem N�mero da torre origem.
 * @param destino N�mero da torre destino.
 * @param temp N�mero da torre tempor�ria.
*/
void solve(int QTD_DISCOS, int origem, int destino, int temp)
{
  /** N�mero de ordem de cada movimento na sequ�ncia de resolu��o. */
  static int rank = 0;

  if (QTD_DISCOS > 0)
  {
    solve(QTD_DISCOS-1, origem, temp, destino);
    printf("%4d ) %c --> %c\n", ++rank, '@' + origem, '@' + destino);
    solve(QTD_DISCOS-1, temp, destino, origem);
  }
}

/**
 * Invoca o core da resolu��o com o par�metro fornecido na linha de comando e
 * constantes que caracterizam o problema.
 *
 * @param Quantidade de discos a movimentar entre as 3 pilhas.
*/
int main(int argc, char **argv)
{
  int d = atoi(argv[1]);

  solve(d, 1, 3, 2);

  return 0;
}
