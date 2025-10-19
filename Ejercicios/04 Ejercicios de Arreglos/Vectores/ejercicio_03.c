// Dado un listado de valores numéricos i y x, donde i es un entero mayor que 0 y menor o igual 999, 
// y x un número real, almacenar x en la posición i de un vector. 
// El listado no se ingresa ordenado por posición. Informar la cantidad de números y 
// el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición. 
// Omitir las posiciones que no contengan valor.
// Considerar una estructura de datos de tamaño físico máximo de 1000 posiciones.

#include <stdio.h>
#define MAXIMO_FISICO 1000

typedef int vec[MAXIMO_FISICO];

void cargar_vector(vec vector)
{
    int posicion, numero_a_ingresar;
    printf("Ingrese la posicion que deseas ingresar (numero mayor o igual a 1 y menor o igual a 999) (0 para finalizar): ");
    scanf("%i", &posicion);
    while (posicion != 0)
        {
            if (posicion > 0 && posicion <= MAXIMO_FISICO-1)
                {
                    printf("Ingrese un numero a introducir en el vector: ");
                    scanf("%i", &numero_a_ingresar);
                    vector[posicion] = numero_a_ingresar;
                    printf("Ingrese la posicion que deseas ingresar (numero mayor o igual a 1 y menor o igual a 999) (0 para finalizar): ");
                    scanf("%i", &posicion);
                }
        else
            {
                printf("El numero no esta entre 1 y 999.");
            }
        }
}

void mostrar_vector(vec vector)
{
    int x, contador = 0;
    for (x = 0; x < MAXIMO_FISICO; x++)
    {
        if (vector[x] != 0)
        {
            printf("Posicion %i: %i\n", x, vector[x]);
            contador++;
        }
    }
    printf("El vector tiene %i numeros.", contador);
}

int main()
{
    vec vector = {0};
    cargar_vector(vector);
    mostrar_vector(vector);
    return 0;
}