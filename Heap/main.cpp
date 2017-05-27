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

int* heapSort(Elem arr[], int n) {
    Heap h = consHeap(BuildArbin(arr, n, 0));
    int* orderedArr = (int*) malloc(n * sizeof(int));

    for (int i = 0; h; i++) {
        // printBfs(h);
        orderedArr[i] = value(h);
        h = deleteTop(h);
    }

    return orderedArr;
}


int main () {
    int n;
    cin >> n;
    Elem arr[n];
    RecibeElems(arr, n);


    int* orderedArr = heapSort(arr, n);
    cout << orderedArr[0]<< endl;
    for (int i = 0; i < n; ++i)
    {
        cout << orderedArr[i] << " ";
    }
    cout << endl;
    return 0;
}
