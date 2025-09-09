// Dados a y n números enteros, informar la potencia enésima de a por productos sucesivos.

#include <stdio.h>

int main()
{
    int numero_1, potencia, x, resultado=1;
    printf("Ingrese un numero: ");
    scanf("%i", &numero_1);
    printf("Ingrese una potencia: ");
    scanf("%i", &potencia);
    for (x = 0; x<potencia; x++)
            {
            resultado*=numero_1;
            }
    printf("La potencia %i del numero %i es %i", potencia, numero_1, resultado);
    return 0;
}