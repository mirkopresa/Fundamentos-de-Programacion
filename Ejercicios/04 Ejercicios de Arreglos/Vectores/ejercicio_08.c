// Dadas las siguientes declaraciones de constantes y tipos:
// #define MAX 1000 typedef int vector_t[MAX]
// Desarrollar una función en lenguaje C que reciba como parámetros un vector de tipo vector_t ya cargado y su máposicionimo lógico, que devuelva:
// - un valor de verdad que informe si el vector está ordenado ascendentemente
// - la menor diferencia entre elementos contiguos.
// Se solicita resolver lo pedido recorriendo una sola vez al vector.

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000 

typedef int vector_t[MAX];

void ascendente_y_menor_diferencia(vector_t vector, int maximo_logico)
{
    int x, posicion, menor_diferencia = 99999;
    bool ascendente = true;
    posicion = maximo_logico - 1;
    while (ascendente && (posicion > 0))
    {
        if (vector[posicion] > vector[posicion-1])
        {
            printf("verdadero %i %i \n", vector[posicion], vector[posicion-1]);
            ascendente = true;
        }
        else
            if (vector[posicion] < vector[posicion-1]) 
            {
                printf("falso %i %i \n", vector[posicion], vector[posicion-1]);
                ascendente = false;
            }
        if ((vector[posicion] - vector[posicion-1]) < menor_diferencia)
        {
            menor_diferencia = vector[posicion] - vector[posicion-1];
        }
        posicion--;
    }
    if (ascendente)
    {
        printf("El vector esta ordenado de manera ascendente.\n");
        printf("La menor diferencia entre los numeros del vector es: %i", menor_diferencia);
    }
    else
    {
        printf("El vector no esta ordenado de manera ascendente.");
    }
}

int main()
{
    vector_t vector = {15, 18, 20, 27, 28, 46, 70};
    int maximo_logico = 7;
    ascendente_y_menor_diferencia(vector, maximo_logico);
    return 0;
}


