// Ingresar una serie de numeros y luego mostrar el promedio y todos los numeros superiores al promedio calculado. 
// Suponer que no se ingresan mas de 100 numeros. La carga finaliza cuando se ingrese el numero cero

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

float CalcularPromedio(TVEC vector, int ML)
{
    float promedio;
    int x, suma = 0;

    for (x = 0; x < ML; x++)
    {
        suma += vector[x];
    }

    if (ML > 0)
    {
        promedio = suma / ML;
    }

    return promedio;
}

void MostrarNumerosMayores(TVEC vector, int ML, float promedio)
{
    int x;
    for (x = 0; x < ML; x++)
    {
        if (vector[x] > promedio)
            {
                printf("El numero %i es superior al promedio\n", vector[x]);
            }
    }
}


int main()
{
    TVEC vector;
    int ML = 0;
    float promedio;

    CargarVector(vector, &ML);

    promedio = CalcularPromedio(vector, ML);
    printf("El promedio de la serie de numeros es %0.2f\n", promedio);

    MostrarNumerosMayores(vector, ML, promedio);

    return 0;
}