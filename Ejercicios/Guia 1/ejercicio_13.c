// Solicitar un número entero positivo al usuario y calcular su factorial. En el caso de
// ingresar un número negativo mostrar un mensaje que diga “no se puede calcular el factorial del número ingresado”.
// Recordar que por definición factorial(0)=1 y factorial(1)=1

#include <stdio.h>

int main()
{
    int x, numero, factorial = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    if (numero < 0)
        {
            printf("No es posible calcular el factorial del numero ingresado.");
            return -1;
        }
    for (x = 2; x<=numero; x++)
    {
        factorial *= x;
    }
    printf("El factorial de %d es %d", numero, factorial);
    return 0;
}