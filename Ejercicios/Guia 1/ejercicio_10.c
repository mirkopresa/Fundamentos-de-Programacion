// Dada una fecha con año, mes y día, informar si es correcta o no. Solicitarle los
// datos al usuario de forma independiente. Considerar años bisiestos.

#include <stdio.h>

int main()
{
    int anio, mes, dia;

    printf("Ingrese un anio: ");
    scanf("%i", &anio);

    printf("Ingrese un mes: ");
    scanf("%i", &mes);

    printf("Ingrese un dia: ");
    scanf("%i", &dia);

    if ((anio > 0) && ((dia > 1) && (dia < 30)) && ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)))
        {
        printf("El dia %i del mes %i del anio %i es correcto", dia, mes, anio);
        return -1;
        }
    else
        if ((anio < 0) || ((dia < 1) || (dia > 31)) || ((mes < 1) || (mes > 12)) || ((dia == 31) && (mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)))
            {
            printf("La fecha ingresada no es correcta");
            return -1;
            }
        else
            if ((anio > 0) && ((dia > 1) && (dia < 31)) && ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)))
            {
            printf("El dia %i del mes %i del anio %i es correcto", dia, mes, anio);
            return -1;
            }
            else
                if (((anio > 0) && (((anio % 4) == 0) || (((anio % 400)== 0)))) && (dia = 29) && (mes = 2) || ((dia > 1) && (dia < 28) && (mes == 2)))
                {
                printf("El dia %i del mes %i del año %i es correcto", dia, mes, anio);
                return -1;
                }
                else
                {
                printf("La fecha ingresada no es correcta");
                return -1;
                }
    if (((anio > 0) && (((anio % 4) == 0) || (((anio % 400)== 0)))) && (dia = 29) && (mes = 2))
        {
        printf("El dia %i del mes %i del año %i es correcto", dia, mes, anio);
        return -1;
        }
    else
        {
        printf("La fecha ingresada no es correcta");
        return -1;
        }
    return 0;
}