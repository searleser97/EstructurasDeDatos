#include <iostream>

using namespace std;

// Binary tree structure
template <class T> class Node {

public: T data;
public: Node<T>* left;
public: Node<T>* right;

	Node (T data, Node<T>* left, Node<T>* right) {
		this -> data = data;
		this -> left = left;
		this -> right = right;
	}
};


template <class T> class priorqueue {

public: T data;
public: Node<T>* root;
private: Node<T>* tmp;
private: Node<T>* ult;

	priorqueue (T data) {
		root = new Node<T>(data, NULL, NULL);
		ult = root;
	}

	Node<T>* push(T data) {
		Node<T>* nuevo = new Node<T>(data, NULL, NULL);
		if (ult -> left == NULL) 
			ult -> left = nuevo;
		else if (ult -> right == NULL) {
			ult -> right = nuevo;
			ul
		}
	}

}



int main() {



	return 0;
}