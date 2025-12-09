//division recursiva
#include <stdio.h>

int division_recursiva(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return 0;   
    }
    return 1 + division_recursiva(dividendo - divisor, divisor); 
}

int resto_division_recursiva(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return dividendo;
    }
    return resto_division_recursiva(dividendo - divisor, divisor);
}

int main()
{
    printf("La division de 10 por 5 es: %i\n", division_recursiva(10, 5));
    printf("El resto de dividir 10 por 4 es: %i", resto_division_recursiva(10, 4));
    return 0;
}