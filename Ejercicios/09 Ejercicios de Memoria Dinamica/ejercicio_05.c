// Escribir un programa el cual reserve memoria dinámica para almacenar una
// cantidad n de struct del tipo t_alumno (ver anexo). El usuario debe ingresar la
// cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y
// almacenarlos en la memoria previamente reservada. Mostrar luego todos los
// datos de todos los alumnos. Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int padron;
char nombre[30];
char apellido[30];
} t_alumno;

int main()
{
    int cantidad_alumnos;
    t_alumno *alumnos;
    printf("Ingrese la cantidad de alumnos a ingresar: ");
    scanf("%i", &cantidad_alumnos);
    alumnos = malloc(cantidad_alumnos * sizeof(t_alumno));
    if (alumnos != NULL)
    {
        int i;
        printf("Se ingresaran %i alumnos.\n", cantidad_alumnos);
        for (i = 0; i < cantidad_alumnos; i++)
        {
            printf("Padron: ");
            scanf("%i", &alumnos[i].padron);
            printf("Nombre: ");
            scanf("%s", alumnos[i].nombre);
            printf("Apellido: ");
            scanf("%s", alumnos[i].apellido);
        }
        for (i = 0; i < cantidad_alumnos; i++)
        {
            printf("------------ Alumno %i ------------\n", i + 1);
            printf("Padron: %i\n", alumnos[i].padron);
            printf("Nombre: %s\n", alumnos[i].nombre);
            printf("Apellido: %s\n", alumnos[i].apellido);
            printf("-----------------------------------\n\n");
        }
        free(alumnos);
    }
    else
    {
        printf("No se ha podido reservar la memoria.");
    }
    return 0;
}