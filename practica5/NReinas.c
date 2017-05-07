#include "presentacion.h"
#include "NReinas.h"

/* La función inicializar se utiliza solo una vez, para hacer que los valores del "arreglo de control de columnas" del tablero, sean -1,
en otras palabras, esta haciendo que no haya reinas ubicadas en ninguna de las posiciones de cada columna */
void
inicializar (int *tablero, int tamanio)
{
  int i;
  for (i = 0; i < tamanio; i++)	//Ciclo que inicializa las "posiciones" de las reinas en -1
    tablero[i] = -1;
}


/* La función Sin_Ataque, verifica si la reina que estamos posicionando en un determinado lugar de una columna del tablero, 
ataca a otra puesta en alguna de las columnas anteriores, esto es, si la posición en la columna es igual, o si esta en diagonal (lo que se cumple si,
al restar la posición actual (en arreglo de control), con alguna posición i anterior, este resultado es igual al valor positivo de la diferencia entre
la posición de la reina en la columna actual (osea, el valor almacenado en la posición actual del arreglo de control) menos la posición en columna de la 
reina en la columna i del arreglo de control*/
boolean
Sin_Ataque (int *tablero, int pos_actual)
{
  int i = 0;
  for (i = 0; i < pos_actual; i++)
    {
      if (tablero[i] == tablero[pos_actual])	//Si posiciones en columna de la reina colocada actualmente, y otra reina anterior, son iguales...
	return FALSE;		//... reina colocada recientemente, ataca

      if (pos_actual - i == abs (tablero[pos_actual] - tablero[i]))
	/*Esta condición básicamente verifica que la reina colocada recientemente en una posición de columna, está colocada en una linea diagonal
	   donde se ubica otra reina, en otra posición de la línea diagonal (y otra columna). En caso de ser afirmativo, según el juego de ajedrez, reina actual ataca */
	return FALSE;
    }
  return TRUE;			//Si no se cumplen las condiciones anteriores para ninguna de las reinas colocadas anteriormente, entonces la reina actual NO ATACA.
}

/* Función pintar, presenta gráficamente el tablero, y arriba de él, escribe el "arreglo de control de columnas", es decir, aparecen los valores almacenados
en cada posición del arreglo, en otras palabras, las posiciones de las reinas de cada columna*/

void
pintar (int *tablero, int tamanio)
{
  int fil, col;
  printf ("\n Solucion 1: \n");
  printf ("\n ");
  for (fil = 0; fil < tamanio; fil++)	//Ciclo que imprime los valores almacenados en el arreglo de control principal, esto es de forma horizontal
    {
      printf (" %d ", tablero[fil]);	//Recordemos que si se imprime -1, quiere decir que no hay una reina en esa columna
    }
  printf ("\n\n ");
  for (fil = 0; fil < tamanio; fil++)	//Bloque que imprime el tablero. Para posiciones donde no haya reinas, aparecerá una 'X', y en la ubicación de la reina, aparecerá una 'Q'
    {
      for (col = 0; col < tamanio; col++)
	{
	  //A continuación verificamos si hay que colocar 'Q' (si estamos en la posición en columna indicada por el "arreglo de control de columnas"), o 'X'
	  if (fil == tablero[col])
	    {
	      /*Como un extra, también verificamos si una reina llego al final de la columna actual y atacó a alguna de las reinas en todos sus movimientos
	         anteriores (sobre dicha columna). De ser así, tendra que quitarse del tablero y optar por mover la reina de la columna anterior, por lo cuál
	         la reina que "se quita", desaparecerá al momento de cumplir esta condición, apareciendo una 'X' en su lugar (y comenzará a moverse la reina
	         de la columna anterior).
	         Para que se diferenceé el "quitar" una reina, de inicializar la columna, se debe tomar en cuenta que si se inicializa, 
	         aparece un "-1", pero si se quita, aparece   la última posición en la que se puso la reina (tamanio-1) */

	      if ((col == 1) && (fil == tamanio - 1)
		  && (tablero[col + 1] == tamanio - 1)
		  && (tablero[col + 2] == tamanio - 1)
		  && (Sin_Ataque (tablero, col - 1))
		  && (tablero[col - 1] != 1))
		printf (" X ");
	      else if ((fil == tamanio - 1)
		       && (!Sin_Ataque (tablero, col)
			   || !Sin_Ataque (tablero, col - 1)))
		{
		  printf (" X ");

		}
	      else
		printf (" Q ");
	    }
	  else			//Si no estamos hablando de la posición en la que, según el "arreglo de control de columnas", se localiza la reina, entonces ponemos 'X'
	    printf (" X ");

	}
      printf ("\n ");		//Espacios que sirven para dar un atractivo visual al programa
    }

  printf ("\n Solucion 2: \n");
//A continuacion se imprime una segunda solucion, esta se forma sabiendo que, si vemos al tablero como una matriz, la transpuesta de esta matriz, también dará solución al problema (practicamente se repite el proceso anterior, pero ahora se debe tomar filas como columnas y viceversa).
  printf ("\n ");
  for (fil = 0; fil < tamanio; fil++)	//Bloque que imprime el tablero. Para posiciones donde no haya reinas, aparecerá una 'X', y en la ubicación de la reina, aparecerá una 'Q'
    {
      printf (" %d ", tablero[fil]);	//Se escribe un vector vertical que marca los cambios en cada fila (recordemos que ahora imprimimos la transpuesta del tablero).
      if (tablero[fil] != -1)	//Esta condiciòn solo es para que el tablero no se mueva al aparecer "-1" a la izquierda, solo es para el atractivo visual
	printf (" ");
      for (col = 0; col < tamanio; col++)	//Se repite el mismo procedimiento cambiando solo la siguiente instrucciòn (ahora se considera columnas)
	{
	  if (col == tablero[fil])
	    {
	      if ((col == 1) && (fil == tamanio - 1)	//Estas instrucciones siguen igual, para la soluciòn 2 tambièn verifica que reina halla llegado al final y no ataque (y deba moverse otra).
		  && (tablero[col + 1] == tamanio - 1)
		  && (tablero[col + 2] == tamanio - 1)
		  && (Sin_Ataque (tablero, col - 1))
		  && (tablero[col - 1] != 1))
		printf (" X ");
	      else if ((fil == tamanio - 1)
		       && (!Sin_Ataque (tablero, col)
			   || !Sin_Ataque (tablero, col - 1)))
		{
		  printf (" X ");

		}
	      else
		printf (" Q ");
	    }
	  else
	    printf (" X ");

	}
      printf ("\n ");
    }
  EsperarMiliSeg (250);		//Pausamos para ver cambios gráficamente

}

/* La función Reinas, básicamente efectua el cálculo recursión del backtracking, en ella se debe saber si la reina movida recientemente, ataca a
alguna de las otras reinas posicionadas anteriormente, por lo que se requiere llamar a la función Sin_Ataque. La variable "pos_actual" será la que definirá
la posición horizontal en el "arreglo de control de columnas", o mejor dicho, en que columna del tablero nos encontramos.*/

boolean
Reinas (int *tablero, int pos_actual, int tamanio)
{

  int i, col, fil;
  boolean no_ataca;		//Variable que guardará el resultado de la llamada recursiva, así, guardará si la reinas no se atacan al final del recorrido

  if (pos_actual == tamanio)	/*Caso base de las llamadas recursivas, termina la serie de llamadas recursivas cuando ya no debe seguirse realizando,
				   esto es, cuándo ya se recorrió todo el arreglo de control. 

				   Podemos ver a las llamadas recursivas como una especie de
				   ciclo for "horizontal" sobre el "arreglo de control de columnas", y a esta sentencia base, como el límite de dicho ciclo */

    {

      return TRUE;
    }
  else				/*Si no hemos llegado al final del tablero (terminamos de recorrer por llamadas recursivas, las columnas), continuamos el proceso: recorremos verticalmente 
				   las columnas, moviendo una reina por cada columna y cuidando que no ataque, según el ajedrez, a las reinas anteriormente posicionadas */
    {
      for (i = 0; i < tamanio; i++)	//Ciclo que mueve las reinas "verticalmente" en cada columna
	{

	  BorrarPantalla ();
	  printf ("\n Calculando... \n");


	  tablero[pos_actual] = i;	//En esta parte almacenamos en la columna actual, el valor (o "fila") en la que encuentra la reina
	  pintar (tablero, tamanio);	//Pintamos tablero con cambios respectivos en las reinas movidas
	  if (Sin_Ataque (tablero, pos_actual))	//Si la reina en la posición actual de la columna actual no ataca a ninguna de las reinas anteriores...
	    {
	      no_ataca = Reinas (tablero, pos_actual + 1, tamanio);	/*... dejamos esta reina en la posición (o fila) marcada y volvemos a realizar el cálculo
									   para una nueva columna (la columna a continuación, es decir, el índice siguiente del arreglo) */
	    }

	  if (no_ataca == TRUE)	/*Si llegamos a la última columna del "arreglo de control" (se avanzá por medio de recursividad)
				   y pudimos colocar la reina de forma que no ataque, terminamos la función, regresando "TRUE"
				   para afirmar que se pudo terminar juego con las reinas sin atacarse */
	    {
	      return TRUE;
	    }


	}
      return FALSE;		/*Si acabo el ciclo for (de "acomodo" vertical), llegando también al final del tablero en tanto a sus columnas (horizontalmente, por
				   recursividad), y las reinas siempre se atacaron, se regresa FALSE, es decir, que no pudo solucionarse el juego de forma correcta */

    }
}

boolean
CalculoReinas (int *tablero, int tamanio)	/*Función que calcula la solución del juego, por lo cuál requiere retornar si se logró resolver o no,
						   por medio de la función Reinas. */
{
  inicializar (tablero, tamanio);
  return Reinas (tablero, 0, tamanio);
}
