// Escribir una función que reciba un mes y un año como números enteros; 
// y devuelva la cantidad de días del mes, considerando los años bisiestos. 
// Tenga en cuenta que un año bisiesto es aquel divisible por 4, 
// salvo que sea divisible por 100, en cuyo caso también debe ser divisible por 400.

#include <stdio.h>

int cantidad_dias_mes(int mes, int anio)
{
    int dias;
    if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12))
        dias = 31;
    else 
        {
        if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
            dias = 30;
        }
    if (mes == 2)
        { 
        if ((((anio % 4) == 0) && ((anio % 100) != 0)) || ((anio % 400) == 0))
            dias = 29;
        else
            dias = 28;
        }
    return dias;
}