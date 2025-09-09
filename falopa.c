// Escribir un programa en C que calcule y muestre la suma de los n primeros números naturales. 
// Siendo n un número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2
// Realizar una prueba ingresando tu  número de legajo.

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