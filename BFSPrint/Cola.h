#include <cstdlib>

typedef struct Nodo {
	Elem dato;
	struct Nodo* sig;
} *ApNodo;

typedef struct CNodo
{
	ApNodo prim;
	ApNodo ult;
} *Cola;

Cola nueva() {
	Cola nueva = (Cola) malloc(sizeof(struct CNodo));
	nueva -> prim = nueva -> ult = NULL;
	return nueva;
}

int esNueva(Cola q) {
	return q -> prim == NULL;
}

// solo se esta regresando 'Cola q' para que algo como 'formar(formar(formar(formar(q, 'a'), 'b'), 'c'), 'd');' funcione
Cola formar(Cola q, Elem e) {
	ApNodo nodo = (ApNodo) malloc(sizeof(struct Nodo));
	nodo -> dato = e;
	nodo -> sig = NULL;
	if (esNueva(q)) {
		q -> prim = nodo;
		q -> ult = nodo;
	} else {
		q -> ult -> sig = nodo;
		q -> ult = nodo;
	}
	return q;
}

Elem frente(Cola q) {
	return q -> prim -> dato;
}

void desformar(Cola q) {
	if (esNueva(q)) {
		return;
	}

	// se pone aqui el temp para que el free(temp) aplique para cualquiera de los dos casos siguientes
	ApNodo temp = q -> prim;

	if (q -> prim == q -> ult) {
		q -> prim = q -> ult = NULL;
		return;
	}

	q -> prim = q -> prim -> sig;

	free(temp);
}

void impCola(Cola q) {
	ApNodo primero = q -> prim;
	while (primero != NULL) {
		std::cout << primero -> dato << std::endl;
		primero = primero -> sig;
	}
}
