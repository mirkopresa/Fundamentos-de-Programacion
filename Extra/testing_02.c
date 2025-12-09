// Se tiene un listado con los padrones y las notas finales de los alumnos de Algebra, 
// el ingreso de datos finaliza con padron=0. 
// Se pide mostrar La nota mayor, La nota menor y el promedio de notas.
// mostrar padron de nota mayor y padron de nota menor

#include <stdio.h>

int main()
{
    int padron, padron_mayor, padron_menor, nota, mayor = 0, menor = 11, suma = 0, cantidad = 0;
    float promedio;
    printf("Ingresar un numero de padron: ");
    scanf("%i", &padron);
    printf("Ingresar la nota final: ");
    scanf("%i", &nota);

    while (padron != 0)
    {
        suma+=nota;
        cantidad++;
        if (nota > mayor)
            {
                padron_mayor=padron;
                mayor=nota;
            }
        if (nota < menor)
            {
                padron_menor=padron;
                menor=nota;
            }
        printf("Ingresar un numero de padron: ");
        scanf("%i", &padron);
        printf("Ingresar la nota final: ");
        scanf("%i", &nota);
    }

    promedio=(suma / cantidad);

    printf("La nota mayor es %i, la nota menor es %i, y el promedio de notas es %0.2f\n", mayor, menor, promedio);
    printf("El padron de nota mayor es %i, y el padron de nota menor es %i", padron_mayor, padron_menor);

    return 0;
}