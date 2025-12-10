// Desarrollar una función recursiva para realizar una búsqueda binaria en un vector.

#include <stdio.h>
#define MAX_FISICO 50
typedef int vec[MAX_FISICO];

int busqueda_binaria_recursiva(vec numeros, int inicio, int fin, int numero_buscado)
{
    if ((numero_buscado < numeros[inicio]) || (numero_buscado > numeros[fin]))
    {
        return -1;
    }
    int mitad = inicio + ((fin - inicio) / 2);
    if ((numeros[mitad] == numero_buscado))
    {
        return mitad;
    }
    if (numeros[mitad] < numero_buscado)
    {
        return busqueda_binaria_recursiva(numeros, mitad + 1, fin, numero_buscado);
    }
    return busqueda_binaria_recursiva(numeros, inicio, mitad - 1, numero_buscado);
}

int main()
{
    vec numeros = {1, 2, 34, 40, 777, 899, 1010};
    int maximo_logico = 7;
    int numero_buscado, resultado;
    printf("Ingrese un numero a buscar: ");
    scanf("%i", &numero_buscado);
    resultado = busqueda_binaria_recursiva(numeros, 0, maximo_logico - 1, numero_buscado);
    if (resultado == -1)
    {
        printf("No se encontro el numero buscado");
    }
    else
    {
        printf("Se encontro el numero buscado en la posicion %i", resultado);
    }
    return 0;
}