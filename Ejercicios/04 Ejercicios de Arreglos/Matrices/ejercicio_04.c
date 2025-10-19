// Escribir un programa modular que dada una matriz del tipo descrito a continuación, 
// muestre el menor número que aparece y cuantas veces aparece dicho número en la matriz.

#include <stdio.h>
#define CANT_FILAS 3 
#define CANT_COLS 3 
typedef int matriz_t[CANT_FILAS][CANT_COLS];

int menor_numero(matriz_t matriz)
{
    int menor = matriz[0][0];
    int i, j;
    for (i = 0; i < CANT_FILAS; i++)
    {
        for (j = 0; j < CANT_COLS; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }
    return menor;
}

int cantidad_menor_numero(matriz_t matriz, int menor)
{
    int i, j, contador = 0;
    for (i = 0; i < CANT_FILAS; i++)
    {
        for (j = 0; j < CANT_COLS; j++)
        {
            if (matriz[i][j] == menor)
            {
                contador++;
            }
        }
    }
    return contador;
}

int main()
{
    matriz_t matriz = {
        {5, 10, 14},
        {5, 4, 7},
        {8, 4, 12},
    };
    int menor, cantidad;

    menor = menor_numero(matriz);
    cantidad = cantidad_menor_numero(matriz, menor);
    printf("El menor numero de la matriz es %i, y aparece %i veces.", menor, cantidad);

    return 0;
}