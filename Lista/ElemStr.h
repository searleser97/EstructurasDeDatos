#include <cstring>
typedef char* Elem;

using namespace std;

void impElem (Elem e) {cout << e << endl;}
int igualesElem (Elem e1, Elem e2) {return strcmp(e1, e2) == 0;}
int esMenor (Elem e1, Elem e2) {return strcmp(e1, e2) < 0;}