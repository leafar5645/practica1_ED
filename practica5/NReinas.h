/* Título: NReinas.h 
   Descripción: Cabecera de la práctica 5, contiene las definiciones de TRUE y FALSE para trabajar con funciones booleanas.
    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1.0
*/

#define TRUE 1
#define FALSE 0


void pintar (int *tablero, int tamanio);	//Función que pintará los cambios en el tablero,en cada paso
void inicializar (int *tablero, int tamanio);	//Función que inicializa los valores del "arreglo de control de columnas" del tablero, en -1
boolean Reinas (int *tablero, int pos_actual, int tamanio);	//Función que realiza los cálculos principales, va haciendo el backtracking. Al final indica si se resolvió o no el juego
boolean sin_Ataque (int *tablero, int pos_actual);	//Función que revisará si la pieza movida recientemente, ataca a otra colocada anteriormente
boolean CalculoReinas (int *tablero, int tamanio);	//Función "inicial" que manda a llamar a la función reinas.
