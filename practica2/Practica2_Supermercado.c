/*Programa principal de la simulaciòn 2.1 (supermercado).
Equipo 932 */

#include "TADColaEst.h"    //Se incluye la biblioteca de la cola estàtica, podemos variar esto quitando alguno de los comentarios de abajo.
//#include "TADColaEstCirc.h"
//#include "TADColaDin.h"
#include <stdlib.h>
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


int
main (void)
{
  cola cajas[10];	            //Cada posicion sera una caja, viene siendo un arreglo de colas, recordemos que la ultima posicion es para el "nulo"
  int i = 0;    //Se declaran e inicializan los enteros y arreglos a utilizar,
  elemento e;			    
  char nom_merc[50];		  //Este arreglo lo usaremos solo para guardar el nombre del supermercado, tecleado al inicio
  int tiempo_total = 0;	
  int num_caja = 0;			//Valor de la caja en los "arreglos".
  int tiempos[11];	    	//Tiempo de cada caja, la posicion 10 sera para el tiempo en que llegan los clientes.
  int clientes_en_caja[10];		    //Los clientes de las cajas (el numero de caja es la posicion del arreglo)
  boolean no_hay_filas = FALSE;			
  int ncajas = 0;		    //Numero de cajas disponibles.
   srand (time (NULL));			//Sentencia que se utiliza para buscar numeros random, esto serà utilizado para asignar nùmero a los clientes (identificador de cada uno de ellos por cola).
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
  printf("\n");                         //Estas impresiones màs que nada son para dar un aspecto agradable al programa.
  printf("\n");
  for (i = 1; i <= ncajas; i++)	   //Se pide a continuaciòn dar el tiempo en el que atiende cada caja, en segundos.
    {
      printf ("\tIngresa el tiempo en que la caja %d atiende:   ", i);
      scanf ("%d", &tiempos[i-1]);	
    }
  printf ("\n\tIngresa cuanto tardan los clientes en llegar:   ");
  scanf ("%d", &tiempos[10]);
  /*  -------------------------------------------------------------------------------------- */

  //Ciclo principal, con el checamos la condicion de cierre: cierra si se atendìo màs de 100 clientes y no hay filas en ninguna caja
  while ((clientes_atend < 100) || (no_hay_filas == FALSE))   
    {
      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
      usleep (500000);		//Tiempo de pausa entre cada acciòn, debe darse en milisegundos
      tiempo_total++;		//Tiempo de la simulaciòn

      if ((tiempo_total % tiempos[10]) == 0) 
	{
    	//depende del tiempo que hayamos dado a la llegada de los clientes, bàsicamente da la llegada de un nuevo cliente
	  num_caja = rand () % ncajas;	//Se da un valor random para poner a cada cliente nuevo en una caja.
	  clientes_en_caja[num_caja] = clientes_en_caja[num_caja] + 1;	
	  e.n = clientes_en_caja[num_caja];  //El elemento serà el cliente que acabamos de meter.
	  Queue (&cajas[num_caja], e);	//Mete al cliente dado a "fila" indicada, es decir a la posicion dada para la cola
	}
      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
		
      for (i = 0; i < ncajas; i++)
	{
	  if (Empty (&cajas[i]) == FALSE)	//Si la caja no esta vacia...
	    {
	      if (((tiempo_total % tiempos[i]) == 0))	
		{
		//Si pasò el tiempo en que la caja termina de atender, suma uno al nùmero total de clientes atendidos: sacamos al cliente de la cola 
		  e = Dequeue (&cajas[i]);
		  clientes_atend++;	
		}
	    }
	}

      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
      /* ciclo que revisa si hay filas en cada caja */
      for (i = 0; i < ncajas; i++)	
	{
	  if (Empty (&cajas[i]) == TRUE)  //Si las cajas (cada una es una cola) estàn vacìas, entonces no hay filas
	    {                  
	      no_hay_filas = TRUE;
	    }
	  else
	    {
	      no_hay_filas = FALSE;
	      i = ncajas+1;  
		/* El indice se aumenta a un nùmero cualquiera al que no llegue el numero de cajas, para que se acabe el for,
		 el cual comprueba que todas las cajas estan vacias */
 	    }
	}
    }

  return 0;
}
