// Desarrollar un programa que solicite al usuario el ingreso de 2 números enteros 
// y calcule el máximo común divisor de forma recursiva.

#include <stdio.h>

int mcd(int numero_1, int numero_2)
{
    if (numero_2 == 0)
    {
        return numero_1;
    }
    return mcd(numero_2, numero_1 % numero_2);
}

int main()
{
    int numero_1, numero_2;
    printf("Ingrese el primer numero: ");
    scanf("%i", &numero_1);
    printf("Ingrese el segundo numero: ");
    scanf("%i", &numero_2);
    printf("El maximo comun divisor de %i y %i es: %i", numero_1, numero_2, mcd(numero_1, numero_2));
    return 0;
}