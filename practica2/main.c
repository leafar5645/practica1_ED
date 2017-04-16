#include "TADColaEst.h"
//#include "TADColaEstCirc.h"
//#include "TADColaDin.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define TIEMPO_ATENCION 5
#define TIEMPO_CLIENTE 3
#define TIEMPO_USUARIO 5
#define TIEMPO_PREFERENTE 10

typedef struct cajero
{
  int num;
  elemento e;
} cajero;

void
gotoxy (int x, int y)
{
  printf ("%c[%d;%df", 0x1A, y, x);
}

boolean
colas_vacias (cola * C, cola * U, cola * P)
{
  if (Empty (C) == TRUE && Empty (U) == TRUE && Empty (P) == TRUE)
    return TRUE;
  return FALSE;
}

void
vaciar_cajeros (cajero * cajeros, int n)
{
  int i = 0;
  while (i < n)
    {
      (cajeros + i)->e.num = 0;
      (cajeros + i)->e.car = ' ';
      i++;
    }
  return;
}

int
cajeros_libres (cajero * cajeros, int n)
{
  int i = 0;
  while (i < n)
    {
      if ((cajeros + i)->e.num != 0)
	return (i + 1);
      i++;
    }

  return 0;
}

void
imprimir (cajero * cajeros, cola C, cola U, cola P, int n)
{
	int i=0;
        int j = 0;
	elemento x;
	int o,p,q;
	o = Size(&P);
	p = Size(&U);
	q = Size(&C);
	while(i<n)
	{
		gotoxy((10*i),5);
		printf("%c%d",(cajeros+i)->e.car,(cajeros+i)->e.num);
	}
	i=1;
	j=1;
	while(i<=3)
	{
		while(j<=3)
		{
			gotoxy((5*i),(2*j));
			if(i==1 && o>=j)
			{
				x=Element(&P,j);
				printf("%c%d",x.car,x.num);
			}
			if(i==2 && p>=j)
			{
				x=Element(&U,j);
				printf("%c%d",x.car,x.num);
			}
			if(i==3 && q>=j)
			{
				x=Element(&C,j);
				printf("%c%d",x.car,x.num);
			}
			j++;
		}
		gotoxy((5+i),8);
		if(i=1)
		{
			if((o-3)<0)
				printf("0");
			else
				printf("%d",(o-3));
		}
		if(i=2)
		{
			if((p-3)<0)
				printf("0");
			else
				printf("%d",(p-3));
		}
		if(i=3)
		{
			if((q-3)<0)
				printf("0");
			else
				printf("%d",(q-3));
		}
		i++;
		j=1;

	}

    return;
}

int
main ()
{
  unsigned int tiempo = 0;
  cajero *cajeros = 0;
  cola C;
  cola U;
  cola P;
  elemento c;
  elemento u;
  elemento p;
  int numc = 1;
  int numu = 1;
  int nump = 1;
  int q = 0;
  int n;
  int m;
  int i = 0;
  system ("clear");
  printf ("ingrese el numero de cajeros en la simulacion: ");
  scanf ("%d", &n);
  printf("\n");
  cajeros = malloc (2 * n * sizeof (cajero));
  while(i<n)
  {
	  printf("\t\t%d",(i+1));
	  i++;
  }
  printf("\n");
  Initialize (&C);
  Initialize (&U);
  Initialize (&P);
  vaciar_cajeros (cajeros, n);
  while (TRUE)
    {
      sleep (1);
      if (tiempo % TIEMPO_CLIENTE == 0)
	{
	  c.car = 'c';
	  c.num = numc;
	  Queue (&C, c);
	  numc++;
	}
      if (tiempo % TIEMPO_USUARIO == 0)
	{
	  u.car = 'u';
	  u.num = numu;
	  Queue (&U, u);
	  numu++;
	}
      if (tiempo % TIEMPO_PREFERENTE == 0)
	{
	  p.car = 'p';
	  p.num = nump;
	  Queue (&P, p);
	  nump++;
	}
      m = cajeros_libres (cajeros, n);
      if (tiempo % TIEMPO_ATENCION == 0 || m != 0)
	{
	  if (tiempo % TIEMPO_ATENCION == 0)
	    vaciar_cajeros (cajeros, n);
	  while (m != 0 && colas_vacias (&C, &U, &P) == 0)
	    {
	      if (m != 0 && Empty (&P) == '0' && q != 5)
		{
		  p = Dequeue (&P);
		  (cajeros + m - 1)->e = p;
		}
	      m = cajeros_libres (cajeros, n);
	      if (m != 0 && Empty (&P) == '0' && Empty (&U) != '0' && q != 5)
		{
		  u = Dequeue (&U);
		  (cajeros + m - 1)->e = u;
		}
	      m = cajeros_libres (cajeros, n);
	      if ((m != 0 && Empty (&C) != '0')
		  && ((Empty (&U) == 0 && Empty (&P) == 0) || q == 5))
		{
		  c = Dequeue (&C);
		  (cajeros + m - 1)->e = c;
		}
	      m = cajeros_libres (cajeros, n);
	      if (q == 5 || Empty (&C) == '0')
		q = 0;
	    }
	}
      imprimir (cajeros, C, U, P, n);
      tiempo++;
    }

}
