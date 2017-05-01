// Biblioteca optimizada, reduciendo hasta el 35% aproximadamente del tiempo para obtener resultados.
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
    case 2:  //En este caso, tomamos en cuenta que el valor de n=2 tambièn es "1", por lo que lo escribimos, reduciendo llamadas recursivas.
      return 1;
    case 1:
      return 1;
    case 0:
      return 0;
    default:
      return fibonacci (n - 1) + fibonacci (n - 2);  //A continuaciòn, se da el mismo comportamiento del fibonacci recursivo "normal".
    }
}
