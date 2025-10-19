// Dada una matriz cuadrada de 5x5 cargada por el usuario con números enteros, escribir un programa modular que muestre:
// a) Todos los elementos de la matriz.
// b) La suma de todos los elementos de la matriz.
// c) La suma de la diagonal principal.
// d) La suma de la diagonal secundaria.
// e) La suma de los elementos del triángulo superior.
// f) La suma de los elementos del triángulo inferior.
// g) Si es una matriz diagonal (todos los elementos por fuera de la diagonal principal son igual a cero)
// Cada módulo debe optimizar la cantidad de iteraciones a realizar.

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
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

int suma_total(mat matriz)
{
    int i, j, suma = 0;
    for (i = 0; i < MAX_FILAS; i++)
    {
        for(j = 0; j < MAX_COLUMNAS; j++)
        {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int suma_diagonal_principal(mat matriz)
{
    int i, suma_diagonal_principal = 0;
    for (i = 0; i < MAX_COLUMNAS; i++)
    {
        suma_diagonal_principal += matriz[i][i];
    }
    return suma_diagonal_principal;
}

int suma_diagonal_secundaria(mat matriz)
{
    int i, suma_diagonal_secundaria = 0;
    for (i = 0; i < MAX_FILAS; i++)
    {
        suma_diagonal_secundaria += matriz[i][MAX_FILAS-i-1];
    }
    return suma_diagonal_secundaria;
}

int suma_triangulo_superior(mat matriz)
{
    int i, j, contador = 0, suma_triangulo_superior = 0;
    for (i = 0; i < MAX_FILAS; i++)
    {
        for (j = 1 + contador; j < MAX_COLUMNAS; j++)
        {
            suma_triangulo_superior += matriz[i][j];
        }
        contador++;
    }
    return suma_triangulo_superior;
}

int suma_triangulo_inferior(mat matriz)
{
    int i, j, suma_triangulo_inferior = 0;
    for (i = 1; i < MAX_FILAS; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("num %i\n", matriz[i][j]);
            suma_triangulo_inferior += matriz[i][j];
        }
    }
    return suma_triangulo_inferior;
}

bool check_matriz_diagonal(mat matriz)
{
    bool diagonal_superior = false, diagonal_inferior = false, matriz_diagonal = false;
    int i, j, contador = 0;
    for (i = 0; i < MAX_FILAS; i++)
    {
        for (j = 1 + contador; j < MAX_COLUMNAS; j++)
        {
            if (matriz[i][j] == 0)
            {
                diagonal_superior = true;
            }
        }
        contador++;
    }
    for (i = 1; i < MAX_FILAS; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (matriz[i][j] == 0)
            {
                diagonal_inferior = true;
            }
        }
    }
    if (diagonal_inferior && diagonal_superior)
    {
        matriz_diagonal = true;
    }
    return matriz_diagonal;
}


int main()
{
    mat matriz;
    int suma, suma_diagonal_prin, suma_diagonal_secun, suma_triangulo_sup, suma_triangulo_inf;
    bool diagonal;

    cargar_matriz(matriz);
    mostrar_matriz(matriz);
    suma = suma_total(matriz);
    printf("La suma total de la matriz es: %i\n", suma);
    suma_diagonal_prin = suma_diagonal_principal(matriz);
    printf("La suma de la diagonal de la matriz es: %i\n", suma_diagonal_prin);
    suma_diagonal_secun = suma_diagonal_secundaria(matriz);
    printf("La suma de la diagonal secundaria de la matriz es: %i\n", suma_diagonal_secun);
    suma_triangulo_sup = suma_triangulo_superior(matriz);
    printf("La suma del triangulo superior de la matriz es: %i\n", suma_triangulo_sup);
    suma_triangulo_inf = suma_triangulo_inferior(matriz);
    printf("La suma del triangulo inferior de la matriz es: %i\n", suma_triangulo_inf);
    diagonal = check_matriz_diagonal(matriz);
    if (diagonal)
    {
        printf("La matriz ingresada es diagonal.");
    }
    else
    {
        printf("La matriz ingresada no es diagonal.");
    }
    return 0;
}