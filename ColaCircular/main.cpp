#include "Colac.h"

int main() {
	srand(time(NULL));

	int n1 = 0;
	cout << "Ingrese el numero de elementos aleatorios a insertar en la cola circular" << endl;
	cin >> n1;
	Colac c = randColac(n1);
	impColac(c);
	cout << endl;

	cout << "primero: " << primero(c) << endl;
	c = desformar(c);
	cout << "Se ha desformado el primer elemento con exito" << endl;

	getchar();
	// Colac c = formarC(39,formarC(38,formarC(37,formarC(36,formarC(35, nuevac())))));
	// impColac(c);

	while(true) {
		getchar();
		c = rotar(c);
		impColac(c);
	}

	return 0;
}