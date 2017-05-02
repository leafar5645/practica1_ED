//Biblioteca del programa de torres de hanoi. Equipo 932
#include "Hanoi.h"
/*  Instrucciones: Muestra las operaciones a realizar para mover n discos, de acuerdo a las reglas del juego "Torres de Hanoi":
- Solo se puede mover el disco superior de cualquiera de las astas/palos.
- Un disco más grande nunca puede estar encima de uno más pequeño */

void    
Hanoi (int ndiscos, int A, int C, int B, int repetHan)  //Funciòn que hace la operaciòn del juego de las torres
{

  if (ndiscos == 1)
    {
      //Si solo tienes un disco en el palo, lo pasas al destino automaticamente*/

      printf (" Mueve del Palo %d a Palo %d, al disco (%d):\n", A, C,
	      ndiscos);

      pintar (ndiscos, A, C, B, repetHan);  //Se imprime el disco a moverse y el final, la torre formada en el destino.
      repetHan++;   
     /*Recordemos que "repetHan" sirve para conocer el nùmero de veces que se ha llegado al caso base no recursivo tras una 
     serie de operaciones (cuando se mueve 1 palo al destino propuesto), entonces guarda el nùmero de movimientos 
     (cambios de palo/nùmero de disco) o llamadas recursivas. Asì, por ejemplo para ndiscos =3, se necesitan hacer 6 movimientos, 
     osea 6 llamadas a Hanoi, por lo que repeHan=6. */
    }
  //Si existen màs de un disco, debes seguir una serie de pasos para lograr el objetivo del juego
  else
    {
   //para hacer la llamada recursiva de continuaciòn, se requiere que 
      Hanoi (ndiscos - 1, A, B, C, repetHan);  //ahora, se hace una llamada recursiva, pero esta vez el palo definido como "auxiliar" pasarà a ser el palo "destino" 

      printf (" Mueve del Palo %d a Palo %d, al disco (%d):\n", A, C,
	      ndiscos);
//Indica cambio, ahora con el palo 1 (A) como origen y el palo 2 (auxiliar/B) como el destino. A continuacion se pega en pantalla el disco a moverse.      

      pintar (repetHan + 1, A, B, C, repetHan + ndiscos); 
      /*repetHan es màs grande a numero de discos, en el caso de tener discos de posiciòn 
      inicial/tamaño diferente a 1, por ejemplo para 2 discos, repetHan tendrìa que ser =3 y ndiscos=2, lo cual se consigue haciendo 
      la suma establecida en la sentencia anterior para todo repetHan y ndiscos*/

      Hanoi (ndiscos - 1, B, C, A, repetHan);
//Ultimo pase de discos, con palo 2 (B) como origen, palo 3 (C) como destino. 
/* La funcion se creo a base de 2 palos, conociendo la forma en la que se modifican los "destinos" y "auxiliares". Sin embargo, puede funcionar
recursivamente para cualquier nùmero de discos, puesto que al final de todo, podrìamos decir que los procedimientos se van reduciendo hasta que se tiene la misma operacion con 2 palos en torre, y posteriormente con uno sòlo. */

    }

}

/*En la funcion pintar, se dibuja a los discos representados por cuadritos, para una mejor comprensión. Al final se mostrarà la torre completa simulando que ya se construyo en el palo destino */

void
pintar (int ndiscos, int A, int C, int B, int RepetHan)
{
  int cont, cont2 = 0;

  for (cont = 0; cont <= ndiscos; cont++)  //En este bloque de fors, se imprimen los cuadritos horizontalmente con sus respectivos espacios, para dar una mejor calidad "gràfica"
    {                                      
      for (cont2 = ndiscos - cont2; cont2 > 0; cont2--)  
	{
	  printf (" ");
	  printf (" ");		//Da espacio al primer disco
	}
      for (cont2 = 0; cont2 < cont; cont2++)
	{
	  printf (" ");    //Los espacios separan los cuadritos para que se vean mejor
	  printf ("%c", 254);	//Se imprime el cuadrito mediante su funciòn ascii para windows. En otros SO, probablemente se verà una figurita diferente, puesto que no reconocerà el còdigo ascci, sin embargo, aùn asì, se distingue sobre el demàs texto, cumpliendo su funciòn gràfica
	  printf (" ");		
	  printf ("%c", 254);
	  while (repetHan > ndiscos)
	    {
	   /*Si se pidiò hacer màs movimientos o llamadas con recursividad que el nùmero de discos, se va aumentando el tamaño "gràfico" 
	   del disco, este bloque de instrucciones servirà para aumentar el tamaño horizontal del disco solicitado, recordando que 
	   dicho tamaño, por definiciòn del juego, aumenta en 1 unidad conforme bajamos en la torre de hanoi (los discos de abajo deben
	   ser de mayor tamaño que los de arriba) */
		  /* Un ejemplo es, en el momento en el que se mueva al disco de posiciòn inicial 3 (tamaño 3), el repetHan =6, puesto 
		  que se requiere hacer 6 movimientos de discos o repeticiones de la funciòn Hanoi para resolver el juego, y ndiscos=3, 
		  por lo que se imprimiran 4 cuadritos màs a parte de nuestros 2 cuadritos iniciales (para disco de tamaño 1)*/
	      printf (" ");
	      printf ("%c", 254);	
	      printf (" ");	
	      printf ("%c", 254);
	      repetHan--;
	    }

	}
      printf ("\n");  //Al finalizar la impresion de cuadritos horizontalmente, se darà un salto de pàgina para que se visualice una torre, esto al final de la ejecuciòn del programa.
    }


}
