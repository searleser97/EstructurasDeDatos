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

//----------------------fin Elem.h---------Inicio Lista.h-----------------------------------

typedef struct Nodo
{
	Elem dato;
	struct Nodo *sig;
} *Lista;

// Signatura
int esvacia(Lista);
Elem cabeza(Lista); // ultimo elemento en entrar a la cola
Lista resto(Lista);
Lista vacia();
Lista cons(Elem, Lista);
int numElem(Lista);
void impLista(Lista);
Lista pegaListas(Lista, Lista);
Lista invierteLista(Lista);
int sonIguales(Lista, Lista);
int palindroma(Lista);
Lista insOrden(Elem, Lista);
Lista ordena(Lista);
Lista consListaInt(int size, int from, int to);
Elem frente(Lista); // primero en estar formado en la cola
Lista desformar(Lista);
// fin signatura

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

// inclusive random
int random(int from, int to) {
	return rand() % (to + 1 - from) + from;;
}

Lista consListaInt(int size, int from, int to) {
	if (size == 0) return vacia();
	int randN = random(from, to);
	int randPrior = random(from, to);
	Elem e = nuevoElem(randN, randPrior);
	return insOrden(e, consListaInt(size - 1, from, to));
}

Elem frente(Lista l) {
	if (l == NULL) return NULL;
	if (l -> sig == NULL) return cabeza(l);
	return frente(resto(l));
}

Lista desformar(Lista l) {
	if (l -> sig -> sig == NULL) {
		l -> sig = NULL;
		return l;
	}
	return cons(cabeza(l), desformar(resto(l)));
}

void impListaFull(Lista l) {
	impLista(l);

	Elem primero = frente(l);
	Elem ultimo = cabeza(l);
	cout << endl;
	cout << "Primer Elemento: ";
	impElem(primero);
	cout << endl;
	cout << "Ultimo Elemento: ";
	impElem(ultimo);
	cout << endl;
}

//----------------------fin lista.h---------Inicio main-----------------------------------

int main() {
	srand(time(NULL));

	int n1 = 0;

	cout << "Ingrese el numero de elementos aleatorios a insertar en la cola de prioridades" << endl;
	cin >> n1;

	Lista a = consListaInt(n1, 33, 126);

	cout << endl;
	cout << "Cola ordenada por prioridades:" << endl << endl;
	impListaFull(a);

	desformar(a);
	impListaFull(a);
	cout << endl;
	cout << endl;
	desformar(a);
	impListaFull(a);
	return 0;
}
