/* Título: Practica4_Hanoi.c 
   Descripción: Aquí se realizan las operaciones principales y se manda a llamar a las funciones de las bibliotecas. Esta funciòn repetirà sus instrucciones cuantas veces quiera el usuario.
    -Recibe: No se ingresa nada, puesto que es la función principal.
    -Retorna: Retorna un entero “0” para indicar que el programa corrió sin fallos
   
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: 11 de Mayo de 2017               Versión: 1.9
*/
#include "Hanoi.h"

int
main (void)
{
	/*repetHan: Esta variable serà importante para la impresiòn de los discos, pues bàsicamente almacena
	la cantidad de veces que se llego al caso base no recursivo de Hanoi (fin de una serie de recursividad), o el nùmero de veces que se moviò al disco tamanio 1*/ 
  int repetHan = 0;  
  int inicio = 1, auxiliar = 2, destino = 3;  //Variables para designar cada palo (son 3)
  int numdisc = 1, i;   //numdisc nos permitirà, bàsicamente, saber con que disco se esta trabajando (por su posiciòn/tamaño, donde el disco 1, està hasta arriba de la torre).
  char repetirProg = 's';
  printf ("\n\t\t\t PRACTICA 4. RECURSIVIDAD EN TORRES DE HANOI ");
  while (repetirProg == 's')  //La variable "repetirProg" nos indicarà si se desea repetir las instrucciones del programa desde cero cada vez que finalice el programa.
    {
      printf ("\n Ingresa numero de discos: ");
      scanf ("%d", &numdisc);
      if (numdisc < 1 || numdisc > 25)  //Damos un lìmite de discos a ingresar, por lògica, no podemos ingresar 0, y màs de 25 serìan muy complicados de manejar
	printf ("\nIngresa una cantidad de discos valida para el juego.\n");
      else
	{
	  /*Al tratarse de que los discos iràn moviendose entre los palos, cambiando su posicion inicial, auxiliar y final,
	     se llamarà a los palos como 1,2,3 y no como "inicio,auxiliar y fin", ya que esto causara ambiguedad. */
	  printf
	    ("\n----------------- Los movimientos a realizar son: ----------------------\n\n");
	  Hanoi (numdisc, inicio, destino, auxiliar, repetHan);  //llamamos a la funciòn Hanoi, al cual desarrollarà una serie de llamadas recursivas, con el fin de resolver el juego
	  printf
	    ("\n-------------------------------------------------------------------------\n");
	  printf ("\n Finalmente, la torre quedara asi:\n");    //Con el fin de evitar que se imprima la torre incompleta cada que termine una llamada recursiva, se dediciò mejor imprimir còmo queda la torre al final.
	  pintar (numdisc, inicio, destino, auxiliar, repetHan);
	  printf
	    ("\n Deseas observar el juego con otra cantidad de discos? (s)=SI / (n)=NO  ");
	  scanf ("%s", &repetirProg);
	  if (repetirProg == 's')  //Recordemos que al final del programa, nos pregunta si queremos volver a hacer càlculos.
	    printf
	      ("\n------------------------------------------------------------------------------------------------------------------------\n");
	}
    }
  return 0;
}
