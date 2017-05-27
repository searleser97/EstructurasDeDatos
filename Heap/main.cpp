#include <iostream>
#include "arbin.h"
#include "heap.h"
#include "Cola.h"

using namespace std;

// prints '1' if there is no left child and '0' if there is no right child
void printBfs(Arbin root) {
    Cola q = nueva();
    q = formar(q, root);

    while (!esNueva(q)) {

        int qSize = ColaTam(q);

        for (int i = 0; i < qSize; i++) {
            Arbin aux = frente(q);
            cout << value(aux) << " ";
            q = desformar(q);

            if (leftChild(aux)) {
                q = formar(q, leftChild(aux));
            }
            if (rightChild(aux)) {
                q = formar(q, rightChild(aux));
            }
        }

        cout << endl;

    }
}

void RecibeElems(Elem arr[], int n) {
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}

Arbin BuildArbin(Elem arr[], int n, int actPos) {

    int LchildPos = actPos + actPos + 1;
    int RchildPos = LchildPos + 1;

    // if it doesn't have any children
    if (LchildPos >= n)
        return createArbin(arr[actPos]);

    if (RchildPos >= n)
        return createArbin(arr[actPos], BuildArbin(arr, n, LchildPos));

    return createArbin(arr[actPos], BuildArbin(arr, n, LchildPos), BuildArbin(arr, n, RchildPos));

}

void heapSort(Elem arr[], int n) {
    Heap h = consHeap(BuildArbin(arr, n, 0));

    while (true) {
        // printBfs(h);
        cout << value(h) << endl;
        h = deleteTop(h);
        if (!h)
            break;
    }
}


int main () {
    int n;
    cin >> n;
    Elem arr[n];
    RecibeElems(arr, n);


    heapSort(arr, n);



    // Arbin a = BuildArbin(arr, n, 0);
    // cout << "=======" << endl;
    // printBfs(a);
    // cout << "......." << endl;
    // Heap h = consHeap(a);
    // printBfs(h);
    return 0;
}
