// Se dan como datos de entrada las fechas de nacimiento (día, mes, anio) y los números
// de DNI de cada integrante de un grupo.
// Se indica fin de datos de entrada cuando día = 0.
// Muestre por pantalla el número de DNI del integrante más joven del grupo.

#include <stdio.h>

int main()
{
    int dia, mes, anio, dni, menor = 0, finalizar = 1;

    while (finalizar != 0)
        {
            printf("Ingrese una fecha (dd/mm/yyyy): ");
            scanf("%i/%i/%i", &dia, &mes, &anio);
            printf("Ingrese un DNI: ");
            scanf("%i", &dni);
            if (dia == 0)
                finalizar = 0;
            if (dni > menor)
                menor=dni;
        }
    printf("Terminaste de ingresar datos.\n");
    printf("El integrante mas joven del grupo tiene como DNI: %i", menor);
    return 0;
}