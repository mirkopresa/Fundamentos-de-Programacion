// Ingresar un numero positivo (validar) e indicar si es primo

#include <stdio.h>

int main()
{
    int numero, contador = 0, x;

    printf("Ingresa un numero: ");
    scanf("%i", &numero);

    for (x=2; x<numero; x++)
        {
            if ((numero % x) == 0)
                contador++;
        }
    
    if (contador >= 1)
        printf("El numero %i no es primo", numero);
    else
        printf("El numero %i es primo", numero);

    return 0;
}