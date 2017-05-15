/* 
Título: fibonacci.c 
   Descripción: Función que calcula la posición (numero 'n') de la  
                         serie fibonacci que se indica.
-	Recibe: Posición o número en la serie. 
-	Retorna: Entero, el valor encontrado en esa posición.   
    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1
*/
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
  /*Ejemplo: Si n=3, hace la suma de los valores de la serie, en n=2 y n=1, para saber estos valores, vuelve a realizar el mismo càlculo (recursividad) para n=2
  y n=1, asì, para n=1 (caso base), regresa 1 y se le suma 1 (valor resultante para la posicion n=2, ya que se sumo los valores de n=0 y n=1, es decir,
  0+1). Finalmente, el resultado serà 1+1 = 2*/
}
