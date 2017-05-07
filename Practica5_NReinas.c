// Pr�ctica 5, N-Reinas ... equipo 932
#include "presentacion.h"
#define TRUE 1
#define FALSE 0

void pintar (int *tablero, int tamanio);	//Funci�n que pintar� los cambios en el tablero,en cada paso
void inicializar (int *tablero, int tamanio);	//Funci�n que inicializa los valores del "arreglo de control de columnas" del tablero, en -1
boolean Reinas (int *tablero, int pos_actual, int tamanio);	//Funci�n que realiza los c�lculos principales, va haciendo el backtracking. Al final indica si se resolvi� o no el juego
boolean sin_Ataque (int *tablero, int pos_actual);	//Funci�n que revisar� si la pieza movida recientemente, ataca a otra colocada anteriormente
boolean CalculoReinas (int *tablero, int tamanio);	//Funci�n "inicial" que manda a llamar a la funci�n reinas.

/* La funci�n inicializar se utiliza solo una vez, para hacer que los valores del "arreglo de control de columnas" del tablero, sean -1,
en otras palabras, esta haciendo que no haya reinas ubicadas en ninguna de las posiciones de cada columna */
void
inicializar (int *tablero, int tamanio)
{
  int i;
  for (i = 0; i < tamanio; i++)	//Ciclo que inicializa las "posiciones" de las reinas en -1
    tablero[i] = -1;
}


/* La funci�n Sin_Ataque, verifica si la reina que estamos posicionando en un determinado lugar de una columna del tablero, 
ataca a otra puesta en alguna de las columnas anteriores, esto es, si la posici�n en la columna es igual, o si esta en diagonal (lo que se cumple si,
al restar la posici�n actual (en arreglo de control), con alguna posici�n i anterior, este resultado es igual al valor positivo de la diferencia entre
la posici�n de la reina en la columna actual (osea, el valor almacenado en la posici�n actual del arreglo de control) menos la posici�n en columna de la 
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
	/*Esta condici�n b�sicamente verifica que la reina colocada recientemente en una posici�n de columna, est� colocada en una linea diagonal
	   donde se ubica otra reina, en otra posici�n de la l�nea diagonal (y otra columna). En caso de ser afirmativo, seg�n el juego de ajedrez, reina actual ataca */
	return FALSE;
    }
  return TRUE;			//Si no se cumplen las condiciones anteriores para ninguna de las reinas colocadas anteriormente, entonces la reina actual NO ATACA.
}

/* Funci�n pintar, presenta gr�ficamente el tablero, y arriba de �l, escribe el "arreglo de control de columnas", es decir, aparecen los valores almacenados
en cada posici�n del arreglo, en otras palabras, las posiciones de las reinas de cada columna*/

void
pintar (int *tablero, int tamanio)
{
  int fil, col;
printf("\n Solucion 1: \n");
  printf ("\n ");
  for (fil = 0; fil < tamanio; fil++)	//Ciclo que imprime los valores almacenados en el arreglo de control principal.
    {
      printf (" %d ", tablero[fil]);	//Recordemos que si se imprime -1, quiere decir que no hay una reina en esa columna
    }
  printf ("\n\n ");
  for (fil = 0; fil < tamanio; fil++)	//Bloque que imprime el tablero. Para posiciones donde no haya reinas, aparecer� una 'X', y en la ubicaci�n de la reina, aparecer� una 'Q'
    {
      for (col = 0; col < tamanio; col++)
	{
	  //A continuaci�n verificamos si hay que colocar 'Q' (si estamos en la posici�n en columna indicada por el "arreglo de control de columnas"), o 'X'
	  if (fil == tablero[col])
	    {
	      /*Como un extra, tambi�n verificamos si una reina llego al final de la columna actual y atac� a alguna de las reinas en todos sus movimientos
	         anteriores (sobre dicha columna). De ser as�, tendra que quitarse del tablero y optar por mover la reina de la columna anterior, por lo cu�l
	         la reina que "se quita", desaparecer� al momento de cumplir esta condici�n, apareciendo una 'X' en su lugar (y comenzar� a moverse la reina
	         de la columna anterior).
	         Para que se diference� el "quitar" una reina, de inicializar la columna, se debe tomar en cuenta que si se inicializa, 
	         aparece un "-1", pero si se quita, aparece   la �ltima posici�n en la que se puso la reina (tamanio-1) */

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
	  else			//Si no estamos hablando de la posici�n en la que, seg�n el "arreglo de control de columnas", se localiza la reina, entonces ponemos 'X'
	    printf (" X ");

	}
      printf ("\n ");		//Espacios que sirven para dar un atractivo visual al programa
    }

printf("\n Solucion 2: \n");
//A continuacion se imprime una segunda solucion, esta se forma sabiendo que, si vemos al tablero como una matriz, la transpuesta de esta matriz, tambi�n dar� soluci�n al problema (practicamente se repite el proceso anterior, pero ahora se debe tomar filas como columnas y viceversa).
  printf ("\n ");
for (fil = 0; fil < tamanio; fil++)	//Bloque que imprime el tablero. Para posiciones donde no haya reinas, aparecer� una 'X', y en la ubicaci�n de la reina, aparecer� una 'Q'
    {
 printf (" %d ", tablero[fil]);
if(tablero[fil]!=-1)
printf(" ");
      for (col = 0; col < tamanio; col++)
	{
	  if (col == tablero[fil])
	    {
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
	  else
	    printf (" X ");

	}
      printf ("\n ");
    }
  EsperarMiliSeg (250); //Pausamos para ver cambios gr�ficamente

}

/* La funci�n Reinas, b�sicamente efectua el c�lculo recursi�n del backtracking, en ella se debe saber si la reina movida recientemente, ataca a
alguna de las otras reinas posicionadas anteriormente, por lo que se requiere llamar a la funci�n Sin_Ataque. La variable "pos_actual" ser� la que definir�
la posici�n horizontal en el "arreglo de control de columnas", o mejor dicho, en que columna del tablero nos encontramos.*/

boolean
Reinas (int *tablero, int pos_actual, int tamanio)
{

  int i, col, fil;
  boolean no_ataca;		//Variable que guardar� el resultado de la llamada recursiva, as�, guardar� si la reinas no se atacan al final del recorrido

  if (pos_actual == tamanio)	/*Caso base de las llamadas recursivas, termina la serie de llamadas recursivas cuando ya no debe seguirse realizando,
				   esto es, cu�ndo ya se recorri� todo el arreglo de control. 

				   Podemos ver a las llamadas recursivas como una especie de
				   ciclo for "horizontal" sobre el "arreglo de control de columnas", y a esta sentencia base, como el l�mite de dicho ciclo */

    {

      return TRUE;
    }
  else				/*Si no hemos llegado al final del tablero (terminamos de recorrer por llamadas recursivas, las columnas), continuamos el proceso: recorremos verticalmente 
				   las columnas, moviendo una reina por cada columna y cuidando que no ataque, seg�n el ajedrez, a las reinas anteriormente posicionadas */
    {
      for (i = 0; i < tamanio; i++)	//Ciclo que mueve las reinas "verticalmente" en cada columna
	{

	  BorrarPantalla ();
	  printf ("\n Calculando... \n");


	  tablero[pos_actual] = i;
	  pintar (tablero, tamanio);	//Pintamos tablero con cambios respectivos en las reinas movidas
	  if (Sin_Ataque (tablero, pos_actual))	//Si la reina en la posici�n actual de la columna actual no ataca a ninguna de las reinas anteriores...
	    {
	      no_ataca = Reinas (tablero, pos_actual + 1, tamanio);	/*... dejamos esta reina en la posici�n marcada y volvemos a realizar el c�lculo
									   para una nueva columna (la columna a continuaci�n, es decir, el �ndice siguiente del arreglo) */
	    }

	  if (no_ataca == TRUE)	/*Si llegamos a la �ltima columna del "arreglo de control" (se avanz� por medio de recursividad)
				   y pudimos colocar la reina de forma que no ataque, terminamos la funci�n, regresando "TRUE"
				   para afirmar que se pudo terminar juego con las reinas sin atacarse */
	    {
	      return TRUE;
	    }


	}
      return FALSE;		/*Si acabo el ciclo for (de "acomodo" vertical), llegando tambi�n al final del tablero en tanto a sus columnas (horizontalmente, por
				   recursividad), y las reinas siemore se atacaron, se regresa FALSE, es decir, que no pudo realizarse el juego de forma correcta */

    }
}

boolean
CalculoReinas (int *tablero, int tamanio)	/*Funci�n que calcula la soluci�n del juego, por lo cu�l requiere retornar si se logr� resolver o no,
						   por medio de la funci�n Reinas. */
{
  inicializar (tablero, tamanio);
  return Reinas (tablero, 0, tamanio);
}


int
main (void)			//Funci�n principal, se efect�an las instrucciones principales del programa.
{
  int *tablero;
  int tamanio = 0;		//tamanio: Almacenar� el tamanio para el tablero N*N (es decir, cuanto vale esa N)
  int i,j;			//Variables para realizar recorridos

  printf ("\n\t\t\t PRACTICA 5. N-REINAS (BACKTRACKING) \n");
  printf (" Ingresa tamanio (en cuadros) del tablero: ");
  scanf ("%d", &tamanio);	//Solicitamos tamanio

  if (tamanio > 1)		//Si se ingres� un numero mayor a 1, se realizan c�lculos
    {
      tablero = (int *) malloc (sizeof (int) * (tamanio + 1));	//Se solicita un bloque de memoria, es decir usamos memoria din�mica, pues no sabemos de que tama�o ser� el tablero

      if (CalculoReinas (tablero, tamanio) == TRUE)	//Si se pudo resolver el juego de forma satisfactoria, se termina agradeciendo por jugar.               
	{
	  BorrarPantalla ();
	  pintar (tablero, tamanio);	//Imprimimos la soluci�n gr�fica
//Luego, imprimimos las 2 soluciones propuestas (como conjunto de coordenadas), esto se obtiene de forma similar a como se hace la representaci�n gr�fica.
printf("\n Soluciones propuestas para %d reinas:\n\t", tamanio);
for(i=0;i<tamanio;i++)
{
for(j=0;j<tamanio;j++)
{	 
if(j==tablero[i]) 
printf ("(%d,%d) ",i,j);
}}
printf("\n\t");
for(i=0;i<tamanio;i++)
{
for(j=0;j<tamanio;j++)
{	 
if(j==tablero[i]) 
printf ("(%d,%d) ",j,i);
}}
printf("\n");	
}
      else			//Si no se resuelve el juego, se indica que no puede calcularse soluci�n
	{
	  BorrarPantalla ();
	  pintar (tablero, tamanio);	//Imprimimos la soluci�n gr�fica
	  EsperarMiliSeg (400);	//Damos 0.4 segundos de pausa para dar atractivo visual al programa
	  printf ("\n\t ERROR, no hay forma de acomodar las reinas.\n\n");
	  return 0;
	}


    }
  else				//Si se meti� un n�mero menor a 1, por l�gica no hay c�lculos a realizar.
    printf ("\nIntroduce un numero mayor a uno. \n");
  return 0;
}
