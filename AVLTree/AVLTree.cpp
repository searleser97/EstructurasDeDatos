/*
Case 1: Difference between right and left roots is just one (balance factor lesser or equal to one in all of its nodes), in all of its nodes.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    priority_queue<int> A;
    int N, K;

    cin >> N >> K;
    K = -1 * K;

    for (int i = 0; i < N; i++) {
        int aux;
        cin >> aux;
        A.push(-1 * aux);
    }

    
    int op = 0;
    while (true) {

        // cout << A.top() << " " << K << endl;
        if (A.empty()) {
            cout << "-1" << endl;
            return 0;
        }
        if (A.top() <= K) {
            break;
        }
        int lsc1 = A.top();
        A.pop();
        if (A.empty()) {
            cout << "-1" << endl;
            return 0;
        }
        int lsc2 = A.top();
        A.pop();
        A.push(lsc1 + 2 * lsc2);
        op++;
    }

    cout << op << endl;


    return 0;
}
