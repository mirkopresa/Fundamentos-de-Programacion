// Implementar una función recursiva la cual calcule la potencia entre dos números enteros. 
// Pasa la resolución debe basarse en el algoritmo de exponenciación binaria.

#include <stdio.h>

unsigned long long potencia_exponenciacion_binaria(int numero, int exponente)
{
    if (exponente == 1)
    {
        return numero;
    }
    if (exponente == 0)
    {
        return 1;
    }
    if (exponente % 2 == 0)
    {
        return potencia_exponenciacion_binaria(numero, exponente / 2) * potencia_exponenciacion_binaria(numero, exponente / 2);
    }
    return numero * potencia_exponenciacion_binaria(numero, exponente - 1);
}

int main()
{
    int numero, exponente;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    printf("Ingrese un exponente: ");
    scanf("%i", &exponente);
    printf("%i^%i = %llu", numero, exponente, potencia_exponenciacion_binaria(numero, exponente));
    return 0;
}