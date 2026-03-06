#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ingreso_dinamico(int *vector, int *maximo_logico)
{
    int cantidad = 0, capacidad = 5, numero;
    bool terminado = false;
    printf("Ingrese un numero (0 para terminar): ");
    scanf("%i", &numero);
    while (numero != 0 && !terminado)
    {
        cantidad++;
        if (cantidad > capacidad)
        {
            capacidad += 5;
            int *temp = realloc(vector, capacidad * sizeof(int));
            if (temp == NULL)
            {
                printf("No se pudo reservar la memoria.");
                terminado = true;
                cantidad--;
            }
            else
            {
                vector = temp;
            }
        }
        if (!terminado)
        {
            vector[cantidad - 1] = numero;
            printf("Ingrese un numero (0 para terminar): ");
            scanf("%i", &numero);
        }
    }
    *maximo_logico = cantidad;
    return vector;
}