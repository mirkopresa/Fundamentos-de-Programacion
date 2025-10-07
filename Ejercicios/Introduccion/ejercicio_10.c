// Dada una fecha con año, mes y día, informar si es correcta o no. Solicitarle los
// datos al usuario de forma independiente. Considerar años bisiestos.


// NO FUNCIONA LO TENGO QUE ARREGLAR

#include <stdio.h>

int main()
{
    int anio, mes, dias;

    printf("Ingrese un anio: ");
    scanf("%i", &anio);

    printf("Ingrese un mes: ");
    scanf("%i", &mes);

    printf("Ingrese un dia: ");
    scanf("%i", &dias);

if (((mes <= 12) && (mes >= 1)) && (anio > 0) && ((dias >= 1) && (dias <= 31)))
    {
        if (((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) && (dias <= 31))
            printf("El dia %i del mes %i del anio %i es correcto", dias, mes, anio);
        else 
            {
            if (((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) && (dias <= 30))
                printf("El dia %i del mes %i del anio %i es correcto", dias, mes, anio);
            }
        if (mes == 2)
            { 
            if (((((anio % 4) == 0) && ((anio % 100) != 0)) || ((anio % 400) == 0)) && (dias == 29))
                printf("El dia %i del mes %i del anio %i es correcto", dias, mes, anio);
            else
                {
                if (dias <= 28)
                    printf("El dia %i del mes %i del anio %i es correcto", dias, mes, anio);}
                }
    }
else
    printf("La fecha ingresada no es correcta");
return 0;
}