// Author: Sergio Silvester
#include "Cola.h"
#include "AVLTree.h"
#include <iostream>

using namespace std;

void printBfs()

int main () {

    Avl root = NULL;

    cout << endl;
    cout << "isEmpty() = " << (empty(root) ? "True" : "False") << endl;
    cout << endl;

    root = createAvl('A');
    root = insertAvl('B', root);
    root = insertAvl('C', root);
    root = insertAvl('D', root);
    root = insertAvl('E', root);
    root = insertAvl('F', root);
    root = insertAvl('G', root);



    return 0;
}

