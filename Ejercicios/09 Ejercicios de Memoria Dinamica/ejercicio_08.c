// Implementar una función que retorna un puntero a un vector de n valores de
// tipo int, todos inicializados en cero, el cual apunta a un bloque de memoria
// dinámica, respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL.

#include <stdio.h>
#include <stdlib.h>

int *crear_vector_inicializado(int cantidad_numeros)
{
    int *vector;
    vector = malloc(cantidad_numeros * sizeof(int));
    if (vector != NULL)
    {
        int i;
        for (i = 0; i < cantidad_numeros; i++)
        {
            vector[i] = 0;
        }
    }
    return vector;
}

int main()
{
    int cantidad_numeros;
    printf("Ingrese la cantidad de numeros del vector: ");
    scanf("%i", &cantidad_numeros);
    int *vector = crear_vector_inicializado(cantidad_numeros);
    free(vector);
    return 0;
}