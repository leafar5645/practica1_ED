/*  Título: Practica2_Supermercado.c
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: 1 de junio de 2017               Versión: 1.5
*/
#include "TADColaEst.h"
//#include "TADColaEstCirc.h"
//#include "TADColaDin.h"
#include <stdlib.h>

/* Funciòn principal, opera las colas, haciendo la simulacion de un mercado: en cada cola o caja, van llegando clientes que son atendidos en un tiempo establecido por caja, al tener màs de 100 clientes atendidos y las cajas vacias, el programa se termina. 
Recibe: No recibe nada, es la funciòn donde se pediràn los datos a utilizar.
Retorna: un entero "0" si el programa corre sin errores.*/
int
main (void)
{
  cola cajas[10];	            //Cada posicion serà una caja, viene siendo un arreglo de colas, recordemos que la ùltima posiciòn es para el "nulo"
  int i = 0;
  elemento e;			    
  char nom_merc[50];		   //Nombre del supermercado
  int tiempo_total = 0;	
  int num_caja = 0;			//Valor de la caja en los "arreglos".
  int tiempos[11];	    	//Tiempo de cada caja, la ùltima posiciòn serà para el tiempo en que llegan los clientes.
  int clientes_en_caja[10];		    //Los clientes de las cajas (el nùmero de caja es la posiciòn del arreglo)
  boolean no_hay_filas = FALSE;			
  int ncajas = 0;		    //Nùmero de cajas disponibles.
   srand (time (NULL));			
  int clientes_atend = 0;
	

  while(i < 10)	//inicializamos las colas y los arreglos que se van a utilizar 
    {
      tiempos[i] = 0;  //Este arreglo sera muy ùtil pues nos ayudarà a saber que cajas no estan en servicio, por ello la importancia de inicializarlo a 0
      Initialize (&cajas[i]); //Inicializamos colas
      clientes_en_caja[i] = 0;
      i++;
    }

                     //INFORMACION QUE SE PIDE INICIANDO EL PROGRAMA
  /*  -------------------------------------------------------------------------------------- */
  printf ("\n\t\t\t\tPRACTICA 2. Simulacion 1\n");
  
  printf ("\n\tIngresa el nombre del supermercado: ");
  fgets (nom_merc, 100, stdin);	                            //Usamos fgets al tratarse de leer cadenas
  printf ("\n\tIngresa numero de cajas atendiendo:  ");
  scanf ("%d", &ncajas);	
  if(ncajas <1 || ncajas>9 )             //Como parte de las instrucciones del programa, se mencionò que no puede haber màs de 9 cajas atendiendo.
  {
  printf("\n\n\t\tNO EXISTE ESE NUMERO DE CAJAS.\n");
  return 0;
  }
  printf("\n");                   //espacios impresos para dar atractivo visual al programa
  printf("\n");
  for (i = 1; i <= ncajas; i++)	
    {
      printf ("\tIngresa el tiempo en que la caja %d atiende:   ", i);  //Se ingresan los tiempos de atenciòn para cada caja que està en servicio.
      scanf ("%d", &tiempos[i-1]);	
    }
  printf ("\n\tIngresa cuanto tardan los clientes en llegar:   "); //En la posiciòn 10 del arreglo de tiempos, se guarda el tiempo en que tardan en llegar los clientes.
  scanf ("%d", &tiempos[10]);
  /*  -------------------------------------------------------------------------------------- */

  //Ciclo principal, con el checamos la condiciòn de cierre: cierra si se atendiò màs de 100 clientes y no hay filas en ninguna caja
  while ((clientes_atend < 100) || (no_hay_filas == FALSE))   
    {
      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);
      usleep (500000);		//Tiempo de pausa entre cada acciòn, debe darse considerando que la funciòn trabaja con 1x10^-7 segundos
      tiempo_total++;		//Tiempo de la simulaciòn

      if ((tiempo_total % tiempos[10]) == 0) 
	{
    	//depende del tiempo que hayamos dado a la llegada de los clientes, basicamente da la llegada de un nuevo cliente
	  num_caja = rand () % ncajas;	//Se da un valor random para poner a cada cliente nuevo en una caja.
	  clientes_en_caja[num_caja] = clientes_en_caja[num_caja] + 1;	
	  e.n = clientes_en_caja[num_caja]; //Hacemos que los elementos de la cola, sean el cliente en cada caja (con un nùmero que los identifica por cola).
	  Queue (&cajas[num_caja], e);	//Mete al cliente dado a fila indicada, es decir a la posiciòn dada para la cola
	}
      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc); //Se imprime el estado del supermercado mientras no se termine de cumplir la condiciòn principal del programa
		
      for (i = 0; i < ncajas; i++)
	{
	  if (Empty (&cajas[i]) == FALSE)	//Si la caja no esta vacia...
	    {
	      if (((tiempo_total % tiempos[i]) == 0))	
		{
		//Si paso el tiempo en que la caja termina de atender, se suma uno al numero total de clientes atendidos: sacamos al cliente de la cola 
		  e = Dequeue (&cajas[i]);
		  clientes_atend++;	
		}
	    }
	}

      Imprimir_en_pantalla(cajas, i, tiempos, tiempo_total, clientes_atend, e, nom_merc);  //Imprimimos nuevamente el estado, ahora con la modificaciòn en la cantidad de clientes atendidos
      /* ciclo que revisa si hay filas en cada caja */
      for (i = 0; i < ncajas; i++)	
	{
	  if (Empty (&cajas[i]) == TRUE)	
	    {
	      no_hay_filas = TRUE;
	    }
	  else
	    {
	      no_hay_filas = FALSE;
	      i = ncajas+1;  
		/* El indice se aumenta a un numero cualquiera al que no llegue el nùmero de cajas, para que se acabe el for,
		 el cual comprueba que todas las cajas estan vacias */
 	    }
	}
    }

  return 0;  //Cuando la condiciòn principal termina de ejecutarse, se acaba el programa regresando un entero "0" para indicar al SO que el programa corriò sin problemas.
}
