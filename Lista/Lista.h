#include "ElemStr.h"
#include <cstdlib>
#include <ctime>

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
		impElem(cabeza(l));
		impLista(resto(l));
	}
}

Lista pegaListas(Lista l1, Lista l2) {
	if (esvacia(l1)) return l2;
	else cons(cabeza(l1), pegaListas(resto(l1),l2));
}

Lista invierteLista(Lista l){
	if (esvacia(l)) return l;
	else return pegaListas(invierteLista(resto(l)),cons(cabeza(l), vacia()));
}

int sonIguales(Lista l1, Lista l2) {
	if (esvacia(l1) && esvacia(l2)) return 1;
	else if (esvacia(l1) && !esvacia(l2)) return 0;
	else if (!esvacia(l1) && esvacia(l2)) return 0;
	else return igualesElem(cabeza(l1), cabeza(l2)) && sonIguales(resto(l1), resto(l2));
}

int palindroma(Lista l) {return sonIguales(l, invierteLista(l));}


Lista insOrden(Elem e, Lista l) {
	if(esvacia(l)) return cons(e, vacia());
	else if (esMenor(e, cabeza(l))) return cons(e, l);
	else return cons(cabeza(l), insOrden(e, resto(l)));
}

Lista ordena(Lista l) {
	if(esvacia(l)) return l;
	else return insOrden(cabeza(l), ordena(resto(l)));
}

Lista consListaInt(int size, int from, int to) {
	if (size == 0) return vacia();
	int randN = rand() % to + from;
	return cons((Elem)randN, consListaInt(size - 1, from, to));
}