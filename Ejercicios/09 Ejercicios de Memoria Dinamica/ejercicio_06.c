// Implementar una función que retorna un puntero a un struct del tipo
// t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,
// respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int padron;
char nombre[30];
char apellido[30];
} t_alumno;

t_alumno *crear_alumno()
{
    return malloc(sizeof(t_alumno));
}

int main()
{
    t_alumno *alumno = crear_alumno();
    if (alumno != NULL)
    {
        printf("---- Ingreso datos del alumno ----\n");
        printf("Padron: ");
        scanf("%i", &alumno->padron);
        printf("Nombre: ");
        scanf("%s", alumno->nombre);
        printf("Apellido: ");
        scanf("%s", alumno->apellido);
        printf("\n--------Alumno--------\n");
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
