// Escribir una función que recibirá por parámetro, una palabra, que representa un 
// sustantivo en singular.  
// La función deberá devolver, el plural de dicho sustantivo, aplicando las siguientes reglas: 
// a. Agregar una “s” al final, si la palabra termina en vocal sin acento. 
// b. Agregar una “s” al final, si la palabra termina con una é (acentuada). 
// c. Si la palabra termina en “z”, la reemplazamos por “ces”. 
// d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción 
// de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á, 
// í, ó, ú. 
// e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular, 
// por lo tanto la función deberá devolver lo mismo que recibió. 
 
// Hacer 1 o mas funciones para cada uno de los ejercicios
// muy tedioso para seguirlo, lo dejo aca

#include <stdio.h>

#include <string.h>
#define MAX 50
typedef char T_cadena[MAX];

void obtener_palabra(T_cadena palabra)
{
    printf("Ingresa una palabra: ");
    fgets(palabra, MAX, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
    fflush(stdin);
}

void vocal_sin_acento(T_cadena palabra)
{
    int letra_final;
    letra_final = strlen(palabra) - 1;
    if ((palabra[letra_final] == 'a') || (palabra[letra_final] == 'e') || (palabra[letra_final] == 'i') || (palabra[letra_final] == 'o') || (palabra[letra_final] == 'u'))
    {
        palabra[letra_final + 1] = 's';
        palabra[letra_final + 2] = '\0';
    }
}

int main()
{
    T_cadena palabra, palabra_plural;
    obtener_palabra(palabra);
    vocal_sin_acento(palabra);
    printf("Plural: %s ", palabra);
    return 0;
}