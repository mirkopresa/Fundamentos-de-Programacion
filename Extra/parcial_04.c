#include <stdio.h>
#define MF 20
typedef int Tvector[MF];

void invertir_vector(Tvector vector, int maximo_logico, int* intercambios_realizados)
{
    int posicion, numero, i = 0, intercambios = 0;
    posicion = maximo_logico - 1;

    while (i < posicion)
    {
        if (vector[posicion] != vector[i])
            {
                numero = vector[posicion];
                vector[posicion] = vector[i];
                vector[i] = numero;
                intercambios++;
            }
        posicion--;
        i++;
    }
    *intercambios_realizados = intercambios;
}

void mostrar_vector(Tvector vector, int maximo_logico)
{
    int x;
    printf("El vector tiene %i numeros y es:\n", maximo_logico);
    for (x = 0; x < maximo_logico; x++)
    {
        printf("Posicion %i: %i\n", x, vector[x]);
    }
}

int main()
{
    int intercambios_realizados, maximo_logico = 9;
    Tvector vector = {11, 20, 4, 5, 10, 11, 13, 19, 11};
    mostrar_vector(vector, maximo_logico);
    invertir_vector(vector, maximo_logico, &intercambios_realizados);
    printf("Intercambios realizados: %i\n", intercambios_realizados);
    mostrar_vector(vector, maximo_logico);
    return 0;
}