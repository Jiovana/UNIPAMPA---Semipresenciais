/**
 * Resolução do problema clássico das Torres de Saigon via algoritmo recursivo.
 *
 * Exemplo de compilação e execução no Linux:
 *
 *    prompt> gcc saigon.c -o saigon
 *    prompt> ./saigon QUANTIDADE_DE_DISCOS
 *
 * Nota: Imprime (2^QUANTIDADE_DE_DISCOS)-1 linhas de texto na saída padrão.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Core da resolução com impressão da sequência ótima de movimentos.
 *
 * @param QTD_DISCOS Quantidade de discos a movimentar.
 * @param origem Número da torre origem.
 * @param destino Número da torre destino.
 * @param temp Número da torre temporária.
*/
void solve(int QTD_DISCOS, int origem, int destino, int temp)
{
  /** Número de ordem de cada movimento na sequência de resolução. */
  static int rank = 0;

  if (QTD_DISCOS > 0)
  {
    solve(QTD_DISCOS-1, origem, temp, destino);
    printf("%4d ) %c --> %c\n", ++rank, '@' + origem, '@' + destino);
    solve(QTD_DISCOS-1, temp, destino, origem);
  }
}

/**
 * Invoca o core da resolução com o parâmetro fornecido na linha de comando e
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
