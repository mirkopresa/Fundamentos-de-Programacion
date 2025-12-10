// Desarrollar un programa que muestre la suma de los primeros N números naturales. 
// El número N lo debe ingresar el usuario.

#include <stdio.h>

int suma_numeros_naturales(int numero)
{
    if (numero < 1)
    {
        return 0;
    }
    return numero + suma_numeros_naturales(numero - 1);
}

int main()
{
    int numero;
    printf("Ingrese un numero para calcular la suma de los primeros n naturales: ");
    scanf("%i", &numero);
    printf("La suma de los primeros %i naturales es: %i", numero, suma_numeros_naturales(numero));
    return 0;
}

