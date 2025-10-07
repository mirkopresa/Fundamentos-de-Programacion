// Escribir una función que dados 2 números, 
// calcule el porcentaje que el primero representa respecto del segundo.

#include <stdio.h>

float porcentaje(int numero_1, int numero_2)
{
    float resultado;
    resultado = ((float)numero_1/numero_2) * 100;
    return resultado;
}
