// Escribir una función que reciba dos valores enteros y devuelva la suma de los valores entre el menor y el mayor de dichos números, incluídos.
// No debe imprimir el valor, debe solamente devolverlo.

// Invocarla para los valores (-2, 2); (5, -10); (0, -4); (10, 15) y (-3, -25); mostrando en cada caso lo que devuelve.

#include <stdio.h>

int suma_valores( int numero_1, int numero_2 )
{
    int suma = 0, mayor, menor, x;
    if (numero_1 > numero_2)
        {
        mayor = numero_1;
        menor = numero_2;
        }
    else
        {
        mayor = numero_2;
        menor = numero_1;
        }
    for (x=menor; x<=mayor; x++)
        {
            suma += x;
        }
    return suma;
}

int main()
{
    printf(suma_valores(-2, 2));
    printf(suma_valores(5, -10));
    printf(suma_valores(0, -4));
    printf(suma_valores(10, 15));
    printf(suma_valores(-3, -25));
    return 0;
}