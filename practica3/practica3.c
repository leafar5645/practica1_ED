#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "TADLista.h"
#include "presentacion.h"
#include <locale.h>

int colisiones;  //contador de colisiones
void ptab(int tabla[97])
{
	int n=0;
	while(n<97)
	{
		printf("    %d", tabla[n]);
		n=n+1;
	}
}
int maxo(int tabla[97])
{
	int mayor =tabla[0];
	int n=0;
	int aux=0;
	while(n<97)
	{
		aux=tabla[n];
		if (aux>mayor)
		{
			mayor=aux;
		}
		n=n+1;
	}
	return mayor;
	
}
void acentos (char palabra[50])  //funcion para guardar y buscar las palabras con acento
{
	int n=0;
	while(n<strlen(palabra))
	{
	if((int)palabra[n] == -15)
	{
	     palabra[n]=164; //ñ	
		
	}
	if((int)palabra[n] == -19)
	{
	     palabra[n]=161 ;	//i
		
	}
	if((int)palabra[n] == -31)
	{
	     palabra[n]=160;	 //a
		
	}
	if((int)palabra[n] == -23)
	{
	     palabra[n]=130;	 //e
		
	}
	if((int)palabra[n] == -13)
	{
	     palabra[n]=162;//o	
		
	}
	if((int)palabra[n] == -6)
	{
	     palabra[n]=163; //u	
		
	}
	if((int)palabra[n] == -55)
	{
	     palabra[n]=144; //E	
		
	}
	if((int)palabra[n] == -45)
	{
	     palabra[n]=181; //O	
		
	}
	if((int)palabra[n] == -63)
	{
	     palabra[n]=163; //A	
		
	}
	if((int)palabra[n] == -51)
	{
	     palabra[n]=214; //I	
		
	}
	if((int)palabra[n] == -38)
	{
	     palabra[n]=233; //U
		
	}
	n=n+1;
	
		
	}
}

int status_tab(int tabla[97]) //funcion para devolver el numero de campos vacios en la tabla 
{

	int n=0;
	 int vacio=0;
	 
	while(n<97)
	{
	
		if(tabla[n]== -1)
		{
			vacio=vacio+1;
		}
		n=n+1;
	}
	return vacio;
}
int convertir_asc(char palabra[50]) //funcion para obtener la suma del valor ascii de las letras de la palabra  
{
	
	int n=0;
	int valor=0;
	while(palabra[n] != '\0')
	{
      
		
		valor=valor+(int)(palabra[n]);
		n=n+1;
	}

	return valor;
}

void separacion(char string[350] , char palabra[50], char definicion[300] , char valor) //funcion para separar el string en dos la palabra y la definicion y el char valor se agrega al comienzo
{
	int n=0;
	int j=0;
		palabra[0]= valor;

	while(string[n] != ':')
	{

		palabra[n+1]=string[n];
			
		n=n+1;
	}
	n=n+1;
	
	while(string[n] != '\n')
	{
		
		
		definicion[j]=string[n];
		j=j+1;
		n=n+1;
	}
	//definicion[j+1]='\0';
	//printf("palabra: %s \n" , palabra);
	//printf("definicion: %s \n" , definicion);
	
	
}
void rellenar(int tabla[97]) //relllena la tabla con -1
{
	
	int n=0;
	while(n<97)
	{
		tabla[n]=-1;
		n=n+1;
	}
}
int fun_hash (char palabra[50]) //Funcion para obtener un valor hash para la palabra
{
	
	int resul;
	int valor=0;
	valor=convertir_asc(palabra); //valor es igual a la funcion convertir ascii
 resul= ((strlen(palabra))*(int)palabra[0] - (int)palabra[strlen(palabra)-1]); //el resultado es igual al tamaño de la palabra por el valor de la primera letra menos el valor de la letra que esta en el valor del tamaño de la cadena - 1 
 resul=resul + valor + 1;
resul=resul%97;	
	
	return resul;
}



int main (void)

{
	lista diccionario[97]; //la tabla hash de tamaño 97
	

    char palabra[50];
	
     int tabla[97];
	rellenar(tabla); //rellenamos la tabla
    int hash=0;	
	elemento a;
	elemento b;
	boolean t;
	char valor;
	int vacio=0;
    int salir=0;
int ordenB=0;	
	int n=0;
	char aux='n';
	char archivo[50];
	FILE * dic; //declarando un archivo
	FILE * Expor;
	int opcion=0;
	char definicion[300];
	unsigned char string[350]=""; //la cadena que va almacenar lo que sacamos del archivo
	posicion p ; 
	posicion p2;
    posicion p3;
	while(salir != 1) //mientras salir no sea igual a 1 seguiremos en el programa
	{
	 vacio=status_tab(tabla);
     ordenB=maxo(tabla);//esto es lo del orden maximo de busqueda	
     ordenB=ordenB+1;	
     ptab(tabla);	 
	printf("bienvenido al diccionario \n ");
	printf("tecle el numero de la opcion mas conveniente para usted                                       El numero de colisiones en la tabla es: %d  \n ", colisiones);
	printf("1 Cargar archivo de definiciones                                                              El orden maximo de busqueda es de : %d      \n ", ordenB);
    printf("2 Agregar una palabra y su definicion                                                         El numero de campos vacio en la tabla es: %d \n ", vacio);
    printf("3 Buscar una palabra y su definicion                                                          El tamaño de la tabla es de 97 \n ");
    printf("4 Modificar una definicion  \n ");
    printf("5 Eliminar una palabra \n ");
    printf("6  salir \n ");	
    scanf("%d" , &opcion);
if(opcion==1)
	
{	
memset(archivo, 0, 50); //limpiamos la variable archivo que llevara el nombre del archivo
fflush( stdin ); //limpiamos para que no venga basura 
	printf("Tecle el nombre del archivo \n");
	gets(archivo);
	fflush( stdin );

	
	dic = fopen ( archivo, "r" ); //abriendo el archivo prueba.txt
	
	
while ((valor = fgetc(dic)) != '^') //sacaremos todo del archivo hasta encontrar este simbolo
 	{
		
 		fgets(string,350,dic); //tomar toda una linea del archivo con un maximo de 350 carateres
 		
		separacion( string , palabra , definicion , valor); //vamos a dividir la cadena que obtuvimos en 2 la palabra y la definicion mandamos valor porque al evaluar si no este simbolo ^ el cursor de mueve en uno y perdemos el primer caracter 
		acentos(palabra);
		
		
		n=fun_hash(palabra);//aplicarle un hash a la cedena para obtener un entero
		
		//en la tabla hash buscamos la casilla que coincida con el resultado de la funcion e incrementamos la casilla para indicar que hay una palabra mas
		strcpy( a.palabra, palabra );  //copiamos la palabra al elemento
		strcpy( a.definicion, definicion ); 
		
		if(tabla[n] != -1) //verificamos si  no es la primera palabra con ese hash 
		{
		   p=First(&diccionario[n]); // al no ser la primera palabra con ese hash buscamos la primera en la lista con ese numero de hash
		  
			while(p != NULL) //mientras la direccion sea valida haremos lo siguiente
			{
				
			b=Position(&diccionario[n] , p);// sacamos el elemento de la posicion p 
			if (strcmp(a.palabra,b.palabra) == 0) //verificamos que no sea igual a la palabra que queremos meter, porque no debe haber palabras repetidas
			{
			printf("la palabra ya existe ");
			vacio=status_tab(tabla);
			 printf("El numero de campos vacios en la tabla es %d \n " , vacio);
		
		  
				Sleep(200);
				
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;	//salvamos la posicion p en p2
				if(p!= 0)
				{
					
				p=Following(&diccionario[n] , p2); //buscamos la posicion siguiente para repetir todo el proceso y verificar que no exista la palabra 
				}
				if (p==NULL)// en caso de que la siguiente ya fuera null insertamos el elemento despues del ultimo
				{
				Add(&diccionario[n] , a);	
				tabla[n]=tabla[n]+1;
				colisiones=colisiones +1;
				printf("Palabra insertada  ");
				vacio=status_tab(tabla);
		printf("El numero de campos vacios en la tabla es %d  " , vacio);
				printf("El hash de la palabra es : %d  y la palabra :  %s \n " , n, palabra);
				Sleep(200);
				}
				memset(b.palabra, 0, 50);
			}
			
		}
		}
		
		else//en caso de que sea la primera palabra con ese hash se inicializa la lista n y se agrega el primer elemento 
		{
		Initialize(&diccionario[n]); // al ser la primera palabra inicializamos la lista
		tabla[n]=tabla[n]+1;// incrementamos el valor en ese hash de la tabla para saber que ya exite una con este hash
		Add(&diccionario[n] , a);
		printf("Palabra insertada  ");
		vacio=status_tab(tabla);
		printf("El numero de campos vacios en la tabla es %d  " , vacio);
			
			printf("El hash de la palabra es : %d  y la palabra :  %s \n " , n, palabra);
				Sleep(200);
		}
			
		memset(string, 0, 350);
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 300);
		memset(definicion, 0, 300);//limpiamos el buffer para no mandar cosas demas
 	}
	fclose(dic);
		memset(string, 0, 350);
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 300);
		memset(definicion, 0, 300);//limpiamos el buffer para no mandar cosas demas
		
}


	if(opcion== 2) // esta funcion es practicamente lo mismo que la anterior excepto sin while del archivo ya que aqui solo se imserta una palabra
	{
		
		fflush(stdin);
	printf("porfavor teclea la palabra a ingresar  \n");
	gets(palabra);
	printf("porfavor ingrese su definicion \n");
	fflush(stdin);
	gets(definicion);
	fflush(stdin);
	n=fun_hash(palabra);
	strcpy(a.palabra , palabra);
	strcpy(a.definicion , definicion);
	
	if(tabla[n] != -1) //verificamos si  no es la primera palabra con ese hash
		{
			
			 p=First(&diccionario[n]);
			while(p != 0) 
			{
				
			b=Position(&diccionario[n] , p); 
			if (strcmp(a.palabra,b.palabra) == 0) 
			{
			printf("la palabra ya existe  ");
			vacio=status_tab(tabla);
		printf("El numero de campos vacios en la tabla es %d  " , vacio);
			printf("El hash de la palabra es : %d  \n  " , n);
			Sleep(1500);
				
				tabla[n]=tabla[n] -1;
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;;	//salvamos la posicion p en p2
				p=Following(&diccionario[n] , p); //buscamos la posicion siguiente para repetir todo el proceso de manera que todas se ordenen 
				if (p==0)// en caso de que la siguiente ya fuera null insertamos el elemento despues del ultimo
				{
				Add(&diccionario[n] , a);
                printf("Palabra insertada");
                tabla[n]=tabla[n]+1;				
				colisiones=colisiones +1;
				vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
			   	printf("El hash de la palabra es : %d  y la palabra :  %s \n " , n, palabra);
			   
			   Sleep(1500);
				}
				memset(b.palabra, 0, 50);
			}
			
				
			}
		}
		else//en caso de que sea la primera palabra con ese hash se inicializa la lista n y se agrega el primer elemento 
		{
		Initialize(&diccionario[n]);
		Add(&diccionario[n] , a);
		printf("Palabra insertada  ");
		tabla[n]=tabla[n]+1;
		vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
			   	printf("El hash de la palanra es : %d  \n " , n);
			   //printf("El numero de colisiones es: %d " , colisiones);
				Sleep(1500);
		
		}
		
		memset(string, 0, 300);
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 250);
		memset(definicion, 0, 250);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	}
	if(opcion==3)// esta la opcion de la busqueda
	{
	
	
	printf("teclea la palabra a buscar \n");
	fflush(stdin);
	gets(palabra);
	fflush(stdin);
	n=fun_hash(palabra);
	if(tabla[n] <0) //si el valor hash lleva a una casilla que no tiene letras es decir su valor es -1, la palbra no existe
	{
		printf("la palabra no existe");
		
				Sleep(1500);
	}
	else //si no repetimos el mismo proceso que en las opciones anteriores buscamos la palabra 
	{
		p=First(&diccionario[n]);
		while(p != 0)
		{
			b=Position(&diccionario[n] , p);
			if (strcmp(palabra,b.palabra) == 0) // si encuentra que las palabras son  iguales la encontramos 
			{
			printf("la palabra  existe \n");
				printf("El hash de la palabra es : %d  \n " , n);	
				
				printf(" Definicion: %s \n" , b.definicion);
			
				Sleep(9000);
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;;	//salvamos la posicion p en p2
				p=Following(&diccionario[n] , p2); //buscamos la posicion siguiente para repetir todo el proceso  
				if (p==0)// en caso de que la siguiente ya fuera null la palabra no existe 
				{
				printf("la palabra no existe \n");
					printf("El hash de la palabra es : %d   " , n);
				
				Sleep(1500);
				}
				memset(b.palabra, 0, 50);
			}
		}
	}
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 250);
		memset(definicion, 0, 250);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	}
	
	if(opcion==4) // esta opcion es igual a la anterior solo que si encontramos la palbra pediremos una definicion
	{
		fflush(stdin);
	printf("teclea la palabra a editar \n");
	gets(palabra);
	fflush(stdin);
	n=fun_hash(palabra);
	if(tabla[n] <0)
	{
			printf("El hash de la palanra es : %d  \n " , n);
		printf("la palabra no existe");
		
		
				Sleep(1500);
	}
	else
	{
		p=First(&diccionario[n]);
		while(p != 0)
		{
			b=Position(&diccionario[n] , p);
			if (strcmp(palabra,b.palabra) == 0) 
			{
			printf("la palabra  existe \n");
					printf("El hash de la palabra es : %d  \n " , n);
				
				printf("Teclea la nueva definicion \n");
				gets(definicion);
				fflush(stdin);
				strcpy(a.palabra , palabra);
				strcpy(a.definicion , definicion);
				Replace(&diccionario[n] , p , a); // la funcion replace del tadlista para cambia el elemento por el que tiene la nueva definicion
				printf("cambio exitoso \n");
				
				Sleep(1500);
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;;	//salvamos la posicion p en p2
				p=Following(&diccionario[n] , p2); //buscamos la posicion siguiente para repetir todo el proceso de manera que todas se ordenen 
				if (p==0)// en caso de que la siguiente ya fuera null insertamos el elemento despues del ultimo
				{
						printf("El hash de la palanra es : %d  \n " , n);
				printf("la palabra no existe");
				
				Sleep(1500);
				}
				memset(b.palabra, 0, 50);
			}
		}
	}
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 250);
		memset(definicion, 0, 250);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	}
	
	if(opcion==5) //esta opcion al igual que las demas va buscar la palabra y en caso de encontrarla preguntara si desea eliminar
	{
		fflush(stdin);
	printf("teclea la palabra a eliminar \n");
	gets(palabra);
	fflush(stdin);
	n=fun_hash(palabra);
	if(tabla[n] <0)
	{
			printf("El hash de la palabra es : %d  \n " , n);
		printf("la palabra no existe \n");
		vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
	}
	else
	{
		p=First(&diccionario[n]);
		while(p != 0)
		{
			b=Position(&diccionario[n] , p);
			if (strcmp(palabra,b.palabra) == 0) 
			{
			printf("la palabra  existe \n");
					printf("El hash de la palabra es : %d  \n " , n);
				printf("Palabra: %s \n" , b.palabra);
				printf("Definicion: %s \n" , b.definicion);
				printf("confirme la eliminacion s/n  \n "); //te pide confirmar la eliminacion
				scanf("%c" , &aux);
				if (aux == 's')
				{
					Remove(&diccionario[n] , p);//en caso de confirmar la eliminacion usa la funcion remove del tadlista para quitar el elemento
					tabla[n]=tabla[n]-1;//se reduce el numero de elementos que tienen ese hash 
					if(tabla[n]==-1) //si se quedo sin elementos se elimina la lista
					{
						Destroy(&diccionario[n]);
					}
					else// si no solo se reducen las colisiones
					{
						colisiones=colisiones-1;
					}
					printf("Palabra eliminada \n ");
					vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
				Sleep(1500);
				}
				else
				{
					printf("okey no se ha realizado ningun cambio \n");
					vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
									Sleep(1500);
				}
				
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;;	//salvamos la posicion p en p2
				p=Following(&diccionario[n] , p2); //buscamos la posicion siguiente para repetir todo el proceso de manera que todas se ordenen 
				if (p==0)// en caso de que la siguiente ya fuera null insertamos el elemento despues del ultimo
				{
				printf("la palabra no existe \n ");
					printf("El hash de la palabra es : %d  \n " , n);
				vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
				
				Sleep(1500);
				}
				memset(b.palabra, 0, 50);
			}
		}
	}
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 250);
		memset(definicion, 0, 250);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	
	}
	
	if(opcion==6)
	{
	salir=1;// salir lo igualamos a 1 para poder salir del while 
	}
	


	
	

BorrarPantalla();
   }
   printf("adios \n");
	return 0;
}