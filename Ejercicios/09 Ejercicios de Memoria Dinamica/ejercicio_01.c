// Escribir un programa el cual reserve memoria dinámica para almacenar un
// número entero (int), le solicite al usuario el ingreso de un número y se asigna
// dicho valor en la memoria reservada, luego mostrar dicho valor por pantalla
// Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *puntero = NULL;
    puntero = malloc(sizeof(int));
    if (puntero != NULL)
    {
        printf("Ingrese un numero: ");
        scanf("%i", puntero);
        printf("Numero ingresado: %i", *puntero);
        free(puntero);
    }
    else
    {
        printf("Error al reservar espacio en la memoria.");
    }
    return 0;
}