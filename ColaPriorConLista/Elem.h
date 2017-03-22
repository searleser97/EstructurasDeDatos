#include <cstring>
#include <cstdlib>
#include <ctime>

#include <iostream>

typedef char ElemValue;

using namespace std;

typedef struct NodoElem
{
	ElemValue dato;
	int prioridad;
} *Elem;

void impElem (Elem e) {cout << "[dato: " << e -> dato << ", prioridad: " << e -> prioridad << "]" << endl;}
//int igualesElem (Elem e1, Elem e2) {return strcmp(e1 -> dato, e2 -> dato) == 0;}
int igualesElem (Elem e1, Elem e2) {return e1 -> dato == e2 -> dato;}
int esMenor (Elem e1, Elem e2) {return e1 -> prioridad < e2 -> prioridad;}

Elem nuevoElem(ElemValue ev, int prior) {
	Elem e = (Elem) malloc(sizeof(struct NodoElem));
	e -> dato = ev;
	e -> prioridad = prior;
	return e;
}