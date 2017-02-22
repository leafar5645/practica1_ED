#define TRUE 1
#define FALSE 0
#define MAX_ELEMENT 150

typedef char boolean;

typedef struct
{
int num;
char car;
} elemento;

typedef struct
{
elemento A[MAX_ELEMENT];
int tope;
}pila;

//Inicializa una pila (recibe referencia a la pila)
void Initialize(pila *s);
void Destroy(pila *s);
void Push(elemento e,pila *s);
elemento Pop(pila *s);
int Size(pila *s);
boolean Empty(pila *s);
elemento Top(pila *s);

