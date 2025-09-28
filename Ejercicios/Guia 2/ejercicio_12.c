// Escribir una función que reciba dos valores enteros, 
// y devuelva el máximo común divisor entre ambos números. 
// Recordemos que se define el máximo común divisor (MCD) de dos o más números enteros 
// al mayor número entero que los divide sin dejar resto alguno. Utilizar el algoritmo de Euclides.

#include <stdio.h>

int MCD(int numero_1, int numero_2)
{
    int resto = numero_2;
    while ((numero_1 % numero_2) != 0)
    {
            resto = (numero_1 % numero_2);
            numero_1 = numero_2;
            numero_2 = resto;
    }
    return resto;
}