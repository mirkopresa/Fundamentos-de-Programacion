// Escribir una función que reciba como parámetro una cadena de caracteres y 
// devuelva la cantidad de caracteres no alfabéticos que hay en la cadena. 
// No tener en cuenta la ñ, ni las vocales acentuadas. 

#include <stdio.h>
#include <string.h>
#define MAX 30
typedef char T_cadena[MAX];

int caracteres_no_alfabeticos(T_cadena cadena)
{
    int i = 0, cantidad_caracteres = 0;
    while (cadena[i] != '\0')
    {
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')))
            cantidad_caracteres++;
        i++;
    }
    return cantidad_caracteres;
}

int main()
{
    T_cadena cadena;
    printf("Ingresa una cadena de caracteres y numeros: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
    printf("Cantidad de caracteres no alfabeticos en %s: %i", cadena, caracteres_no_alfabeticos(cadena));
    return 0;
}