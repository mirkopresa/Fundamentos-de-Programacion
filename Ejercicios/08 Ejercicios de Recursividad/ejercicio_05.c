// Desarrollar una función recursiva para obtener el mayor valor en un vector de números enteros.

#include <stdio.h>
#define MAX_FISICO 50
typedef int vec[MAX_FISICO];

int mayor_numero_recursivo(vec numeros, int inicio, int maximo_logico, int mayor_numero)
{
    if (inicio == maximo_logico)
    {
        return mayor_numero;
    }
    if (numeros[inicio] > mayor_numero)
    {
        mayor_numero = numeros[inicio];
    }
    return mayor_numero_recursivo(numeros, inicio + 1, maximo_logico, mayor_numero);
}

int main()
{
    vec numeros = {40, 3, 77, 414, 420, 69420, 101};
    int maximo_logico = 7;
    printf("El mayor numero del vector es: %i", mayor_numero_recursivo(numeros, 1, maximo_logico, numeros[0]));
    return 0;
}