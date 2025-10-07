// Cargar una serie de números reales positivos en un vector. 
// No se conoce la cantidad exacta de datos, pero se sabe que no superan los 100. 
// La serie finaliza cuando se ingresa cero. 
// Informar el valor máximo, la cantidad de veces que aparece y la/s posición/es que ocupa.

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


void numero_maximo(vec vector, int maximo_logico)
{
    int x, y, maximo = 0, cantidad = 0;
    for (x = 0; x < maximo_logico; x++)
    {
        if (vector[x] > maximo)
        {
            maximo = vector[x];
        }
    }
    printf("El valor maximo es %i y ocupa las posiciones:\n", maximo);
    for (y = 0; y < maximo_logico; y++)
    {
        if (vector[y] == maximo)
        {
            printf("Posicion %i: %i\n", y, vector[y]);
            cantidad++;
        }
    }
    printf("El numero maximo aparece %i veces.", cantidad);
}


int main()
{
    vec vector;
    int maximo_logico;
    cargar_vector(vector, &maximo_logico);
    numero_maximo(vector, maximo_logico);
    return 0;
}