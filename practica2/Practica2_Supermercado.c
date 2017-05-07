/*Programa principal de la simulaciòn 2.1 (supermercado).
Autor: Equipo 932 
Año 2017*/

#include "TADColaEst.h"    //Se incluye la biblioteca de la cola estàtica, podemos variar esto quitando alguno de los comentarios de abajo.
//#include "TADColaDin.h"
#include "ImprimirCajas.h"  
#include <stdlib.h>

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
