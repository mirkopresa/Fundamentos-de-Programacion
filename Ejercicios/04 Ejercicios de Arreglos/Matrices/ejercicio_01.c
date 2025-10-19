// Dada una matriz de 3x4, escribir un programa que permita cargar sus datos y luego mostrarlos.

#include <stdio.h>
#define MAX_FILAS 3
#define MAX_COLUMNAS 4
typedef int mat[MAX_FILAS][MAX_COLUMNAS];

void cargar_matriz(mat matriz)
{
    int i, j, numero;
    for (i = 0; i < MAX_FILAS; i++)
        {
            for (j = 0; j < MAX_COLUMNAS; j++)
            {
                printf("Ingrese un numero a cargar en la fila %i columna %i: ", i+1, j+1);
                scanf("%i", &numero);
                matriz[i][j] = numero;
            }
        }
}

void mostrar_matriz(mat matriz)
{
    int i, j;
    for (i = 0; i < MAX_FILAS; i++)
        {
            for (j = 0; j < MAX_COLUMNAS; j++)
            {
                printf("Fila %i Columna %i: %i\n", i+1, j+1, matriz[i][j]);
            }
        }
}



int main()
{
    mat matriz;
    
    cargar_matriz(matriz);
    mostrar_matriz(matriz);

    return 0;
}