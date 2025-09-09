// Ingresar un número entero y decir si:
// a) es par o impar.
// b) es mayor, menor o igual a cero.

#include <stdio.h>

int main()
{
    int numero;
    printf("Ingresar un numero entero: ");
    scanf("%i", &numero);
    if ((numero % 2) == 0)
        printf("El numero %i es par.\n", numero);
    else
        printf("El numero %i es impar.\n", numero);
    if (numero > 0)
        printf("El numero %i es mayor a 0", numero);
    else
        if (numero < 0)
            printf("El numero %i es menor a 0", numero);
        else
            printf("El numero %i es igual a 0", numero);
    return 0;
}