#include "Colac.h"



int procesa(Elem e, int timeAsigned) {
	e -> tiempo = e -> tiempo - timeAsigned;
	return e -> tiempo;
}

int main() {
	srand(time(NULL));

	int n1 = 0;
	int time = 0;
	cout << "Ingrese el numero de elementos aleatorios a insertar en la cola circular" << endl;
	cin >> n1;
	cout << "Ingrese el tiempo por defecto que se le asignara a cada proceso por iteracion" << endl;
	cin >> time;

	Colac c = randColac(n1);
	impColac(c);
	cout << endl;



	cout << "PRIMERO: ";
	impElem(primero(c));
	cout << endl;

	// c = desformar(c);
	// cout << "Se ha desformado el primer elemento con exito" << endl;

	getchar();
	// Colac c = formarC(39,formarC(38,formarC(37,formarC(36,formarC(35, nuevac())))));
	// impColac(c);

	while(true) {
		getchar();
		
		if (procesa(primero(c), time) <= 0)
			c = desformar(c);
		if (esNuevac(c))
			break;
		c = rotar(c);
		impColac(c);
	}

	cout << "Todos los procesos han finalizado con exito" << endl << endl;

	return 0;
}