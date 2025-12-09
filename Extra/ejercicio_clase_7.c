// Escribir un programa en C, que:
// - declare una cadena para almacenar como máximo 40 caracteres y como valor inicial le asigne tu nombre y apellido
// - recorra la cadena e imprima sólo las consonantes, una debajo de la otra
// - indique cuantas consonantes hay en tu nombre y apellido

#include <stdio.h>
#define MAX 40

int main()
{
    char cadena[MAX] = "mirko presa";
    int x = 0, consonantes = 0;
    while (cadena[x] != '\0')
    {
        if ((cadena[x] != 'a') && (cadena[x] != 'e') && (cadena[x] != 'i') && (cadena[x] != 'o') && (cadena[x] != 'u')  && (cadena[x] != ' '))
            {
                printf("%c\n", cadena[x]);
                consonantes++;
                x++;
            }
        else
            {
                x++;
            }
    }
    printf("\nCantidad de consonantes: %i", consonantes);
    return 0;
}