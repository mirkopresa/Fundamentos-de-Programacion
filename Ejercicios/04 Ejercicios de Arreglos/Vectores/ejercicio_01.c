// Dado un número n entero positivo y un listado de n números reales, almacenar los números en un vector según el orden de entrada.
// Informar el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición. (1 <= n <= 100)

#include <stdio.h>
#define MAXIMO_FISICO 100

typedef int vec[MAXIMO_FISICO];

void cargar_vector(int numero, vec vector, int* maximo_logico)
{
    int x, contador = 0, numero_a_ingresar;
    for (x = 0; x < numero; x++)
    {
        printf("Ingrese un numero a introducir en el vector: ");
        scanf("%i", &numero_a_ingresar);
        vector[x] = numero_a_ingresar;
        contador++;
    }
    *maximo_logico = contador;
}

void mostrar_vector(vec vector, int maximo_logico)
{
    int x;
    printf("El vector tiene %i numeros y es:\n", maximo_logico);
    for (x = 0; x < maximo_logico; x++)
    {
        printf("%i ", vector[x]);
    }
}

int main()
{
    int numero, maximo_logico;
    vec vector;
    printf("Ingrese un numero positivo: ");
    scanf("%i", &numero);
    if (numero >= 1 && numero <= MAXIMO_FISICO)
        {
        cargar_vector(numero, vector, &maximo_logico);
        mostrar_vector(vector, maximo_logico);
        }
    else
        printf("El numero no esta entre 1 y 100.");
    return 0;
}