/* Título: presentacion.h
Autor: Edgardo Adrián Franco Martínez
Versión 1.0 (25 de Septiembre 2012)
Descripción: Cabecera de la libreria para recrear presentaciones más agradables al usuario en el modo consola

Observaciones: La implementación de esta libreria es distinta si se trata de Windows o Linux, ya que requerirá de funciones no ANSI C
 
     Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha de uso por el equipo: 18 de Mayo de 2017             
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//DECLARACIÓN DE FUNCIONES Y VARIABLES

typedef unsigned char boolean;	//Definimos al boolean como un tipo de dato caracter (especial)

void MoverCursor (int x, int y);	//Función para mover el cursor de escritura de pantalla, simulación de la función gotoxy() que se tenia en borland 3.0 en la libreria conio.h

void EsperarMiliSeg (int t);	//Función para esperar un tiempo en milisegundos, simulación de la función delay() que se tenia en borland 3.0 en la libreria conio.h

void BorrarPantalla (void);	//Función para borrar la pantalla de la consola, simulación de la función clrscr() que se tenia en borland 3.0 en la libreria conio.h
