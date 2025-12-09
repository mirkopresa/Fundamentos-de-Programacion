// Escribir una función que dado un tiempo expresado en segundos, devuelva
// por parámetros el equivalente en días, horas, minutos y segundos.
// Utilizar esta función dentro de un programa que solicite el valor al usuario.
// Se debe validar que el valor ingresado sea entero positivo, de lo contrario,
// deberá mostrarse el mensaje: “Valor ingresado inválido”

#include <stdio.h>
#include <stdbool.h>

void conversor_tiempo(int tiempo, int *dias, int* horas, int *minutos, int *segundos, bool *valido)
{
    // mas facil era hacerlo con / y %
    *valido = false;
    if (tiempo > 0)
        *valido = true;
        *dias = tiempo / 86400;
        tiempo = tiempo % 86400;

        *horas = tiempo / 3600;
        tiempo = tiempo % 3600;

        *minutos = tiempo / 60;
        tiempo = tiempo % 60;

        *segundos = tiempo;
}

int main()
{
    int tiempo, dias = 0, horas = 0, minutos = 0, segundos = 0;
    bool valido;
    tiempo = 1234567;
    conversor_tiempo(tiempo, &dias, &horas, &minutos, &segundos, &valido);
    if (valido)
        printf("El intervalo de %i segundos es de %i dias, %i horas, %i minutos y %i segundos", tiempo, dias, horas, minutos, segundos);
    else
        printf("Valor ingresado invalido");
    return 0;
}