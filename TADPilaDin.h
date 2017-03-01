/* LIBRERIA: Cabecera de el TAD PILA DINMICA
AUTOR: Edgardo Adri¡n Franco Martnez (C) Septiembre 2012
VERSI"N: 1.3

DESCRIPCI"N: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se aaden y se remueven por un solo extremo.
Este extremo es llamado €tope€ de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos din¡mica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecucin del programa. En este caso la memoria 
no queda fija durante la compilacin y se lograr¡ este dinamismo 
a travez del modelo "nodo" el cu¡l se reservar¡ dinamicamente logrando 
modelar una pila.
*/

//DEFINICIONES DE CONSTANTES
#define TRUE1
#define FALSE0

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

//Definir un nodo que ser¡ utilizado para almacenar una posicin de la pila (Nodo), lo que incluira a un elemento y a un apuntador al siguiente nodo
typedef struct nodo
{
//Elemento a almacenar en cada nodo de la pila
elemento e;
//Apuntador al elemento de debajo (Requerido por ser una implementacin din¡mica -Usuario: No modificar)
struct nodo *abajo;
}nodo;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila
{
nodo *tope;
}pila;

//DECLARACI"N DE FUNCIONES
void Initialize(pila *s);//Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e);//Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);//Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);//Vacia (Preguntar si la pila esta vacia)
elemento Top(pila *s);//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s);//Tamao de la pila (Obtener el nºmero de elementos en la pila)
void Destroy(pila *s);//Elimina pila (Borra a todos los elementos y a la pila de memoria)
