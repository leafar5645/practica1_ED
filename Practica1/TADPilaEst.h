/* Tìtulo: TADPilaEst.h
LIBRERIA: Cabecera de el TAD PILA ESTÃTICA
AUTOR ORIGINAL: Edgardo Adrián Franco Martínez (C) Septiembre 2016
VERSIÃ“N: 1.0

DESCRIPCIÃ“N: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando se le 
asigna una cantidad fija de memoria para esa estructura 
antes de la ejecuciÃ³n del programa. 


	   EQUIPO 932
   Integrantes:
	      - Hernández Ruiz Rafael
	      - Maya Rocha Luis Emmanuel
	      - Rivas Rojas Arturo
	    Fecha de uso por el equipo: 18 de Mayo de 2017              

*/

//DEFINICIONES DE CONSTANTES
#define MAX_ELEMENT 1000
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	char car;
	int num;
	float num2;
	//***
}elemento;

//Definir una pila (Se modela con una estructura que únicamente incluye un puntero a "elemento")
typedef struct pila
{		
	elemento arreglo[MAX_ELEMENT]; //La pila es un arreglo estático de MAX_ELEMET
	int tope; 		//El tope es un entero (Índice del arreglo de elementos)
}pila;

//DECLARACIÒN DE FUNCIONES
void Initialize(pila *s);		//Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e);	//Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);	             //Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);		//Vacía (Preguntar si la pila esta vacía)
elemento Top(pila *s);	//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s);		//Tamaño de la pila (Obtener el número de elementos en la pila)
void Destroy(pila *s);	//Elimina pila (Borra a todos los elementos y a la pila de memoria)


