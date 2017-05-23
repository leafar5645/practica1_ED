/* Título: Practica4_Fibo_Tribo.c 
   Descripción: Es el archivo principal, donde se desarrollan las instrucciones más 
                        importantes, en esta función se ingresan los datos a utilizar y aparece un 
                        menú donde eliges si quieres ver solo el valor de la serie fibonacci en una 
                        posición indicada, o toda la serie hasta dicha posición, y también si quieres 
                        obtener la serie tribonacci hasta la posición ingresada.
                 - No recibe datos iniciales.
		 - Regresa 0, es decir, que no tuvo error el programa. Devuelve, al llamar a las funciones, doubles "disfrazados" de enteros, pues los nùmeros de las series son enteros (y trabajamos con doubles por el nùmero de dìgitos que aguantan)
   
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: 11 de Mayo de 2017               Versión: 1.4
*/
#include "Fibonacci_Tribonacci.h"

int
main (void)
{
  char resp = 's';   //Variable que definirá si se repite o no el programa
  int n = 0, opcion, posicion;

  while (resp == 's') /*Mientras la variable "resp" sea 's' de "si", se realizarán las instrucciones 
                                  del programa */
    {
      printf ("\n\t\t\t PRACTICA 4. RECURSIVIDAD EN SERIE FIBONACCI Y TRIBONACCI");

      printf ("\n Ingresa posicion en la serie: ");
      scanf ("%d", &n);

      if (n < 0)
	printf ("\nIngresa un numero valido.");

      else
	{       /*Si el numero ingresado fue válido, se introduce un 
                       menú de opciones */
	  printf ("\n Que deseas hacer?");
	  printf ("\n (1) Conocer el valor Fibonacci en la posicion especifica");
	  printf ("\n (2) Observar la serie Fibonacci hasta la posicion dada\n\t");
          printf ("\n (3) Observar la serie Tribonacci hasta la posicion dada\n\t");
	  scanf ("%d", &opcion);

	  switch (opcion) /*Para este menú de opciones trabajaremos con la variable 
                                           "opción" que puede ser igual a 1, 2 o 3, solamente. */
	    {
	    case 1:
	      printf ("\n El numero de la posicion Fibonacci %d de la serie es: %.0lf",
		      n, fibonacci (n));    //Imprime solo el número en la posición indicada.
	      break;   

	    case 2:
	      printf ("\n\t Serie Fibonacci desde posicion cero: \n");   
	      for (posicion = 0; posicion <= n; posicion++)  //En este for, imprimimos los números de la serie fibonacci, cuidando no imprimir decimales pues se trabajó con doubles, ya que supuestamente este tipo de dato aguanta más dígitos o caracteres
		printf ("\t %.0lf", fibonacci (posicion));
	      break;

	    case 3:
	      printf ("\n\t Serie Tribonacci desde posicion cero: \n");   
	      for (posicion = 0; posicion <= n; posicion++)  //Se realiza de forma similar 
		printf ("\t %.0lf", tribonacci (posicion));
	      break;


	    default:
	      printf ("\nIngresa un numero valido.");  /*Si opción es diferente de 1 o 2, no se 
                                                                                   habrá elegido una operación a hacer del 
                                                                                   menú. */
	    }

	}

      printf ("\n\n te gustaria repetir la operación?  (s = Si / N = No): ");
      scanf ("%s", &resp);  //Pedimos que se ingrese la variable resp, para saber si se repiten o no las instrucciones desde cero. 
    }
  return 0;
}
