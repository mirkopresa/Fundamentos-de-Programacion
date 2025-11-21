// Se tienen datos de empleados de una empresa según la siguiente
// estructura:
// Apellido (cadena 35)
// Nombre (cadena 35)
// Legajo (entero 5 dígitos)
// Dirección:
//      Calle (cadena 50)
//      Número (entero)
//      Localidad (cadena 50)
//      Provincia (cadena 50)
//      Código Postal (entero)
// Fecha de Nacimiento: Día, Mes, Año
// Fecha de Ingreso: Día, Mes, Año
// Se pide hacer un programa que almacene los datos de todos los empleados en una tabla en memoria y que permita obtener un listado ordenado 
// por pantalla según distintos ítems, como, por ejemplo, por Apellido y Nombre, por número de legajo, por edad, por antigüedad, por localidad.
// Utilizar un esquema tipo menú.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_EMPLEADOS 50
#define NO_ENCONTRADO -1
typedef struct {
    int dia;
    int mes;
    int anio;
} t_fecha;
typedef struct {
    char calle[50];
    int numero_calle;
    char localidad[50];
    char provincia[50];
    char codigo_postal[8];
} t_direccion;
typedef struct {
    char nombre[35];
    char apellido[35];
    int padron;
    t_direccion direccion;
    t_fecha fecha_nacimiento;
    t_fecha fecha_ingreso;
} t_empleado;

void limpiar_stdin()
{
    while (getchar() != '\n');
}

void agregar_nuevo_empleado(t_empleado empleado[MAX_EMPLEADOS], int* cantidad_empleados)
{
    int i, ingreso = 1, cantidad = 0;
    i = *cantidad_empleados;
    while (ingreso == 1 && i < MAX_EMPLEADOS)
    {
        printf("Ingresa el nombre del empleado: ");
        fgets(empleado[i].nombre, 35, stdin);
        empleado[i].nombre[strcspn(empleado[i].nombre, "\n")] = '\0';
        printf("Ingresa el apellido del empleado: ");
        fgets(empleado[i].apellido, 35, stdin);
        empleado[i].apellido[strcspn(empleado[i].apellido, "\n")] = '\0';
        printf("Ingresa el padron del empleado: ");
        scanf("%i", &empleado[i].padron);
        limpiar_stdin();
        printf("--------Direccion del empleado--------\n");
        printf("Ingresa la calle del empleado: ");
        fgets(empleado[i].direccion.calle, 50, stdin);
        empleado[i].direccion.calle[strcspn(empleado[i].direccion.calle, "\n")] = '\0';
        printf("Ingresa el numero de calle: ");
        scanf("%i", &empleado[i].direccion.numero_calle);
        limpiar_stdin();
        printf("Ingresa la localidad: ");
        fgets(empleado[i].direccion.localidad, 50, stdin);
        empleado[i].direccion.localidad[strcspn(empleado[i].direccion.localidad, "\n")] = '\0';
        printf("Ingresa la provincia: ");
        fgets(empleado[i].direccion.provincia, 50, stdin);
        empleado[i].direccion.provincia[strcspn(empleado[i].direccion.provincia, "\n")] = '\0';
        printf("Ingresa el codigo postal: ");
        scanf("%s", empleado[i].direccion.codigo_postal);
        limpiar_stdin();
        printf("Ingresa la fecha de nacimiento en formato DD/MM/YYYY: ");
        scanf("%d/%d/%d", &empleado[i].fecha_nacimiento.dia, &empleado[i].fecha_nacimiento.mes, &empleado[i].fecha_nacimiento.anio);
        limpiar_stdin();
        printf("Ingresa la fecha de ingreso en formato DD/MM/YYYY: ");
        scanf("%d/%d/%d", &empleado[i].fecha_ingreso.dia, &empleado[i].fecha_ingreso.mes, &empleado[i].fecha_ingreso.anio);
        limpiar_stdin();
        cantidad++;
        i++;
        printf("Deseas ingresar otro empleado? (SI: 1, NO: 0): ");
        scanf("%i", &ingreso);
        limpiar_stdin();
    }
    *cantidad_empleados += cantidad;
}

void ordenamiento_nombre(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i, j;
    t_empleado auxiliar;
    bool continuar = true;
    i = 1;
    while (continuar && i < cantidad_empleados)
    {
        continuar = false;
        for (j = 0; j < cantidad_empleados - i; j++)
        {
            if (strcmp(empleado[j].nombre, empleado[j+1].nombre) > 0)
            {
                auxiliar = empleado[j];
                empleado[j] = empleado[j+1];
                empleado[j+1] = auxiliar;
                continuar = true;
            }
        }
        i++;
    }
}

void ordenamiento_apellido(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i, j;
    t_empleado auxiliar;
    bool continuar = true;
    i = 1;
    while (continuar && i < cantidad_empleados)
    {
        continuar = false;
        for (j = 0; j < cantidad_empleados - i; j++)
        {
            if (strcmp(empleado[j].apellido, empleado[j+1].apellido) > 0)
            {
                auxiliar = empleado[j];
                empleado[j] = empleado[j+1];
                empleado[j+1] = auxiliar;
                continuar = true;
            }
        }
        i++;
    }
}

void ordenamiento_padron(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i, j;
    t_empleado auxiliar;
    bool continuar = true;
    i = 1;
    while (continuar && i < cantidad_empleados)
    {
        continuar = false;
        for (j = 0; j < cantidad_empleados - i; j++)
        {
            if (empleado[j].padron > empleado[j+1].padron)
            {
                auxiliar = empleado[j];
                empleado[j] = empleado[j+1];
                empleado[j+1] = auxiliar;
                continuar = true;
            }
        }
        i++;
    }
}

void ordenamiento_edad(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i, j;
    t_empleado auxiliar;
    bool continuar = true;
    i = 1;
    while (continuar && i < cantidad_empleados)
    {
        continuar = false;
        for (j = 0; j < cantidad_empleados - i; j++)
        {
            if (empleado[j].fecha_nacimiento.anio > empleado[j+1].fecha_nacimiento.anio)
            {
                auxiliar = empleado[j];
                empleado[j] = empleado[j+1];
                empleado[j+1] = auxiliar;
                continuar = true;
            }
        }
        i++;
    }
}

void ordenamiento_antiguedad(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i, j;
    t_empleado auxiliar;
    bool continuar = true;
    i = 1;
    while (continuar && i < cantidad_empleados)
    {
        continuar = false;
        for (j = 0; j < cantidad_empleados - i; j++)
        {
            if (empleado[j].fecha_ingreso.anio > empleado[j+1].fecha_ingreso.anio)
            {
                auxiliar = empleado[j];
                empleado[j] = empleado[j+1];
                empleado[j+1] = auxiliar;
                continuar = true;
            }
        }
        i++;
    }
}

void ordenamiento_localidad(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i, j;
    t_empleado auxiliar;
    bool continuar = true;
    i = 1;
    while (continuar && i < cantidad_empleados)
    {
        continuar = false;
        for (j = 0; j < cantidad_empleados - i; j++)
        {
            if (strcmp(empleado[j].direccion.localidad, empleado[j+1].direccion.localidad) > 0)
            {
                auxiliar = empleado[j];
                empleado[j] = empleado[j+1];
                empleado[j+1] = auxiliar;
                continuar = true;
            }
        }
        i++;
    }
}

int buscar_por_nombre(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados, char* nombre_buscado)
{
    int inicio = 0, fin = cantidad_empleados - 1, mitad;
    bool terminado = false;
    int posicion;
    while (!terminado)
    {
        if ((strcmp(nombre_buscado, empleado[inicio].nombre) < 0) || (strcmp(nombre_buscado, empleado[fin].nombre) > 0))
        {
            terminado = true;
            posicion = NO_ENCONTRADO;
        }
        else
        {
            mitad = inicio + ((fin - inicio)/2);
            if (strcmp(nombre_buscado, empleado[mitad].nombre) == 0)
            {
                terminado = true;
                posicion = mitad;
            } else if (strcmp(nombre_buscado, empleado[mitad].nombre) > 0)
            {
                inicio = mitad + 1;
            } else
            {
                fin = mitad - 1;
            }
        }
    }
    return posicion;
}

int buscar_por_apellido(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados, char* apellido_buscado)
{
    int inicio = 0, fin = cantidad_empleados - 1, mitad;
    bool terminado = false;
    int posicion;
    while (!terminado)
    {
        if ((strcmp(apellido_buscado, empleado[inicio].apellido) < 0) || (strcmp(apellido_buscado, empleado[fin].apellido) > 0))
        {
            terminado = true;
            posicion = NO_ENCONTRADO;
        }
        else
        {
            mitad = inicio + ((fin - inicio)/2);
            if (strcmp(apellido_buscado, empleado[mitad].apellido) == 0)
            {
                terminado = true;
                posicion = mitad;
            } else if (strcmp(apellido_buscado, empleado[mitad].apellido) > 0)
            {
                inicio = mitad + 1;
            } else
            {
                fin = mitad - 1;
            }
        }
    }
    return posicion;
}

int buscar_por_padron(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados, int padron_buscado)
{
    int inicio = 0, fin = cantidad_empleados - 1, mitad;
    bool terminado = false;
    int posicion;
    while (!terminado)
    {
        if ((padron_buscado < empleado[inicio].padron) || (padron_buscado > empleado[fin].padron))
        {
            terminado = true;
            posicion = NO_ENCONTRADO;
        }
        else
        {
            mitad = inicio + ((fin - inicio)/2);
            if (empleado[mitad].padron == padron_buscado)
            {
                terminado = true;
                posicion = mitad;
            } else if (padron_buscado > empleado[mitad].padron )
            {
                inicio = mitad + 1;
            } else
            {
                fin = mitad - 1;
            }
        }
    }
    return posicion;
}

void listado_empleados(t_empleado empleado[MAX_EMPLEADOS], int cantidad_empleados)
{
    int i;
    printf("------Empleados------\n");
    for (i = 0; i < cantidad_empleados; i++)
    {
        printf("\n-------------------------------------\n");
        printf("Empleado %i:\n", i+1);
        printf("Nombre: %s\n", empleado[i].nombre);
        printf("Apellido: %s\n", empleado[i].apellido);
        printf("Padron: %i\n", empleado[i].padron);
        printf("------Direccion del empleado %i------\n", i+1);
        printf("Calle: %s\n", empleado[i].direccion.calle);
        printf("Numero de calle: %i\n", empleado[i].direccion.numero_calle);
        printf("Localidad: %s\n", empleado[i].direccion.localidad);
        printf("Provincia: %s\n", empleado[i].direccion.provincia);
        printf("Codigo postal: %s\n", empleado[i].direccion.codigo_postal);
        printf("-------------------------------------\n");
        printf("Fecha de nacimiento: %d/%d/%d\n", empleado[i].fecha_nacimiento.dia, empleado[i].fecha_nacimiento.mes, empleado[i].fecha_nacimiento.anio);
        printf("Fecha de ingreso: %d/%d/%d\n", empleado[i].fecha_ingreso.dia, empleado[i].fecha_ingreso.mes, empleado[i].fecha_ingreso.anio);
    }
}

void mostrar_empleado(t_empleado empleado[MAX_EMPLEADOS], int buscado)
{
    if (buscado != NO_ENCONTRADO)
    {
        printf("\n-------------------------------------\n");
        printf("Empleado %i:\n", buscado+1);
        printf("Nombre: %s\n", empleado[buscado].nombre);
        printf("Apellido: %s\n", empleado[buscado].apellido);
        printf("Padron: %i\n", empleado[buscado].padron);
        printf("------Direccion del empleado %i------\n", buscado+1);
        printf("Calle: %s\n", empleado[buscado].direccion.calle);
        printf("Numero de calle: %i\n", empleado[buscado].direccion.numero_calle);
        printf("Localidad: %s\n", empleado[buscado].direccion.localidad);
        printf("Provincia: %s\n", empleado[buscado].direccion.provincia);
        printf("Codigo postal: %s\n", empleado[buscado].direccion.codigo_postal);
        printf("-------------------------------------\n");
        printf("Fecha de nacimiento: %d/%d/%d\n", empleado[buscado].fecha_nacimiento.dia, empleado[buscado].fecha_nacimiento.mes, empleado[buscado].fecha_nacimiento.anio);
        printf("Fecha de ingreso: %d/%d/%d\n", empleado[buscado].fecha_ingreso.dia, empleado[buscado].fecha_ingreso.mes, empleado[buscado].fecha_ingreso.anio);
    }
    else
    {
        printf("No se ha encontrado el empleado buscado.\n");
    }
}

int mostrar_menu()
{
    int eleccion;
    printf("Elige la accion a realizar:\n");
    printf("0: Finalizar programa\n");
    printf("1: Ingresar nuevos empleados\n");
    printf("2: Ordenar y listar por nombre\n");
    printf("3: Ordenar y listar por apellido\n");
    printf("4: Ordenar y listar por padron\n");
    printf("5: Ordenar y listar por edad\n" );
    printf("6: Ordenar y listar por antiguedad\n");
    printf("7: Ordenar y listar por localidad\n");
    printf("8: Abrir menu de busqueda\n");
    scanf("%i", &eleccion);
    return eleccion;
}

int mostrar_menu_busqueda()
{
    int eleccion;
    printf("Elige la accion a realizar:\n");
    printf("0: Volver\n");
    printf("1: Buscar por nombre\n");
    printf("2: Buscar por apellido\n");
    printf("3: Buscar por padron\n");
    scanf("%i", &eleccion);
    return eleccion;
}

int main()
{
    int cantidad_empleados = 0;
    t_empleado empleados[MAX_EMPLEADOS];
    int eleccion_menu, eleccion_busqueda, padron_buscado, buscado;
    char nombre_buscado[35], apellido_buscado[35];
    eleccion_menu = mostrar_menu();
    limpiar_stdin();
    while (eleccion_menu != 0)
    {
        switch (eleccion_menu)
        {
            case 1 :
                agregar_nuevo_empleado(empleados, &cantidad_empleados);
                break;
            case 2 :
                if (cantidad_empleados > 0)
                {
                    ordenamiento_nombre(empleados, cantidad_empleados);
                    listado_empleados(empleados, cantidad_empleados);
                }
                else
                    printf("Hay 0 empleados, porfavor agrega uno antes de ordenar y listar.\n");
                break;
            case 3 :
                if (cantidad_empleados > 0)
                {
                    ordenamiento_apellido(empleados, cantidad_empleados);
                    listado_empleados(empleados, cantidad_empleados);
                }
                else
                    printf("Hay 0 empleados, porfavor agrega uno antes de ordenar y listar.\n");
                break;
            case 4 :
                if (cantidad_empleados > 0)
                {
                    ordenamiento_padron(empleados, cantidad_empleados);
                    listado_empleados(empleados, cantidad_empleados);
                }
                else
                    printf("Hay 0 empleados, porfavor agrega uno antes de ordenar y listar.\n");
                break;
            case 5 :
                if (cantidad_empleados > 0)
                {
                    ordenamiento_edad(empleados, cantidad_empleados);
                    listado_empleados(empleados, cantidad_empleados);
                }
                else
                    printf("Hay 0 empleados, porfavor agrega uno antes de ordenar y listar.\n");
                break;
            case 6 :
                if (cantidad_empleados > 0)
                {
                    ordenamiento_antiguedad(empleados, cantidad_empleados);
                    listado_empleados(empleados, cantidad_empleados);
                }
                else
                    printf("Hay 0 empleados, porfavor agrega uno antes de ordenar y listar.\n");
                break;
            case 7 : 
                if (cantidad_empleados > 0)
                {
                    ordenamiento_localidad(empleados, cantidad_empleados);
                    listado_empleados(empleados, cantidad_empleados);
                }
                else
                    printf("Hay 0 empleados, porfavor agrega uno antes de ordenar y listar.\n");
                break;
            case 8 :
                eleccion_busqueda = mostrar_menu_busqueda();
                limpiar_stdin();
                while (eleccion_busqueda != 0)
                {
                    switch (eleccion_busqueda)
                    {
                        case 1 :
                            if (cantidad_empleados > 0)
                            {
                                printf("Ingrese un nombre a buscar: ");
                                scanf("%s", nombre_buscado);
                                limpiar_stdin();
                                ordenamiento_nombre(empleados, cantidad_empleados);
                                buscado = buscar_por_nombre(empleados, cantidad_empleados, nombre_buscado);
                                mostrar_empleado(empleados, buscado);
                            }
                            else
                                printf("Hay 0 empleados, porfavor agrega uno antes de buscar\n");
                            break;
                        case 2 :
                            if (cantidad_empleados > 0)
                            {
                                printf("Ingrese un apellido a buscar: ");
                                scanf("%s", apellido_buscado);
                                ordenamiento_apellido(empleados, cantidad_empleados);
                                limpiar_stdin();
                                buscado = buscar_por_apellido(empleados, cantidad_empleados, apellido_buscado);
                                mostrar_empleado(empleados, buscado);
                            }
                            else
                                printf("Hay 0 empleados, porfavor agrega uno antes de buscar\n");
                            break;
                        case 3 :
                            if (cantidad_empleados > 0)
                            {
                                printf("Ingrese un padron a buscar: ");
                                scanf("%i", &padron_buscado);
                                ordenamiento_padron(empleados, cantidad_empleados);
                                limpiar_stdin();
                                buscado = buscar_por_padron(empleados, cantidad_empleados, padron_buscado);
                                mostrar_empleado(empleados, buscado);
                            }
                            else
                                printf("Hay 0 empleados, porfavor agrega uno antes de buscar\n");
                            break;
                        default :
                            printf("Opcion invalida, porfavor ingresa una nueva: ");
                    }
                    eleccion_busqueda = mostrar_menu_busqueda();
                    limpiar_stdin();
                }
                break;
            default :
                printf("Opcion invalida, porfavor ingresa una nueva: ");
        }
        eleccion_menu = mostrar_menu();
        limpiar_stdin();
    }
    printf("Has finalizado el programa.");
    return 0;
}