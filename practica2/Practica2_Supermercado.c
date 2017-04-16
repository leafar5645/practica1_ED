#include "TADColaEst.h"
//#include "TADColaEstCirc.h"
//#include "TADColaDin.h"
#include <stdlib.h>
void Imprimir_en_pantalla (cola cajas[10], int i, int tiempos[11], int tiempo_total, int atendidos, elemento e, char nom_merc[100])
{
      system ("/usr/bin/clear");		//Borra la pantalla. CAMBIA PARA LINUX
	      printf ("\n\t\t\t\t\tNombre del Supermercado: %s\t\t\t", nom_merc);	
      printf ("\n\t\tRecuerde que cerramos cuando 100 clientes sean atendidos y no haya clientes en espera.\n\n\t\t\t");
      printf ("  ");
	  for (i = 0; i < 10; i++)		//Se imprimer las cajas, esten o no activas
      {
	printf (" caja %d ", i + 1);
      }
      printf("\n\nTiempo de atencion:\t");
      for (i = 0; i < 10; i++)
	{
		if(tiempos[i]==0)
		printf ("   --\t");
		else
	  printf ("   %d\t", tiempos[i]);
	}

      printf ("\n\n\n\nAtendido:\t\t");	
      for (i = 0; i < 10; i++)
      {
      	// A continuacion imprimiremos para cada fila, los clientes en fila, sabiendo que habra si el tamaño de la cola -1 (el atendido), es mayor o igual a lo que se pide.
	if (Size (&cajas[i])-1 >= 0)	//Si no esta vacia, se imprime el elemento al frente de la cola, el cual se simula que es el que esta siendo atendido
	  {
	    e = Front (&cajas[i]);
	    printf ("   %d\t", e.n);
	  }
	  else if(tiempos[i]==0)   //Si la caja esta fuera de servicio, se imprimira una "S" 
	printf ("   S \t");
	else			//Si no hay clientes formados, se imprimira una "N"
	  printf ("   N\t");
      }
            //Se imprimen a continuacion, los clientes formados, no atendidos aun
/* ------------------------------------------------------------------------ */
      printf ("\n\n\nPrimero en fila:\t");	
      for (i = 0; i < 10; i++)
	{
	  if (Size (&cajas[i])-1 >= 1)
	    {
	      e = Element (&cajas[i], 2);  //Se imprime el elemento en la posicion dada, de la caja ingresada (posicion del arreglo de cajas)
	      printf ("   %d\t", e.n);
	    }
	  else if(tiempos[i]==0)
	printf ("   S \t");
	  else
	    printf ("   N\t");
	}

      printf ("\n\nSegundo en fila:\t");
      for (i = 0; i < 10; i++)	
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

      printf ("\n\nTercero en fila:\t");
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
	}

    /* ------------------------------------------------------------------------ */
    
      printf ("\n\n\nTamano de fila:\t\t");	//Imprime el tamaño de la fila, los clientes  no atendidos aun
      for (i = 0; i < 10; i++)
	{
		if(tiempos[i]==0)
		printf ("   --\t");
		else if (Size (&cajas[i]) >0)
	    {
 printf ("    %d\t", Size (&cajas[i])-1);
	    }
	    else
	  printf ("   %d\t", Size (&cajas[i]));
	}
      printf("\n\n\nLas personas llegan cada %d segundos", tiempos[10]);
      printf ("\n  TIEMPO: %d segundos", tiempo_total);	//Imprime el tiempo que lleva la simulacion.
      printf ("\t\t  Numero de clientes atendidos en total:\t  %d", atendidos);	//Imprime el numero total de clientes atendidos.
}


int
main (void)
{
  cola cajas[10];	            //Cada posicion sera una caja, viene siendo un arreglo de colas, recordemos que la ultima posicion es para el "nulo"
  int i = 0;
  elemento e;			    
  char nom_merc[50];		
  int tiempo_total = 0;	
  int num_caja = 0;			//Valor de la caja en los "arreglos".
  int tiempos[11];	    	//Tiempo de cada caja, la posicion 10 sera para el tiempo en que llegan los clientes.
  int clientes_en_caja[10];		    //Los clientes de las cajas (el numero de caja es la posicion del arreglo)
  int no_hay_filas = 0;			
  int ncajas = 0;		    //Numero de cajas disponibles.
   srand (time (NULL));			
  int clientes_atend = 0;
	

  while(i < 10)	//inicializamos las colas y los arreglos que se van a utilizar 
    {
      tiempos[i] = 0;  //Este arreglo sera muy util pues nos ayudara a saber que cajas no estan en servicio, por ello la importancia de inicializarlo a 0
      Initialize (&cajas[i]);
      clientes_en_caja[i] = 0;
      i++;
    }

                     //INFORMACION QUE SE PIDE INICIANDO EL PROGRAMA
  /*  -------------------------------------------------------------------------------------- */
  printf ("\n\t\t\t\tPRACTICA 2. Simulacion 1\n");
  
  printf ("\n\tIngresa el nombre del supermercado: ");
  fgets (nom_merc, 100, stdin);	
  printf ("\n\tIngresa numero de cajas atendiendo:  ");
  scanf ("%d", &ncajas);	
  if(ncajas <1 || ncajas>9 )
  {
  printf("\n\n\t\tNO EXISTE ESE NUMERO DE CAJAS.\n");
  return 0;
  }
  printf("\n");
  printf("\n");
  for (i = 1; i <= ncajas; i++)	
    {
      printf ("\tIngresa el tiempo en que la caja %d atiende:   ", i);
      scanf ("%d", &tiempos[i-1]);	
    }
  printf ("\n\tIngresa cuanto tardan los clientes en llegar:   ");
  scanf ("%d", &tiempos[10]);
  /*  -------------------------------------------------------------------------------------- */

  //Ciclo principal, con el checamos la condicion de cierre: cierra si se atendio mas de 100 clientes y no hay filas en ninguna caja
  while ((clientes_atend < 100) || (no_hay_filas == 1))   
    {
      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
      usleep (500000);		//Tiempo de pausa entre cada accion, debe darse en milisegundos
      tiempo_total++;		//Tiempo de la simulacion

      if ((tiempo_total % tiempos[10]) == 0) 
	{
    	//depende del tiempo que hayamos dado a la llegada de los clientes, basicamente da la llegada de un nuevo cliente
	  num_caja = rand () % ncajas;	//Se da un valor random para poner a cada cliente nuevo en una caja.
	  clientes_en_caja[num_caja] = clientes_en_caja[num_caja] + 1;	
	  e.n = clientes_en_caja[num_caja];
	  Queue (&cajas[num_caja], e);	//Mete al cliente dado a fila indicada, es decir a la posicion dada para la cola
	}
      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
		
      for (i = 0; i < ncajas; i++)
	{
	  if (Empty (&cajas[i]) == FALSE)	//Si la caja no esta vacia...
	    {
	      if (((tiempo_total % tiempos[i]) == 0))	
		{
		//Si paso el tiempo en que la caja termina de atender, suma uno al numero total de clientes atendidos: sacamos al cliente de la cola 
		  e = Dequeue (&cajas[i]);
		  clientes_atend++;	
		}
	    }
	}

      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
      /* ciclo que revisa si hay filas en cada caja */
      for (i = 0; i < ncajas; i++)	
	{
	  if (Empty (&cajas[i]) == TRUE)	
	    {
	      no_hay_filas = 0;
	    }
	  else
	    {
	      no_hay_filas = 1;
	      i = 20;  
		/* El indice se aumenta a un numero cualquiera al que no llegue el numero de cajas, para que se acabe el for,
		 el cual comprueba que todas las cajas estan vacias */
 	    }
	}
    }

  return 0;
}
