#include <stdio.h>
#define MAXIMO_FISICO 100
typedef int Tvector[MAXIMO_FISICO];

void cargar_vector(Tvector vector, int* maximo_logico)
{
    int contador = 0, numero;
    printf("Ingrese un numero al vector (0 para finalizar): ");
    scanf("%i", &numero);
    while (contador < 100 & numero != 0)
    {
        vector[contador] = numero;
        contador++;
        printf("Ingrese un numero al vector (0 para finalizar): ");
        scanf("%i", &numero);
    }
    printf("Has terminado de ingresar numeros.\n");
    *maximo_logico = contador;
}

void invertir_vector(Tvector vector, int maximo_logico)
{
    int inicio = 0, fin = maximo_logico - 1, numero;
    while (inicio < fin)
    {
        numero = vector[fin];
        vector[fin] = vector[inicio];
        vector[inicio] = numero;
        inicio++;
        fin--;
    }
}

void mostrar_vector(Tvector vector, int maximo_logico)
{
    int i;
    for (i = 0; i < maximo_logico; i++)
        printf("Posicion %i: %i\n", i, vector[i]);
}

int main()
{
    Tvector vector;
    int maximo_logico;
    cargar_vector(vector, &maximo_logico);
    invertir_vector(vector, maximo_logico);
    mostrar_vector(vector, maximo_logico);
    return 0;
}