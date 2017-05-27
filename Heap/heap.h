#include <cmath>
#include "Pila.h"
typedef Arbin Heap;

int heightH(Heap root) {
    if (!root)
        return 0;
    return (int) log2(root -> size) + 1;
}

Heap hazHeap(Elem e, Arbin izq, Arbin der) {
    if (!izq && !der) {
        return createArbin(e);
    }

    else if (izq && !der) {
        if (e >= value(izq))
            return createArbin(e, izq);
        else
            return createArbin(value(izq), createArbin(e));
    } else {
        if (e > value(izq) && e > value(der))
            return createArbin(e, izq, der);
        else if (value(izq) >= value(der))
            return createArbin(value(izq), hazHeap(e, leftChild(izq), rightChild(izq)), der);
        else 
            return createArbin(value(der), izq, hazHeap(e, leftChild(der), rightChild(der)));
    }
}

Heap consHeap(Arbin a) {
    if (isEmpty(a))
        return a;
    else if (height(leftChild(a)) - height(rightChild(a)) <= 1)
        return hazHeap(value(a), consHeap(leftChild(a)), consHeap(rightChild(a)));
    else
        cout << "La funcion requiere un arbol completo o heap" << endl;
}

// 1 means left, 0 means right
Elem findNode(Heap h, int n) {
    Pila p = empty();
    int curr_node = n;
    while (curr_node > 1) {
        if(curr_node & 1) {
            p = push(0, p);
        } else {
            p = push(1, p);
        }
        curr_node = curr_node / 2;
    }

    // impPila(p);
    Heap auxh = h;
    while (!isempty(p)) {
        int aux = top(p);
        p = pop(p);

        if (aux) {
            auxh = leftChild(auxh);
        } else {
            auxh = rightChild(auxh);
        }
    }
    return value(auxh);
}

Elem ultimo(Heap h) {
    return findNode(h, h -> size);
}

bool esHoja(Heap h) {
    if(isEmpty(leftChild(h)) && isEmpty(leftChild(h)))
        return true;
    else
        return false;
}

Heap eliminaUltimo(Heap h) {
    if (esHoja(h))
        return NULL;
    else if (heightH(leftChild(h)) > heightH(rightChild(h)))
        return createArbin(value(h), eliminaUltimo(leftChild(h)), rightChild(h));
    else
        return createArbin(value(h), leftChild(h), eliminaUltimo(rightChild(h)));
}

Heap deleteTop(Heap h) {
    if (!h || esHoja(h))
        return NULL;

    Elem e = ultimo(h);

    h = eliminaUltimo(h);
    
    return hazHeap(e, leftChild(h), rightChild(h));
}

