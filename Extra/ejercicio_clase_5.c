// Cargar 2 vectores de numeros enteros y mostrar el producto escalar


#include <stdio.h>
#define MF 100

typedef int TVEC[MF];


void CargarVector(TVEC vector, int* ML)
{
    int numero, contador = 0;

    printf("Ingrese un numero al vector (0 para finalizar): ");
    scanf("%i", &numero);

    while ((numero != 0) && (contador < 100))
    {
        vector[contador] = numero;
        contador++;
        printf("Ingrese un numero al vector (0 para finalizar): ");
        scanf("%i", &numero);
    }

    *ML = contador;
}

int CalcularProductoEscalar(TVEC vector_1, TVEC vector_2, int maximo_logico_1, int maximo_logico_2)
{
    int producto_escalar, suma = 0, x;
    if (maximo_logico_1 == maximo_logico_2)
    {
        for (x = 0; x < maximo_logico_1; x++)
        {
            producto_escalar = vector_1[x] * vector_2[x];
            suma += producto_escalar;
        }
    }
    return suma;
}


int main()
{
    TVEC vector_1, vector_2;
    int maximo_logico_1 = 0, maximo_logico_2 = 0;
    int producto_escalar;

    CargarVector(vector_1, &maximo_logico_1);
    CargarVector(vector_2, &maximo_logico_2);

    producto_escalar = CalcularProductoEscalar(vector_1, vector_2, maximo_logico_1, maximo_logico_2);
    printf("El producto escalar es %i", producto_escalar);

    return 0;
}