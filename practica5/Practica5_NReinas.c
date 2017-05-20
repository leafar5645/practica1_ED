/*  Título: Practica5_NReinas.c
   Descripción: Funciòn principal de la pràctica 5, se efectùan las instrucciones principales.
   Recibe: No recibe nada, en esta funciòn se pediràn los datos necesarios y se crearà el tablero.
   Retorna: Un entero "0" si el programa no tuvo errores de ejecuciòn.
    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1.0
*/
#include "presentacion.h"
#include "NReinas.h"

int
main (void)			//Función principal, se efectúan las instrucciones principales del programa.
{
  int *tablero;
  int tamanio = 0;		//tamanio: Almacenará el tamanio para el tablero N*N (es decir, cuanto vale esa N)
  int i, j;			//Variables para realizar recorridos

  printf ("\n\t\t\t PRACTICA 5. N-REINAS (BACKTRACKING) \n");
  printf (" Ingresa tamanio (en cuadros) del tablero: ");
  scanf ("%d", &tamanio);	//Solicitamos tamanio

  if (tamanio > 1)		//Si se ingresó un nùmero mayor a 1, se realizan cálculos
    {
      tablero = (int *) malloc (sizeof (int) * (tamanio + 1));	//Se solicita un bloque de memoria, es decir usamos memoria dinámica, pues no sabemos de que tamaño será el tablero

      if (CalculoReinas (tablero, tamanio) == TRUE)	//Si se pudo resolver el juego de forma satisfactoria, se mostrarà la soluciòn 1 y la 2 (que es la transpuesta a la 1).               
	{			//En el if anterior, tambièn se efectua el llamado a CalculoReinas lo que implica que se realicen todas sus instrucciones, asi imprimièndose el camino para llegar a la soluciòn
	  BorrarPantalla ();
	  pintar (tablero, tamanio);	//Imprimimos la solución gráfica
//Luego, imprimimos las 2 soluciones propuestas (como conjunto de coordenadas), esto se obtiene de forma similar a como se hace la representación gráfica.
	  printf ("\n Soluciones propuestas para %d reinas:\n\t", tamanio);
	  for (i = 0; i < tamanio; i++)
	    {
	      for (j = 0; j < tamanio; j++)
		{
		  if (j == tablero[i])
		    printf ("(%d,%d) ", i, j);
		}
	    }
	  printf ("\n\t");
	  for (i = 0; i < tamanio; i++)
	    {
	      for (j = 0; j < tamanio; j++)
		{
		  if (j == tablero[i])
		    printf ("(%d,%d) ", j, i);
		}
	    }
	  printf ("\n");
	}
      else			//Si no se resuelve el juego, se indica que no puede calcularse solución
	{
	  BorrarPantalla ();
	  pintar (tablero, tamanio);	//Imprimimos la solución gráfica
	  EsperarMiliSeg (400);	//Damos 0.4 segundos de pausa para dar atractivo visual al programa
	  printf ("\n\t ERROR, no hay forma de acomodar las reinas.\n\n");
	  return 0;
	}

    }
  else				//Si se metió un número menor a 1, por lógica no hay cálculos a realizar.
    printf ("\nIntroduce un numero mayor a uno. \n");
  return 0;
}
