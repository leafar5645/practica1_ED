/* Título:Practica4_Fibo.c 
   Descripción: Es el archivo principal, donde se desarrollan las instrucciones más importantes, en esta funciòn se ingresan los datos a utilizar y aparece un menù donde eliges si quieres ver solo el valor de la serie fibonacci en una posiciòn indicada, o toda la serie hasta dicha posiciòn.
    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1.0
*/
#include "Fibonacci.h"

int
main (void)
{
  char resp = 's';   //Variable que definirà si se repite o no el programa
  int n = 0, opcion, posicion;

  while (resp == 's') //Mientras la variable "resp" sea 's' de "si", se realizaràn las instrucciones del programa
    {
      printf ("\n\t\t\t PRACTICA 4. RECURSIVIDAD EN SERIE FIBONACCI ");

      printf ("\n Ingresa posicion en la serie: ");
      scanf ("%d", &n);

      if (n < 0)
	printf ("\nIngresa un numero valido.");

      else
	{       //Si el numero ingresado fue vàlido para la serie fibonacci, se introduce un menù de opciones
	  printf ("\n Que deseas hacer?");
	  printf ("\n (1) Conocer el valor en la posicion especifica");
	  printf ("\n (2) Observar la serie hasta la posicion dada\n\t");
	  scanf ("%d", &opcion);

	  switch (opcion) //Para este menù de opciones trabajaremos con la variable "opcion" que puede ser igual a 1 o 2, solamente.
	    {
	    case 1:
	      printf ("\n El numero de la posicion %d de la serie es: %.0lf",
		      n, fibonacci (n));    //Imprime solo el nùmero en la posiciòn indicada.
	      break;   

	    case 2:
	      printf ("\n\t Serie desde posicion cero: \n");   
	      for (posicion = 0; posicion <= n; posicion++)  //En este for, imprimimos los nùmeros de la serie fibonacci, cuidando no imprimir decimales pues se trabajo con doubles, ya que supuestamente este tipo de dato aguanta màs dìgitos o caracteres
		printf ("\t %.0lf", fibonacci (posicion));
	      break;

	    default:
	      printf ("\nIngresa un numero valido.");  //Si opcion es diferente de 1 o 2, no se habrà elegido una operaciòn a hacer del menù.
	    }

	}

      printf ("\n\n te gustaria repetir la operacion?  (s = Si / N = No): ");
      scanf ("%s", &resp);  //Pedimos que se ingrese la variable resp, para saber si se repiten o no las instrucciones desde cero.
    }
  return 0;
}
