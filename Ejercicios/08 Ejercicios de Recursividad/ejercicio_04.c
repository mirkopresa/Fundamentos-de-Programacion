// Desarrollar un programa que calcule y muestre por pantalla 
// la división de 2 números mediante restas sucesivas en forma recursiva. 
// Ambos números deben ser ingresados por el usuario.

#include <stdio.h>

int division_recursiva(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return 0;
    }
    return 1 + division_recursiva(dividendo - divisor, divisor);
}

int main()
{
    int dividendo, divisor, resultado;
    printf("Ingresa una division en este formato (XXX / XXX): ");
    scanf("%i / %i", &dividendo, &divisor);
    resultado = (division_recursiva(dividendo, divisor));
    printf("El resultado es: %i", resultado);
    return 0;
}