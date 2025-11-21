// Escribir un programa que dada una matriz de números reales, de n x m,
// devuelva un vector que en cada posición i almacene el elemento mínimo de
// cada fila la i de la matriz.

#include <stdio.h>

#define MAX_FILAS 100
#define MAX_COLUMNAS 100

typedef int mat[MAX_FILAS][MAX_COLUMNAS];

void numero_minimo_fila(mat matriz, int filas, int columnas)
{
    int i, j, k, menor;
    int vector[filas];
    for (i = 0; i < filas; i++)
    {
        menor = matriz[i][i];
        for (j = 0; j < columnas; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
        vector[i] = menor;
    }
    for (k = 0; k < filas; k++)
    {
        printf("En la fila %i de la matriz, el menor numero es %i\n", k, vector[k]);
    }
}

int main()
{
    int filas = 3, columnas = 4;
    mat matriz = {
        {23, 45, 2, 50},
        {32, 6, 10, 42},
        {23, 4, 34, 76}
    };

    numero_minimo_fila(matriz, filas, columnas);

    return 0;
}