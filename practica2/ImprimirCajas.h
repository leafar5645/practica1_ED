/*Cabecera del programa de simulaciòn 1 (Pràctica 2)
Autor: Equipo 932
Año 2017 */

#include "TADColaEst.h"    //Se incluye la biblioteca de la cola estàtica, podemos variar esto quitando alguno de los comentarios de abajo.
//#include "TADColaDin.h"
#include <stdlib.h>
#include <stdio.h>

void Imprimir_en_pantalla (cola cajas[10], int i, int tiempos[11], int tiempo_total, int atendidos, elemento e, char nom_merc[100]); //Funciòn que imprimira el estado de las colas, con atractivo visual para dar a entender que es un centro comercial.
