/*  Título: Practica2_Supermercado.c
   Descripción: funciones que en conjunto realizan una simulaciòn de un supermercado.
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
