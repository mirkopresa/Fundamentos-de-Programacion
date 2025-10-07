// Escribir una función que dado un número entero positivo retorne un valor booleano que indique si el mismo es capicúa (palindromo).

#include <stdio.h>
#include <stdbool.h>

bool capicua(int numero)
{
    bool valido;
    int palindromo = 0, valor = numero, digito;
    while (valor != 0)
        {
            digito = valor % 10;
            palindromo = (palindromo * 10) + digito;
            valor /= 10;
        }
    if (palindromo == numero)
        valido = true;
    else
        valido = false;
    return valido;
}