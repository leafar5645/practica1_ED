/* Título: Hanoi.c 
   Descripción: Muestra las operaciones a realizar para mover n discos, de acuerdo a las reglas del juego "Torres de Hanoi":
- Solo puede mover el disco superior de cualquiera de las astas.
- Un disco más grande nunca puede estar encima de uno más pequeño.

-Recibe: cada una recibe el “tamaño del disco en curso” (ndiscos), el palo inicial, destino y auxiliar y la variable repetHan, aunque en pintar solo se necesitaran los palos, al llamarla al final del programa principal.
-Retorna: Solo hacen operaciones, no regresan algo como tal.

    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1.0
*/
#include "Hanoi.h"
/*  Instrucciones: Muestra las operaciones a realizar para mover n discos, de acuerdo a las reglas del juego "Torres de Hanoi":
- Solo se puede mover el disco superior de cualquiera de las astas/palos.
- Un disco más grande nunca puede estar encima de uno más pequeño */

void    
Hanoi (int ndiscos, int A, int C, int B, int repetHan)  //Funciòn que hace la operaciòn del juego de las torres
{

  if (ndiscos == 1)
    {
      //Si el disco es de tamaño 1, lo pasas al destino automaticamente*/

      printf (" Mueve del Palo %d a Palo %d, al disco (%d):\n", A, C,
	      ndiscos);

      pintar (ndiscos, A, C, B, repetHan); //Se imprime el disco a moverse, este es el caso base no recursivo, CUANDO SE MUEVE EL DISCO 1
      repetHan++;   
     /*Recordemos que "repetHan" sirve para conocer el nùmero de veces que se ha llegado al caso base no recursivo tras una 
     serie de operaciones recursivas, lo cuàl serà util tomar en cuenta y comparar con el nùmero de discos, esto para pintar el disco a
     moverse en una parte del procedimiento determinada. Se busca que esta variable nos indique con que disco estamos trabajando*/
    }
  //Si existen màs de un disco, debes seguir una serie de pasos recursivos para lograr el objetivo del juego
  else
    {
  
      Hanoi (ndiscos - 1, A, B, C, repetHan);  //ahora, se hace una llamada recursiva, pero esta vez el palo definido como "auxiliar" pasarà a ser el palo "destino", el disco a tratar cambiarà.

      printf (" Mueve del Palo %d a Palo %d, al disco (%d):\n", A, C,
	      ndiscos);
//Una vez hecha la llamada recursiva anterior, ahora el palo 1 (A) serà origen y el palo 2 (auxiliar/B),  el destino. A continuacion se pega en pantalla el disco a moverse.      

      pintar (repetHan + 1, A, B, C, repetHan + ndiscos); 
      /*repetHan es màs grande a nùmero de discos, en el caso de tener discos de posiciòn 
      inicial/tamaño diferente a 1. Se buscò la forma de que el repetHan nos indicarà con que no. de disco trabajamos,
      relacionàndolo con el ndiscos con el fin de que al momento de imprimir, se muestre el tamaño correcto del disco trabajado.
      en este caso, se obtuvo mediante pruebas, que si ndiscos= repetHan + 1, y repetHan = repetHan+ndiscos, en està secciòn 
      de còdigo, podremos obtener lo deseado. */
      
     /*Por ejemplo, si ndiscos originalmente es 3, repetHan serìa 4, y al momento de pintar repetHan tendrìa que ser 7 y ndiscos 5, 
     pues la diferencia entre ambos debe ser 2, pues esta seria la cantidad de veces que se le agregarìa cuadritos al disco de tamaño 1*/

      Hanoi (ndiscos - 1, B, C, A, repetHan);
//Ultimo pase de discos, con palo 2 (B) como origen, palo 3 (C) como destino. RepetHan y ndiscos actùan sin cambios ya que se sabe que trabajamos con el disco menor, lo cual no altera dichas variables 
/* La funciòn se creò a base de 2 palos, conociendo la forma en la que se modifican los "destinos" y "auxiliares". Sin embargo, puede funcionar
recursivamente para cualquier nùmero de discos, puesto que al final de todo, podrìamos decir que los procedimientos se van reduciendo hasta que 
se tiene la misma operacion con 2 palos en torre, y posteriormente con uno sòlo. */

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
	  while (RepetHan > ndiscos)
	    {
	  /*Esta secciòn se explicaba arriba con un ejemplo, bàsicamente la diferencia entre repetHan y ndiscos nos indicarà las veces
	  que le añadiremos "2 cuadritos" a nuestro disco original de cada fila de la torre, esto por que cada disco es de diferente tamaño*/
	      printf (" ");
	      printf ("%c", 254);	
	      printf (" ");	
	      printf ("%c", 254);
	      RepetHan--;
	    }

	}
      printf ("\n");  //Al finalizar la impresion de cuadritos horizontalmente, se darà un salto de pàgina para que se visualice una torre, esto al final de la ejecuciòn del programa.
    }
}
