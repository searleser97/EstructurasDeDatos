#include "dicbin.h"
using namespace std;

typedef Dicbin Avl;

Avl createAvl(Elem data = NULL, Avl left = nullptr, Avl right = nullptr) {
    Avl a = (Avl) createDicbin(data, left, right);
    return a;
}

Elem rootVal(Avl root) {
    return value((Arbin) root);
}

Avl rotateLeft(Avl a) {
    return createAvl(val(right(a)), createAvl(val(a), left(a), left(right(a))), right(right(a)));
}

Avl rotateRight(Avl a) {
    return createAvl(val(left(a)), left(left(a)), createAvl(val(a), right(left(a)), right(a)));
}

int balfact(Avl a) {
    return _height(left(a)) - _height(right(a));
}

bool isAvl(Avl a) {
    return abs(balfact(a)) <= 1;
}

Avl balance(Avl a) {
    if (!a)
        return a;

    Avl aux;

    if (isAvl(a)) {
        return createAvl(val(a), balance(left(a)), balance(right(a)));
    } else if (balfact(a) > 1) {
        aux = rotateRight(a);
    } else {
        aux = rotateLeft(a);
    }
    return balance(aux);
}

Avl insertAvl(Elem data, Avl root) {
    root = insert(data, root);
    return balance(root);
}


