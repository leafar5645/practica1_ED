/*  Título: practica3.c
   Descripción: Conjunto de funciones que realizan cada una de las tareas solicitadas por las opciones del menù principal. Se incluye la funciòn principal main (Que contiene al menù y llamadas a las demàs funciones).
    Autor: Equipo 932
    Integrantes:
            - Hernández Ruiz Rafael
	    - Maya Rocha Luis Emmanuel
	    - Rivas Rojas Arturo
    Fecha: 18 de Mayo de 2017               Versión: 3.1
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h> //Biblioteca usada para operaciones con cadenas
#include <time.h>
#include "TADLista.h"
#include "presentacion.h"

int colisiones;  //contador de colisiones, variable global, se requiere en todas las funciones y causa problemas si esta como local en una sola.

void acentos (char palabra[50])  //funciòn para guardar y buscar las palabras con acento
{
	int n=0;
	while(n<strlen(palabra))  //Como se puede ver, se busca donde aparece un acento, de acuerdo a la codificaciòn de un archivo TXT,... 
	{
	if((int)palabra[n] == -15) //... y luego se cambia la codificaciòn al ascii, para que pueda verse el acento en pantalla.
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
	 
	while(n<97)  //Hacemos recorrido por tabla "de claves"
	{
	
		if(tabla[n]== -1)
		{
			vacio=vacio+1; //aumentamos uno al contador vacio cada vez que un campo de la tabla aparezca vacio.
		}
		n=n+1;
	}
	return vacio;
}
int convertir_asc(char palabra[50]) //funciòn para obtener la suma del valor ascii de las letras de la palabra  
{         //Esta funciòn serà vital para el càlculo de la funciòn HASH.
	
	int n=0;
	int valor=0;
	while(palabra[n] != '\0')
	{
      
		
		valor=valor+(int)(palabra[n]); //Recordemos que se imprimirà el valor ascii de la palabra, por lo que se van sumando el de cada letra.
		n=n+1;
	}

	return valor;
}

void separacion(char string[500] , char palabra[50], char definicion[500] , char valor) //funcion para separar el string en dos la palabra y la definiciòn y el char valor se agrega al comienzo
{
	int n=0;
	int j=0;
		palabra[0]= valor;

	while(string[n] != ':')  //Nuestro anàlisis/separaciòn llega hasta los 2 puntos ":", separando asi la definiciòn de la palabra a buscar.
	{

		palabra[n+1]=string[n]; //Metemos la palabra al nuevo arreglo
			
		n=n+1;
	}
	n=n+1;
	/*^*/
	while(string[n] != '\n')
	{
		
		
		definicion[j]=string[n];  //Metemos definiciòn al arreglo del mismo nombre
		j=j+1;
		n=n+1;
	}
	
}
void rellenar(int tabla[97]) //rellena la tabla con -1
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
	lista diccionario[97]; //El arreglo de listas que es igual al tamaño de la tabla 
	

    char  unsigned palabra[50]; //la variable para palabras
	
     int tabla[97];// la tabla hash
	rellenar(tabla); //rellenamos la tabla con -1
    int hash=0;	
	elemento a; //elementos con los que obtendremos, meteremos y compararemos palabras
	elemento b;
	boolean t;
    char valor;  // variable para guardar carateres de un archivo hasta encontrar el carater ^ que significa el fin del archivo 
	int vacio=0; //variable para llevar el numero de espacio vacios en la tabla 
    int salir=0;  //variable que controlora la salida del programa 
    int orden=0; // variable para guardar el orden de busqueda mayor
    int pasos=0;	// variable para contar el numero de pasos en una operacion 
	int n=0;      //varibale que funcionara como contador , hash , indices de lista y tabla 
	int auxo=0;   // variable auxiliar 
	int k=0;         //lo mismo que la variable n
 	int z=0;            // lo mismo que n y k
	char aux='n';     // variable para confirmar eliminacion de una palabra 
	char archivo[50];    // variable para guardar el nombre del archivo 
	FILE * dic; //declarando un archivo
	int opcion=0; // variable para acceder a la funcion deseada del programa 
	char definicion[500]; // variable para guardar definiciones de palabras 
	unsigned char string[500]=""; //la cadena que va almacenar lo que sacamos del archivo
	posicion p ; //posiciones para realizar las busquedas y comparaciones
	posicion p2; // lo mismo 
    posicion p3;
	while(z<97) //inicializaremos todas las listas solo para poder obtener su tamaño aunque no tengan letras
	{
		Initialize(&diccionario[z]);
		z=z+1;
	}
	z=0;
	while(salir != 1) //mientras salir no sea igual a 1 seguiremos en el programa
	{
		
		while(z<97) // proceso para obtener el orden de busqueda mayor 
		{
			
		if(Empty(&diccionario[z])== FALSE)
		{
			
			auxo=Size(&diccionario[z]);
		
		}
		if(auxo>=orden)
		{
			
			orden=auxo;
			
		}
		z=z+1;
		}
		z=0;
	 vacio=status_tab(tabla); //obtener el numero de campos vacios
  	 
	printf("bienvenido al diccionario \n ");
	printf("tecle el numero de la opcion mas conveniente para usted                                       El numero de colisiones en la tabla es: %d  \n ", colisiones);
	printf("1 Cargar archivo de definiciones                                                              El orden maximo de busqueda es de : %d      \n ", orden);
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
		
 		fgets(string,500,dic); //tomar toda una linea del archivo con un maximo de 500 carateres
 		
		separacion( string , palabra , definicion , valor); //vamos a dividir la cadena que obtuvimos en 2 la palabra y la definicion mandamos valor porque al evaluar si no este simbolo ^ el cursor de mueve en uno y perdemos el primer caracter 
		acentos(palabra);
		
		
		k=fun_hash(palabra);//aplicarle un hash a la cedena para obtener un entero
		
		//en la tabla hash buscamos la casilla que coincida con el resultado de la funcion e incrementamos la casilla para indicar que hay una palabra mas
		strcpy( a.palabra, palabra );  //copiamos la palabra al elemento
		strcpy( a.definicion, definicion ); 
		
		if(tabla[k] != -1) //verificamos si  no es la primera palabra con ese hash 
		{
		   p=First(&diccionario[k]); // al no ser la primera palabra con ese hash buscamos la primera en la lista con ese numero de hash
		  
			while(p != NULL) //mientras la direccion sea valida haremos lo siguiente
			{
				
			b=Position(&diccionario[k] , p);// sacamos el elemento de la posicion p 
			if (strcmp(a.palabra,b.palabra) == 0) //verificamos que no sea igual a la palabra que queremos meter, porque no debe haber palabras repetidas
			{
			printf("la palabra ya existe ");
			vacio=status_tab(tabla);
			 printf("letras en el hash %d \n " , tabla[n]);
		
		  
				Sleep(50);
				
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;	//salvamos la posicion p en p2
				if(p!= 0)
				{
					
				p=Following(&diccionario[k] , p2); //buscamos la posicion siguiente para repetir todo el proceso y verificar que no exista la palabra 
				}
				if (p==NULL)// en caso de que la siguiente ya fuera null insertamos el elemento despues del ultimo
				{
				Add(&diccionario[k] , a);	
				tabla[k]=tabla[k]+1;
				colisiones=colisiones +1;
				printf("Palabra insertada  ");
				vacio=status_tab(tabla);
				printf("letras en el hash %d \n " , tabla[k]);
				printf("El hash de la palabra es : %d  y la palabra :  %s \n " , k, palabra);
				Sleep(50);
				}
				memset(b.palabra, 0, 50);
			}
			
		}
		}
		
		else//en caso de que sea la primera palabra con ese hash se inicializa la lista n y se agrega el primer elemento 
		{
		Initialize(&diccionario[k]); // al ser la primera palabra inicializamos la lista
		tabla[k]=tabla[k]+1;// incrementamos el valor en ese hash de la tabla para saber que ya exite una con este hash
		Add(&diccionario[k] , a);
		printf("Palabra insertada  ");
		vacio=status_tab(tabla);
		 printf("letras en el hash %d \n " , tabla[k]);
			
			printf("El hash de la palabra es : %d  y la palabra :  %s \n " , k, palabra);
				Sleep(50);
		}
			
		memset(string, 0, 500);
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 500);
		memset(definicion, 0, 500);//limpiamos el buffer para no mandar cosas demas
 	}
	fclose(dic);
		memset(string, 0, 500);
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 500);
		memset(definicion, 0, 500);//limpiamos el buffer para no mandar cosas demas
		
}


	if(opcion== 2) // esta funcion es practicamente lo mismo que la anterior excepto sin while del archivo ya que aqui solo se imserta una palabra
	{
		
		fflush(stdin);
		pasos=0;
	printf("porfavor teclea la palabra a ingresar  \n");
	gets(palabra);
	printf("porfavor ingrese su definicion \n");
	fflush(stdin);
	gets(definicion);
	fflush(stdin);
	n=fun_hash(palabra);
	strcpy(a.palabra , palabra);
	strcpy(a.definicion , definicion);
	pasos=pasos+1;
	if(tabla[n] != -1) //verificamos si  no es la primera palabra con ese hash
		{
			
			 p=First(&diccionario[n]);
			while(p != 0) 
			{
			pasos=pasos+1;	
			b=Position(&diccionario[n] , p); 
			if (strcmp(a.palabra,b.palabra) == 0) 
			{
			printf("la palabra ya existe  ");
			vacio=status_tab(tabla);
		printf("El numero de campos vacios en la tabla es %d  " , vacio);
			printf("El hash de la palabra es : %d  \n  " , n);
			Sleep(1000);
				
				//tabla[n]=tabla[n] -1;
				p=0;//declaramos p null para salir del while
			}
			else
			{
			    p2=p;;	//salvamos la posicion p en p2
				p=Following(&diccionario[n] , p); //buscamos la posicion siguiente para repetir todo el proceso de manera que todas se ordenen 
				if (p==0)// en caso de que la siguiente ya fuera null insertamos el elemento despues del ultimo
				{
				Add(&diccionario[n] , a);
			pasos=pasos+1;
                printf("Palabra insertada");
                tabla[n]=tabla[n]+1;				
				colisiones=colisiones +1;
				vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
			   	printf("El hash de la palabra es : %d  y la palabra :  %s \n " , n, palabra);
				printf("El numero de pasos en la operacion es: %d \n ", pasos);
			   
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
		pasos=pasos+1;
		printf("Palabra insertada  ");
		tabla[n]=tabla[n]+1;
		vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
			   	printf("El hash de la palanra es : %d  \n " , n);
			   //printf("El numero de colisiones es: %d " , colisiones);
			   printf("El numero de pasos en la operacion es: %d \n ", pasos);
				Sleep(1500);
		
		}
		
		memset(string, 0, 500);
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 500);
		memset(definicion, 0, 500);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	}
	if(opcion==3)// esta la opcion de la busqueda
	{
	
	
	printf("teclea la palabra a buscar \n");
	fflush(stdin);
	gets(palabra);
	fflush(stdin);
	n=fun_hash(palabra);
	pasos=1;
	if(tabla[n] <0) //si el valor hash lleva a una casilla que no tiene letras es decir su valor es -1, la palbra no existe
	{
		printf("la palabra no existe");
		printf("El numero de pasos en la operacion es: %d \n ", pasos);
				Sleep(1000);
	}
	else //si no repetimos el mismo proceso que en las opciones anteriores buscamos la palabra 
	{
		p=First(&diccionario[n]);
		while(p != 0)
		{
			pasos=pasos+1;
			b=Position(&diccionario[n] , p);
			if (strcmp(palabra,b.palabra) == 0) // si encuentra que las palabras son  iguales la encontramos 
			{
			printf("la palabra  existe \n");
				printf("El hash de la palabra es : %d  \n " , n);	
				
				printf(" Definicion: %s \n" , b.definicion);
			    pasos=pasos+1;
				printf("El numero de pasos en la operacion es: %d \n ", pasos);
				printf("El numero de pasos en la operacion es: %d \n ", pasos);
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
					pasos=pasos+1;
				printf("El numero de pasos en la operacion es: %d \n ", pasos);
				Sleep(1000);
				}
				memset(b.palabra, 0, 50);
			}
		}
	}
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 500);
		memset(definicion, 0, 500);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	}
	
	if(opcion==4) // esta opcion es igual a la anterior solo que si encontramos la palbra pediremos una definicion
	{
		fflush(stdin);
	printf("teclea la palabra a editar \n");
	gets(palabra);
	fflush(stdin);
	n=fun_hash(palabra);
	pasos=1;
	if(tabla[n] <0)
	{
			printf("El hash de la palabra es : %d  \n " , n);
		printf("la palabra no existe");
		printf("El numero de pasos en la operacion es: %d \n ", pasos);
		
				Sleep(1000);
	}
	else
	{
		p=First(&diccionario[n]);
		while(p != 0)
		{
			pasos=pasos+1;
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
				pasos=pasos+1;
				printf("El numero de pasos en la operacion es: %d \n ", pasos);
				
				Sleep(1000);
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
				printf("El numero de pasos en la operacion es: %d \n ", pasos);
				
				Sleep(1000);
				}
				memset(b.palabra, 0, 50);
			}
		}
	}
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 500);
		memset(definicion, 0, 500);//limpiamos el buffer para no mandar cosas demas
	    memset(b.palabra, 0, 50);
	}
	
	if(opcion==5) //esta opcion al igual que las demas va buscar la palabra y en caso de encontrarla preguntara si desea eliminar
	{
		fflush(stdin);
	printf("teclea la palabra a eliminar \n");
	gets(palabra);
	fflush(stdin);
	n=fun_hash(palabra);
	pasos=1;
	if(tabla[n] <0)
	{
			printf("El hash de la palabra es : %d  \n " , n);
		printf("la palabra no existe \n");
		vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
			   printf("El numero de pasos en la operacion es: %d \n ", pasos);
	}
	else
	{
		p=First(&diccionario[n]);
		while(p != 0)
		{ 
	    pasos=pasos+1;
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
			   pasos=pasos+2;
			   printf("El numero de pasos en la operacion es: %d \n ", pasos);
				Sleep(1500);
				}
				else
				{
					printf("okey no se ha realizado ningun cambio \n");
					vacio=status_tab(tabla);
		       printf("El numero de campos vacios en la tabla es %d " , vacio);
			   pasos=pasos+2;
			   printf("El numero de pasos en la operacion es: %d \n ", pasos);
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
			   printf("El numero de pasos en la operacion es: %d \n ", pasos);
				
				Sleep(1500);
				}
				memset(b.palabra, 0, 50);
			}
		}
	}
		memset(palabra, 0, 50);
		memset(a.palabra, 0, 50);
		memset(a.definicion, 0, 500);
		memset(definicion, 0, 500);//limpiamos el buffer para no mandar cosas demas
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
