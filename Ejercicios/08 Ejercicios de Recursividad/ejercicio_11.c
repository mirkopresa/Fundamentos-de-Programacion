// Desarrollar un programa que solicite al usuario el ingreso de 2 números A y B 
// y calcule la potencia de A elevado a la B de forma recursiva.

#include <stdio.h>

unsigned long long potencia_recursiva(int numero, int exponente)
{
    if (exponente == 0)
    {
        return 1;
    }
    return numero * potencia_recursiva(numero, exponente - 1);
}

int main()
{
    int numero, exponente;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    printf("Ingrese un exponente: ");
    scanf("%i", &exponente);
    printf("%i^%i = %llu", numero, exponente, potencia_recursiva(numero, exponente));
    return 0;
}