// Escriba una funcion en C que determine si un arreglo de enteros es capicua.
// Asumir que el maximo fisico del arreglo es 30

#include <stdio.h>
#include <stdbool.h>
#define MAXIMO_FISICO 30
typedef int vec[MAXIMO_FISICO];

bool es_capicua(vec vector, int maximo_logico)
{
    bool capicua = true;
    int i;
    i = 0;
    while (capicua && i < maximo_logico / 2)
    {
        if (vector[i] != vector[maximo_logico - 1 - i])
        {
            capicua = false;
        }
        i++;
    }
    return capicua;
}

int main()
{
    vec vector = {414, 12, 1, 11, 414};
    int maximo_logico = 5;
    if (es_capicua(vector, maximo_logico))
    {
        printf("Es capicua");
    }
    else
    {
        printf("No es capicua");
    }
    return 0;
}