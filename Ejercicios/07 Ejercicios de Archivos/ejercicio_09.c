// Se tiene un archivo con los siguientes datos de los empleados de una empresa:
//      Apellido
//      Nombre (35 caracteres)
//      Fecha de Nacimiento (día, mes y año)
//      Fecha de Ingreso (día , mes y año)
//      Sueldo Básico
// Se conoce la fecha de procesamiento.
// Se pide:
// a) imprimir un listado con los apellidos y nombres de las personas que cumplen años en el mes.
// b) Calcular e informar una suma de regalo equivalente al uno por mil del sueldo por cada año cumplido.

#include <stdio.h>
#define CANTIDAD_MESES 12
#define MAX_STRING 35
typedef char string[MAX_STRING];
typedef struct {
    int dia;
    int mes;
    int anio;
} fecha;
typedef struct {
    string apellido;
    string nombre;
    fecha nacimiento;
    fecha ingreso;
    float sueldo;
} t_empleado;

void listado_cumpleanios(FILE *archivo_empleados, int mes)
{
    t_empleado empleado;
    int i;
    float suma_regalo;
    fread(&empleado, sizeof(t_empleado), 1, archivo_empleados);
    printf("-------------- Cumpleanios del mes %i --------------\n", mes);
    while (!feof(archivo_empleados))
    {  
        if (empleado.nacimiento.mes == mes)
        {    
            printf("Nombre: %s\n", empleado.nombre);
            printf("Apellido: %s\n", empleado.nombre);
            printf("Fecha de nacimiento: %i/%i/%i\n", empleado.nacimiento.dia, empleado.nacimiento.mes, empleado.nacimiento.anio);
            printf("Fecha de ingreso: %i/%i/%i\n", empleado.ingreso.dia, empleado.ingreso.mes, empleado.ingreso.anio);
            printf("Sueldo: %.2f\n", empleado.sueldo);
            suma_regalo = (float)empleado.sueldo * 0.001 * (2025 - empleado.nacimiento.anio);
            printf("Suma de regalo: %.2f\n\n", suma_regalo);
        }
        fread(&empleado, sizeof(t_empleado), 1, archivo_empleados);
    }
}

int main()
{
    FILE *archivo_empleados;
    int mes = 11;
    archivo_empleados = fopen("empleados.dat", "rb");
    if (archivo_empleados == NULL)
    {
        printf("No se ha podido abrir el archivo.");
    }
    else
    {
        listado_cumpleanios(archivo_empleados, mes);
        fclose(archivo_empleados);
    }
    return 0;
}