#include "Hanoi.h"
/*  Instrucciones: Muestra las operaciones a realizar para mover n discos, de acuerdo a las reglas del juego "Torres de Hanoi":
- Solo puede mover el disco superior de cualquiera de las astas.
- Un disco m�s grande nunca puede estar encima de uno m�s peque�o */

void
Hanoi (int ndiscos, int A, int C, int B, int repetHan)
{

  if (ndiscos == 1)
    {
      //Si solo tienes un disco en el palo, lo pasas al destino automaticamente*/

      printf (" Mueve del Palo %d a Palo %d, al disco (%d):\n", A, C,
	      ndiscos);

      pintar (ndiscos, A, C, B, repetHan);
      repetHan++;
    }
  //Si existen mas de un disco, debes seguir una serie de pasos para lograr el objetivo del juego
  else
    {

      Hanoi (ndiscos - 1, A, B, C, repetHan);

      printf (" Mueve del Palo %d a Palo %d, al disco (%d):\n", A, C,
	      ndiscos);
//Indica cambio, ahora con el palo 1 (A) como origen y el palo 2 (auxiliar/B) como el destino. A continuacion se pega en pantalla el disco a moverse.      

      pintar (repetHan + 1, A, B, C, repetHan + ndiscos);

      Hanoi (ndiscos - 1, B, C, A, repetHan);
//Ultimo pase de discos, con palo 2 (B) como origen, palo 3 (C) como destino.|

    }

}

/*El la funcion pintar, se dibuja a los discos representados por cuadritos, para una mejor comprensi�n. Al final se mostrara la torre completa simulando que ya se construyo en el palo destino */

void
pintar (int ndiscos, int A, int C, int B, int repetHan)
{
  int cont, cont2 = 0;

  for (cont = 0; cont <= ndiscos; cont++)
    {
      for (cont2 = ndiscos - cont2; cont2 > 0; cont2--)
	{
	  printf (" ");
	  printf (" ");		//Da espacio al primer disco
	}
      for (cont2 = 0; cont2 < cont; cont2++)
	{
	  printf (" ");
	  printf ("%c", 254);	//Estos espacios acomodan el siguiente asterisco que se pondra separado del anterior
	  printf (" ");		//Como se ve, el primer asterisco estara 4 espacios despues del margen
	  printf ("%c", 254);
	  while (repetHan > ndiscos)
	    {
	      printf (" ");
	      printf ("%c", 254);	//Estos espacios acomodan el siguiente asterisco que se pondra separado del anterior
	      printf (" ");	//Como se ve, el primer asterisco estara 4 espacios despues del margen
	      printf ("%c", 254);
	      repetHan--;
	    }

	}
      printf ("\n");
    }


}
