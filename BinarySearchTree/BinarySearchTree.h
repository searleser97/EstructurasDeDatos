using namespace std;
#include "BinaryTree.h"

template <class T> class SearchTreeNode {

private: Node<T>* BinaryTree;

public: SearchTreeNode (T data, SearchTreeNode<T>* left, SearchTreeNode<T>* right) {
        BinaryTree = new Node<T>(data, left, right);
    }

public: void _insert(T data, Node<T>* root) {

        if (!root -> data) {
            root -> data = data;
            return;
        }

        if (data <= root -> data) {
            if (!root -> left) {
                root -> left = new SearchTreeNode<T>(data, nullptr, nullptr);
                return;
            } else
                _insert(data, root -> left);
        } else {
            if (!root -> right) {
                root -> right = new SearchTreeNode<T>(data, nullptr, nullptr);
                return;
            } else
                _insert(data, root -> right);
        }
    }

public: void insert(T data) {
        _insert(data, (Node<T>*) this);
    }
};
