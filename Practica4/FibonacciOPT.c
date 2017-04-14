#include "Fibonacci.h"

/*
Instrucciones: Calcula la posicion (numero 'n') de la serie fibonacci que se indica.
Recibe: Posicion o numero en la serie. 
Retorna: Entero, el valor encontrado en esa posicion. */
double
fibonacci (int n)
{
/*La funcion se encuentra optimizada para calcular numeros grandes en un poco menos de tiempo. */
  switch (n)
    {
    case 2:
      return 1;
    case 1:
      return 1;
    case 0:
      return 0;
    default:
      return fibonacci (n - 1) + fibonacci (n - 2);
    }
}
