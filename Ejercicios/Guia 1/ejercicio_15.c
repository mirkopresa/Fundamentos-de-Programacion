// Dada una serie de números ingresados de a uno.
// Indicar mayor, menor y promedio de la serie.
// El ingreso de números finaliza cuando el usuario ingresa 0.

#include <stdio.h>

int main()
{
    int numero, mayor, menor, cantidad_numeros, total = 0, promedio;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    mayor=numero;
    menor=numero;
    while (numero !=0)
        {
        total += numero;
        cantidad_numeros++;
        if (numero > mayor)
            mayor=numero;
        if (numero < menor)
            menor=numero;
        printf("Ingrese un numero: ");
        scanf("%i", &numero);
        }
    promedio=(total / cantidad_numeros);
    printf("La serie de %i numeros tiene como mayor a %i, como menor a %i y su promedio es %i.", cantidad_numeros, mayor, menor, promedio);
    return 0;
}