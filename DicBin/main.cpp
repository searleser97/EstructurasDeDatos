// Author: Sergio Silvester

#include <iostream>
#include "dicbin.h"

using namespace std;

void postorder(Dicbin root);
void preorder(Dicbin root);
void inorder(Dicbin root);

int main () {

	Dicbin root = NULL;

	cout << endl;
	cout << "isEmpty() = " << (empty(root) ? "True" : "False") << endl;
	cout << endl;

    root = createDicbin('C');
    root = insert('A', root);
    root = insert('D', root);
    root = insert('B', root);

	cout << "Postorder----------" << endl << endl;
	postorder(root);
	cout << endl << endl;
	cout << "Preorder----------" << endl << endl;
	preorder(root);
	cout << endl << endl;
	cout << "Inorder----------" << endl << endl;
	inorder(root);
	cout << endl << endl;

	cout << "isEmpty() = " << (empty(root) ? "True" : "False") << endl;
	cout << endl;
	cout << "size() = " << _size(root) << endl;
	cout << endl;
	cout << "height() = " << _height(root) << endl;
	cout << endl;
	cout << "root value = " << val(root) << endl;
	cout << endl;
	cout << "left child value = " <<  val(left(root)) << endl;
	cout << endl;
	cout << "right child value = " << val(right(root)) << endl;

	return 0;
}


void postorder(Dicbin root) {
    if (root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

void preorder(Dicbin root) {
    if (root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Dicbin root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

