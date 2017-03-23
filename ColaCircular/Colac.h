#include "Elem.h"

typedef struct Nodo
{
	Elem dato;
	struct Nodo *sig;
} *Colac;

// Signatura
int random(int from, int to);
int esNuevac(Colac);
Colac nuevac();
Colac formarC(Elem, Colac);
Colac rotar(Colac);
void impColac(Colac);
Colac randColac(int size);
Elem primero(Colac);
Colac desformar(Colac);
// fin signatura


// inclusive random
int random(int from, int to) {
	return rand() % (to + 1 - from) + from;;
}

int esNuevac(Colac c) {return c == NULL;}

Colac nuevac() {
	return NULL;
}

Colac formarC(Elem e, Colac c) {

	Colac nuevo = (Colac) malloc(sizeof(struct Nodo));
	nuevo ->  dato = e;

	if (esNuevac(c)) {

		nuevo -> sig = nuevo;
	}
	else {
		// el siguiente de nuevo ultimo = primero de la cola
		nuevo -> sig = c -> sig;
		// ultimo = nuevo
		c -> sig = nuevo;
	}

	c = nuevo;

	return c;
}

Colac rotar(Colac c) {
	c = c -> sig;
	return c;
}

void impColac(Colac c) {
	Colac tmp = c;
	while (true) {
		cout << c -> sig -> dato << " ";
		c = rotar(c);
		if (c == tmp) break;
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

Elem primero(Colac cc) {
	return cc -> sig -> dato;
}

Colac desformar(Colac cc) {
	Colac tmp = cc -> sig;

	cc -> sig = cc -> sig -> sig;

	free(tmp);

	return cc;
}
