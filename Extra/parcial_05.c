#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
typedef int Tmatriz[MAX_FILAS][MAX_COLUMNAS];

int suma_valores_divisibles(Tmatriz matriz, int numero)
{
    int i, j, suma = 0;
    for (i = 1; i < MAX_FILAS; i++)
    {
        for (j = 0; j < i; j++)
        {
            if ((matriz[i][j] % numero) == 0)
            {
                suma += matriz[i][j];
            }
        }
    }
    return suma;
}

int main()
{
    Tmatriz matriz = {
        {30, 2, 47, 23, 11},
        {41, 11, 23, 77, 2},
        {20, 8, 22, 15, 9},
        {22, 88, 4, 2, 1},
        {9, 22, 104, 77, 100}
    };
    int numero = 2;

    printf("La suma de los numeros del triangulo inferior divisibles por %i es %i.", numero, suma_valores_divisibles(matriz, numero));
    
    return 0;
}