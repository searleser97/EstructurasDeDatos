// Author: Sergio Silvester

#include <iostream>
#include "AVLTree.h"

using namespace std;

void postorder(Dicbin root);
void preorder(Dicbin root);
void inorder(Dicbin root);

int main () {

<<<<<<< HEAD
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

    Dicbin root = NULL;

    cout << endl;
    cout << "isEmpty() = " << (empty(root) ? "True" : "False") << endl;
    cout << endl;

    root = createDicbin();

    while (true) {
        Elem tmp;
        cin >> tmp;
        if (tmp == 0)
            break;
        root = insertAvl(tmp, root);
    }

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
    cout << "balfact() = " << balfact(root) << endl;
    cout << endl;
    cout << "balfact(right(root)) = " << balfact(right(root)) << endl;
    cout << endl;
    cout << "balfact(right(root)) = " << balfact(right(left(root))) << endl;
    cout << endl;
    cout << "left child value = " <<  val(left(root)) << endl;
    cout << endl;
    cout << "right child value = " << val(right(root)) << endl;
>>>>>>> 05901ed9d0f29f011887d2f237590431fb8763b2
    cout << endl;
    cout << "left child of right child value = " << val(left(right(root))) << endl;
    cout << endl;
    cout << "right child of right child value = " << val(right(right(root))) << endl;
    cout << endl;
    

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

