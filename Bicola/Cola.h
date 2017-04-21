#include "Elem.h"
#include <cstdlib>

typedef struct Nodo {
	Elem dato;
	struct Nodo* sig;
	struct Node* ant;
} *ApNodo;

typedef struct CNodo
{
	ApNodo izq;
	ApNodo der;
} *Cola;

Cola nueva() {
	Cola nueva = (Cola) malloc(sizeof(struct CNodo));
	nueva -> izq = nueva -> der = NULL;
	return nueva;
}

int esNueva(Cola q) {
	return q -> izq == NULL;
}

// solo se esta regresando 'Cola q' para que algo como 'formar(formar(formar(formar(q, 'a'), 'b'), 'c'), 'd');' funcione
Cola formar(Cola q, Elem e) {
	ApNodo nodo = (ApNodo) malloc(sizeof(struct Nodo));
	nodo -> dato = e;
	nodo -> sig = NULL;
	nodo -> ant = NULL;
	if (esNueva(q)) {
		q -> izq = nodo;
		q -> der = nodo;
	} else {
		nodo -> ant = q -> der;
		q -> der -> sig = nodo;
		q -> der = nodo;
	}
	return q;
}

Elem frente(Cola q) {
	return q -> izq -> dato;
}

void desformar(Cola q) {
	if (esNueva(q)) {
		return;
	}

	// se pone aqui el temp para que el free(temp) aplique para cualquiera de los dos casos siguientes
	ApNodo temp = q -> izq;

	if (q -> izq == q -> der) {
		q -> izq = q -> der = NULL;
		return;
	}

	q -> izq = q -> izq -> sig;

	free(temp);
}

void impCola(Cola q) {
	ApNodo primero = q -> izq;
	while (primero != NULL) {
		std::cout << primero -> dato << std::endl;
		primero = primero -> sig;
	}
}