// Se tiene un listado de alumnos que consiste en número de padrón y 4 notas por
// alumno. Informar el mayor y el menor promedio registrado junto con el número de
// padrón del alumno, suponiendo que ambos son únicos.

#include <stdio.h>

int main()
{
    int alumnos, padron, padron_mayor, padron_menor, nota, x, y;
    float nota_total = 0, mayor_promedio = 0, menor_promedio = 50, cantidad_notas = 0, promedio;
    for (x = 0; x < 5; x++)
        {
            // Suponiendo que solo son 5 alumnos
            printf("Ingrese el numero de padron: ");
            scanf("%i", &padron);
            for  (y = 0; y < 4; y++)
                {
                    // 4 notas
                    printf("Ingrese una nota: ");
                    scanf("%i", &nota);
                    nota_total+=nota;
                    cantidad_notas++;
                }
            printf("%f\n", nota_total);
            promedio=(nota_total / cantidad_notas);
            printf("%0.2f\n", promedio);
            if (promedio > mayor_promedio)
                {
                    printf("Se registro un mayor promedio\n");
                    padron_mayor=padron;
                    mayor_promedio=promedio;
                }
            if (promedio < menor_promedio)
                {
                    printf("Se registro un menor promedio\n");
                    padron_menor=padron;
                    menor_promedio=promedio;
                }
            nota_total=0;
            cantidad_notas=0;
        }
    printf("El alumno con padron %i tuvo el mayor promedio, siendo de %0.2f\n", padron_mayor, mayor_promedio);
    printf("El alumno con padron %i tuvo el menor promedio, siendo de %0.2f", padron_menor, menor_promedio);
    return 0;
}