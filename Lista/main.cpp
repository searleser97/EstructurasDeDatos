#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
	srand(time(NULL));

	// int n1 = 0;
	// int n2 = 0;

	// cout << "Ingrese el numero de elementos aleatorios de la lista a" << endl;
	// cin >> n1;
	// cout << "Ingrese el numero de elementos aleatorios de la lista b" << endl;
	// cin >> n2;
	// Lista a = consListaInt(n1, 1, 1000);
	// Lista b = consListaInt(n2, 1, 1000);

	Lista a = cons("holo", vacia());
	Lista b = cons("hola", vacia());

	Lista pegadas = pegaListas(a, b);
	impLista(pegadas);
	cout << "----" << endl;
	impLista(invierteLista(pegadas));
	cout << "----" << endl;
	cout << "sonIguales: " << sonIguales(a, b) << endl;
	cout << "sonIguales: " << sonIguales(a, a) << endl;
	cout << "sonIguales: " << sonIguales(b, b) << endl;
	cout << "lista ordenada" << endl;
	impLista(ordena(pegadas));
	return 0;
}
