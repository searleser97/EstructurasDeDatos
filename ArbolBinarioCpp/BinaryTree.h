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

