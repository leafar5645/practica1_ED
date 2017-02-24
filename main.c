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

      while (l < strlen (expresion))

{

  if (expresion[l] == '(')

    {

      a.car = '(';

      Push (a, &mi_pila);

    }

  if (expresion[l] == ')')

    {

      while (Top (&mi_pila).car != '(')

{

  a = Pop (&mi_pila);



  strcat (salida, &a.car);

}

      a = Pop (&mi_pila);

    }

  p = (int) expresion[l] - 64;

  if (1 <= p & p <= 26)

    {

      letras[(int) expresion[l] - 64] = expresion[l];

      a.car = expresion[l];

      strcat (salida, &a.car);

    }

  if (expresion[l] == '+' || expresion[l] == '-'

      || expresion[l] == '*' || expresion[l] == '/'

      || expresion[l] == '^')

    {

      if (expresion[l] == '+' || expresion[l] == '-')

{

  while (Top (&mi_pila).car == '*'

 || Top (&mi_pila).car == '/'

 || Top (&mi_pila).car == '^'

 || Top (&mi_pila).car == '+'

 || Top (&mi_pila).car == '-')

    {

      a = Pop (&mi_pila);



      strcat (salida, &a.car);



    }



  a.car = expresion[l];

  Push (a, &mi_pila);





}

      if (expresion[l] == '*' || expresion[l] == '/')

{

  while (Top (&mi_pila).car == '^'

 || Top (&mi_pila).car == '*'

 || Top (&mi_pila).car == '/')

    {

      a = Pop (&mi_pila);



      strcat (salida, &a.car);



    }



  a.car = expresion[l];

  Push (a, &mi_pila);





}

      if (expresion[l] == '^')

{

  while (Top (&mi_pila).car == '^')

    {

      a = Pop (&mi_pila);



      strcat (salida, &a.car);



    }



  a.car = expresion[l];

  Push (a, &mi_pila);

}

    }



  l = l + 1;

}



      while (Size (&mi_pila) != 0)

{

  a = Pop (&mi_pila);



  strcat (salida, &a.car);

}



      printf ("\n en postfijo es %s\n", salida);



      while (k < 27)

{

  if (letras[k] != '/')

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
while(z<strlen(salida)+1) 
{
p=(int)salida[y]- 64;
if(1<=p & p<=26)
{
a.num2=valores[p];
            Push(a, &mi_pila);
}


if (salida[z]=='+' || salida[z]=='-' || salida[z]=='*'|| salida[z]=='/' || salida[z]=='^')
{
a=Pop(&mi_pila);
num2=a.num2;
a=Pop(&mi_pila);
num1=a.num2;
if (salida[z]=='+')
{
resultado=num1+num2;
a.num2=resultado;
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
//resultado=pow(num1,num2);
a.num2=resultado;
Push(a , &mi_pila);
}

}
z=z+1;
                y=y+1;
}


a=Pop(&mi_pila);
resultado=a.num2;
printf("el resultado de la expresion es %f" , resultado);




  return 0;

}

