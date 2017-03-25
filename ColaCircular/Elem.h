#include <cstdlib>
#include <ctime>
#include <cstdio>

#include <iostream>

using namespace std;

typedef int ElemValue;

typedef struct NodoElem
{
	ElemValue id;
	int tiempo;
} *Elem;

void impElem (Elem e) {cout << "[id: " << e -> id << ", tiempo: " << e -> tiempo << "]" << endl;}
//int igualesElem (Elem e1, Elem e2) {return strcmp(e1 -> id, e2 -> id) == 0;}
int igualesElem (Elem e1, Elem e2) {return e1 -> id == e2 -> id;}
int esMenor (Elem e1, Elem e2) {return e1 -> tiempo < e2 -> tiempo;}

Elem nuevoElem(ElemValue id, int time) {
	Elem e = (Elem) malloc(sizeof(struct NodoElem));
	e -> id = id;
	e -> tiempo = time;
	return e;
}

// max process is 8
// 5 a 12 id procesos
// 5 a 15 tiempo
