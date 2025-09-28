// Escribir una función, que reciba por parámetro, el valor más alto a utilizar en el cálculo (n). 
// La función debe calcular el valor de Pi utilizando la fórmula de Wallis y devolver el valor de Pi obtenido.

#include <stdio.h>

double producto_wallis(int numero)
{
    double aproximacion_pi = 1.0;
    int x;
    for (x=1; x <= numero; x++)
        aproximacion_pi *= (((2.0 * x) / (2.0 * x - 1.0)) * ((2.0 * x) / (2.0 * x + 1.0)));
    aproximacion_pi *= 2;
    return aproximacion_pi;
}