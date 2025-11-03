// Escribir una función en C, que reciba una cadena que representa una palabra o 
// una frase y devuelva si la misma es o no un palíndromo. 
// Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos. 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50
typedef char T_cadena[MAX];

void obtener_cadena(T_cadena cadena)
{
    printf("Ingresa una palabra: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
}

void cadena_solo_letras(T_cadena cadena, T_cadena solo_letras)
{
    int i = 0, j = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
            solo_letras[j] = cadena[i];
            j++;
        }
        i++;
    }
    solo_letras[j] = '\0';
}

bool es_palindromo(T_cadena cadena)
{
    T_cadena solo_letras;
    bool palindromo = true;
    int inicio = 0;
    cadena_solo_letras(cadena, solo_letras);
    int fin = strlen(solo_letras) - 1;
    while (inicio < fin && palindromo)
    {
        if (solo_letras[inicio] != solo_letras[fin])
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
        printf("La frase %s es palindromo", cadena);
    else
        printf("La frase %s no es palindromo", cadena);
    return 0;
}