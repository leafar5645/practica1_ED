#include<stdio.h>
#include<string.h>
#include"TADPila.h"

int main(void)
{
int i;
int l=0;
int p;
pila mi_pila;
elemento a;
char resp;
char expresion[55];
char salida[150]=" ";
printf("teclea una expresion solo letras mayusculas A-Z y las siguientes operaciones +,*,-,/,^ \n");
scanf("%s",expresion);
int j=0;

int valores[25];
Initialize(&mi_pila);

for(i=0;i<strlen(expresion);i++)
{
if(expresion[i]=='(')
{
a.car='(';
Push(a,&mi_pila);
}
else if(expresion[i]==')')
{
if(Empty(&mi_pila)!=TRUE)
{
a=Pop(&mi_pila);
}
else
{
printf("\nERROR:\nHay parentesis que intentan cerrar y nunca abrieron: %d",i);
return 1;
}
}
}

if(Empty(&mi_pila)==TRUE)
{
printf("\nEXCELENTE");
while(l<strlen(expresion)) 
{
if(expresion[l]=='(')
{
a.car='(';
Push(a,&mi_pila);
}
if(expresion[l]==')')
{
while(Top(&mi_pila).car!='(')
            {
a=Pop(&mi_pila);

strcat(salida , &a.car);
}
              a=Pop(&mi_pila);
}
p=(int)expresion[l]- 64;
if(1<=p & p<=26)
{
a.car=expresion[l];
strcat(salida, &a.car);
}
if (expresion[l]=='+' || expresion[l]=='-' || expresion[l]=='*'|| expresion[l]=='/' || expresion[l]=='^')
{
if(expresion[l]=='+'||expresion[l]=='-')
{
if(Top(&mi_pila).car=='*' || Top(&mi_pila).car=='/' || Top(&mi_pila).car=='^')
{
a=Pop(&mi_pila);

strcat(salida , &a.car);
a.car=expresion[l];
Push(a,&mi_pila);
}
else
{
    a.car=expresion[l];
Push(a,&mi_pila);
}

}
if(expresion[l]=='*'||expresion[l]=='/')
{
if(Top(&mi_pila).car=='^')
{
a=Pop(&mi_pila);

strcat(salida , &a.car);
a.car=expresion[l];
Push(a,&mi_pila);
}
else
{
    a.car=expresion[l];
Push(a,&mi_pila);
}

}
if(expresion[l]=='^')
{
a.car=expresion[l];
Push(a,&mi_pila);
}
}

l=l+1;
}

while(Size(&mi_pila)!=0)
{
a=Pop(&mi_pila);

strcat(salida, &a.car);
}

printf("en postfijo es %s\n", salida);
}
else
{
printf("\nERROR:\nHay parentesis que abrieron y nunca cerraron: %d",i);
return 1;
}

return 0;
}

