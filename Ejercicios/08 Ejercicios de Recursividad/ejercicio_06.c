// Desarrollar un programa que solicite al usuario el ingreso de un número entero 
// y lo muestre invertido. No se puede utilizar vectores.

#include <stdio.h>

// Primera manera
int numero_invertido_recursivo(int numero, int numero_invertido)
{
    if (numero == 0)
    {
        return numero_invertido;
    }
    return numero_invertido_recursivo(numero / 10, numero_invertido * 10 + numero % 10);
}

// Segunda manera
int numero_invertido_recursivo_2(int numero)
{
    if (numero == 0)
    {
        return 0;
    }
    printf("%i", numero % 10);
    return numero_invertido_recursivo_2(numero / 10);
}

int main()
{
    int numero_a_invertir = 377141;
    printf("El numero invertido es %i\n", numero_invertido_recursivo(numero_a_invertir, 0));
    numero_invertido_recursivo_2(numero_a_invertir);
    return 0;
}