/* Título: Hanoi.h 
   Descripción: Cabecera que incluye las bibliotecas predefinidas y define las funciones.
    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1.0
*/
#include <stdio.h> //Incluimos cabecera stdio para usar printfs y scanfs
#include <stdlib.h> 

void Hanoi (int ndiscos, int A, int C, int B, int repetHan); //Funciòn Hanoi, realiza càlculos recursivos.
void pintar (int ndiscos, int A, int C, int B, int RepetHan); //Funciòn pintar, pinta el disco a mover. o como irìa quedando la torre.
