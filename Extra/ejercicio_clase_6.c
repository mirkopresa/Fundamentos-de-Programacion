// Ingresar una serie de numeros positivos (validar) en un vector. 
// Invertir el vector y mostrar la serie invertida.

#include <stdio.h>
#define MF 10

typedef int TVEC[MF];

// falta validar

void cargarVector(TVEC vector, int* maximo_logico)
{
    int numero, contador = 0;

    printf("Ingrese un numero al vector (0 para finalizar): ");
    scanf("%i", &numero);

    while ((numero != 0) && (contador < 10))
    {
        vector[contador] = numero;
        contador++;
        printf("Ingrese un numero al vector (0 para finalizar): ");
        scanf("%i", &numero);
    }

    *maximo_logico = contador;
}

void invertirVector(TVEC vector, int maximo_logico)
{
    int x, y;
    TVEC vector_invertido;
    for (x = 0; x < maximo_logico; x++)
    {
        vector_invertido[x] = vector[maximo_logico-x-1];
    }
    for (y = 0; y < maximo_logico; y++)
    {
        vector[y] = vector_invertido[y];
    }
}

void mostrarSerieInvertida(TVEC vector, int maximo_logico)
{
    int x;
    for (x = 0; x < maximo_logico; x++)
    {
        printf("%i", vector[x]);
    }
}



int main()
{
    TVEC vector;
    int maximo_logico = 0;

    cargarVector(vector, &maximo_logico);
    invertirVector(vector, maximo_logico);
    mostrarSerieInvertida(vector, maximo_logico);

    return 0;
}
