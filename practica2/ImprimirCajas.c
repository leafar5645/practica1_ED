/*  Título: ImprimirCajas.c
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: 1 de junio de 2017               Versión: 1.5
*/
#include "ImprimirCajas.h"

/* Imprimir_en_pantalla, es la funciòn encargada de imprimir de manera visualmente atractiva, el estado de la simulaciòn en un momento determinado, imprimiendo los clientes formados en cada cola, indicando cual es atendido y que cajas estan en servicio.
Recibe: El arreglo de colas (o cajas), una variable "i" para recorridos en ciclos, los tiempos de atenciòn de cada caja y tiempo de llegada de los clientes, el tiempo total del programa, la cantidad de clientes atendidos, el cliente en caja (e) y el nombre del supermercado.
Retorna: No regresa nada como tal, solo imprime cosas.*/
void Imprimir_en_pantalla (cola cajas[10], int i, int tiempos[11], int tiempo_total, int atendidos, elemento e, char nom_merc[100])
{
      system ("/usr/bin/clear");		//Borra la pantalla. Instruccion no perteneciente a ANSI C
	      printf ("\n\t\t\t\t\tNombre del Supermercado: %s\t\t\t", nom_merc);	
      printf ("\n\t\tRecuerde que cerramos cuando 100 clientes sean atendidos y no haya clientes en espera.\n\n\t\t\t");
      printf ("  ");
	  for (i = 0; i < 10; i++)		//Se imprimen las cajas, esten o no activas
      {
	printf (" caja %d ", i + 1);   
      }
      printf("\n\nTiempo de atencion:\t");  //Se imprime el tiempo de atenciòn escrito para cada caja
      for (i = 0; i < 10; i++)
	{
		if(tiempos[i]==0)   //Si la caja esta fuera de servicio, se imprime una linea en donde irìa el tiempo.
		printf ("   --\t");
		else
	  printf ("   %d\t", tiempos[i]);
	}

      printf ("\n\n\n\nAtendido:\t\t");	  //A continuaciòn se imprime una fila de atendidos en cada caja, es decir, el primer elemento (o cliente) de la cola
      for (i = 0; i < 10; i++)
      {
      	// A continuacion imprimiremos para cada fila, los clientes en fila, sabiendo que habra si el tamaño de la cola -1 (el atendido), es mayor o igual a lo que se pide.
	if (Size (&cajas[i])-1 >= 0)	//Si no esta vacìa, se imprime el elemento al frente de la cola, el cual se simula que es el que esta siendo atendido
	  {
	    e = Front (&cajas[i]);  
	    printf ("   %d\t", e.n); //Imprimiendo cliente atendido
	  }
	  else if(tiempos[i]==0)   //Si la caja esta fuera de servicio, se imprimira una "S" 
	printf ("   S \t");
	else			//Si no hay clientes formados, se imprimira una "N"
	  printf ("   N\t");
      }
            //Se imprimen a continuacion, los clientes formados, no atendidos aùn
/* ------------------------------------------------------------------------ */
      printf ("\n\n\nPrimero en fila:\t");	
      for (i = 0; i < 10; i++)
	{
	  if (Size (&cajas[i])-1 >= 1) //Siempre verificandose que exista la cantidad de clientes necesaria para que haya un primer/segundo y tercer lugar en la cola de espera
	    {
	      e = Element (&cajas[i], 2);  //Se imprime el elemento en la posicion dada, de la caja ingresada (posicion del arreglo de cajas)
	      printf ("   %d\t", e.n);
	    }
	  else if(tiempos[i]==0) //Recordemos que si la caja esta fuera de servicio, se imprimirà "S" y si no hay clientes formados en el lugar indicado de la fila, se imprimirà una "N"
	printf ("   S \t");
	  else
	    printf ("   N\t");
	}

      printf ("\n\nSegundo en fila:\t"); //Repetimos el mismo procedimiento de impresiòn en pantalla, para los segundos y terceros en cada fila, cambiando el if correspondiente
      for (i = 0; i < 10; i++)	 //Recordemos que el ciclo for recorre horizontalmente, lo que implica que se imprima el cliente de cada cola, o mejor dicho cada caja del supermercado
	{
	  if (Size (&cajas[i])-1 >= 2)
	    {
	      e = Element (&cajas[i], 3);
	      printf ("   %d\t", e.n);
	    }
	    else if(tiempos[i]==0)
	printf ("   S \t");
	  else
	    printf ("   N\t");
	}

      printf ("\n\nTercero en fila:\t");  //Ahora se imprime el tercero de cada fila, si es que existe (si no, se imprime "N" o "S").
      for (i = 0; i < 10; i++) 
	{
	  if (Size (&cajas[i]) -1 >= 3) 
	    {
	      e = Element (&cajas[i], 4);
	      printf ("   %d\t", e.n);
	    }
	  else if(tiempos[i]==0)
	printf ("   S \t");
	  else
	    printf ("   N\t");
	}  //Hasta ahora, hemos imprimido los clientes atendidos y los clientes formados en 1ª, 2ª y 3ª lugar de cada cola por caja (si existian)

    /* ------------------------------------------------------------------------ */
    
      printf ("\n\n\nTamano de fila:\t\t");	//Imprime el tamaño de la fila de clientes que esperan a ser atendidos
      for (i = 0; i < 10; i++)
	{
		if(tiempos[i]==0) //Si la caja esta fuera de servicio, se imprime una linea.
		printf ("   --\t");
		else if (Size (&cajas[i]) >0)
	    {
 printf ("    %d\t", Size (&cajas[i])-1); //Debemos considerar que no se cuenta al cliente atendido en el momento
	    }
	    else
	  printf ("   %d\t", Size (&cajas[i])); 
	}
      printf("\n\n\nLas personas llegan cada %d segundos", tiempos[10]); //Imprimimos el tiempo de llegada de los clientes, propuesto al inicio del programa.
      printf ("\n  TIEMPO: %d segundos", tiempo_total);	//Imprime el tiempo que lleva la simulaciòn.
      printf ("\t\t  Numero de clientes atendidos en total:\t  %d", atendidos);	//Imprime el nùmero total de clientes atendidos.
}
