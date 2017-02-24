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

  elemento a;

  char resp;

  int k = 0;
  int z=0;

  char expresion[150]="";

  char salida[150] = "";

  char letras[27] = "///////////////////////////";

  int valores[27];
  
  float num1;
  float resultado;
  float num2;


  printf

    ("teclea una expresion solo letras mayusculas A-Z y las siguientes operaciones +,*,-,/,^ \n");

  scanf ("%s", expresion);

  int j = 0;



  Initialize (&mi_pila);



  for (i = 0; i < strlen (expresion); i++)

    {

      if (expresion[i] == '(')

{

  a.car = '(';

  Push (a, &mi_pila);

}

      else if (expresion[i] == ')')

{

  if (Empty (&mi_pila) != TRUE)

    {

      a = Pop (&mi_pila);

    }

  else

    {

      printf

("\nERROR:\nHay parentesis que intentan cerrar y nunca abrieron: %d",

 i);

      return 1;

    }

}

    }



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
    }


  else

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

