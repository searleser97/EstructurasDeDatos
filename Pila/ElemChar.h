typedef char Elem;

using namespace std;

void impElem (Elem e) {cout << e << endl;}

int priority(Elem c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/' || c == '%')
		return 2;
	else if (c == '^')
		return 3;
	else
		return 0;
}

int isOperator(Elem c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		return 1;
	else
		return 0;
}