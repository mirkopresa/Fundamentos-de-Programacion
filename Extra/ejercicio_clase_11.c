// Escribir una función que calcule el factorial de un número recibido
// por parámetro.

#include <stdio.h>

int fact( int num_1 )
{
    int resultado = 1, x;
    for (x=2; x<=num_1; x++)
        {
            resultado *= x;
        }
    return resultado;
}

int main()
{
    int numero_1, factorial;
    printf("Introduce un numero: ");
    scanf("%i", &numero_1);
    factorial = fact(numero_1);
    printf("El factorial de %i es %i", numero_1, factorial);
    return 0;
}