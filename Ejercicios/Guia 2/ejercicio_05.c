// Escribir una función que dados a y b ambos de tipo entero devuelva a ^ b de tipo double para los siguientes casos 
// (no se puede utilizar ninguna biblioteca de funciones matemáticas). Implementar una solución iterativa.

#include <stdio.h>

double potencia(int numero, int exponente)
{
    int x;
    double resultado = 1.0;
    if (exponente >= 0)
        for (x=1; x<=exponente; x++)
        {
            resultado = resultado * numero;
        }
    else
        {
            for (x=1; x<=(-exponente); x++)
            {
                resultado = resultado * numero;
            }
            resultado = (1.0 / resultado);
        }
    return resultado;
}