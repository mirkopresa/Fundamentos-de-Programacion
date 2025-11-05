// Escribir un programa modular en C, que solicite el ingreso de 3 oraciones
// de no más de 50 caracteres cada una.  
// Luego informar: 
// 1. Cuál es la oración más larga.  
// 2. Si hay al menos 2 oraciones iguales.  
// 3. Solicitar el ingreso de una palabra o parte de una oración, e indicar si la misma se encuentra en las oraciones, y en cuales. 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 50
typedef char T_oracion[MAX];

void obtener_oracion(T_oracion oracion)
{
    printf("Ingrese una oracion de no mas de 50 caracteres: ");
    fgets(oracion, MAX, stdin);
    oracion[strcspn(oracion, "\n")] = '\0';
}

void oracion_mas_larga(T_oracion oracion_1, T_oracion oracion_2, T_oracion oracion_3)
{
    if (strlen(oracion_1) > strlen(oracion_2) && strlen(oracion_1) > strlen(oracion_3))
    {
        printf("La oracion:\n%s\n es la mas larga.\n", oracion_1);
    } else if (strlen(oracion_2) > strlen(oracion_1) && strlen(oracion_2) > strlen(oracion_3))
    {
        printf("La oracion:\n%s\n es la mas larga.\n", oracion_2);
    } else
    {
        printf("La oracion:\n%s\n es la mas larga.\n", oracion_3);
    }
}

bool oraciones_iguales(T_oracion oracion_1, T_oracion oracion_2, T_oracion oracion_3)
{
    bool oraciones_iguales = false;
    if (strcmp(oracion_1, oracion_2) == 0)
    {
        oraciones_iguales = true;
    } else if (strcmp(oracion_1, oracion_3) == 0)
    {
        oraciones_iguales = true;
    } else if (strcmp(oracion_2, oracion_3) == 0)
    {
        oraciones_iguales = true;
    }
    return oraciones_iguales;
}

void encontrar_parte_de_oracion(T_oracion oracion_1, T_oracion oracion_2, T_oracion oracion_3)
{
    T_oracion palabra;
    obtener_oracion(palabra);
    if (strstr(oracion_1, palabra) != NULL)
    {
        printf("La palabra %s se encuentra en %s.\n", palabra, oracion_1);
    }
    if (strstr(oracion_2, palabra) != NULL)
    {
        printf("La palabra %s se encuentra en %s.\n", palabra, oracion_2);
    }
    if (strstr(oracion_3, palabra) != NULL)
    {
        printf("La palabra %s se encuentra en %s.\n", palabra, oracion_3);
    }
}

int main()
{
    T_oracion oracion_1, oracion_2, oracion_3;
    obtener_oracion(oracion_1);
    obtener_oracion(oracion_2);
    obtener_oracion(oracion_3);
    oracion_mas_larga(oracion_1, oracion_2, oracion_3);
    oraciones_iguales(oracion_1, oracion_2, oracion_3);
    encontrar_parte_de_oracion(oracion_1, oracion_2, oracion_3);
    return 0;
}