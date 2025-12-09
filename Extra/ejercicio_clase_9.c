// Se pide cargar la informacion en las estructuras necesarias y calcular
// 1- Validar que el nombre y apellido tenga la forma Nombre,Apellido
// 2- Ingresar 2 letras y mostrar todos los nombres y apellidos comprendidos entra ambas
// 3- Ingresar un apellido (solamente) y mostrar los alumnos con ese apellido
// 4- Ingresar un nombre y apellido y mostrar el padron corespondiente

#include <stdio.h>
#define MAX_CARACTERES 30
#define MAX_ALUMNOS 100
typedef char nombre_apellido[MAX_CARACTERES];
typedef nombre_apellido T_alumnos[MAX_ALUMNOS];
typedef int T_nota[MAX_ALUMNOS];
typedef int T_padron[MAX_ALUMNOS];

int main()
{  
    T_alumnos estudiantes;
    T_nota notas;
    T_padron padrones;
    int cantidad_estudiantes;
     int pos;
   
    llenar_listado(estudiantes,notas,padrones,&cantidad_estudiantes);
    //Grupo 1 y 2
    
    muestraAlumnosEntreRango(estudiantes,notas,padrones,cantidad_estudiantes)
    //Grupo 3 y 4
    
    alumno_seleccionados(estudiantes,notas,padrones,cantidad_estudiantes);
    
    //Grupo 5 y 6
    
    printf("Ingrese el nombre y apellido a buscar: ");
    scanf("%s", buscar_nombre_apellido);

    pos= buscarPadronPorNombreYApellido(alumnos, cantidad_estudiantes, buscar_nombre_apellido);
    //Grupo 7 y 8
    
    if  (padronaux==0){
        printf("No se encontro");}
    else{
        printf("El padron es: %d", padrones[pos]);}
    
    return 0;
}