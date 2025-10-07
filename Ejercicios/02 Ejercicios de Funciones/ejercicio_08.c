// Escribir una función que dados a y b devuelva el resto de la división entera,
// sin utilizar el operador correspondiente de lenguaje. 
// Para esta resolución deben considerar la utilización de restas sucesivas.

#include <stdio.h>

int resto( int dividendo, int divisor )
{
    if (divisor != 0)
        while (dividendo >= divisor)
            {
                dividendo-=divisor;
            }
    return dividendo;
}