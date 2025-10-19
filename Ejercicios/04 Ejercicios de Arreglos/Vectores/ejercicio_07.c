// Dado un vector a ordenado ascendente de longitud ml y un elemento p del
// mismo tipo que los elementos del vector, insertar p en el vector a de modo
// que siga ordenado. Validar previamente que en el vector haya espacio libre para guardar el nuevo dato.
// Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar.

#include <stdio.h>
#define MAXIMO_FISICO 10
typedef int vec[MAXIMO_FISICO];


void insertar_vector(vec vector, int* maximo_logico)
{
    int numero_a_insertar, posicion_a_insertar = 0, x;
    printf("Ingresa un numero a insertar: ");
    scanf("%i", &numero_a_insertar);
    if (*maximo_logico < MAXIMO_FISICO)
        {
            posicion_a_insertar = *maximo_logico - 1;
            while (posicion_a_insertar >= 0 && vector[posicion_a_insertar] > numero_a_insertar)
            {
                vector[posicion_a_insertar+1] = vector[posicion_a_insertar];
                posicion_a_insertar--;
            }
            *maximo_logico += 1;
            vector[posicion_a_insertar + 1] = numero_a_insertar;
            printf("Se inserto correctamente.\n");
        }
    else
        {
            printf("El vector no tiene espacio.");
        }
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
    vec vector = {3, 6, 9, 16, 21, 45}; // Vector del ejemplo
    int maximo_logico = 6; // Suponiendo que nos lo dan fijo (no me lo piden hallar cuantos numeros tiene)
    mostrar_vector(vector, maximo_logico);
    insertar_vector(vector, &maximo_logico);
    mostrar_vector(vector, maximo_logico);
    return 0;
}