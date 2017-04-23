#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "presentacion.h"
//#include"TADColaEst.h"
#include"TADColaDin.h"



int main (void)
{
	cola colaEntrada;
	cola colaSalida;
	int numero_procesos=0;
	int n=0;
	char nombre[45]="";
    char actividad[200]="";
	char id[45]="";
	char bufer[200]="";
	int  tiempo=0;
	int tiempo_total=0;
	int tiempo_restante;
	elemento a,b;
	int tiempo_total2=0;
	int tiempo_cola=0;
	char procesoAnt[45]="ninguno";
    char idAnt[45]="ninguno"; 	
printf("Tecle el numero de procesos en la cola \n");
scanf("%d" , &numero_procesos);	

Initialize (&colaEntrada);
Initialize (&colaSalida);

while(n<numero_procesos)
{
	BorrarPantalla();
	fflush( stdin );
	printf("Tecle el nombre del proceso %d \n", n+1);
	gets(nombre);
	fflush( stdin );
	printf("Tecle la actividad del proceso  %d \n", n+1);
   	gets(actividad);
	fflush( stdin );
	printf("Tecle la id del proceso  %d \n", n+1);
	gets(id);
	fflush( stdin );
	printf("Tecle el tiempo del proceso  %d \n", n+1);
	scanf("%d", &tiempo);
	strcpy( a.nombre, nombre );  //a.nombre=nombre;
	strcpy( a.actividad, actividad );//a.actividad=actividad;
	strcpy( a.id, id );//a.id=id
	a.tiempo=tiempo;
	a.tiempo_total=0;
	a.tiempo_restante=tiempo;
	Queue(&colaEntrada, a);
	n=n+1;
	
	
}
elemento c;

while(Empty(&colaEntrada)!=TRUE)
{
	BorrarPantalla();
c=Dequeue(&colaEntrada);
	printf("Proceso en ejecucion: %s \n", c.nombre);
	printf("actividad:  %s \n", c.actividad);
	printf("id: %s \n", c.id);

	tiempo_total=c.tiempo_total+1;
	tiempo_total2=tiempo_total2+1;
	tiempo_cola=tiempo_total2-tiempo_total;
	tiempo_restante=c.tiempo_restante-1;
	printf("Tiempo en ejecucion: %d \n", tiempo_total);
	printf("Tiempo en la cola: %d \n", tiempo_cola);
	printf("Proceso anterior: %s \n", procesoAnt);
	printf("id anterior: %s \n", idAnt);
	strcpy( procesoAnt, c.nombre );
	strcpy( idAnt, c.id );
	
	if(Empty(&colaEntrada)!=TRUE)
	{
	b=Front(&colaEntrada);
	printf("proceso siguiente: %s \n", b.nombre);
	printf("id siguiente: %s \n", b.id);
	}
	else
	{
		printf("proceso siguiente: ninguno \n");
	printf("id siguiente: ningugno \n");	
	}
	if(tiempo_restante!=0)
	{
		
		c.tiempo_total=tiempo_total;
		c.tiempo_restante=tiempo_restante;
		c.tiempo_total2=tiempo_total2;
		Queue(&colaEntrada, c);
	}
	else
	{
		c.tiempo_total2=tiempo_cola + c.tiempo_total+1;
		c.tiempo_restante=tiempo_restante;
		Queue(&colaSalida, c);
	}
Sleep(3000); 	
}
n=0;
BorrarPantalla();
printf("Procesos terminados: \n");
printf("\n");
printf("\n");
while(n<numero_procesos)
{
	printf("Proceso %d :\n",n+1);
	a=Dequeue(&colaSalida);
	printf("nombre del proceso: %s \n",a.nombre);
	printf("id del proceso: %s \n", a.id);
	printf("tiempo total: %d \n", a.tiempo_total2);
	n=n+1;
	printf("\n");
	printf("\n");
}
	
return 0;	
}