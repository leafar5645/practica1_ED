#include "TADColaEst.h"
//#include "TADColaDin.h"
#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include <Windows.h>
#define TIEMPO_ATENCION 7
#define TIEMPO_CLIENTE 5
#define TIEMPO_USUARIO 6
#define TIEMPO_PREFERENTE 8

typedef struct cajero
{
	unsigned int tmp;
	elemento e;
} cajero;

void mover_cursor( int x, int y ) 
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y }; 
	SetConsoleCursorPosition( hStdout, position );
	return;
}
int mod(int a, int b)
{
	if(a>=b)
		return a%b;
	else
		return b%a;
}

void vaciar_cajeros (cajero * cajeros, int n)
{
	int i = 0;
	while (i < n)
	{
		(cajeros + i)->e.num = 0;
		(cajeros + i)->e.car = ' ';
		(cajeros + i)->tmp= TIEMPO_ATENCION;
		i++;
	}
	return;
}

int cajeros_libres (cajero * cajeros, int n)
{
	int i = 0;
	while (i < n)
	{
		if ((cajeros + i)->e.num == 0)
			return (i + 1);
		i++;
	}

	return 0;
}

void imprimir ( cola C, cola U, cola P, cajero * cajeros, int n)
{
	int i=1;
	elemento e;
	while(i<=3)
	{
		mover_cursor(16,10*i);
		if(Size(&C)>=i)
		{
			e=Element(&C,i);
			printf("%c%d",e.car,e.num);
		}
		else
			printf("_ ");
		mover_cursor(32,10*i);
		if(Size(&U)>=i)
		{
			e=Element(&U,i);
			printf("%c%d",e.car,e.num);
		}
		else
			printf("_ ");
		mover_cursor(48,10*i);
		if(Size(&P)>=i)
		{
			e=Element(&P,i);
			printf("%c%d",e.car,e.num);
		}
		else
			printf("_ ");
		i++;
	}
	mover_cursor(16,40);
	if(Size(&C)<=3)
		printf("0");
	else
		printf("%d",Size(&C)-3);
	mover_cursor(32,40);
	if(Size(&U)<=3)
		printf("0");
	else
		printf("%d",Size(&U)-3);
	mover_cursor(48,40);
	if(Size(&P)<=3)
		printf("0");
	else
		printf("%d",Size(&P)-3);
	i=0;
	while(i<n)
	{
		mover_cursor((i+1)*16,5);
		printf("%c%d",(cajeros+i)->e.car,(cajeros+i)->e.num);
		i++;
	}
	return;
}


int main ()
{
	unsigned int tiempo= TIEMPO_ATENCION;
	cajero *cajeros;
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
	int j = 0;
	system ("cls");
	printf ("ingrese el numero de cajeros en la simulacion: ");
	scanf ("%d", &n);
	cajeros = malloc (sizeof(cajero) * n);
    mover_cursor(1,1);
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
		Sleep (1000);
		if (mod(TIEMPO_CLIENTE, tiempo) == 0)
		{
			c.car = 'c';
			c.num = numc;
			Queue (&C, c);
			numc++;
		}
		if (mod(TIEMPO_USUARIO, tiempo) == 0)
		{
			u.car = 'u';
			u.num = numu;
			Queue (&U, u);
			numu++;
		}
		if (mod(TIEMPO_PREFERENTE, tiempo) == 0)
		{
			p.car = 'p';
			p.num = nump;
			Queue (&P, p);
			nump++;
		}
		j=0;
		while (j<n)
		{
			if (mod(TIEMPO_ATENCION, (cajeros + j)->tmp) == 0)
			{
				(cajeros + j)->e.num = 0;
				(cajeros + j)->e.car = ' ';
				(cajeros + j)->tmp = TIEMPO_ATENCION;
			}
			j++;
		}
		m = cajeros_libres (cajeros, n);
		while (m != 0 && (Empty (&C) == FALSE || Empty (&U) == FALSE || Empty (&P) == FALSE))
		{
			if (m != 0 && Empty (&P) == FALSE && q != 5)
			{
				p = Dequeue (&P);
				(cajeros + m - 1)->e = p;
				(cajeros + m - 1)->tmp = TIEMPO_ATENCION;
				q++;
			}
			m = cajeros_libres (cajeros, n);
			if (m != 0 && Empty (&P) == TRUE && Empty (&U) == FALSE && q != 5)
			{
				u = Dequeue (&U);
				(cajeros + m - 1)->e = u;
				(cajeros + m - 1)->tmp = TIEMPO_ATENCION;
				q++;
			}
			m = cajeros_libres (cajeros, n);
			if ((m != 0 && Empty (&C) == FALSE)
				&& ((Empty (&U) == TRUE && Empty (&P) == TRUE) || q == 5))
			{
				c = Dequeue (&C);
				(cajeros + m - 1)->e = c;
				(cajeros + m - 1)->tmp = TIEMPO_ATENCION;
				q=0;
			}
			m = cajeros_libres (cajeros, n);
			if (m != 0 && (q == 5 || Empty (&C) == TRUE))
				q = 0;
		}
		imprimir ( C, U, P, cajeros, n);
		tiempo++;
		i=0;
		while(i<n)
		{
			(cajeros + i)->tmp++;
			i++;
		}
	}
}
