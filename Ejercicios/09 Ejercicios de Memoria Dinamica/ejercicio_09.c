// Reservar memoria para almacenar una palabra ingresada por el usuario, es
// leída en una cadena auxiliar, luego copiada a memoria dinámica, recordando
// que se requiere adicionar un carácter de fin de cadena '\n'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 50

int main()
{
    char *cadena, cadena_auxiliar[MAX_STRING];
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena_auxiliar, MAX_STRING, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    cadena = malloc(strlen(cadena_auxiliar) * sizeof(char) + 1);
    if (cadena != NULL)
    {
        strcpy(cadena, cadena_auxiliar);
        printf("Cadena: %s", cadena);
        free(cadena);
    }
    else
    {
        printf("Error al reservar la memoria.");
    }
    return 0;
}