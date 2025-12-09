#include <stdio.h>
#include <stdbool.h>

void ingresar_numero_positivo(int* numero)
{
    int numero_ingresado;
    printf("Ingresa un numero positivo: ");
    scanf("%i", &numero_ingresado);
    while (numero_ingresado < 0)
    {
        printf("El numero ingresado no es positivo\n");
        printf("Ingresa un numero positivo: ");
        scanf("%i", &numero_ingresado);
    }
    *numero = numero_ingresado;
}

bool es_capicua(int numero)
{
    bool numero_capicua = false;
    int capicua = 0, numero_a_comparar = numero, digito;
    while (numero != 0)
    {
        capicua *= 10;
        digito = numero % 10;
        numero /= 10;
        capicua += digito;
    }
    if (capicua == numero_a_comparar)
        numero_capicua = true;

    return numero_capicua;
}

int main()
{
    int numero;
    ingresar_numero_positivo(&numero);
    if (es_capicua(numero))
        printf("El numero %i es capicua", numero);
    else
        printf("El numero %i no es capicua", numero);

    return 0;
}