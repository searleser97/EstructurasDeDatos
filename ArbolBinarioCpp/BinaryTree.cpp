// Author: Sergio Silvester

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef char Elem;

// Binary tree structure
template <class T> class Node {

public: T data;
public: Node<T>* left;
public: Node<T>* right;
// public: int size;

	Node (T data, Node<T>* left, Node<T>* right) {
		this -> data = data;
		this -> left = left;
		this -> right = right;
	}

public: bool isEmpty() {
		if (this == NULL)
			return true;
		else
			return false;
	}

public: int size () {
		return _size(this);
	}

public: T value() {
		return this -> data;
	}

public: Node<T>* leftChild() {
		return this -> left;
	}

public: Node<T>* rightChild() {
		return this -> right;
	}

private: int _size(Node<T>* root) {
		if (root == NULL)
			return 0;
		else
			return 1 + _size(root -> left) + _size(root -> right);
	}

	public: int height() {
		return _height(this);
	}

	private: int _height(Node<T>* root) {
		if (!root)
			return 0;

		return 1 + max(_height(root -> left), _height(root -> right));
	}


};

Elem randoms();
Node<Elem>* createNode(Elem e);
void randomSons(Node<Elem>* root, int niveles);
Node<Elem>* createRandomTree(int niveles);
void postorder(Node<Elem>* root);
void preorder(Node<Elem>* root);
void inorder(Node<Elem>* root);

int main () {
	srand(time(NULL));

	Node<Elem>* root = NULL;

	cout << endl;
	cout << "isEmpty() = " << (root -> isEmpty() ? "True" : "False") << endl;
	cout << endl;

	root = createNode('F');
	root -> left = createNode('B');
	root -> left -> left = createNode('A');
	root -> left -> right = createNode('D');
	root -> left -> right -> left = createNode('C');
	root -> left -> right -> right = createNode('E');
	root -> right = createNode('G');
	root -> right -> right = createNode('I');
	root -> right -> right -> left = createNode('H');

	// Node<Elem>* root = createRandomTree(3);

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

Node<Elem>* createNode(Elem e) {
	Node<Elem>* node = new Node<Elem>(e, NULL, NULL);
	return node;
}

void randomSons(Node<Elem>* root, int niveles) {

	if (niveles == 0) {
		return;
	}

	Node<Elem>* left = createNode(randoms());
	Node<Elem>* right = createNode(randoms());
	root -> left = left;
	root -> right = right;
	niveles--;
	randomSons(root -> left, niveles);
	randomSons(root -> right, niveles);

}

Node<Elem>* createRandomTree(int niveles) {
	Node<Elem>* root = createNode(random());
	randomSons(root, --niveles);
	return root;
}

void postorder(Node<Elem>* root) {
	if (root != NULL) {
		postorder(root -> left);
		postorder(root -> right);
		cout << root -> data << " ";
	}
}

void preorder(Node<Elem>* root) {
	if (root != NULL) {
		cout << root -> data << " ";
		preorder(root -> left);
		preorder(root -> right);
	}
}

void inorder(Node<Elem>* root) {
	if (root != NULL) {
		inorder(root -> left);
		cout << root -> data << " ";
		inorder(root -> right);
	}
}