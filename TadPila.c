#include"TADPila.h"
void Initialize(pila *s)
{
s->tope=-1;
return;
}

void Destroy(pila *s)
{
Initialize(s);
return;
}

void Push(elemento e,pila *s)
{
s->tope++;
s->A[s->tope]=e;
return;
}

elemento Pop(pila *s)
{
elemento r;
r=s->A[s->tope];
s->tope--;
return r;
}

int Size(pila *s)
{
return s->tope+1;
}

boolean Empty(pila *s)
{
if(Size(s)==0)
return TRUE;
return FALSE;
}

elemento Top(pila *s)
{
return s->A[s->tope];
}


