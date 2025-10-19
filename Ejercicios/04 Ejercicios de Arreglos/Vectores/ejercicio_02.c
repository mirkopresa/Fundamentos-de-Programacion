// Dado un listado de números reales del cual no se conoce la cantidad, almacenar los números en un vector en el orden de entrada.
// Informar la cantidad de números y el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición.
// Considerar una estructura de datos de tamaño físico máximo de 1000 posiciones.

#include <stdio.h>
#define MAXIMO_FISICO 1000

typedef int vec[MAXIMO_FISICO];

void cargar_vector(vec vector, int* maximo_logico)
{
    int contador = 0, numero_a_ingresar;
    printf("Ingrese un numero a introducir en el vector (0 para finalizar): ");
    scanf("%i", &numero_a_ingresar);
    while (numero_a_ingresar != 0)
    {
        vector[contador] = numero_a_ingresar;
        contador++;
        printf("Ingrese un numero a introducir en el vector (0 para finalizar): ");
        scanf("%i", &numero_a_ingresar);
    }
    *maximo_logico = contador;
}

void mostrar_vector(vec vector, int maximo_logico)
{
    int x;
    printf("El vector tiene %i numeros y es:\n", maximo_logico);
    for (x = 0; x < maximo_logico; x++)
    {
        printf("Posicion %i: %i\n", x, vector[x]);
    }
}

int main()
{
    int maximo_logico;
    vec vector;

    cargar_vector(vector, &maximo_logico);
    mostrar_vector(vector, maximo_logico);
    
    return 0;
}