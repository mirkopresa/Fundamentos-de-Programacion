// Dadas dos fechas, informar cuál es la fecha anterior. Los datos se dan según
// los siguientes casos:
// a) Cada fecha consiste en 3 números, día, mes y año.
// b) Cada fecha consiste en un único número en formato aammdd.
// c) Cada fecha consiste en un único número en formato ddmmaa.
// Puede darse el caso que las fechas sean iguales.

#include <stdio.h>

// Caso A

void primer_fecha(int dia_1, int dia_2, int mes_1, int mes_2, int anio_1, int anio_2)
{
    if ((anio_1 > anio_2) || ((anio_1 == anio_2) && (mes_1 > mes_2)) || ((anio_1 == anio_2) && (mes_1 == mes_2) && (dia_1 > dia_2)))
    {
        printf("La fecha %i del %i del %i es anterior\n", dia_2, mes_2, anio_2);
    }
    else
    {
        printf("La fecha %i del %i del %i es anterior\n", dia_1, mes_1, anio_1);
    }
}

// Caso B

void primer_fecha_2(int fecha_1, int fecha_2)
{
    int dia_1, dia_2, mes_1, mes_2, anio_1, anio_2;
    dia_1 = fecha_1 % 100;
    dia_2 = fecha_2 % 100;
    mes_1 = (fecha_1 / 100) % 100;
    mes_2 = (fecha_2 / 100) % 100;
    anio_1 = fecha_1 / 10000;
    anio_2 = fecha_2 / 10000;
    if ((anio_1 > anio_2) || ((anio_1 == anio_2) && (mes_1 > mes_2)) || ((anio_1 == anio_2) && (mes_1 == mes_2) && (dia_1 > dia_2)))
    {
        printf("La fecha %i del %i del %i es anterior\n", dia_2, mes_2, anio_2);
    }
    else
    {
        printf("La fecha %i del %i del %i es anterior\n", dia_1, mes_1, anio_1);
    }
}


// Caso C, no lo voy a hacer


int main()
{
    int dia_1 = 28, mes_1 = 3, anio_1 = 2005, dia_2 = 4, mes_2 = 12, anio_2 = 2006;
    int fecha_1 = 250328, fecha_2 = 121212;
    primer_fecha(dia_1, dia_2, mes_1, mes_2, anio_1, anio_2);
    primer_fecha_2(fecha_1, fecha_2);
}