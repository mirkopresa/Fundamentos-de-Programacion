// Cargar una serie de números reales positivos en un vector. 
// No se conoce la cantidad exacta de datos, pero se sabe que no superan los 100. 
// La serie finaliza cuando se ingresa cero. Utilizar una función que invierta el contenido del vector.
// Informar el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición

#include <stdio.h>
#define MAXIMO_FISICO 100

typedef int vec[MAXIMO_FISICO];

void cargar_vector(vec vector, int* maximo_logico)
{
    int numero_a_ingresar, contador = 0;
    printf("Ingrese un numero a ingresar (0 para finalizar): ");
    scanf("%i", &numero_a_ingresar);
    while (numero_a_ingresar != 0)
    {
        vector[contador] = numero_a_ingresar;
        contador++;
        printf("Ingrese un numero a ingresar (0 para finalizar): ");
        scanf("%i", &numero_a_ingresar);
    }
    *maximo_logico = contador;
}

void invertir_vector(vec vector, int maximo_logico)
{
    int x, y;
    vec vector_invertido;
    printf("(Se invierte el vector)\n");
    for (x = 0; x < maximo_logico; x++)
    {
        vector_invertido[maximo_logico-1-x] = vector[x];
    }
    for (y = 0; y < maximo_logico; y++)
    {
        vector[y] = vector_invertido[y];
    }
}

void mostrar_vector(vec vector, int maximo_logico)
{
    int x;
    for (x = 0; x < maximo_logico; x++)
    {
        printf("Posicion %i: %i\n", x, vector[x]);
    }
}

int main()
{
    vec vector;
    int maximo_logico;
    cargar_vector(vector, &maximo_logico);
    invertir_vector(vector, maximo_logico);
    mostrar_vector(vector, maximo_logico);
    return 0;
}