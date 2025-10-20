// Escribir un programa que solicite al usuario dos números enteros positivos y determine el máximo común divisor entre dos números.

#include <stdio.h>
#include <stdbool.h>

void ingresar_numero(int* numero_1, int* numero_2)
{
    int numero_ingresado_1, numero_ingresado_2;
    printf("Ingresa un numero positivo: ");
    scanf("%i", &numero_ingresado_1);
    while (numero_ingresado_1 < 0)
    {
        printf("El numero ingresado no es positivo. Intentalo de nuevo\n");
        printf("Ingresa un numero positivo: ");
        scanf("%i", &numero_ingresado_1);
    }
    printf("Ingresa otro numero positivo: ");
    scanf("%i", &numero_ingresado_2);
    while (numero_ingresado_2 < 0)
    {
        printf("El numero ingresado no es positivo. Intentalo de nuevo\n");
        printf("Ingresa otro numero positivo: ");
        scanf("%i", &numero_ingresado_2);
    }
    *numero_1 = numero_ingresado_1;
    *numero_2 = numero_ingresado_2;
}

bool maximo_comun_divisor(int numero_1, int numero_2, int* mcd)
{
    bool valido = false;
    int residuo;
    while (numero_2 != 0)
    {
        residuo = (numero_1%numero_2);
        numero_1 = numero_2;
        numero_2 = residuo;
    }
    if (numero_2 == 0)
    {
        valido = true;
    }
    *mcd = numero_1;
    return valido;
}


int main()
{
    int numero_1, numero_2, mcd;

    ingresar_numero(&numero_1, &numero_2);
    if (maximo_comun_divisor(numero_1, numero_2, &mcd))
    {
        printf("El maximo comun divisor entre %i y %i es %i", numero_1, numero_2, mcd);
    }
    else
    {
        printf("No se ha podido encontrar.");
    }
    return 0;
}