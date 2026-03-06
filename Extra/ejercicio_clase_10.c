// ENUNCIADO EJERCICIO: Matriz Numeros Existentes

// Implementar la función ejercicio_3 que reciba una matriz cargada con números enteros entre 0 y 100, y el máximo lógico de filas y el de columnas de ésta.
// La función debe mostrar por pantalla los numeros que se encuentran presentes en la matriz y la cantidad de apariciones de cada uno de ellos.

// Considerar que solo se puede recorrer una vez la matriz. Está permitida la utilización de un vector auxiliar.

// Por ejemplo:
// se tiene la siguiente matriz de 3x3
// {
//   {56, 89, 56},
//   {78, 23, 11},
//   {75, 56, 11}
// }

// El resultado debe ser:
// 11 -> 2
// 23 -> 1
// 56 -> 3
// 75 -> 1
// 87 -> 1
// 89 -> 1

#include <stdio.h>
#define FILAS 100
#define COLUMNAS 100

typedef int tipo_matriz[FILAS][COLUMNAS];

void ejercicio_3(tipo_matriz matriz, int filas, int columnas)
{
    int i, j, k, numero, contador[101] = {0};
  
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            numero = matriz[i][j];
            contador[numero]++;
        }
    }

    for(k = 0; k < 100; k++)
    {
        if (contador[k] > 0)
        {
            printf("%i -> %i\n", k, contador[k]);
        }
    }

}

int main()
{
    tipo_matriz matriz = {
        {56, 89, 56},
        {78, 23, 11},
        {75, 56, 11}
    };
    int maximo_logico_filas = 3, maximo_logico_columnas = 3;

    ejercicio_3(matriz, maximo_logico_filas, maximo_logico_columnas);

    return 0;
}