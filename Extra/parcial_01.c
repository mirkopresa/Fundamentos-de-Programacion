/*
* Desarrollar una funcion que reciba como parametros un vector de tipo Tvector ya cargado con datos que se encuentrar ordenados
* de manera ascendente, su maximo logico y un numero entero que debe ser intercalo en dicho vector de modo que este siga ordenado.
* Se espera que la funcion devuelva true si pudo realizarlo y false si no.
* Tanto el vector como el maximo logico actualizados deben devolverse sobre los parametros.
*
* Escribir un programa que invoque dicha funcion.
*
* Nota: Se solicita resolverlo recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar. 
*/

#include <stdio.h>
#include <stdbool.h>
#define MF 5
typedef int T_vector[MF];

bool intercalar_vector(T_vector vector, int* ML, int numero)
{
    bool intercalado = true;
    int i;

    if (*ML >= MF)
    {
        intercalado = false;
    }
    i = *ML - 1;
    while(intercalado && vector[i] > numero)
    {
        vector[i+1] = vector[i];
        i--;
    }
    if (intercalado)
    {
        vector[i+1] = numero;
        *ML += 1;
    }
    return intercalado;
}

void mostrar_vector(T_vector vector, int maximo_logico)
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
    T_vector vector = {1,3,7,9};
    int maximo_logico = 4, numero = 6;
    if (intercalar_vector(vector, &maximo_logico, numero))
    {
        mostrar_vector(vector, maximo_logico);
    }
    else
    {
        printf("No se ha podido intercalar.");
    }
    return 0;
}