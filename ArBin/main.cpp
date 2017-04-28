// Author: Sergio Silvester

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "arbin.h"

typedef char Elem;

using namespace std;

Elem randoms();
void randomSons(Arbin root, int niveles);
Arbin createRandomTree(int niveles);
void postorder(Arbin root);
void preorder(Arbin root);
void inorder(Arbin root);

int main () {
	srand(time(NULL));

	Arbin root = NULL;

	cout << endl;
	cout << "isEmpty() = " << (isEmpty(root) ? "True" : "False") << endl;
	cout << endl;

	root = createArbin('F');
	root -> left = createArbin('B');
	root -> left -> left = createArbin('A');
	root -> left -> right = createArbin('D');
	root -> left -> right -> left = createArbin('C');
	root -> left -> right -> right = createArbin('E');
	root -> right = createArbin('G');
	root -> right -> right = createArbin('I');
	root -> right -> right -> left = createArbin('H');

	// root = createRandomTree(3);

	cout << "Postorder----------" << endl << endl;
	postorder(root);
	cout << endl << endl;
	cout << "Preorder----------" << endl << endl;
	preorder(root);
	cout << endl << endl;
	cout << "Inorder----------" << endl << endl;
	inorder(root);
	cout << endl << endl;

	cout << "isEmpty() = " << (isEmpty(root) ? "True" : "False") << endl;
	cout << endl;
	cout << "size() = " << size(root) << endl;
	cout << endl;
	cout << "height() = " << height(root) << endl;
	cout << endl;
	cout << "root value = " << value(root) << endl;
	cout << endl;
	cout << "left child value = " <<  value(leftChild(root)) << endl;
	cout << endl;
	cout << "right child value = " << value(rightChild(root)) << endl;

	return 0;
}

// inclusive random
Elem randoms() {

	int min = 33;
	int max = 126;
	char ran = rand() % (max + 1 - min) + min;
	return ran;
}

void randomSons(Arbin root, int niveles) {

	if (niveles == 0) {
		return;
	}

	Arbin left = createArbin(randoms());
	Arbin right = createArbin(randoms());
	root -> left = left;
	root -> right = right;
	niveles--;
	randomSons(root -> left, niveles);
	randomSons(root -> right, niveles);

}

Arbin createRandomTree(int niveles) {
	Arbin root = createArbin(random());
	randomSons(root, --niveles);
	return root;
}

void postorder(Arbin root) {
    if (root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

void preorder(Arbin root) {
    if (root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Arbin root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

