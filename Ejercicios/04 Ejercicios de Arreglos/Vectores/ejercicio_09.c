// Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente
// y el segundo ordenado descendente, crear un nuevo vector c de longitud n + m
// elementos intercalando los elementos de a y b de modo que c quede ordenado ascendente.

#include <stdio.h>
#define MAXIMO_FISICO 10
typedef int vec[MAXIMO_FISICO];

void cargar_vector_ascendente(vec vector_1, int* maximo_logico_1)
{
    int numero_a_ingresar, numero_anterior = -99999, contador = 0;
    printf("Ingrese un numero a ingresar al vector ascendente (0 para finalizar): ");
    scanf("%i", &numero_a_ingresar);
    while (numero_a_ingresar != 0)
    {
        if (numero_a_ingresar > numero_anterior)
            {
                vector_1[contador] = numero_a_ingresar;
                numero_anterior = numero_a_ingresar;
                contador++;
            }
        else
            {
                printf("Error: Has ingresado un numero menor al anterior\n");
            }
        printf("Ingrese un numero a ingresar al vector ascendente (0 para finalizar): ");
        scanf("%i", &numero_a_ingresar);
    }
    *maximo_logico_1 = contador;
}
void cargar_vector_descendente(vec vector_2, int* maximo_logico_2)
{
    int numero_a_ingresar, numero_anterior = 9999999, contador = 0;
    printf("Ingrese un numero a ingresar al vector descendente (0 para finalizar): ");
    scanf("%i", &numero_a_ingresar);
    while (numero_a_ingresar != 0)
    {
        if (numero_a_ingresar < numero_anterior)
            {
                vector_2[contador] = numero_a_ingresar;
                numero_anterior = numero_a_ingresar;
                contador++;
            }
        else
            {
                printf("Error: Has ingresado un numero mayor al anterior\n");
            }
        printf("Ingrese un numero a ingresar al vector descendente (0 para finalizar): ");
        scanf("%i", &numero_a_ingresar);
    }
    *maximo_logico_2 = contador;
}

void intercalar_vectores(vec vector_1, vec vector_2, vec vector_intercalado, int maximo_logico_1, int maximo_logico_2, int* maximo_logico_intercalado)
{
    int x = 0, posicion_vector_1, posicion_vector_2;
    *maximo_logico_intercalado = maximo_logico_1 + maximo_logico_2;
    posicion_vector_1 = 0;
    posicion_vector_2 = maximo_logico_2 - 1;
    while (posicion_vector_1 < maximo_logico_1 && posicion_vector_2 >= 0)
    {
        if (vector_1[posicion_vector_1] <= vector_2[posicion_vector_2])
        {
            vector_intercalado[x] = vector_1[posicion_vector_1];
            posicion_vector_1++;
            x++;
        }
        else
        {
            vector_intercalado[x] = vector_2[posicion_vector_2];
            posicion_vector_2--;
            x++;
        }
    }
    while (posicion_vector_1 < maximo_logico_1)
    {
        vector_intercalado[x] = vector_1[posicion_vector_1];
        posicion_vector_1++;
        x++;
    }
    while (posicion_vector_2 >= 0)
    {
        vector_intercalado[x] = vector_2[posicion_vector_2];
        posicion_vector_2--;
        x++;
    }
    
}

void mostrar_vector(vec vector, int maximo_logico)
{
    int x;
    for (x = 0; x < maximo_logico; x++)
    {
        printf("Posicion %i: %i\n", x, vector[x]);
    }
}


int main()
{
    vec vector_1 = {0}, vector_2 = {0}, vector_intercalado;
    int maximo_logico_1, maximo_logico_2, maximo_logico_intercalado;
    cargar_vector_ascendente(vector_1, &maximo_logico_1);
    cargar_vector_descendente(vector_2, &maximo_logico_2);
    intercalar_vectores(vector_1, vector_2, vector_intercalado, maximo_logico_1, maximo_logico_2, &maximo_logico_intercalado);
    mostrar_vector(vector_intercalado, maximo_logico_intercalado);
    return 0;
}