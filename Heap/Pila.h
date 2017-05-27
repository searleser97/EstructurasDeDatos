#include <cstdlib>

typedef struct NodoP
{
    int dato;
    struct NodoP *sig;
} *Pila;

int isempty(Pila l) {return l == NULL;}

int top(Pila l) {if (isempty(l)) return NULL; return l->dato;}

Pila pop(Pila l) {if (isempty(l)) return NULL; return l->sig;}
Pila empty() {return NULL;}

Pila push(int e, Pila l)
{
    Pila t = (Pila)malloc(sizeof(struct NodoP));
    t->dato = e;
    t->sig = l;
    return t;
}

int numElem(Pila l) {
    if(isempty(l)) return 0;
    else return 1 + numElem(pop(l));
}

void impPila(Pila l) {

    Pila aux = l;
    while (aux) {
        cout << top(aux) << endl;
        aux = aux -> sig;
    }
}