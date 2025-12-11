// Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras
// ingresadas por el usuario. Crear una estructura de datos dinámica de dos
// dimensiones que permita almacenar esta información. Mostrar toda la
// información de la estructura luego de haber sido cargada. Liberar toda la
// memoria al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 50

typedef char* t_palabra;
typedef t_palabra* t_vec;

int main()
{
    int cantidad_palabras;
    char palabra[MAX_STRING];
    printf("Ingrese una cantidad de palabras a ingresar: ");
    scanf("%i", &cantidad_palabras);
    t_vec palabras = malloc(cantidad_palabras * sizeof(t_palabra));
    if (palabras != NULL)
    {
        int i;
        for (i = 0; i < cantidad_palabras; i++)
        {
            printf("Palabra %i: ", i + 1);
            scanf("%s", palabra);
            palabras[i] = malloc(strlen(palabra) * sizeof(char) + 1);
            if (palabras[i] != NULL)
            {
                strcpy(palabras[i], palabra);
            }
            else
            {
                printf("No se ha podido reservar la memoria para la palabra");
            }
        }
        for (i = 0; i < cantidad_palabras; i++)
        {
            printf("%s ", palabras[i]);
            free(palabras[i]);
        }
        free(palabras);
    }
    else
    {
        printf("No se ha podido reservar la memoria.");
    }
    return 0;
}