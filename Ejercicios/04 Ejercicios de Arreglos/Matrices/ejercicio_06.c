// Dadas dos matrices A y B, tales que A∈Rm×n y B∈Rq×p , escribir un programa que permita cargar sus dimensiones y sus datos. 
// El programa debe multiplicarlas (A.B) en caso de ser posible o devolver una señal si la operación no puede realizarse. 
// Para la estructura de datos considere un tamaño máximo de 10 (m, n y p pueden tomar valores entre 1 y 10). 
// Aclaración: para multiplicar matrices, la primera matriz debe tener igual columnas que fi las tenga la segunda (n = q). La matriz resultante será C∈Rm×p

#include <stdio.h>
#include <stdbool.h>
#define MAX 10
typedef int mat[MAX][MAX];


void cargar_matriz(mat matriz, int* filas, int* columnas)
{
    int i, j, numero, matriz_filas, matriz_columnas;
    printf("Ingrese la cantidad de filas de la matriz: ");
    scanf("%i", &matriz_filas);
    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%i", &matriz_columnas);
    for (i = 0; i < matriz_filas; i++)
    {
        for (j = 0; j < matriz_columnas; j++)
        {
            printf("Ingrese el numero a ingresar en la fila %i columna %i: ", i+1, j+1);
            scanf("%i", &numero);
            matriz[i][j] = numero;
        }
    }
    *filas = matriz_filas;
    *columnas = matriz_columnas;
}

bool multiplicar_matrices(mat matriz_1, mat matriz_2, mat matriz_resultante, int filas_1, int filas_2, int* filas_resultante, int columnas_1, int columnas_2, int* columnas_resultante)
{
    int i, j, k, multiplicado = false;
    if (columnas_1 == filas_2)
        {
            *filas_resultante = filas_1; 
            *columnas_resultante = columnas_2;
            for (i = 0; i < *filas_resultante; i++)
            {
                for (j = 0; j < *columnas_resultante; j++)
                {
                    matriz_resultante[i][j] = 0;
                    for (k = 0; k < columnas_1; k++)
                    {
                        matriz_resultante[i][j] += matriz_1[i][k] * matriz_2[k][j];
                    }
                }
            }
            multiplicado = true;   
        }
    else
    {
        printf("No se ha podido multiplicar las matrices.");
    }
    return multiplicado;
}

void mostrar_matriz(mat matriz, int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
        {
            for (j = 0; j < columnas; j++)
            {
                printf("Fila %i Columna %i: %i\n", i+1, j+1, matriz[i][j]);
            }
        }
}

int main()
{
    mat matriz_1, matriz_2, matriz_resultante;
    int filas_1, filas_2, filas_resultante, columnas_1, columnas_2, columnas_resultante;
    bool multiplicado;
    cargar_matriz(matriz_1, &filas_1, &columnas_1);
    cargar_matriz(matriz_2, &filas_2, &columnas_2);
    multiplicado = multiplicar_matrices(matriz_1, matriz_2, matriz_resultante, filas_1, filas_2, &filas_resultante, columnas_1, columnas_2, &columnas_resultante);
    if (multiplicado)
        {
            mostrar_matriz(matriz_resultante, filas_resultante, columnas_resultante);
        }
}