// Escribir un programa el cual reserve memoria dinámica para almacenar un
// struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los
// datos del alumno y almacenarlos en la memoria previamente reservada.
// Mostrar luego todos los datos del alumno. Liberar la memoria reservada al
// finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int padron;
char nombre[30];
char apellido[30];
} t_alumno;


int main()
{
    t_alumno *alumno;
    alumno = malloc(sizeof(t_alumno));
    if (alumno != NULL)
    {
        printf("---- Ingreso datos del alumno ----\n");
        printf("Padron: ");
        scanf("%i", &alumno->padron);
        printf("Nombre: ");
        scanf("%s", alumno->nombre);
        printf("Apellido: ");
        scanf("%s", alumno->apellido);
        printf("\n\n--------Alumno--------\n");
        printf("Padron: %i\n", alumno->padron);
        printf("Nombre: %s\n", alumno->nombre);
        printf("Apellido: %s\n", alumno->apellido);
        free(alumno);
    }
    else
    {
        printf("No se ha podido reservar la memoria.");
    }
    return 0;
}

