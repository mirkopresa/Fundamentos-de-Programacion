// Escribir un programa que solicite el ingreso de una serie de números. 
// Por cada número ingresado se deberá informar si el mismo es o no, un número capicúa.
// Se debe evaluar que lo ingresado, sea un número entero positivo, de lo contrario, 
// se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente. 
// El ingreso de números, termina cuando el usuario ingresa el número cero.

#include <stdio.h>
#include <stdbool.h>

void ingreso_numeros(int* numero)
{
    int numero_positivo;
    printf("Ingresa un numero positivo (0 para finalizar): ");
    scanf("%i", &numero_positivo);
    while (numero_positivo < 0)
    {
        printf("Numero invalido.\n");
        printf("Ingresa un numero positivo (0 para finalizar): ");
        scanf("%i", &numero_positivo);
    }
    *numero = numero_positivo;
}

bool capicua(int numero)
{
    bool es_capicua = false;
    int digito = 0, numero_1 = numero, numero_2 = 0;
    while (numero != 0)
    {
        numero_2 *= 10;
        digito = numero % 10;
        numero_2 += digito;
        numero /= 10;
    }
    if (numero_1 == numero_2)
    {
        es_capicua = true;
    }
    return es_capicua;
}

int main()
{
    int numero;
    ingreso_numeros(&numero);
    while (numero != 0)
    {
        if (capicua(numero))
        {
            printf("El numero ingresado es capicua.\n");
        }
        ingreso_numeros(&numero);
    }
    printf("Has terminado de ingresar numeros.");
    return 0;
}