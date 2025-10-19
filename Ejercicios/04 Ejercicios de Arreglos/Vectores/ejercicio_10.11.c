// Dado un vector a de longitud n y un elemento p del mismo tipo que los
// elementos del vector, buscar p en el vector a y devolver la posición que ocupa
// en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
// repeticiones.

// Idem problema anterior, pero el vector está ordenado ascendente

#include <stdio.h>
#define MAXIMO_FISICO 100
typedef int vec[MAXIMO_FISICO];


void cargar_vector(vec vector, int* maximo_logico)
{
    int numero_a_ingresar, contador = 0;
    printf("Ingrese un numero a ingresar (0 para finalizar): ");
    scanf("%i", &numero_a_ingresar);
    while (numero_a_ingresar != 0)
    {
        vector[contador] = numero_a_ingresar;
        contador++;
        printf("Ingrese un numero a ingresar (0 para finalizar): ");
        scanf("%i", &numero_a_ingresar);
    }
    *maximo_logico = contador;
}

// Sirve para vectores ascendentes tambien
void buscar_numero(vec vector, int maximo_logico)
{
    int numero_a_buscar, contador = 0;
    printf("Ingrese un numero a buscar: ");
    scanf("%i", &numero_a_buscar);
    while (vector[contador] != numero_a_buscar && contador != maximo_logico)
    {
        contador++;
    }
    if (contador == maximo_logico)
    {
        printf("El numero %i no se ha encontrado.", numero_a_buscar);
    }
    else
    {
        printf("El numero %i se encuentra en la posicion %i.", numero_a_buscar, contador);
    }
}


int main()
{
    vec vector;
    int maximo_logico;

    cargar_vector(vector, &maximo_logico);
    buscar_numero(vector, maximo_logico);

    return 0;
}