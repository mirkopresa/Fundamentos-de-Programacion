// Escribir un programa modular en C, que solicite el ingreso de 1 oración, de no más de 100 caracteres.  
// Luego informar la cantidad de vocales minúsculas, no acentuadas, que hay en la oración.

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef char T_oracion[MAX];

void obtener_oracion(T_oracion oracion)
{
    printf("Ingrese una oracion de no mas de 100 caracteres: ");
    fgets(oracion, MAX, stdin);
    oracion[strcspn(oracion, "\n")] = '\0';
}

int cantidad_vocales(T_oracion oracion)
{
    int contador = 0, i = 0;
    while (oracion[i] != '\0')
    {
        if (oracion[i] == 'a' || oracion[i] == 'e' || oracion[i] == 'i' || oracion[i] == 'o' || oracion[i] == 'u')
        {
            contador++;
        }
        i++;
    }
    return contador;
}

int main()
{
    T_oracion oracion;
    obtener_oracion(oracion);
    printf("La cantidad de vocales de %s es: %i", oracion, cantidad_vocales(oracion));
    return 0;
}