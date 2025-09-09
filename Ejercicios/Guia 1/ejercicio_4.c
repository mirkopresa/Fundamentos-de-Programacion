// Calcular y mostrar la suma de los n primeros números naturales. Siendo n un
// número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2

#include <stdio.h>

int main()
{
    int numero, suma;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    suma=(numero*(numero+1) / 2);
    printf("La suma de los primeros %d numeros naturales es %d\n", numero, suma);
    return 0;
}