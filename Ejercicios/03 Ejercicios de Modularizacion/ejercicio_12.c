// Solicitar al usuario un número natural positivo entre 1 y 20.
// En el caso que el número ingresado este fuera de rango indicarle al usuario y solicitarlo nuevamente.
// Luego si el numero ingresado es primo se pide mostrar como resultado el factorial del mismo, 
// en el caso que no sea primo se pide mostrar como resultado la suma n-ésima parcial del número -> (n*(n+1))/2

#include <stdio.h>
#include <stdbool.h>

void ingresar_numero(int* numero)
{
    int numero_ingresado;
    printf("Ingresar un numero entre 1 y 20: ");
    scanf("%i", &numero_ingresado);
    while (numero_ingresado < 1 || numero_ingresado > 20)
    {
        printf("Numero ingresado fuera del rango\n");
        printf("Ingresar un numero entre 1 y 20: ");
        scanf("%i", &numero_ingresado);
    }
    *numero = numero_ingresado;
}

bool es_primo(int numero)
{
    int i, divisores = 0;
    bool numero_primo = false;
    for (i = 1; i <= numero; i++)
    {
        if ((numero % i) == 0)
        {
            divisores++;
        }
    }
    if (divisores <= 2)
    {
        numero_primo = true;
    }
    return numero_primo;
}


unsigned long long factorial(int numero)
{
    int i;
    unsigned long long factorial = 1;
    for (i = 2; i <= numero; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int suma_enesima(int numero)
{
    int suma;
    suma = (numero * (numero + 1)) / 2;
    return suma;
}

int main()
{
    int numero;
    ingresar_numero(&numero);
    if (es_primo(numero))
    {
        printf("El numero %i es primo.\n", numero);
        printf("Su factorial es %llu", factorial(numero));
    }
    else
    {
        printf("El numero %i no es primo.\n", numero);
        printf("La suma enesima del numero %i es %i", numero, suma_enesima(numero));
    }
    return 0;
}