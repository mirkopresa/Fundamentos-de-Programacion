#include <stdio.h>

// permitir q usuario ingrese los valores

void cargarValores(int matriz[3][3], int filas, int columnas)
{
    int i, j, numero;
    for (i=0; i < filas; i++)
    {
        for (j=0; j < columnas; j++)
        { 
            printf("Ingrese el valor de la fila %i, columna %i: ", j, i);
            scanf("%i", &numero);
            matriz[i][j] = numero;
        }
    }
}


// Declaración de la función que recibe una matriz como parámetro
void imprimirMatriz(int matriz[3][3], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int suma_diagonal(int matriz[3][3], int filas)
{
    int i, suma = 0;
    for (i = 0; i < filas; i++)
    {
        suma += matriz[i][i];
    }
    return suma;
}

int suma_diagonal_opuesta(int matriz[3][3], int filas)
{
    int i, suma = 0;
    for (i = 0; i < filas; i++)
    {
        suma += matriz[filas-1-i][i];
    }
    return suma;
}

void suma_elementos_fila(int matriz[3][3], int vector[3], int filas, int columnas)
{
    int suma_fila = 0;
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            suma_fila += matriz[i][j];
        }
        vector[i] = suma_fila;
        suma_fila = 0;
    }
}

void imprimirVector(int vector[3], int elementos)
{
    int i;
    for (i = 0; i < elementos; i++)
    {
        printf("%d ", vector[i]);
    }
}

int main() {
    // Definición de una matriz de 3x3
    int matriz[3][3] = {};
    int vector[3] = {};
    int suma, suma_inferior;

    // Cargo valores

    cargarValores(matriz, 3, 3);

    // Llamada a la función pasando la matriz como parámetro
    imprimirMatriz(matriz, 3, 3);

    // Sumo la diagonal

    suma = suma_diagonal(matriz, 3);
    printf("La suma de la diagonal de la matriz es: %i\n", suma);

    suma_inferior = suma_diagonal_opuesta(matriz, 3);
    printf("La suma de la diagonal inferior de la matriz es: %i\n", suma_inferior);

    // Creo el vector con la suma de las filas 

    suma_elementos_fila(matriz, vector, 3, 3);

    imprimirVector(vector, 3);

    return 0;
}