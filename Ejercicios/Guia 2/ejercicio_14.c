// Un número entero positivo se dice perfecto si es igual a la suma de todos
// sus divisores excepto él mismo. Ejemplo: los números 6, 28 y 496 son perfectos.
// (6 = 1+2+3)
// (28 = 1+2+4+7+14)
// (496 = 1+2+4+8+16+31+62+124+248)
// Se pide:
// a) Escribir una función booleana que permita discernir si un número (único parámetro) es perfecto.
// b) Dar un ejemplo de cómo se hace referencia a dicha función desde un programa o desde otro subprograma.

#include <stdio.h>
#include <stdbool.h>

bool numero_perfecto(int numero)
{
    bool perfecto = false;
    int x, suma = 0;
    for (x=1; x<numero; x++)
        {
            if ((numero % x) == 0)
                    suma += x;
        }
    if (suma == numero)
        perfecto = true;
    return perfecto;
}

int main()
{
    printf("%d", numero_perfecto(496));
    return 0;
}