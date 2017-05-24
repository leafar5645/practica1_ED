/*  Tìtulo: TADPilaEst.c
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA ESTÁTICA (TADPilaEst.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2016
VERSIÓN: 1.0

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando se le 
asigna una cantidad fija de memoria para esa estructura 
antes de la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADPilaEst.c

	   EQUIPO 932
   Integrantes:
	      - Hernández Ruiz Rafael
              - Maya Rocha Luis Emmanuel
	      - Rivas Rojas Arturo
	    Fecha de uso por el equipo: 18 de Mayo de 2017              
*/

//LIBRERAS
#include "TADPilaEst.h"

//DEFINICIÓN DE FUNCIONES

/*
void Initialize(pila *s);
Descripción: Inicializar pila (Iniciar una pila para su uso)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
	(*s).tope=-1; //s->tope=-1; 
	return;
}

/*
void Push(pila *s, elemento e);
Descripción: Empilar (Introducir un elemento a la pila)
Recibe: pila *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario ha creado una pila y se tiene la referencia a ella, s ya ha sido inicializada.
Además no se valida el índice del arreglo (tope) está fuera del arreglo es decir hay desbordamiento
y se causará en error.
*/
void Push(pila *s, elemento e)
{
	s->tope++;
	s->arreglo[s->tope]=e;
	return;
}

/*
elemento Pop(pila *s);
Descripción: Desempilar (Extraer un elemento de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraído de la pila)
Observaciones: El usuario ha creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Además no se valida si la pila esta vacía (tope == -1) antes de desempilar (causa error desempilar si esta está vacía)
*/
elemento Pop (pila *s)
{
	elemento r;
	r=s->arreglo[s->tope];
	s->tope--;
	return r; 	
}

/*
boolean Empy(pila *s);
Descripción: //Vacía (Preguntar si la pila esta vacía)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE según sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
	boolean r;	
	if(s->tope==-1)
	{
		r= TRUE;	
	}	
	else
	{
		r= FALSE;
	}	
	return r;	
}

/*
elemento Top(pila *s);
Descripción: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario ha creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Además no se valida si la pila esta vacía antes de consultar al elemento del tope (causa error si esta está vacía).
*/
elemento Top(pila *s)
{
	return s->arreglo[s->tope];	
}

/*
elemento Top(pila *s);
Descripción: Tamaño de la pila (Obtener el número de elementos en la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: int (Tamaño de la pila -1->Vacía, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
	return s->tope+1;
}

/*
void Destroy(pila *s);
Descripción: Elimina pila (Borra a todos los elementos en a la pila de memoria)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y se tiene la referencia a ella.
*/
void Destroy(pila *s)
{
	//s->tope=-1;
	Initialize(s);
	return;
}
