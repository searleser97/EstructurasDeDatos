#include "Colac.h"
//#include <unistd.h>

// int procesa(Elem e, int timeAsigned) {
// 	e -> tiempo = e -> tiempo - timeAsigned;
// 	return e -> tiempo;
// }

void duerme(int mss) {
	mss = mss/2;
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			for (int k = 0; k < mss; ++k)
			{
				int h = 0;
			}
		}
	}
}

int procesa(Elem e, int timeAsigned) {
	for (int i = 0; i < timeAsigned; ++i)
	{
		e -> tiempo = e -> tiempo - 1;
		cout << "=" << flush;
		// sleep(1);
		duerme(500);
		if (e -> tiempo <= 0) break;
	}
	cout << endl << flush;
	return e -> tiempo;
}

int main() {
	srand(time(NULL));

	int n1 = 0;
	int time = 0;
	cout << "Ingrese el numero de procesos aleatorios(<= 8) a insertar en la cola circular" << endl;
	cin >> n1;
	cout << "Ingrese el tiempo por defecto que se le asignara a cada proceso por iteracion" << endl;
	cin >> time;

	Colac c = randColac(n1);
	impColac(c);
	cout << endl;

	cout << "PRIMERO: ";
	impElem(primero(c));
	cout << endl << flush;

	getchar();

	cout << endl << flush;

	while(true) {
		
		impColac(c);
		if (procesa(primero(c), time) <= 0)
			c = desformar(c);
		if (esNuevac(c))
			break;
		c = rotar(c);
		
	}

	cout << "Todos los procesos han finalizado con exito" << endl << endl;

	return 0;
}