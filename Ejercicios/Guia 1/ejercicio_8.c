// Ingresar un número (del 1 al 12) que representa un mes, indicar la cantidad de días de dicho mes.

#include <stdio.h>

int main()
{
    int numero;
    printf("Ingresa el numero de un mes, para saber su cantidad de dias: ");
    scanf("%i", &numero);
    if ((numero > 12) || (numero < 1))
        {
        printf("El mes que ingresaste no es valido.");
        return -1;
        }
    if (numero == 2)
        printf("El mes numero %i tiene 28 dias", numero);
    else
        if ((numero == 4) || (numero == 6) || (numero == 9) || (numero == 11))
            printf("El mes numero %i tiene 30 dias", numero);
        else
            printf("El mes numero %i tiene 31 dias", numero);
    return 0;
}