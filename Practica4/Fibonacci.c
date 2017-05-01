// Biblioteca del programa fibonacci. Equipo: 932 
#include "Fibonacci.h"

/*
Instrucciones: Calcula la posiciòn (numero 'n') de la serie fibonacci que se indica.
Recibe: Posicion o numero en la serie. 
Retorna: Entero, el valor encontrado en esa posicion. */
double
fibonacci (int n)
{
/*La funcion se encuentra sin optimizar, Si el numero de la serie es menor a 2, se imprime, terminando la recursividad */
  if (n < 2)
    return n;  //Si el numero ingresado "n" es menor a 2, se imprime dicho numero, si no, se realiza la suma, que por definiciòn, pide la serie fibonacci
  else
    return fibonacci (n - 1) + fibonacci (n - 2);
}
