// Solicitar al usuario el ingreso de una temperatura (puede tener decimales por ejemplo 24.5) 
// y la unidad en la que se encuentra (siendo solo un carácter F ó C). Luego el programa debe mostrar la temperatura ingresada
// , convertida en la otra unidad. La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula:
// C=5.0 / 9.0 * (F − 32)

#include <stdio.h>

int main()
{
    float temperatura, convertida;
    char unidad;

    printf("Ingrese una temperatura: ");
    scanf("%f", &temperatura);

    printf("Ingrese su unidad de temperatura: ");
    scanf(" %c", &unidad);

    if (unidad == 'C' || unidad == 'c')
        {
        convertida=((temperatura * 9.0/5.0) + 32);
        printf("La temperatura convertida a F es %.2f\n", convertida);
        }
    else{
        if (unidad == 'F' || unidad == 'f' )
            {
            convertida=((5.0 / 9.0) * (temperatura - 32));
            printf("La temperatura convertida a C es %.2f\n", convertida);
            }
        else
            {
            printf("La unidad ingresada no es ni C ni F");
            return -1;
            }
    }
    return 0;
}