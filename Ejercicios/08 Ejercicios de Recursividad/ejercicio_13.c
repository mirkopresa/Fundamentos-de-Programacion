// Desarrollar una función recursiva que compruebe si un número es binario. 
// Un número binario está formado únicamente por ceros y unos.

#include <stdio.h>
#include <stdbool.h>

bool es_binario(int numero)
{
    if (numero % 10 != 0 && numero % 10 != 1)
    {
        return false;
    }
    if (numero == 0 || numero == 1)
    {
        return true;
    }
    return es_binario(numero / 10);
}

int main()
{
    int numero;
    printf("Ingrese un numero binario: ");
    scanf("%i", &numero);
    if (es_binario(numero))
    {
        printf("Es binario.");
    }
    else
    {
        printf("No es binario.");
    }
    return 0;
}