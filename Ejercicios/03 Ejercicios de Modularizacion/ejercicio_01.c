// Escribir un programa donde el usuario ingrese una secuencia de números terminada en cero y se le informe la cantidad de múltiplos de 2, 3, 5 y 7. 
// Utilizar una función que dados dos números como parámetros por valor devuelve un valor boolean que indique si el primero es o no múltiplo del segundo.

#include <stdio.h>
#include <stdbool.h>

bool es_multiplo(int numero, int multiplo)
{
    bool multiplo_valido = false;
    if ((numero % multiplo) == 0) 
    {
        multiplo_valido = true;
    }
    return multiplo_valido;
}

int main()
{
    int numero, multiplos_2 = 0, multiplos_3 = 0, multiplos_5 = 0, multiplos_7 = 0;
    printf("Ingresa una secuencia de numeros (0 para finalizar): ");
    scanf("%i", &numero);
    while (numero != 0)
    {
        if (es_multiplo(numero, 2))
        {
            multiplos_2++;
        }
        if (es_multiplo(numero, 3))
        {
            multiplos_3++;
        }
        if (es_multiplo(numero, 5))
        {
            multiplos_5++;
        }
        if (es_multiplo(numero, 7))
        {
            multiplos_7++;
        }
        printf("Ingresa una secuencia de numeros (0 para finalizar): ");
        scanf("%i", &numero);
    }

    printf("Cantidad de multiplos de 2: %i\n", multiplos_2);
    printf("Cantidad de multiplos de 3: %i\n", multiplos_3);
    printf("Cantidad de multiplos de 5: %i\n", multiplos_5);
    printf("Cantidad de multiplos de 7: %i\n", multiplos_7);

    return 0;
}