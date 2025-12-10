// Desarrollar un programa que calcule la factorial de un número en forma recursiva.

#include <stdio.h>

int factorial(int numero)
{
    if (numero == 1 || numero == 0)
    {
        return 1;
    }
    return factorial(numero - 1) * numero;
}

int main()
{
    printf("El factorial de 5 es: %i", factorial(5));
    return 0;
}