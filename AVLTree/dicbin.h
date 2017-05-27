#include "arbin.h"

typedef Arbin Dicbin;

Dicbin createDicbin(Elem data = NULL, Dicbin left = nullptr, Dicbin right = nullptr) {
    Dicbin t = (Dicbin) createArbin(data, left, right);
    return t;
}

bool empty(Dicbin root) {
    return isEmpty((Arbin) root);
}

Elem val(Dicbin root) {
    return value((Arbin) root);
}

Dicbin left(Dicbin root) {
    return (Dicbin) leftChild((Arbin) root);
}

Dicbin right(Dicbin root) {
    return (Dicbin) rightChild((Arbin) root);
}

int _size(Dicbin root) {
    return size((Arbin) root);
}

int _height(Dicbin root) {
    return height((Arbin) root);
}

Dicbin insert(Elem data, Dicbin root) {

    if (!root -> data)
        root -> data = data;
    else {
        if (data <= root -> data) {
            if (!root -> left)
                root -> left = createDicbin(data);
            else
                insert(data, root -> left);
        } else {
            if (!root -> right)
                root -> right = createDicbin(data);
            else
                insert(data, root -> right);
        }
    }

    return root;
}