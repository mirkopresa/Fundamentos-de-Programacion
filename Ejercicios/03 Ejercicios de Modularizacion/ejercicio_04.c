// Dada una fecha en formato aaaammdd, verifi car si es correcta.
// Si lo es, informarla según “dd de cccc de aaaa”.
// Si no lo es, mostrar un mensaje de error acorde.
// cccc es la cadena de caracteres correspondiente al mes mm.


#include <stdio.h>
#include <stdbool.h>

int conversor_fecha(int fecha, int* dia, int* mes, int* anio)
{
    *dia = fecha % 100;
    *mes = (fecha / 100) % 100;
    *anio = fecha / 10000;
}

bool fecha_valida(int dia, int mes, int anio)
{
    bool valido = false;
    if ((dia == 29) && (mes == 2) && (((anio % 4) == 0 && (anio % 100) != 0) || ((anio % 400) == 0)))
    {
        valido = true;
    }
    if (((dia >= 1) && (dia <= 31) && ! ((dia == 29) && (mes == 2))) && (anio > 1) && ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)))
    {
        valido = true;
    }
    if (((dia >= 1) && (dia <= 30)) && ! (((dia == 29) && (mes == 2)) || (dia == 31)) && (anio > 1) && ((mes == 2) || (mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)))
    {
        valido = true;
    }
    return valido;
}

void mostrar_fecha(int dia, int mes, int anio)
{
    if (mes == 1)
    {
        printf("%i de enero de %i", dia, anio);
    }
    if (mes == 2)
    {
        printf("%i de febrero de %i", dia, anio);
    }
    if (mes == 3)
    {
        printf("%i de marzo de %i", dia, anio);
    }
    if (mes == 4)
    {
        printf("%i de abril de %i", dia, anio);
    }
    if (mes == 5)
    {
        printf("%i de mayo de %i", dia, anio);
    }
    if (mes == 6)
    {
        printf("%i de junio de %i", dia, anio);
    }
    if (mes == 7)
    {
        printf("%i de julio de %i", dia, anio);
    }
    if (mes == 8)
    {
        printf("%i de agosto de %i", dia, anio);
    }
    if (mes == 9)
    {
        printf("%i de septiembre de %i", dia, anio);
    }
    if (mes == 10)
    {
        printf("%i de octubre de %i", dia, anio);
    }
    if (mes == 11)
    {
        printf("%i de noviembre de %i", dia, anio);
    }
    if (mes == 12)
    {
        printf("%i de diciembre de %i", dia, anio);
    }
}

int main()
{
    int dia, mes, anio, fecha = 20050308;
    conversor_fecha(fecha, &dia, &mes, &anio);
    if (fecha_valida(dia, mes, anio))
    {
        mostrar_fecha(dia, mes, anio);
    }
    else
    {
        printf("La fecha ingresada no es valida");
    }
}