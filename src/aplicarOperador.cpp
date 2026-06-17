#include "Interpretador.h"

double aplicarOperador(double value1, double value2, string operador) {

    if (operador == "+") {
        return value1 + value2;
    } else if (operador == "-") {
        return value1 - value2;
    } else if (operador == "*") {
        return value1 * value2;
    } else if (operador == "/") {
        return value1 / value2;
    }

    return 0;
}