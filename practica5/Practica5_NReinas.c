// Práctica 5, N-Reinas ... equipo 932
#include "presentacion.h"
#include "NReinas.h"
#define TRUE 1
#define FALSE 0

void pintar (int *tablero, int tamanio);	//Función que pintará los cambios en el tablero,en cada paso
void inicializar (int *tablero, int tamanio);	//Función que inicializa los valores del "arreglo de control de columnas" del tablero, en -1
boolean Reinas (int *tablero, int pos_actual, int tamanio);	//Función que realiza los cálculos principales, va haciendo el backtracking. Al final indica si se resolvió o no el juego
boolean sin_Ataque (int *tablero, int pos_actual);	//Función que revisará si la pieza movida recientemente, ataca a otra colocada anteriormente
boolean CalculoReinas (int *tablero, int tamanio);	//Función "inicial" que manda a llamar a la función reinas.

int
main (void)			//Función principal, se efectúan las instrucciones principales del programa.
{
  int *tablero;
  int tamanio = 0;		//tamanio: Almacenará el tamanio para el tablero N*N (es decir, cuanto vale esa N)
  int i,j;			//Variables para realizar recorridos

  printf ("\n\t\t\t PRACTICA 5. N-REINAS (BACKTRACKING) \n");
  printf (" Ingresa tamanio (en cuadros) del tablero: ");
  scanf ("%d", &tamanio);	//Solicitamos tamanio

  if (tamanio > 1)		//Si se ingresó un numero mayor a 1, se realizan cálculos
    {
      tablero = (int *) malloc (sizeof (int) * (tamanio + 1));	//Se solicita un bloque de memoria, es decir usamos memoria dinámica, pues no sabemos de que tamaño será el tablero

      if (CalculoReinas (tablero, tamanio) == TRUE)	//Si se pudo resolver el juego de forma satisfactoria, se termina agradeciendo por jugar.               
	{
	  BorrarPantalla ();
	  pintar (tablero, tamanio);	//Imprimimos la solución gráfica
//Luego, imprimimos las 2 soluciones propuestas (como conjunto de coordenadas), esto se obtiene de forma similar a como se hace la representación gráfica.
printf("\n Soluciones propuestas para %d reinas:\n\t", tamanio);
for(i=0;i<tamanio;i++)
{
for(j=0;j<tamanio;j++)
{	 
if(j==tablero[i]) 
printf ("(%d,%d) ",i,j);
}}
printf("\n\t");
for(i=0;i<tamanio;i++)
{
for(j=0;j<tamanio;j++)
{	 
if(j==tablero[i]) 
printf ("(%d,%d) ",j,i);
}}
printf("\n");	
}
      else			//Si no se resuelve el juego, se indica que no puede calcularse solución
	{
	  BorrarPantalla ();
	  pintar (tablero, tamanio);	//Imprimimos la solución gráfica
	  EsperarMiliSeg (400);	//Damos 0.4 segundos de pausa para dar atractivo visual al programa
	  printf ("\n\t ERROR, no hay forma de acomodar las reinas.\n\n");
	  return 0;
	}


    }
  else				//Si se metió un número menor a 1, por lógica no hay cálculos a realizar.
    printf ("\nIntroduce un numero mayor a uno. \n");
  return 0;
}
