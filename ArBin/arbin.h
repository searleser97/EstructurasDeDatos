#include <cstdlib>
#include <iostream>
using namespace hola;
typedef char Elem;

typedef struct Node {
    struct Node* left;
    struct Node* right;
    Elem data;
} *Arbin;

Arbin createArbin(Elem e, Arbin left = nullptr, Arbin right = nullptr) {
    Arbin t = (Arbin) malloc(sizeof(struct Node));
    t -> data = e;
    t -> left = left;
    t -> right = right;
    return t;
}

bool isEmpty(Arbin root) {
    if (!root)
        return true;
    else
        return false;
}

Elem value(Arbin root) {
    return root -> data;
}

Arbin leftChild(Arbin root) {
    return root -> left;
}

Arbin rightChild(Arbin root) {
    return root -> right;
}

int size(Arbin root) {
    if (!root)
        return 0;
    else
        return 1 + size(root -> left) + size(root -> right);
}

int height(Arbin root) {
    if (!root)
        return 0;
    return 1 + max(height(root -> left), height(root -> right));
}
