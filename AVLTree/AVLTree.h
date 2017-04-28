#include "dicbin.h"
using namespace std;

typedef Dicbin Avl;

Avl createAvl(Elem data = NULL, Avl left = nullptr, Avl right = nullptr) {
    Avl a = (Avl) createDicbin(data, left, right);
    return a;
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

Avl rotateLeftRight(Avl a) {
    return rotateLeft(createAvl(val(a), left(a), rotateRight(right(a))));
}

Avl rotateRightLeft(Avl a) {
    return rotateRight(createAvl(val(a), rotateLeft(left(a)), right(a)));
}

bool isAvl(Avl a) {
    return abs(balfact(a)) <= 1;
}

Avl balance(Avl a) {
    if (!a)
        return a;
    if (isAvl(a)) {
        return createAvl(val(a), balance(left(a)), balance(right(a)));
    } else if (balfact(a) > 0) {
        return rotateRight(a);
    } else if (balfact(a) < 0)
        return rotateLeft(a);
}

Avl insertAvl(Elem data, Avl root) {
    return balance(insert(data, root));
}
