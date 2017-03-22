#include "ElemChar.h"
#include <cstdlib>

typedef struct Nodo
{
	Elem dato;
	struct Nodo *sig;
} *Pila;

int isempty(Pila l) {return l == NULL;}

Elem top(Pila l) {if (isempty(l)) return NULL; return l->dato;}

Pila pop(Pila l) {if (isempty(l)) return NULL; return l->sig;}
Pila empty() {return NULL;}

Pila push(Elem e, Pila l)
{
	Pila t = (Pila)malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = l;
	return t;
}

int numElem(Pila l) {
	if(isempty(l)) return 0;
	else return 1 + numElem(pop(l));
}

void impPila(Pila l) {
	if (l != NULL) {
		impElem(top(l));
		impPila(pop(l));
	}
}