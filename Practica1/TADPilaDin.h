/* TÌTULO: TADPilaDin.h
LIBRERIA: Cabecera del TAD PILA DINÃMICA
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2012
VERSIÒN: 1.3

DESCRIPCIÒN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecuciÃ³n del programa. En este caso la memoria 
no queda fija durante la compilaciÃ³n y se logrará¡ este dinamismo 
a través del modelo "nodo" el cuál se reservará¡ dinámicamente logrando 
modelar una pila.

  EQUIPO 932
   Integrantes:
	      - Hernández Ruiz Rafael
	      - Maya Rocha Luis Emmanuel
	      - Rivas Rojas Arturo
	    Fecha de uso por el equipo: 18 de Mayo de 2017   
*/

//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	char c;
	//***
	//***
	//***
}elemento;

//Definir un nodo que será utilizado para almacenar una posiciÃ³n de la pila (Nodo), lo que incluirá a un elemento y a un apuntador al siguiente nodo
typedef struct nodo
{
	//Elemento a almacenar en cada nodo de la pila	
	elemento e;	
	//Apuntador al elemento de debajo (Requerido por ser una implementaciÃ³n dinámica -Usuario: No modificar)
	struct nodo *abajo;
}nodo;

//Definir una pila (Se modela con una estructura que únicamente incluye un puntero a "elemento")
typedef struct pila
{		
	nodo *tope;
}pila;

//DECLARACIÃ“N DE FUNCIONES
void Initialize(pila *s); //Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e); //Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);	//Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);	//Vacía (Preguntar si la pila esta vacía)
elemento Top(pila *s);	//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s); 	//Tamaño de la pila (Obtener el número de elementos en la pila)
void Destroy(pila *s);	//Elimina pila (Borra a todos los elementos y a la pila de memoria)
