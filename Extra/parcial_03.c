#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
typedef int Tmatriz[MAX_FILAS][MAX_COLUMNAS];

void elementos_matriz(Tmatriz matriz, int filas, int columnas, int numero, int* cant_veces_numero, int* cant_numeros_mayores)
{
    int contador_numero = 0, contador_numeros_mayores = 0, i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (matriz[i][j] == numero)
                contador_numero++;
            if (matriz[i][j] > numero)
                contador_numeros_mayores++;
        }
    }
    *cant_veces_numero = contador_numero;
    *cant_numeros_mayores = contador_numeros_mayores;
}

int main()
{
    Tmatriz matriz = {
        {3, 5, 5},
        {5, 11, 37},
        {40, 5, 1}
    };
    int cant_veces_numero, cant_numeros_mayores, numero = 5;
    elementos_matriz(matriz, 3, 3, numero, &cant_veces_numero, &cant_numeros_mayores);
    printf("Cantidad de veces que %i aparece en la matriz: %i\n", numero, cant_veces_numero);
    printf("Cantidad de numeros mayores a %i: %i", numero, cant_numeros_mayores);

    return 0;
}