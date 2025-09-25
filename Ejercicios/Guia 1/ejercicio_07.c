// Ingresar un número (del 1 al 7) que representa un día de la semana, escribir el
// nombre del día correspondiente. En el caso de haber ingresado un número fuera de
// rango indicarle del error al usuario.

#include <stdio.h>

int main()
{
int numero;
printf("Ingrese un numero del 1 al 7 para saber a que dia de la semana corresponde: ");
scanf("%i", &numero);
if ((numero > 7) || (numero < 1))
    {
    printf("El numero que ingresaste no es valido");
    }
else
    if (numero == 1)
        printf("El dia %i de la semana es lunes.", numero);
        else
            if (numero == 2)
                printf("El dia %i de la semana es martes.", numero);
            else
                if (numero == 3)
                    printf("El dia %i de la semana es miercoles.", numero);
                else
                    if (numero == 4)
                        printf("El dia %i de la semana es jueves.", numero);
                    else
                        if (numero == 5)
                            printf("El dia %i de la semana es viernes.", numero);
                        else
                            if (numero == 6)
                                printf("El dia %i de la semana es sabado.", numero);
                            else
                                printf("El dia %i de la semana es domingo.", numero);
return 0;
}