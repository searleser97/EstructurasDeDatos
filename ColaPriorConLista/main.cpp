#include "Lista.h"

int main() {
	srand(time(NULL));

	int n1 = 0;

	cout << "Ingrese el numero de elementos aleatorios a insertar en la cola de prioridades" << endl;
	cin >> n1;

	Lista a = consListaInt(n1, 33, 126);

	cout << endl;
	cout << "Cola ordenada por prioridades:" << endl << endl;
	impListaFull(a);

	desformar(a);
	impListaFull(a);
	cout << endl;
	cout << endl;
	desformar(a);
	impListaFull(a);
	return 0;
}
