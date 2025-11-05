// Escribir un programa modular en C, que solicite el ingreso de no más de 20 
// palabras. C 
// Cada palabra no tendrá más de 20 caracteres. Informar: 
// 1. Mostrar las palabras ingresadas. 
// 2. Cuál es la palabra más larga.  
// 3. Solictar el ingreso de una palabra, e indicar si la misma se encuentra entre  
// las ingresadas

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CARACTERES 20
#define MAX_PALABRAS 20
typedef char T_palabra[MAX_CARACTERES];
typedef T_palabra T_palabras[MAX_PALABRAS];

void obtener_palabra(T_palabra palabra)
{
    fgets(palabra, MAX_CARACTERES, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
    fflush(stdin);
}

void ingreso_palabras(T_palabras palabras, int* cantidad_palabras)
{
    T_palabra palabra;
    int i = 0;
    printf("Ingrese una palabra (X para finalizar): ");
    obtener_palabra(palabra);
    while (strcmp(palabra, "X") != 0 && i < MAX_PALABRAS-1)
    {
        strcpy(palabras[i], palabra);
        i++;
        printf("Ingrese una palabra (X para finalizar): ");
        obtener_palabra(palabra);
    }
    *cantidad_palabras = i;
}

void mostrar_palabras(T_palabras palabras, int cantidad_palabras)
{
    int i;
    for (i = 0; i < cantidad_palabras; i++)
    {
        printf("Palabra numero %i: %s\n", i+1, palabras[i]);
    }
}

bool palabra_encontrada(T_palabras palabras, int cantidad_palabras)
{
    T_palabra palabra_a_encontrar;
    int i = 0;
    bool encontrada = false;
    printf("Ingrese una palabra a encontrar en el array: ");
    obtener_palabra(palabra_a_encontrar);
    while (!encontrada && i < cantidad_palabras)
    {
        if (strcmp(palabra_a_encontrar, palabras[i]) == 0)
        {
            encontrada = true;
        }
        i++;
    }
    return encontrada;
}

int main()
{
    T_palabras palabras;
    int cantidad_palabras;
    ingreso_palabras(palabras, &cantidad_palabras);
    mostrar_palabras(palabras, cantidad_palabras);
    if (palabra_encontrada(palabras, cantidad_palabras))
    {
        printf("Se ha encontrado la palabra buscada.");
    }
    else
    {
        printf("No se ha encontrado la palabra buscada.");
    }
    return 0;
}