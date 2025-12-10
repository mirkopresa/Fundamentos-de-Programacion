// Desarrollar una función recursiva que compruebe si un número pasado como parámetro es capicúa.

#include <stdio.h>
#include <stdbool.h>

bool es_capicua_recursivo(int numero, int numero_capicua, int original)
{
    if (numero_capicua == original)
    {
        return true;
    }
    if (numero == 0 && numero_capicua != original)
    {
        return false;
    }
    return es_capicua_recursivo(numero / 10, numero_capicua * 10 + numero % 10, original);
}

int main()
{
    int numero = 14441, numero_capicua = 0;
    if (es_capicua_recursivo(numero, numero_capicua, numero))
    {
        printf("Es capicua.");
    }
    else
    {
        printf("No es capicua.");
    }
    return 0;
}