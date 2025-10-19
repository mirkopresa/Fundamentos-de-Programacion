// Escribir una función en C, que reciba:
// a) como primer parámetro un vector de números enteros;
// b) como segundo parámetro, la cantidad de elementos en el vector;
// c) como tercer parámetro deberá devolver la cantidad de valores negativos que hay en el vector recibido;
// d) como cuarto parámetro, la cantidad de elementos positivos que hay en el vector recibido.

#include <stdio.h>
#define MAXIMO_FISICO 100
typedef int vec[MAXIMO_FISICO];

void cantidad_positivos_y_negativos(vec vector, int maximo_logico, int* cantidad_negativos, int* cantidad_positivos)
{
    int x, contador_negativos = 0, contador_positivos = 0;
    for (x = 0; x < maximo_logico; x++)
    {
        if (vector[x] < 0)
        {
            contador_negativos++;
        }
        else
            if (vector[x] > 0)
            {
                contador_positivos++;
            }
    }
    *cantidad_negativos = contador_negativos;
    *cantidad_positivos = contador_positivos;
}

int main()
{
    vec vector_1 = {2, 8, 1, -5, 4}, vector_2 = {-2, -15, -3}, vector_3 = {0, 0, 10, 12, 23, 55, 1};
    int cantidad_negativos, cantidad_positivos, maximo_logico;
    maximo_logico = 5;
    cantidad_positivos_y_negativos(vector_1, maximo_logico, &cantidad_negativos, &cantidad_positivos);
    printf("Negativos: %i - Positivos: %i\n", cantidad_negativos, cantidad_positivos);
    maximo_logico = 3;
    cantidad_positivos_y_negativos(vector_2, maximo_logico, &cantidad_negativos, &cantidad_positivos);
    printf("Negativos: %i - Positivos: %i\n", cantidad_negativos, cantidad_positivos);
    maximo_logico = 7;
    cantidad_positivos_y_negativos(vector_3, maximo_logico, &cantidad_negativos, &cantidad_positivos);
    printf("Negativos: %i - Positivos: %i\n", cantidad_negativos, cantidad_positivos);
    return 0;
}