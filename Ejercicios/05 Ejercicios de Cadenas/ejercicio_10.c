// Escribir un programa modular que solicite el ingreso de dos palabras y luego
// muestre las mismas según la longitud de cada una de ellas, mostrando primero la de menor longitud.
// A igualdad de longitud, mostrar primero la menor de las dos, en términos de
// orden alfabético.
// Las palabras tienen una longitud máxima de 15 caracteres

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 15
typedef char T_cadena[MAX];

void mostrar_palabra_por_longitud(T_cadena palabra_1, T_cadena palabra_2)
{
    if (strlen(palabra_1) == strlen(palabra_2))
    {
        if (strcmp(palabra_1, palabra_2) > 0)
        {
            printf("Primer palabra: %s\n", palabra_2);
            printf("Segunda palabra: %s", palabra_1);
        }
        else
        {
            printf("Primer palabra: %s\n", palabra_1);
            printf("Segunda palabra: %s", palabra_2);
        }
    }
    else if (strlen(palabra_1) > strlen(palabra_2))
    {
        printf("Primer palabra: %s\n", palabra_2);
        printf("Segunda palabra: %s", palabra_1);
    } 
    else
    {
        printf("Primer palabra: %s\n", palabra_1);
        printf("Segunda palabra: %s", palabra_2);
    }
}

void obtener_cadena(T_cadena cadena)
{
    printf("Ingrese una palabra: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
}

int main()
{
    T_cadena palabra_1, palabra_2;
    obtener_cadena(palabra_1);
    obtener_cadena(palabra_2);
    mostrar_palabra_por_longitud(palabra_1, palabra_2);
    return 0;
}