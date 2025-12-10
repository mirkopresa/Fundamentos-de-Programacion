// Desarrollar un programa que solicite al usuario el ingreso de un número entero y muestre el resultado de sumar sus dígitos.

#include <stdio.h>

int suma_digitos_recursivo(int numero)
{
    if (numero == 0)
    {
        return 0;
    }
    return numero % 10 + suma_digitos_recursivo(numero / 10);
}

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    printf("La suma de los digitos de %i es: %i", numero, suma_digitos_recursivo(numero));
    return 0;
}