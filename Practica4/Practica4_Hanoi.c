#include "Hanoi.h"

int
main (void)
{
  int repetHan = 0;
  int inicio = 1, auxiliar = 2, destino = 3;
  int numdisc = 1, i;
  char repetirProg = 's';
  printf ("\n\t\t\t PRACTICA 4. RECURSIVIDAD EN TORRES DE HANOI ");
  while (repetirProg == 's')
    {
      printf ("\n Ingresa numero de discos: ");
      scanf ("%d", &numdisc);
      if (numdisc < 1 || numdisc > 25)
	printf ("\nIngresa una cantidad de discos valida para el juego.\n");
      else
	{
	  /*Al tratarse de que los discos iran moviendose entre los palos, cambiando su posicion inicial, auxiliar y final,
	     se llamara a los palos como 1,2,3 y no como "inicio,auxiliar y fin", ya que esto causara ambiguedad. */

	  /* Sin embargo, para la funcion Hanoi, se mandaran el palo de posicion origen, el destino y auxiliar. Esto ira modificandose. */
	  printf
	    ("\n----------------- Los movimientos a realizar son: ----------------------\n\n");
	  Hanoi (numdisc, inicio, destino, auxiliar, repetHan);
	  printf
	    ("\n-------------------------------------------------------------------------\n");
	  printf ("\n Finalmente, la torre quedara asi:\n");
	  pintar (numdisc, inicio, destino, auxiliar, repetHan);
	  printf
	    ("\n Deseas observar el juego con otra cantidad de discos? (s)=SI / (n)=NO  ");
	  scanf ("%s", &repetirProg);
	  if (repetirProg == 's')
	    printf
	      ("\n------------------------------------------------------------------------------------------------------------------------\n");
	}
    }
  return 0;
}
