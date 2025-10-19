// Dadas dos matrices A y B cuadradas de igual dimensión, tales que A∈Rn×n y B∈Rn×n , 
// escribir un programa que permita cargar su dimensión y sus datos. 
// El programa debe sumarlas y mostrar la matriz resultante. 
// Para la estructura de datos considere un tamaño máximo de 10 (1 <= n <= 10).

#include <stdio.h>
#define DIMENSION 10
typedef int mat[DIMENSION][DIMENSION];

void cargar_matriz_cuadrada(mat matriz, int* dimension)
{
    int i, j, numero, dimension_matriz;
    printf("Ingrese la dimension de la matriz cuadrada (numero del 1 al 10): ");
    scanf("%i", &dimension_matriz);
    for (i = 0; i < dimension_matriz; i++)
    {
        for (j = 0; j < dimension_matriz; j++)
        {
            printf("Numero a ingresar en la fila %i columna %i: ", i, j);
            scanf("%i", &numero);
            matriz[i][j] = numero;
        }
    }
    *dimension = dimension_matriz;
}

void suma_matrices_cuadradas(mat matriz_a, mat matriz_b, mat matriz_resultante, int dimension)
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matriz_resultante[i][j] = matriz_a[i][j] + matriz_b[i][j];
        }
    }
}

void mostrar_matriz(mat matriz, int dimension)
{
    int i, j;
    for (i = 0; i < dimension; i++)
        {
            for (j = 0; j < dimension; j++)
            {
                printf("Fila %i Columna %i: %i\n", i+1, j+1, matriz[i][j]);
            }
        }
}

int main()
{
    mat matriz_a, matriz_b;
    mat matriz_resultante;
    int dimension_a, dimension_b;

    cargar_matriz_cuadrada(matriz_a, &dimension_a);
    cargar_matriz_cuadrada(matriz_b, &dimension_b);
    if (dimension_a == dimension_b)
    {
        suma_matrices_cuadradas(matriz_a, matriz_b, matriz_resultante, dimension_a);
        printf("Matriz resultante de la suma de ambas matrices: ");
        mostrar_matriz(matriz_resultante, dimension_a);
    }
    else
    {
        printf("Las matrices no cuentan con la misma dimension, entonces no se han podido sumar.");
    }

    return 0;
}