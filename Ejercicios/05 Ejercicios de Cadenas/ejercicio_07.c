// Escribir una función en C, que reciba una cadena que representa una palabra y 
// devuelva si la misma es o no un palíndromo. 
// Una palabra es un palíndromo, si se lee igual en ambos sentidos. 
// Evitar realizar ciclos innecesarios.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20
typedef char T_cadena[MAX];

void obtener_cadena(T_cadena cadena)
{
    printf("Ingresa una palabra: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
}

bool es_palindromo(T_cadena cadena)
{
    bool palindromo = true;
    int inicio = 0, fin = strlen(cadena) - 1;
    while (inicio < fin && palindromo)
    {
        if (cadena[inicio] != cadena[fin])
            palindromo = false;
        inicio++;
        fin--;
    }
    return palindromo;
}


int main()
{
    T_cadena cadena;
    obtener_cadena(cadena);
    if (es_palindromo(cadena))
        printf("La palabra %s es palindromo", cadena);
    else
        printf("La palabra %s no es palindromo", cadena);
    return 0;
}