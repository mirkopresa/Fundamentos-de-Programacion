// ENUNCIADO EJERCICIO: Inserción de elemento en vector
 
// Dadas las siguientes declaraciones de constantes y tipos:
// #define MAX 100
// typedef int t_vector[MAX]

// Desarrollar una funcion en lenguaje C que reciba tres parámetros, un vector del tipo t_vector ya cargado con datos que se encuentran en ORDEN ASCENDENTE, su máximo
// lógico y un número entero que debe ser intercalado en el vector, de modo que siga ordenado.

// Se espera que la funcion devuelva al módulo invocante true si pudo realizar lo solicitado y false si no pudo hacerlo.
// Tanto el vector como el máximo lógico actualizados deben devolverse sobre los parámetros recibidos.

// Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar.
// Escribir un programa que invoque dicha funcion.

#define MAX 100
typedef int t_vector[MAX];

#include <stdio.h>
#include <stdbool.h>

bool intercalar_numero_vector(t_vector vector, int* maximo_logico, int numero_a_intercalar)
{
    bool valido;
    int x, posicion;
    posicion = *maximo_logico;
    if (*maximo_logico >= 100)
    {
        valido = false;
    }
    else
    {
        valido = true;
    }
    if (valido)
    {
        while ((posicion > 0) && vector[posicion-1] > numero_a_intercalar)
        {
            vector[posicion] = vector[posicion - 1];
            posicion--;
        }
        vector[posicion] = numero_a_intercalar;
        *maximo_logico += 1;
    }
    return valido;
}

void mostrar_vector(t_vector vector, int maximo_logico)
{
    int x;
    for (x = 0; x < maximo_logico; x++)
    {
        printf("Posicion %i: %i\n", x, vector[x]);
    }
}

int main()
{
    t_vector vector = {3, 4, 7, 9, 13};
    int numero, maximo_logico;
    bool validez;
    numero = 4;
    maximo_logico = 5;
    validez = intercalar_numero_vector(vector, &maximo_logico, numero);
    printf("Validez: %i\n", validez);
    if (validez)
        mostrar_vector(vector, maximo_logico);
    return 0;
}