// Escribir una función que dados a y b devuelva el cociente de la división
// entera, sin utilizar el operador correspondiente del lenguaje. Para esta
// resolución deben considerar la utilización de restas sucesivas.

#include <stdio.h>

int cociente( int dividendo, int divisor )
{
    int cociente = 0;
    if (divisor != 0)
        while (dividendo >= divisor)
            {
                cociente++;
                dividendo-=divisor;
            }
    return cociente;
}

int main()
{
    printf("%i", cociente(100, 0));
    return 0;
}