// ingresar los datos de 5 alumnos
// indicar el nombre del alumno con mejor promedio
// indicar el promedio general en el primer parcial
// ordenar ascendentemente el listado segun el padron
// ingresar un padron por teclado, buscarlo e imprimir toda la informacion de ese alumno
#include <stdio.h>
#include <stdbool.h>
#define MAX_ALUMNOS 2
typedef struct {
    char nombre[30];
    int legajo;
    char email[50];
    int notas[2];
    float promedio;
} t_alumno;
typedef t_alumno t_alumnos[MAX_ALUMNOS];

void ingresar_alumno(t_alumnos alumnos)
{
    int i;
    for (i = 0; i < MAX_ALUMNOS; i++)
    {
        printf("Ingresa el nombre del alumno: ");
        scanf("%s", &alumnos[i].nombre);
        printf("Ingresa el padron del alumno: ");
        scanf("%i", &alumnos[i].legajo);
        printf("Ingresa el email del alumno: ");
        scanf("%s", &alumnos[i].email);
        printf("Ingresa la primera nota del alumno: ");
        scanf("%i", &alumnos[i].notas[0]);
        printf("Ingresa la segunda nota del alumno: ");
        scanf("%i", &alumnos[i].notas[1]);
        alumnos[i].promedio = (float)((alumnos[i].notas[0] + alumnos[i].notas[1])/2);
    }
}

int mejor_promedio(t_alumnos alumnos)
{
    float mejor_promedio = alumnos[0].promedio;
    int alumno, i;
    for (i = 0; i < MAX_ALUMNOS; i++)
    {
        if (alumnos[i].promedio > mejor_promedio)
        {
            mejor_promedio = alumnos[i].promedio;
            alumno = i;
        }
    }
    return alumno;
}

float promedio_primer_parcial(t_alumnos alumnos)
{
    int i, suma = 0;
    float promedio;
    for (i = 0; i < MAX_ALUMNOS; i++)
    {
        suma += alumnos[i].notas[0];
    }
    promedio = ((float)suma/MAX_ALUMNOS);
    return promedio;
}

void ordenar_mejorado(t_alumnos alumnos)
{
    int i, j;
    t_alumno aux;   
    bool continuar=true;
    i=1;
    while (continuar && i < MAX_ALUMNOS - 1) 
    {
        continuar=false;
        for (j = 0; j < MAX_ALUMNOS - 1; j++) 
        {
            if (alumnos[j].legajo > alumnos[j+1].legajo) 
            {
                aux=alumnos[j]; 
                alumnos[j]=alumnos[j+1]; 
                alumnos[j+1]=aux;
                continuar=true;
            } 
        }
        i++;
    }
}

void mostrar_alumnos(t_alumnos alumnos)
{
    int i;
    for (i = 0; i < MAX_ALUMNOS; i++)
    {
        printf("Alumno %d\n", i+1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Padron: %d\n", alumnos[i].legajo);
        printf("Email: %s\n", alumnos[i].email);
        printf("Nota Parcial 1: %d Nota Parcial 2: %d\n", alumnos[i].notas[0], alumnos[i].notas[1]);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
    }
}

void encontrar_alumno(t_alumnos alumnos, int padron_a_encontrar) // busqueda bianria era elc aso
{
    int posicion;
    int inicio = 0, fin = MAX_ALUMNOS - 1, medio;
    bool encontrado = false;
    while(!encontrado) 
    {
              if ((padron_a_encontrar < alumnos[medio].legajo) || (padron_a_encontrar > alumnos[medio].legajo)) {
                    encontrado = true; 
                    posicion = 0;
                } else {
                    medio = inicio + ((fin-inicio)/2);
                }
            
            if(alumnos[medio].legajo == padron_a_encontrar) 
            {            
                encontrado = true;
            } else if(alumnos[medio].legajo < padron_a_encontrar) 
            {
                inicio = medio + 1;
            } else 
            {
                fin = medio - 1;
            }
        }
    if (encontrado)
    {   
        printf("Nombre del alumno: %s\n", alumnos[posicion].nombre);
        printf("Padron del alumno: %i\n", alumnos[posicion].legajo);
        printf("Email del alumno: %s\n", alumnos[posicion].email);
        printf("Notas del alumno: %i, %i\n", alumnos[posicion].notas[0], alumnos[posicion].notas[1]);
        printf("Promedio del alumno: %.2f\n", alumnos[posicion].promedio);
    }
    else
    {
        printf("No se ha encontrado el alumno buscado.");
    }
}

int main()
{
    t_alumnos alumnos;
    int padron_a_encontrar;
    ingresar_alumno(alumnos);
    printf("El nombre del alumno con el mejor promedio es: %s\n", alumnos[mejor_promedio(alumnos)].nombre);
    printf("El promedio del primer parcial fue %.2f\n", promedio_primer_parcial(alumnos));
    ordenar_mejorado(alumnos);
    mostrar_alumnos(alumnos);
    printf("Ingrese un padron a encontrar en la tabla de alumnos: ");
    scanf("%i", &padron_a_encontrar);
    encontrar_alumno(alumnos, padron_a_encontrar);
    return 0;
}
