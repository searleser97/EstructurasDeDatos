#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Pila.h"

using namespace std;

char *infixToPostfix(char *str);

char *concat(const char *s1, char c);

int main(int argc, char* argv[]) {

    string tmp;
    cin >> tmp;
    const char* a = tmp.c_str();

    if (strcmp(a, "0") == 0) {
        char* def = "(b+(b^2-4*a*c)^(1/2))/(2*a)";
        a = concat(def, 0);
    }

    cout << "output: " << infixToPostfix((char*)a) << endl;
    return 0;
}

char *concat(const char *s1, char c) {
    char *result = (char *) malloc(strlen(s1) + 1 + 1); //+1 for the zero-terminator
    strcpy(result, s1);
    result[strlen(result)] = c;
    return result;
}

char* infixToPostfix(char* str) {

    Pila p = empty();

    char *result = "";
    int sSize = strlen(str);

    for (int i = 0; i < sSize; i++) {

        if (isOperator(str[i])) {

            if (top(p) == '(' || isempty(p))
                p = push(str[i], p);
            else {

                while (priority(str[i]) <= priority(top(p)) && !isempty(p)) {
                    result = concat(result, top(p));
                    p = pop(p);
                }
                p = push(str[i], p);
            }
        } else if (str[i] == '(')
            p = push(str[i], p);

        else if (str[i] == ')') {
            while (!isempty(p) && top(p) != '(') {
                result = concat(result, top(p));
                p = pop(p);
            }
            p = pop(p);
        } else
            result = concat(result, str[i]);
    }

    while (!isempty(p)) {
        result = concat(result, top(p));
        p = pop(p);
    }

    free(p);
    return result;
}