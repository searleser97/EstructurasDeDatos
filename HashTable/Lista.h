#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

typedef char Dato;

typedef struct Info
{
	int key;
	Dato dato;
} *Elem;

// void impElem (Elem e) {cout << e << endl;}

typedef struct Nodo
{
	Elem dato;
	struct Nodo *sig;
} *Lista;

int esvacia(Lista l) {return l == NULL;}

Elem cabeza(Lista l) {return l->dato;}

Lista resto(Lista l) {return l->sig;}
Lista vacia() {return NULL;}

Lista cons(Elem e, Lista l)
{
	Lista t = (Lista)malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = l;
	return t;
}

int numElem(Lista l) {
	if(esvacia(l)) return 0;
	else return 1 + numElem(resto(l));
}

void impLista(Lista l) {
	if (l != NULL) {
		cout << l -> dato -> dato << endl;
		impLista(resto(l));
	}
}
