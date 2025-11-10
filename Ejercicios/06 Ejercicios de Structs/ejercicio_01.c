// Se tienen los siguientes datos de los empleados de una empresa:
// Apellido (35 caracteres)
// Nombre (35 caracteres)
// Fecha de Nacimiento (día, mes y año)
// Fecha de Ingreso (día, mes y año)
// Sueldo Básico
// Se conoce la cantidad N de empleados y la fecha de procesamiento.
// Se pide: Imprimir un listado con los apellidos y nombres de las personas
// que cumplan años en el mes y calcular e informar una suma de regalo
// equivalente al uno por mil del sueldo por cada año cumplido.

#include <stdio.h>
#include <string.h>
#define MAX 35
#define MAX_EMPLEADOS 10
typedef char t_string[MAX];
typedef struct {
    int anio;
    int mes;
    int dia;
} t_fecha;

typedef struct {
    t_string nombre;
    t_string apellido;
    t_fecha fecha_nacimiento;
    t_fecha fecha_ingreso;
    float sueldo;
} t_empleado;

void listado_cumpleanios(t_empleado vec[MAX_EMPLEADOS], int cantidad_empleados)
{
    int mes, i;
    float suma_regalo = 0;
    printf("Ingrese un mes para chequear quien cumple anios: ");
    scanf("%i", &mes);
    for (i = 0; i < cantidad_empleados; i++)
    {
        if (vec[i].fecha_nacimiento.mes == mes)
        {
            printf("Nombre del cumpleaniero: %s\n", vec[i].nombre);
            printf("Apellido del cumpleaniero: %s\n", vec[i].apellido);
            printf("Fecha de nacimiento: %i/%i/%i\n", vec[i].fecha_nacimiento.dia, vec[i].fecha_nacimiento.mes, vec[i].fecha_nacimiento.anio);
            printf("Fecha de ingreso: %i/%i/%i\n", vec[i].fecha_ingreso.dia, vec[i].fecha_ingreso.mes, vec[i].fecha_ingreso.anio);
            printf("Sueldo: %.2f\n", vec[i].sueldo);
            suma_regalo = vec[i].sueldo * (2025-vec[i].fecha_nacimiento.anio)/100;
            printf("Este empleado recibira como regalo la suma de %.2f pesos.\n", suma_regalo);
        }
    }
}


int main()
{
    t_empleado empleado_1, empleado_2;
    int cantidad_empleados = 2;
    // paja hacer uno para ingresar cosas
    strcpy(empleado_1.nombre, "Mirko");
    strcpy(empleado_1.apellido, "Presa");
    empleado_1.fecha_nacimiento.anio = 2005;
    empleado_1.fecha_nacimiento.mes = 3;
    empleado_1.fecha_nacimiento.dia = 8;
    empleado_1.fecha_ingreso.anio = 2024;
    empleado_1.fecha_ingreso.mes = 11;
    empleado_1.fecha_ingreso.dia = 29;
    empleado_1.sueldo = 800000;
    strcpy(empleado_2.nombre, "Juan");
    strcpy(empleado_2.apellido, "Falopa");
    empleado_2.fecha_nacimiento.anio = 2000;
    empleado_2.fecha_nacimiento.mes = 4;
    empleado_2.fecha_nacimiento.dia = 11;
    empleado_2.fecha_ingreso.anio = 2020;
    empleado_2.fecha_ingreso.mes = 21;
    empleado_2.fecha_ingreso.dia = 1;
    empleado_2.sueldo = 1100000;
    t_empleado empleados[MAX_EMPLEADOS] = {empleado_1, empleado_2};
    listado_cumpleanios(empleados, cantidad_empleados);
    return 0;
}