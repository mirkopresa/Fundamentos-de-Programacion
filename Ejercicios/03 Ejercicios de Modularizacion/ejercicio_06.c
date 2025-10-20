// Dada una secuencia de números enteros informar los n primeros números
// primos que aparezcan y su sumatoria.
// El valor de n es ingresado por el usuario previo al ingreso de los números de la lista.

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
    if ((contador == 2) || (contador == 1))
    {
        primo = true;
    }
    return primo;
}

int main()
{
    int i = 0, primos, numero, suma = 0;
    printf("Ingrese una cantidad de primos: ");
    scanf("%i", &primos);
    while (i != primos)
    {
        printf("Ingrese un numero: ");
        scanf("%i", &numero);
        if (es_primo(numero))
        {
            printf("El numero %i es primo.\n", numero);
            i++;
            suma += numero;
        }
    }
    printf("La suma de los numeros primos ingresados es %i", suma);
    return 0;
}
