// Escribir un programa que muestre las tablas de multiplicar desde la tabla del 1 hasta la
// tabla del 9 para los primeros 100 números naturales


#include <stdio.h>

int main()
{
    int numero, multiplicado, x;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);

    for (x=1; x<=10; x++)
        {
            multiplicado=(numero*x);
            printf("El numero %i multiplicado por %i es %i\n", numero, x, multiplicado);
        }
    return 0;
}