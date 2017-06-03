#include "HashMap.h"
#include <iostream>
using namespace std;
int main () {
    HashTable ht = newHashTable(23);
    insert(ht, 100, 'a');
    insert(ht, 95, 'b');
    insert(ht, 3, 'c');
    cout << elemInKey(ht, 3) << endl;
	return 0;
}
