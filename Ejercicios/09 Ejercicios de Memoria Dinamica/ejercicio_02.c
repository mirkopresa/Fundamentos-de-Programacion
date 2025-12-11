// Escribir un programa el cual reserve memoria dinámica para almacenar una
// cierta cantidad de números enteros (n * int), este valor n debe ser ingresado por
// el usuario. Luego solicitarle que ingresé n valores enteros ingresados de a uno y
// almacenarlos en la memoria previamente reservada. Mostrar luego todos los
// valores ingresados. Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros, cantidad_numeros;
    printf("Ingrese la cantidad de numeros a ingresar: ");
    scanf("%i", &cantidad_numeros);
    numeros = malloc(cantidad_numeros * sizeof(int));
    if (numeros != NULL && cantidad_numeros > 0)
    {
        int i;
        for (i = 0; i < cantidad_numeros; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%i", &numeros[i]); // o numeros + i
        } 
        for (i = 0; i < cantidad_numeros; i++)
        {
            printf("Numero %i: %i\n", i + 1, numeros[i]); // o *(numeros + i)
        }
        free(numeros);
    }
    else
    {
        printf("Error al reservar el espacio en la memoria.");
    }
    return 0;
}