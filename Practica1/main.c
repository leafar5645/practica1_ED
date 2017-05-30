/*  Título: main.c
   Descripción: función principal de la práctica 1, aquí se efectúan las instrucciones principales del código, mandando a llamar funciones extra. 
                 Se pedirá una expresión de letras y operandos, checando que estén bien puestos los paréntesis, y mostrando expresión ordenada en posfijo, luego se pedirá el valor de cada letra y se hará la operación.
 
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: Abril de 2017               Versión: 2.1
*/

#include<stdio.h>
#include<string.h>
#include"TADPila.h"
#include<math.h>

int
main (void)
{

  int i;

  int l = 0;

  int p;

  pila mi_pila;  

  elemento a;			//Nos servirá para almacenar elementos del tope de la pila

  char resp;

  int k = 0;
  int z = 0;

  char expresion[150] = "";	//Arreglo donde se almacenara la expresión escrita al inicio.

  char salida[150] = "";

  char letras[27] = "///////////////////////////";	//Arreglo donde se almacenan las letras que pueden ingresarse (A-Z).

  float valores[27];		//Arreglo para guardar los valores ingresados para cada letra.

  float num1;
  float resultado;		//Es la variable para el resultado final de la evaluación
  float num2;

  printf
    ("teclea una expresion solo letras mayusculas A-Z y las siguientes operaciones +,*,-,/,^ \n");

  scanf ("%s", expresion);	//Se trata de una cadena de caracteres.

  int j = 0;

  Initialize (&mi_pila);	//Inicializamos la pila creada 



  for (i = 0; i < strlen (expresion); i++)	//Aumentamos el índice del arreglo hasta que sea menor a la cantidad añadida de elementos en la expresión.

    {

      if (expresion[i] == '(')	//Solo si es igual a paréntesis de entrada, hacemos el push.

	{

	  a.car = '(';

	  Push (a, &mi_pila);

	}

      else if (expresion[i] == ')')	//Si es paréntesis de salida, sacamos el paréntesis de entrada que se acceso al ùltimo.


	{

	  if (Empty (&mi_pila) != TRUE)
	    {

	      a = Pop (&mi_pila);

	    }

	  else			//Si al repetir el proceso, llega un punto donde la pila este vacía, quiere decir que se agregaron más par. de salida.

	    {

	      printf
		("\nERROR:\nHay parentesis que intentan cerrar y nunca abrieron: %d",
		 i);

	      return 1;		//Y regresamos al sistema que hubo un error.

	    }

	}

    }				//Terminación del ciclo for (ya terminaron de "cerrarse los paréntesis de entrada y salida entre si"). 


  if (Empty (&mi_pila) == TRUE)

    {

      printf ("\nEXCELENTE");

      while (l < strlen (expresion))	//si la expresión está bien la analizaremos completa para separar y reacomodar los componentes

	{

	  if (expresion[l] == '(')	//si es paréntesis que abre lo meteremos a la pila

	    {

	      a.car = '(';

	      Push (a, &mi_pila);

	    }

	  if (expresion[l] == ')')	//si es paréntesis que cierra sacaremos todo de la pila hasta encontrar un paréntesis que abrió y juntaremos todo lo que vamos sacando a la cadena salida con la función strcat

	    {

	      while (Top (&mi_pila).car != '(')    //Mientras no aparezca un paréntesis de entrada...

		{

		  a = Pop (&mi_pila);   //...Almacenamos en la variable "a" al elemento sacado de la pila

		  strcat (salida, &a.car); //y concatenamos el elemento a la salida

		}

	      a = Pop (&mi_pila); //Cuándo aparezca un paréntesis de entrada, termina el recorrido (ya sacamos lo que estaba entre los paréntesis), y sacamos el paréntesis de entrada de la pila

	    }

	  p = (int) expresion[l] - 64;	//el valor ascii de los caracteres menos 64 si es una letra mayuscula A-Z p tendra un valor de 1 a 26

	  if (1 <= p & p <= 26)	//vemos si es una letra

	    {

	      letras[(int) expresion[l] - 64] = expresion[l];	//al aparecer un letra la guardamos en el arreglo letras en la posición de su valor ascii menos 64 para que estén en orden y después pedir sus valores

	      a.car = expresion[l];

	      strcat (salida, &a.car);	//concadenamos la letra

	    }

	  if (expresion[l] == '+' || expresion[l] == '-' || expresion[l] == '*' || expresion[l] == '/' || expresion[l] == '^')	//si es un operador veremos las siguientes condiciones

	    {  //Verificamos que en la cadena, durante el recorrido, aparezca un operador, si es así, se realizarán una serie de instrucciones para poder acomodar la expresión en posfijo

	      if (expresion[l] == '+' || expresion[l] == '-')

		{

		  while (Top (&mi_pila).car == '*' || Top (&mi_pila).car == '/' || Top (&mi_pila).car == '^' || Top (&mi_pila).car == '+' || Top (&mi_pila).car == '-')	//si el operador es + o - menos y en la pila hay operadores de mayor o igual importancia los va a sacar todos

		    {

		      a = Pop (&mi_pila);

		      strcat (salida, &a.car);	//concatena todo lo que sacamos, es decir, va colocando en nuestra salida, los elementos que se van sacando de la pila

		    }

		  a.car = expresion[l];	//y guarda en la pila el nuevo operador

		  Push (a, &mi_pila);

		}

	      if (expresion[l] == '*' || expresion[l] == '/')  //Hacemos un if "inicial" separando los operadores por jerarquìa

		{

		  while (Top (&mi_pila).car == '^' || Top (&mi_pila).car == '*' || Top (&mi_pila).car == '/')	//lo mismo que con la suma pasa con * y / saca los de mayor o igual importancia

		    {

		      a = Pop (&mi_pila);

		      strcat (salida, &a.car);	//los concatena

		    }

		  a.car = expresion[l];

		  Push (a, &mi_pila);	//y guarda el nuevo operador

		}

	      if (expresion[l] == '^')

		{

		  while (Top (&mi_pila).car == '^')	//se realiza el mismo procedimiento con la potencia, que es la operación de más jerarquía.

		    {

		      a = Pop (&mi_pila);

		      strcat (salida, &a.car);

		    }



		  a.car = expresion[l];	//Igualamos el elemento del tope con el valor de la expresión en el índice determinado. 

		  Push (a, &mi_pila);	//Metemos a la pila el elemento.

		}

	    }


	  l = l + 1;		//el contador para avanzar en la expresión

	}

      while (Size (&mi_pila) != 0)	//si la pila no está vacía sacamos y concatenamos todo

	{

	  a = Pop (&mi_pila);
	  strcat (salida, &a.car); //concatenando lo que extraemos, a la cadena "salida"

	}

      printf ("\n La expresion escrita en postfijo es %s\n", salida);	//mostramos la expresión

      while (k < 27)
	{

	  if (letras[k] != '/')	// el arreglo letras fue declarado lleno de estas diagonales para identificarlas como vacío a las letras no  ingresadas en la pila, ahora recorremos el arreglo buscando cual tiene letra y pedimos su valor

	    {
	      printf ("teclea el valor de la letra %c \n", letras[k]);
	      scanf ("%f", &valores[k]);
	    }

	  k = k + 1;
	}

      Destroy (&mi_pila);
    }				//Terminación del if en el caso de que se ingresaron los paréntesis de forma correcta.

  else				//Si la pila aún tenía elementos, quiere decir que falto cerrar parentesis.

    {
      printf ("\nERROR:\nHay parentesis que abrieron y nunca cerraron: %d",
	      i);

      return 1; //Entonces, regresaríamos un “1” del main, esto significa que el programa tiene un error
    }

  z = 0;
  int y = 0;
  while (z < strlen (salida) + 1)	//recorreremos la salida para evaluar toda la operación
    {
      p = (int) salida[y] - 64;	//vemos si es una letra si lo es p va tener valor de 1 a 26
      if (1 <= p & p <= 26)
	{
	  a.num2 = valores[p];
	  Push (a, &mi_pila);	//guardamos el valor de la letra
	}


      if (salida[z] == '+' || salida[z] == '-' || salida[z] == '*' || salida[z] == '/' || salida[z] == '^')	//en caso de ser un operador por lo menos debe haber dos números en la pila así que los sacaremos para trabajar con ellos 

	{
	  a = Pop (&mi_pila);
	  num2 = a.num2;
	  a = Pop (&mi_pila);
	  num1 = a.num2;
	  if (salida[z] == '+')	//si es "+",  sumará los números, y así irá haciendo las demás operaciones.
	    {
	      resultado = num1 + num2;
	      a.num2 = resultado;	//guardamos el resultado en la pila como otro valor para operar con el, en caso de ser necesario.
	      Push (a, &mi_pila);
	    }
	  if (salida[z] == '-') //Hacemos un if por cada operador, haciendo la operación entre num1 y num2
	    {
	      resultado = num1 - num2;
	      a.num2 = resultado;
	      Push (a, &mi_pila);
	    }
	  if (salida[z] == '+')   //Recordemos que num2 es el elemento que está en el tope de la pila (el último que se metió)
	    {
	      resultado = num1 + num2;
	      a.num2 = resultado;
	      Push (a, &mi_pila);
	    }
	  if (salida[z] == '*')
	    {
	      resultado = num1 * num2;
	      a.num2 = resultado;
	      Push (a, &mi_pila);
	    }
	  if (salida[z] == '/')
	    {
	      resultado = (float) num1 / num2; //Para la división hacemos un casteo, para poder obtener resultados con decimales
	      a.num2 = resultado;
	      Push (a, &mi_pila);
	    }
	  if (salida[z] == '^')
	    {
	      resultado = powf (num1, num2);  //Para la potencia usamos la función "powf" que nos sirve para obtener potencias con decimales
	      a.num2 = resultado; 
	      Push (a, &mi_pila);
	    }

	}
      z = z + 1;
      y = y + 1;
    }

  a = Pop (&mi_pila);		//sacamos el ultimo valor que quedo en la pila el cual es el resultado//sacamos el ultimo valor que quedo en la pila el cual es el resultado
  resultado = a.num2;
  printf ("el resultado de la expresion es %f\n", resultado);

  return 0;
}
