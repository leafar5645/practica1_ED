#include "ImprimirCajas.h"  

void Imprimir_en_pantalla (cola cajas[10], int i, int tiempos[11], int tiempo_total, int atendidos, elemento e, char nom_merc[100])
{  //Funciòn que serà llamada cada vez que se quiera imprimir el estado de las colas del supermercado.
      system ("/usr/bin/clear");		//Borra lo escrito en pantalla.
	      printf ("\n\t\t\t\t\tNombre del Supermercado: %s\t\t\t", nom_merc);	
      printf ("\n\t\tRecuerde que cerramos cuando 100 clientes sean atendidos y no haya clientes en espera.\n\n\t\t\t");
      printf ("  ");
	  for (i = 0; i < 10; i++)		//Se imprimer las cajas, esten o no activas
      {
	printf (" caja %d ", i + 1);                 
      }
      printf("\n\nTiempo de atencion:\t");      //Tambièn se imprimira el tiempo de atenciòn señalado para cada caja.
      for (i = 0; i < 10; i++)
	{
		if(tiempos[i]==0)              //Si no se ingreso un tiempo para la caja indicada, quiere decir que èsta, esta fuera de servicio
		printf ("   --\t");            // Al estar fuera de servicio, se imprime una linea horizontal
		else
	  printf ("   %d\t", tiempos[i]);
	}

      printf ("\n\n\n\nAtendido:\t\t");	       
      for (i = 0; i < 10; i++)
      {
      	// A continuacion imprimiremos para cada fila, los clientes formados en fila, sabiendo que habra si el tamaño de la cola -1 (el atendido), es mayor o igual al numero de cliente en la fila pedido.
	if (Size (&cajas[i])-1 >= 0)	//Si no esta vacia, se imprime el elemento al frente de la cola, el cual se simula que es el que esta siendo atendido
	  {
	    e = Front (&cajas[i]);      
	    printf ("   %d\t", e.n);
	  }
	  else if(tiempos[i]==0)   //Si la caja esta fuera de servicio, se imprimira una "S" 
	printf ("   S \t");
	else			//Si no hay clientes formados en la posicion dicha (no hay ni un solo cliente en la fila, ni si quiera uno atendido), se imprimira una "N"
	  printf ("   N\t");
      }
            //Se imprimen a continuacion, los clientes formados, no atendidos aun
/* ------------------------------------------------------------------------ */
      printf ("\n\n\nPrimero en fila:\t");	
      for (i = 0; i < 10; i++)     //Estos bloques for son los encargados de recorrer "el arreglo" de colas, con ello podremos imprimir "horizontalmente" lo pedido.
	{
	  if (Size (&cajas[i])-1 >= 1)   //Recordemos que le restamos 1 al tamaño pues no estamos contando al primer elemento en fila (cliente atendido)
	    {
	      e = Element (&cajas[i], 2);  //Se imprime el elemento en la posicion dada, de la caja ingresada (posicion del arreglo de cajas)
	      printf ("   %d\t", e.n);
	    }
	  else if(tiempos[i]==0)    //De la misma forma que como se hizo con la fila horizontal del cliente atendido, si la caja esta fuera de servicio, se imprime "S", si no hay clientes, "N"
	printf ("   S \t");
	  else
	    printf ("   N\t");
	}

      printf ("\n\nSegundo en fila:\t");   //Repetimos un procedimiento similar para imprimir (horizontalmente) los clientes formados en segundo lugar en cada fila
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

      printf ("\n\nTercero en fila:\t");  //.... y tambièn para los clientes en el tercer lugar.
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
    
      printf ("\n\n\nTamano de fila:\t\t");	//Imprime el tamaño de la fila, el numero de clientes  no atendidos aun
      for (i = 0; i < 10; i++)
	{
		if(tiempos[i]==0)
		printf ("   --\t");    //Se imprime una linea, si la caja esta fuera de servicio.
		else if (Size (&cajas[i]) >0)  
	    {
 printf ("    %d\t", Size (&cajas[i])-1);  //Se resta un 1, ya que en el tamaño de la fila de una caja, no se cuenta al cliente atendido en esa caja
	    }
	    else
	  printf ("   %d\t", Size (&cajas[i]));  //... si no hay clientes atendidos/formados, se debe imprimir "0" y no "-1", esto viene de no contar al cliente atendido en una fila.
	}
      printf("\n\n\nLas personas llegan cada %d segundos", tiempos[10]);
      printf ("\n  TIEMPO: %d segundos", tiempo_total);	//Imprime el tiempo que lleva la simulaciòn.
      printf ("\t\t  Numero de clientes atendidos en total:\t  %d", atendidos);	//Imprime el numero total de clientes atendidos.
}
