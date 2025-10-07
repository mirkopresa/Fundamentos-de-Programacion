// Escribir una función que reciba un valor entero y calcule el factorial del mismo. 
// Si no se puede calcular el factorial del valor recibido, 
// la función deberá devolver 0, de lo contrario deberá devolver el valor calculado.

#include <stdio.h>

int factorial( int num_1 )
{
    int resultado = 1, x;
    if (num_1 < 0)
        resultado = 0;
    else
        {
            for (x=2; x<=num_1; x++)
            {
                resultado *= x;
            }
        }
    return resultado;
}