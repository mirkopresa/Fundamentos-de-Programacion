// Escribir una función que reciba un valor y calcule el factorial del mismo.
// No debe imprimir el valor, debe solamente devolverlo.
// Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado. 

// Invocarla para los valores -8, 0, 1, 5; mostrando en cada caso lo que devuelve.

#include <stdio.h>

int factorial( int num_1 )
{
    int resultado = 1, x;
    if (num_1 < 0)
        resultado = 0;
    else
        {
            for (x=2; x<=num_1; x++)
            {
                resultado *= x;
            }
        }
    return resultado;
}

int main()
{
    printf("El factorial de -8 es %i\n", factorial(-8));
    printf("El factorial de 0 es %i\n", factorial(0));
    printf("El factorial de 1 es %i\n", factorial(1));
    printf("El factorial de 5 es %i\n", factorial(5));
    return 0;
}