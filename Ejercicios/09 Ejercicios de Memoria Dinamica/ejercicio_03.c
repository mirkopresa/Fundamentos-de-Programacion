// Asumiendo que ya existe un puntero que apuntan a un bloque de memoria
// previamente reservada con malloc de tamaño (n * int), redimensionar dicha
// memoria a un tamaño de (2 * n *int).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros, *auxiliar, cantidad_numeros;
    printf("Ingrese una cantidad de numeros a ingresar: ");
    scanf("%i", &cantidad_numeros);
    numeros = malloc(cantidad_numeros * sizeof(int));
    if (numeros != NULL)
    {
        printf("Bloque de memoria reservado con %i enteros.\n", cantidad_numeros);
        auxiliar = realloc(numeros, 2 * cantidad_numeros * sizeof(int));
        if (auxiliar != NULL)
        {
            printf("Nuevo bloque de memoria reservado con %i enteros.", cantidad_numeros * 2);
            numeros = auxiliar;
        }
        else
        {
            printf("Error al reservar el nuevo bloque de memoria.");
        }
        free(numeros);
    }
    else
    {
        printf("Error al reservar el espacio de memoria.");
    }
    return 0;
}