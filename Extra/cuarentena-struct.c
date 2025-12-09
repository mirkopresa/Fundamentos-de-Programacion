/* Cuarentena

Se pide un programa que analice los datos de la “Cuarentena” del año 2020 que comenzó el viernes 20 de Marzo.

1) Ingresar los infectados por cada día del año 2020.
2) Informar que día de la cuarentena fue el Pico.
3) Mostrar un listado de cantidad de infectados y día ordenado descendente por cantidad de infectados.
4) Ingresar un día del año e indicar cuantos infectados hubo.

5) Indicar cual fue el domingo con menos infectados.
6) Indicar cual fue el sábado con menos infectados.

primer dia del año 2020 -> miercoles

*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_DIAS 366
#define DIAS_SEMANA 7

typedef struct  {
     int dia;
     int infectados;
} registro_t;

typedef registro_t TInfectados[MAX_DIAS];

void cargar_datos(TInfectados infectados, int ml) {
    int i, dia;
    printf("\nIngrese los datos de los infectados por día\n");
    for (i = 0; i < ml; i++) {
        dia = i + 1;
        printf("\t%d): ", dia);
        scanf("%d", &infectados[i].infectados);
        infectados[i].dia = dia;
    }
}

registro_t calcular_pico(TInfectados infectados, int ml) {
    int i;
    registro_t pico = infectados[0];

    for (i = 1; i < ml; i++)
    {
        if (infectados[i].infectados > pico.infectados)
        {
            pico = infectados[i];
        }
    }
    return pico;
}

void informar_dia_pico(TInfectados infectados, int ml) {
    registro_t pico = calcular_pico(infectados, ml);

    printf("\nEl día con más infectados fue el %d con %d infectados", pico.dia, pico.infectados);
}

void ordenar_infectados(TInfectados infectados, int ml) {
    registro_t aux;
    int i;
    bool seguir = true;
    
    while(seguir)
    {
        ml--;
        seguir = false;
        for(i = 0 ; i < ml ; i++)
        {
            if(infectados[i].infectados < infectados[i+1].infectados)
            {
                seguir = true;
                aux = infectados[i];
                infectados[i] = infectados[i+1];
                infectados[i+1] = aux;
            }
        }
    }
}

void imprimir_vector_infectados(TInfectados infectados, int ml) {
    int i;

    printf("\n\tINFECTADOS\tDIAS");
    for (i = 0; i < ml; i++)
    {
        printf("\n\t%6d\t\t%2d", infectados[i].infectados, infectados[i].dia);
    }   
}

int ingreso_consulta_dia() {
    int dia;
    printf("\nIngrese un dia: ");
    scanf("%d",&dia);
    return dia;
}

int buscar_dia(TInfectados infectados, int ml, int dia) {
    int i=0;
    int posicion = -1; // -1 es no encontrado
    bool encontrado=false;
    
    while (!encontrado && i<ml) {
        if (infectados[i].dia == dia)
        {
            encontrado=true;
            posicion=i;
        }
        i++;
    }

    return posicion;
}

void infectados_en_dia(TInfectados infectados, int ml) {
    int dia = ingreso_consulta_dia();
    int indice = buscar_dia(infectados, ml, dia);
    
    if(indice < 0)
        printf("\nNo existen registros de la fecha solicitada");
    else
        printf("\nEl día %d hubo %d infectados.", infectados[indice].dia, infectados[indice].infectados);
}

int main() {
    TInfectados infectados;

    cargar_datos(infectados, MAX_DIAS);
    informar_dia_pico(infectados, MAX_DIAS);

    ordenar_infectados(infectados, MAX_DIAS);
    imprimir_vector_infectados(infectados, MAX_DIAS);
    infectados_en_dia(infectados, MAX_DIAS);
    
    // COMPLETAR PUNTOS 5 Y 6
    return 0;
}