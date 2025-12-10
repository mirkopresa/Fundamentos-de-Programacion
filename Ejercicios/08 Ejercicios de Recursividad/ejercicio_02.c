// Desarrollar un programa que calcule y muestre por pantalla 
// los primeros N términos de la sucesión de Fibonacci en forma recursiva.

#include <stdio.h>

int sucesion_fibonacci(int numero)
{
    if (numero == 0)
    {
        return 0;
    }
    if (numero == 1)
    {
        return 1;
    }
    return sucesion_fibonacci(numero - 1) + sucesion_fibonacci(numero - 2);
}

int main()
{
    printf("Sucesion de fibonacci de 14: %i", sucesion_fibonacci(14));
    return 0;
}