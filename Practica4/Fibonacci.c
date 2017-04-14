#include "Fibonacci.h"

/*
Instrucciones: Calcula la posicion (numero 'n') de la serie fibonacci que se indica.
Recibe: Posicion o numero en la serie. 
Retorna: Entero, el valor encontrado en esa posicion. */
double
fibonacci (int n)
{
/*La funcion se encuentra sin optimizar, Si el numero de la serie es menor a 2, se imprime, terminando la recursividad */
  if (n < 2)
    return n;
  else
    return fibonacci (n - 1) + fibonacci (n - 2);
}
