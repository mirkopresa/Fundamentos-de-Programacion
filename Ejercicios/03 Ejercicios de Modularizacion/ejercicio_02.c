// Generar los n (valor ingresado por el usuario) primeros números naturales 
// e informar por pantalla un listado de cada número generado junto con el factorial correspondiente. 
// Utilizar una función que dado un número devuelva su factorial.
// Validar que el número ingresado sea entero positivo, caso contrario se le debe indicar 
// al usuario que el número es incorrecto y se le solicita el ingreso nuevamente.

#include <stdio.h>
#include <stdbool.h>

int calcular_factorial(int numero)
{
    int factorial = 1;
    int i;

    for (i = 2; i <= numero; i++)
    {
        factorial *= i;
    }

    return factorial;
}

bool validar_entero(int numero)
{
    bool entero_positivo = false;
    if (numero > 0)
    {
        entero_positivo = true;
    }
    return entero_positivo;
}

int main()
{
    int numero, contador;
    printf("Ingresa un numero: ");
    scanf("%i", &numero);

    if (validar_entero(numero))
    {
        contador = 1;
        while (contador != numero+1)
        {
            printf("Numero %i - Factorial %i\n", contador, calcular_factorial(contador));
            contador++;
        }
    }
    else
    {
        printf("El numero ingresado no es valido.");
    }

    return 0;
}