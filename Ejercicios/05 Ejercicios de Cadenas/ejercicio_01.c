// Escribir una función que reciba como parámetro una cadena de caracteres y 
// devuelva la cantidad de dígitos numéricos que hay en la cadena

#include <stdio.h>
#include <string.h>
#define MAX 30
typedef char T_cadena[MAX];

int digitos_cadena(T_cadena cadena)
{
    int cantidad_digitos_numericos = 0, i = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
            cantidad_digitos_numericos++;
        i++;
    }
    return cantidad_digitos_numericos;
}

int main()
{
    T_cadena cadena;
    printf("Ingresa una cadena de caracteres y numeros: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
    printf("Cantidad de digitos numericos en %s: %i", cadena, digitos_cadena(cadena));
    return 0;
}