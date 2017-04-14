#include "Fibonacci.h"

int
main (void)
{
  char resp = 's';
  int n = 0, opcion, posicion;

  while (resp == 's')
    {
      printf ("\n\t\t\t PRACTICA 4. RECURSIVIDAD EN SERIE FIBONACCI ");

      printf ("\n Ingresa posicion en la serie: ");
      scanf ("%d", &n);

      if (n < 0)
	printf ("\nIngresa un numero valido.");

      else
	{
	  printf ("\n Que deseas hacer?");
	  printf ("\n (1) Conocer el valor en la posicion especifica");
	  printf ("\n (2) Observar la serie hasta la posicion dada\n\t");
	  scanf ("%d", &opcion);

	  switch (opcion)
	    {
	    case 1:
	      printf ("\n El numero de la posicion %d de la serie es: %.0lf",
		      n, fibonacci (n));
	      break;

	    case 2:
	      printf ("\n\t Serie desde posicion cero: \n");
	      for (posicion = 0; posicion <= n; posicion++)
		printf ("\t %.0lf", fibonacci (posicion));
	      break;

	    default:
	      printf ("\nIngresa un numero valido.");
	    }

	}

      printf ("\n\n te gustaria repetir la operacion?  (s = Si / N = No): ");
      scanf ("%s", &resp);
    }
  return 0;
}
