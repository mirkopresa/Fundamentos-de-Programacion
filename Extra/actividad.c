// ordenar mediante el metodo de burbujeo o burbujeo optimizado los elementos de un arreglo conformado por los digitos de tu dni

#include <stdio.h>
#include <stdbool.h>
#define MF 8
typedef int vec[MF];

void metodo_ordenamiento(vec vector, int maximo_logico)
{
    int i, j, numero;
    bool intercambio = true;
    i = 1;
    while ((i < maximo_logico) && intercambio)
    {
        intercambio = false;
        for (j = 0; j < maximo_logico-1; j++)
            if (vector[j] > vector[j+1])
            {
                numero = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = numero;
                intercambio = true;
            }
        i++;
    }
}

void mostrar_vector(vec vector, int maximo_logico)
{
    int i;
    printf("El vector tiene %i numeros y es:\n", maximo_logico);
    for (i = 0; i < maximo_logico; i++)
    {
        printf("Posicion %i: %i\n", i, vector[i]);
    }
}


int main()
{
    vec digitos_dni = {4, 6, 5, 8, 1, 1, 5, 2};
    int maximo_logico = 8;
    mostrar_vector(digitos_dni, maximo_logico);
    metodo_ordenamiento(digitos_dni, maximo_logico);
    mostrar_vector(digitos_dni, maximo_logico);
    return 0;
}