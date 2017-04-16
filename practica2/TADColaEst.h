/*
LIBRERIA: Cabecera de el TAD COLA ESTÁTICA
AUTOR: Edgardo Adrián Franco Martínez (C) Febrero 2017
VERSIÓN: 1.6

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando 
se le asigna una cantidad fija de memoria para esa estructura 
antes de la ejecución del programa. 
*/

//DEFINICIONES DE CONSTANTES
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define TRUE	1
#define FALSE	0
#define MAX_ELEMENT 100
//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
 typedef  char boolean;         //   SOLO PARA LINUX

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	char dato[45];
	int tiempo;
	int tiempo_total;
	int n;
} elemento;

//Definir una cola (Se modela con una estructura que incluye un arreglo estatico de "elemento",
//de MAX_ELEMENT de longitud, así como dos subindices para controlar el frente y final dela cola)
typedef struct cola
{
	elemento elementos[MAX_ELEMENT];
	int frente;
	int final;
	int num_elem;
} cola;

//DECLARACIÓN DE FUNCIONES
void Initialize(cola * c);			//Inicializar cola (Initialize): Recibe una cola y la inicializa para su trabajo normal.
void Queue(cola * c, elemento e);	//Encolar (Queue): Recibe una cola y agrega un elemento al final de ella. 
elemento Dequeue(cola * c);			//Desencolar (Dequeue): Recibe una cola y remueve el elemento del frente retornándolo.
boolean Empty(cola * c);			//Es vacía (Empty): Recibe la cola y devuelve verdadero si esta esta vacía.
elemento Front(cola * c);			//Frente (Front): Recibe una cola y retorna el elemento del frente.	
elemento Final(cola * c);			//Final (Final): Recibe una cola y retorna el elemento del final.
elemento Element(cola *c, int i); 	// Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición.
int Size(cola *c);					//Tamaño (Size): Retorna el tamaño de la cola 	
void Destroy(cola * c);				//Eliminar cola (Destroy): Recibe una cola y la libera completamente.
