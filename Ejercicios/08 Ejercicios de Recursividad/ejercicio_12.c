// Desarrollar un programa que muestre los primeros N números naturales. 
// El número N lo debe ingresar el usuario.

#include <stdio.h>

void mostrar_naturales(int numero)
{
    if (numero == 0)
    {
        return;
    }
    mostrar_naturales(numero - 1);
    printf("%i ", numero);
}

int main()
{
    int numero;
    printf("Ingrese un numero para ver los primeros N naturales: ");
    scanf("%i", &numero);
    mostrar_naturales(numero);
    return 0;
}