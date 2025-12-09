// Escribir un programa modular que dada una matriz del tipo descrito a continuacion
// muestre el menor número que aparece y cuantas veces aparece dicho numero en la matriz

#define CANT_FILAS 3
#define CANT_COLS 3
typedef int matriz_t[CANT_FILAS][CANT_COLS];

#include <stdio.h>

void CargarMatriz(matriz_t matriz)
{
    int i, j, numero;
    for (i = 0; i < CANT_FILAS; i++)
    {
        for (j = 0; j < CANT_COLS; j++)
        {
            printf("Ingrese el valor de la fila %i, columna %i: ", i, j);
            scanf("%i", &numero);
            matriz[i][j] = numero;
        }
    }
}

int BuscarMenor(matriz_t matriz)
{
    int i, j, menor;
    menor = matriz[0][0];
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

void MostrarMenores(matriz_t matriz, int menor)
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
    printf("El numero %i aparece %i veces.", menor, contador);
}

int main()
{
    int menor;
    matriz_t matriz;
    CargarMatriz(matriz);
    menor = BuscarMenor(matriz);
    MostrarMenores(matriz, menor);
    return 0;
}