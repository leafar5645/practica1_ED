#include<stdio.h>

#include<string.h>

#include"TADPila.h"

#include<math.h>

float potencia(float num1 , float num2)
{
int z=1;
float resultado=num1;
while (z<num2)
{
resultado=resultado*num1;
z=z+1;
}
return resultado;

}


int

main (void)

{
 
  int i;

  int l = 0;

  int p;

  pila mi_pila;

  elemento a; //Nos servirà para almacenar elementos del tope de la pila

  char resp;

  int k = 0;
  int z=0;

  char expresion[150]=""; //Arreglo donde se almacenara la expresion escrita al inicio.

  char salida[150] = "";

  char letras[27] = "///////////////////////////";  //Arreglo donde se almacenan las letras que pueden ingresarse (A-Z).

  int valores[27];  //Arreglo para guardar los valores ingresados para cada letra.
  
  float num1;
  float resultado; //Es la variable para el resultado final de la evaluacion
  float num2;


  printf

    ("teclea una expresion solo letras mayusculas A-Z y las siguientes operaciones +,*,-,/,^ \n");

  scanf ("%s", expresion);  //Se trata de una cadena de caracteres.

  int j = 0;



  Initialize (&mi_pila); //Inicializamos la pila creada 



  for (i = 0; i < strlen (expresion); i++)  //Aumentamos el indice del arreglo hasta que sea menor a la cantidad añadida de elementos en la expresion.

    {

      if (expresion[i] == '(')  //Solo si es igual a parentesis de entrada, hacemos el push.

{

  a.car = '(';

  Push (a, &mi_pila);

}

      else if (expresion[i] == ')')   //Si es parentesis de salida, sacamos el parentesis de entrada que se acceso al ùltimo.


{

  if (Empty (&mi_pila) != TRUE) 
    {      

      a = Pop (&mi_pila);

    }

  else          //Si al repetir el proceso, llega un punto donde la pila este vacìa, quiere decir que se agregaron mas par. de salida.

    {

      printf              

("\nERROR:\nHay parentesis que intentan cerrar y nunca abrieron: %d",

 i);

      return 1;    //Y regresamos al sistema que hubo un error.

    }

}

    }   //Terminacion del ciclo for (ya terminaron de "cerrarse los parentesis de entrada y salida entre si"). 



  if (Empty (&mi_pila) == TRUE)   

    {

      printf ("\nEXCELENTE");

      while (l < strlen (expresion))  //si la expresion esta bien la analizaremos completa para separar y reacomodar los componentes

{

  if (expresion[l] == '(')     //si es parentesis que abre lo meteremos a la pila

    {

      a.car = '(';

      Push (a, &mi_pila);

    }

  if (expresion[l] == ')')    //si es parentesis que cierra sacaremos todo de la pila hasta encontrar un prentesis que abrio y juntaremos todo lo que vamos sacando a la cadena salida con la funcion strcat

    {

      while (Top (&mi_pila).car != '(')

{

  a = Pop (&mi_pila);



  strcat (salida, &a.car);

}

      a = Pop (&mi_pila);

    }

  p = (int) expresion[l] - 64;   //el valor ascii de los caracteres menos 64 si es una letra mayuscula A-Z p tendra un valor de 1 a 26

  if (1 <= p & p <= 26) //vemos si es una letra

    {

      letras[(int) expresion[l] - 64] = expresion[l]; //al aparecer un letra la guardamos en el arreglo letras en la posicion de su valor ascii menos 64 para que esten en orden y despues pedir sus valores

      a.car = expresion[l];

      strcat (salida, &a.car);//concadenamos la letra

    }

  if (expresion[l] == '+' || expresion[l] == '-'

      || expresion[l] == '*' || expresion[l] == '/'

      || expresion[l] == '^') //si es un operador veremos las siguientes condiciones

    {

      if (expresion[l] == '+' || expresion[l] == '-') 

{

  while (Top (&mi_pila).car == '*'

 || Top (&mi_pila).car == '/'

 || Top (&mi_pila).car == '^'

 || Top (&mi_pila).car == '+'

 || Top (&mi_pila).car == '-') //si el operador es + o - menos y en la pila hay operadores de mayor o igual importancia los va a sacr todos

    {

      a = Pop (&mi_pila);



      strcat (salida, &a.car);//concatena todo lo que sacamos



    }



  a.car = expresion[l];//y guarda en la pila el nuevo operador

  Push (a, &mi_pila);





}

      if (expresion[l] == '*' || expresion[l] == '/')

{

  while (Top (&mi_pila).car == '^'

 || Top (&mi_pila).car == '*'

 || Top (&mi_pila).car == '/') //lo mismo que con la suma pasa con * y / saca los de mayor o igual importancia

    {

      a = Pop (&mi_pila);



      strcat (salida, &a.car);//los concatena



    }



  a.car = expresion[l];

  Push (a, &mi_pila);//y guarda el nuevo operador





}

      if (expresion[l] == '^')

{

  while (Top (&mi_pila).car == '^')//y mas de los mismo con potencia

    {

      a = Pop (&mi_pila);



      strcat (salida, &a.car);



    }



  a.car = expresion[l];

  Push (a, &mi_pila);

}

    }



  l = l + 1; //el contador para avanzar en la expresion

}



      while (Size (&mi_pila) != 0) //si la pila no esta vacia sacamos y concatenamos todo

{

  a = Pop (&mi_pila);



  strcat (salida, &a.car);

}



      printf ("\n en postfijo es %s\n", salida); //mostramos la expresion



      while (k < 27)

{

  if (letras[k] != '/') // el arreglo letras fue declarado lleno de estas diagonales para identificarlas como vacio  pero las fueron las letras que se tclearon en la pila como se hizo anteriormente ahora recorremos el arreglo buscando cual tiene tiene letra y pedimos su valor

    {

      printf ("teclea el valor de la letra %c \n", letras[k]);

      scanf ("%d", &valores[k]);

    }

  k = k + 1;

}




Destroy(&mi_pila);
    }                  //Terminacion del if en el caso de que se ingresaron los parentesis de forma correcta.


  else                     //Si la pila aùn tenìa elementos, quiere decir que falto cerrar parentesis.

    {

      printf ("\nERROR:\nHay parentesis que abrieron y nunca cerraron: %d",

      i);

      return 1;

    }

z=0;
int y=0;
while(z<strlen(salida)+1) //recorreremos la salida para evaluar toda la operacion
{
p=(int)salida[y]- 64;//vemos si es una letra si lo es p va tener valor de 1 a 26
if(1<=p & p<=26)
{
a.num2=valores[p];
            Push(a, &mi_pila); //guardamos el valor de la letra
}


if (salida[z]=='+' || salida[z]=='-' || salida[z]=='*'|| salida[z]=='/' || salida[z]=='^') //en caso de ser un operador por lo menos debe haber dos numeros en la pila asi que los sacaremos para trabajar con ellos 
 
{
a=Pop(&mi_pila);
num2=a.num2;
a=Pop(&mi_pila);
num1=a.num2;
if (salida[z]=='+') //si es mas la suma de los numeros y asi con las demas
{
resultado=num1+num2;
a.num2=resultado;//guardamos el resultado en la pila como otro valor para operar con el en caso de ser necesario
Push(a , &mi_pila);
}
if (salida[z]=='-')
{
resultado=num1-num2;
a.num2=resultado;
Push(a , &mi_pila);
}
if (salida[z]=='+')
{
resultado=num1+num2;
a.num2=resultado;
Push(a , &mi_pila);
}
if (salida[z]=='*')
{
resultado=num1*num2;
a.num2=resultado;
Push(a , &mi_pila);
}
if (salida[z]=='/')
{
num2=1/num2;
resultado=num1*num2;
a.num2=resultado;
Push(a , &mi_pila);
}
if (salida[z]=='^')
{
resultado=potencia(num1 , num2);
a.num2=resultado;
Push(a , &mi_pila);
}

}
z=z+1;
                y=y+1;
}


a=Pop(&mi_pila);//sacamos el ultimo valor que quedo en la pila el cual es el resultado//sacamos el ultimo valor que quedo en la pila el cual es el resultado
resultado=a.num2;
printf("el resultado de la expresion es %f\n" , resultado);




  return 0;

}

