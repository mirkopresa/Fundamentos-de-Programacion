// Dado un número entero positivo ingresado por el usuario, procesarlo e indicar:
// (realizar un programa diferente para cada caso)
// a) La cantidad de dígitos pares e impares que lo componen.
// b) El menor y el mayor dígito del número.

#include <stdio.h>

int main()
{
    int numero, digito, par=0, impar=0, mayor=0, menor=0, x;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);
    while (numero != 0)
        {
        digito=(numero % 10);
        if ((digito % 2) == 0)
            par++;
        else
            impar++;
        if (digito > mayor)
            mayor=digito;
        else
            menor=digito;
        numero=(numero / 10);
        }
    printf("El numero tenia %i digitos pares, y %i digitos impares.\n", par, impar);
    printf("Mayor digito: %i\n", mayor);
    printf("Menor digito: %i", menor);
    return 0;
}