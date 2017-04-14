/*IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA DINMICA (TADPilaDin.h)
AUTOR: Edgardo Adrin Franco Martnez (C) Septiembre 2012
VERSIN: 1.3

DESCRIPCIN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado "tope" de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinmica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecucin del programa. En este caso la memoria 
no queda fija durante la compilacin.

COMPILACIN PARA GENERAR EL CDIGO OBJETO: gcc -c TADPilaDin.c
*/

//LIBRERAS
#include <stdlib.h>
#include "TADPilaDin.h"

//DEFINICIN DE FUNCIONES

/*
void Initialize(pila *s);
Descripcin: Inicializar pila (Iniciar una pila para su uso)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
s->tope=NULL; //(*s).tope=NULL;
return;
}

/*
void Push(pila *s, elemento e);
Descripcin: Empilar (Introducir un elemento a la pila)
Recibe: int *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si el malloc() pudo o no apartar memoria, se idealiza que siempre funciona bien 
y no se acaba la memoria
*/
void Push(pila *s, elemento e)
{
nodo *aux;
aux=malloc(sizeof(nodo));
(*aux).e=e;  //aux->e=e;
aux->abajo=s->tope;
s->tope=aux;
return;
}


/*
void Pop(pila *s);
Descripcin: Desempilar (Extraer un elemento de la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraido de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de desempilar (causa error desempilar si esta esta vaca), 
tampoco se valida si free() pudo o no liberar la memoria, se idealiza que siempre funciona bien 
*/
elemento Pop (pila *s)
{
elemento r;
nodo *aux;
r=s->tope->e;
aux=s->tope;
s->tope=s->tope->abajo;
free(aux);
return r;
}

/*
boolean Empty(pila *s);
Descripcin: //Vacia (Preguntar si la pila esta vacia)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE segn sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
boolean r;
if(s->tope==NULL)
{
r=TRUE;
}
else
{
r=FALSE;
}
return r;
}

/*
elemento Top(pila *s);
Descripcin: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemnto del tope (causa error si esta esta vaca).
*/
elemento Top(pila *s)
{
return s->tope->e;
}

/*
int Size(pila *s);
Descripcin: Tamaño de la pila (Obtener el nmero de elementos en la pila)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: int (Tamaño de la pila -1->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
nodo *aux;
int tam_pila=0;
aux=s->tope;
if(aux!=NULL)
{
tam_pila++;
while(aux->abajo!=NULL)
{
tam_pila++;
aux=aux->abajo;
}
}
return tam_pila;
}

/*
void Destroy(pila *s);
Descripcin: Elimina pila (Borra a todos los elementos en a la pila de memoria)
Recibe: int *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
void Destroy(pila *s)
{
nodo *aux;
if(s->tope!=NULL)
{
while(s->tope!=NULL)
{
aux=s->tope->abajo;
free(s->tope);
s->tope=aux;
}
}
return;
}

