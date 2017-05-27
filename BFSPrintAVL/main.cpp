// Author: Sergio Silvester
#include "AVLTree.h"
#include "Cola.h"

#include <iostream>

using namespace std;

void inorder(Avl root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

// prints '1' if there is no left child and '0' if there is no right child
void printBfs(Avl root) {
    Cola q = nueva();
    q = formar(q, root);

    while (!esNueva(q)) {

        int qSize = ColaTam(q);

        for (int i = 0; i < qSize; i++) {
            Avl aux = frente(q);
            cout << rootVal(aux) << " ";
            q = desformar(q);

            if (rootVal(aux) == '1' || rootVal(aux) == '0')
                continue;

            if (leftChild(aux)) {
                q = formar(q, leftChild(aux));
            } else {
                q = formar(q, createAvl('1'));
            }

            if (rightChild(aux)) {
                q = formar(q, rightChild(aux));
            } else {
                q = formar(q, createAvl('0'));
            }
        }

        cout << endl;

    }
}

int main () {

    int n;
    Dicbin root;

    cin >> n;
    if (n == 0) {

        root = createDicbin('A');

        for (int i = 'B'; i < 'M'; ++i)
        {
            root = insert(i, root);
            printBfs(root);
            cout << root -> size << endl;
            cout << "*******" << endl;
        }
        ////////////////////////////////// Dicbin to Avl
        root = balance(root);
        printBfs(root);
        cout << "*******" << endl;

    } else {
        Elem aux;
        cin >> aux;
        root = createDicbin(aux);
        n -= 1;
        for (int i = 0; i < n; ++i)
        {
            Elem input;
            cin >> input;
            root = insert(input, root);
        }
        root = balance(root);
        printBfs(root);
        cout << "*******" << endl;
    }

    cout << "//////////" << endl;
    inorder(root);
    cout << endl;
    return 0;
}

