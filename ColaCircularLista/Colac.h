#include "Elem.h"

typedef struct Nodo
{
	Elem dato;
	struct Nodo *sig;
} *Lista;

typedef struct ApUltimo
{
	Lista ultimo;
} *Colac;

// Signatura
int random(int from, int to);
int esNuevac(Colac);
Colac nuevac();
Colac formarC(Elem, Colac);
Colac rotar(Colac);
void impColac(Colac);
Colac randColac(int size);
// fin signatura


// inclusive random
int random(int from, int to) {
	return rand() % (to + 1 - from) + from;;
}

int esNuevac(Colac c) {return c -> ultimo == NULL;}

Colac nuevac() {

	Colac cc = (Colac) malloc(sizeof(struct ApUltimo));
	cc -> ultimo = NULL;
	return cc;
}

Colac formarC(Elem e, Colac c) {

	Lista nuevo = (Lista) malloc(sizeof(struct Nodo));
	nuevo ->  dato = e;

	if (esNuevac(c))
		nuevo -> sig = nuevo;
	else if (c -> ultimo == c -> ultimo -> sig) {
		c -> ultimo -> sig = nuevo;
		nuevo -> sig = c -> ultimo;
	} else {
		nuevo -> sig = c -> ultimo -> sig;
		c -> ultimo -> sig = nuevo;
	}

	c -> ultimo = nuevo;

	return c;
}

Colac rotar(Colac c) {
	c -> ultimo = c -> ultimo -> sig;
	return c;
}

void impColac(Colac c) {
	Lista tmp = c -> ultimo;
	while (true) {
		cout << c -> ultimo -> sig -> dato << " ";
		c = rotar(c);
		if (c -> ultimo == tmp) break;
	}
}

Colac randColac(int size) {
	Colac c = nuevac();
	while (size--) {
		Elem e = random(33, 126);
		c = formarC(e, c);
	}

	return c;
}
