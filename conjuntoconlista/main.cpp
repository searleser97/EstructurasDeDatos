#include <iostream>
#include "conjunto.h"

using namespace std;

int main() {
	srand(time(NULL));

	int n1 = 0;
	int n2 = 0;

	cout << "Ingrese el numero de elementos aleatorios de la lista a" << endl;
	cin >> n1;
	cout << "Ingrese el numero de elementos aleatorios de la lista b" << endl;
	cin >> n2;
	Conj a = (Conj) consListaInt(n1, 1, 9);
	Conj b = (Conj) consListaInt(n2, 1, 9);
	cout << endl;
	cout << "cardinalidad a: " << cardinalidad(a) << endl;
	cout << "cardinalidad b: " <<cardinalidad(b) << endl;
	cout << endl;
	impC(a);
	cout << "----" << endl;
	impC(b);
	cout << endl;
	a = elimina(cabeza(resto(a)), a);
	cout << "elmina segundo elemento" << endl;
	impC(a);
	cout << endl;
	Conj u = une(a, b);
	cout << "a + b" << endl;
	impC(u);

	cout << "a ^ b" << endl;
	Conj ab = interseccion(a, b);
	impC(ab);

	cout << "a - b" << endl;
	Conj dif = diferencia(a, b);
	impC(dif);

	return 0;
}
