// Escribir una función que reciba un valor n, entero, y devuelva la suma de los valores entre 0 y n.

#include <stdio.h>

int suma_entre_valores(int numero_1)
{
    int x, resultado = 0;
    for (x=0; x<=numero_1; x++)
    {
        resultado += x;
    }
    return resultado;
}
