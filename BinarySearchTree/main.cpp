// Author: Sergio Silvester

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "BinarySearchTree.h"

using namespace std;

typedef char Elem;

Elem randoms();
SearchTreeNode<Elem>* createNode(Elem e);
void randomSons(SearchTreeNode<Elem>* root, int niveles);
void postorder(SearchTreeNode<Elem>* root);
void preorder(SearchTreeNode<Elem>* root);
void inorder(SearchTreeNode<Elem>* root);

int main () {
    srand(time(NULL));

    SearchTreeNode<Elem>* root = NULL;

    cout << endl;
    cout << "isEmpty() = " << (root -> isEmpty() ? "True" : "False") << endl;
    cout << endl;

    root = createNode((Elem) NULL);

    root -> insert('K');

    root -> insert('D');

    root -> insert('W');

    root -> insert('F');

    // SearchTreeNode<Elem>* root = createRandomTree(3);

    cout << "Postorder----------" << endl << endl;
    postorder(root);
    cout << endl << endl;
    cout << "Preorder----------" << endl << endl;
    preorder(root);
    cout << endl << endl;
    cout << "Inorder----------" << endl << endl;
    inorder(root);
    cout << endl << endl;

    cout << "isEmpty() = " << (root -> isEmpty() ? "True" : "False") << endl;
    cout << endl;
    cout << "size() = " << root -> size() << endl;
    cout << endl;
    cout << "height() = " << root -> height() << endl;
    cout << endl;
    cout << "root value = " << root -> value() << endl;
    cout << endl;
    cout << "left child value = " << root -> leftChild() -> value() << endl;
    cout << endl;
    cout << "right child value = " << root -> rightChild() -> value() << endl;

    return 0;
}

// inclusive random
Elem randoms() {

    int min = 33;
    int max = 126;
    char ran = rand() % (max + 1 - min) + min;
    return ran;
}

SearchTreeNode<Elem>* createNode(Elem e) {
    SearchTreeNode<Elem>* node = new SearchTreeNode<Elem>(e, NULL, NULL);
    return node;
}

void postorder(SearchTreeNode<Elem>* root) {
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

void preorder(SearchTreeNode<Elem>* root) {
    if (root != NULL) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(SearchTreeNode<Elem>* root) {
    if (root != NULL) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}