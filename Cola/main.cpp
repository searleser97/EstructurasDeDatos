#include <iostream>
#include "Cola.h"
using namespace std;

int main() {
	Cola q = nueva();
	
	formar(formar(formar(formar(q, 'a'), 'b'), 'c'), 'd');

	impCola(q);

	return 0;
}