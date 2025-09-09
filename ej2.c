// Solicitar al usuario el ingreso de una temperatura (puede tener decimales por ejemplo 24.5) 
// y la unidad en la que se encuentra (siendo solo un carácter F ó C). Luego el programa debe mostrar la temperatura ingresada
// , convertida en la otra unidad. La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula:
// C=5.0 / 9.0 * (F − 32)

#include <stdio.h>

int main()
{
    int numero, resultado, x;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    resultado=(numero % 10);
    printf("%i", resultado);
    return 0;
}