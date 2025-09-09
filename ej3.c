// Escribir un programa en C que solicite al usuario el ingreso de un número entero e informe el factorial del mismo.

#include <stdio.h>

int main()
{
    int x, numero, factorial = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    for (x = 2; x<=numero; x++)
    {
        factorial *= x;
    }
    printf("El factorial de %d es %d", numero, factorial);
}