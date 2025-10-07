// Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que
// trabajó en el mes y el valor de la hora. Mostrarle el resultado al usuario con un mensaje adecuado.

#include <stdio.h>

int main()
{
    float valor_hora, sueldo;
    int horas;
    printf("Ingrese la cantidad de horas trabajadas en el mes: ");
    scanf("%i", &horas);
    printf("Ingrese el valor de la hora: ");
    scanf("%f", &valor_hora);
    sueldo=(horas * valor_hora);
    printf("Has trabajado %i horas, y tu sueldo total es: $%.2f ", horas, sueldo);
    return 0;
}