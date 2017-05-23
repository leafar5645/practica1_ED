/* Título: Hanoi.h 
   Descripción: Cabecera que incluye las bibliotecas predefinidas y define las funciones.
   -Recibe: cada una recibe el “tamaño del disco en curso” (ndiscos), el palo inicial, destino y auxiliar y la variable repetHan, aunque en pintar solo se necesitaran los palos, al llamarla al final del programa principal.
   -Retorna: Solo hacen operaciones, no regresan algo como tal.
   
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: 11 de Mayo de 2017               Versión: 1.2
*/
#include <stdio.h> //Incluimos cabecera stdio para usar printfs y scanfs
#include <stdlib.h> 

void Hanoi (int ndiscos, int A, int C, int B, int repetHan); //Funciòn Hanoi, realiza càlculos recursivos.
void pintar (int ndiscos, int A, int C, int B, int RepetHan); //Funciòn pintar, pinta el disco a mover. o como irìa quedando la torre.
