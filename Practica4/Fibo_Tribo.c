/* Título: Fibo_Tribo.c 
   Descripción: Función que calcula la posición (numero 'n') en la  
                         serie Fibonacci o en la serie Tribonacci
-	Recibe: Posición o número en la serie. 
-	Retorna: Entero, el valor encontrado en esa posición.   
    Autor: Equipo 932            Fecha: 11 de Mayo de 2017
    Versión: 1.0
*/
#include "Fibonacci_Tribonacci.h"

	/*
	Instrucciones: Calcula la posición (numero 'n') de la serie   
              Fibonacci que se indica.
	Recibe: Posición o numero en la serie. 
	Retorna: Entero, el valor encontrado en esa posición. */
double
fibonacci (int n)
{
	/*La función se encuentra sin optimizar, Si el número de la  
             serie es menor a 2, se imprime, terminando la recursividad */
  if (n < 2)
    return n;  //Si el numero ingresado "n" es menor a 2, se imprime  
        dicho número, si no, se realiza la suma, que por definición,  
        pide la serie fibonacci
  else
    return fibonacci (n - 1) + fibonacci (n - 2); 
	/*Ejemplo: Si n=3, hace la suma de los valores de la serie, en
              n=2 y n=1, para saber estos valores, vuelve a realizar el
              mismo cálculo (recursividad) para n=2
    	 y n=1, así, para n=1 (caso base), regresa 1 y se le suma 1
              (valor resultante para la posición n=2, ya que se sumó los
              valores de n=0 y n=1, es decir, 0+1). Finalmente, el resultado 
              será 1+1 = 2*/
}
/* A continuación se escribe la función que, de manera similar, realizará los cálculos para la serie Tribonacci. */
double
tribonacci (int n)
{
  if (n < 3)
  {
      if (n == 0)
          return 1;  
     else
         return n;  //Si el numero ingresado "n" es menor a 3, se imprime  
        dicho número, si no, se realiza la suma, que por definición,  
        pide la serie tribonacci
  }
  else
    return tribonacci (n - 1) + tribonacci (n - 2) +  tribonacci (n - 3);
}
