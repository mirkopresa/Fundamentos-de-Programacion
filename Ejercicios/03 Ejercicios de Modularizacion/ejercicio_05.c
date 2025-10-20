// Dada una secuencia de números enteros ingresados por el usuario, informar aquellos que sean primos. 
// El listado finaliza al ingresar cero. 
// Al finalizar el ingreso se debe indicar la cantidad y la sumatoria de aquellos que fueron primos.

#include <stdio.h>
#include <stdbool.h>

bool es_primo(int numero)
{
    bool primo = false;
    int i, contador = 0;
    for (i = 1; i <= numero; i++)
    {
        if ((numero % i) == 0)
        {
            contador++;
        }
    }
    if (contador == 2)
    {
        primo = true;
    }
    return primo;
}



int main()
{
    int numero, i, contador, cantidad_primos = 0, suma_primos = 0;
    printf("Ingrese un numero (finalizar ingreso con 0): ");
    scanf("%i", &numero);
    while (numero != 0)
    {
        if (es_primo(numero))
        {
            printf("El numero %i es primo\n", numero);
            cantidad_primos++;
            suma_primos += numero;
        }
        printf("Ingrese un numero (finalizar ingreso con 0): ");
        scanf("%i", &numero);
    }

    printf("Cantidad de primos: %i\n", cantidad_primos);
    printf("Suma total de los numeros primos: %i", suma_primos);
    
    return 0;
}