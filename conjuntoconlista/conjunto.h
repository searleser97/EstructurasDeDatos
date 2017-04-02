#include "Lista.h"

typedef Lista Conj;

Conj vacio();
Conj insert(Elem e, Conj c);
bool esvacio(Conj);
bool estaen(Elem, Conj);
Conj elimina(Elem, Conj);
Conj une(Conj, Conj);
Conj interseccion(Conj, Conj);
Conj diferencia(Conj, Conj);
int cardinalidad(Conj);
void impC(Conj);

Conj vacio() {
	return NULL;
}

bool esvacio(Conj c) {
	return esvacia(c);
}

bool estaen(Elem e, Conj c) {
	if (esvacio(c))
		return false;
	if (e == cabeza(c))
		return true;

	return estaen(e, resto(c));
}

Conj insert(Elem e, Conj c) {
	if (estaen(e, c))
		return c;

	return cons(e, c);
}

Conj elimina(Elem e, Conj c) {
	if (esvacio(c))
		return vacio();
	if (e == cabeza(c))
		return resto(c);

	return cons(cabeza(c), elimina(e, resto(c)));
}

Conj une(Conj c1, Conj c2) {
	if (esvacio(c2))
		return c1;

	return insert(cabeza(c2), une(c1, resto(c2)));
}

Conj interseccion(Conj c1, Conj c2) {
	if (esvacio(c2))
		return vacio();
	if (estaen(cabeza(c2), c1))
		return insert(cabeza(c2), interseccion(c1, resto(c2)));
	return interseccion(c1, resto(c2));
}

Conj diferencia(Conj c1, Conj c2) {
	if (esvacio(c2))
		return c1;
	if (estaen(cabeza(c2), c1))
		return elimina(cabeza(c2), diferencia(c1, resto(c2)));
	return diferencia(c1, resto(c2));
}

int cardinalidad(Conj c) {
	if (esvacio(c))
		return 0;

	return 1 + cardinalidad(resto(c));
}

void impC(Conj c) {
	impLista(c);
}

