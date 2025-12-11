// Implementar una función que retorna un puntero a un vector de n struct del
// tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,
// respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int padron;
char nombre[30];
char apellido[30];
} t_alumno;

t_alumno *crear_alumnos(int cantidad_alumnos)
{
    return malloc(cantidad_alumnos * sizeof(t_alumno));
}

int main()
{
    int cantidad_alumnos;
    printf("Ingrese la cantidad de alumnos a ingresar: ");
    scanf("%i", &cantidad_alumnos);
    t_alumno *alumnos = crear_alumnos(cantidad_alumnos);
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