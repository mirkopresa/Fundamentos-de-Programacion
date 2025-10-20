// En una competencia de salto en largo, se presentaron 5 participantes. 
// De cada uno se ingresa:
// Número de participante
// Fecha de nacimiento (aaaammdd)
// Distancias de sus 3 saltos expresados en metros.
// El mejor de los 3 saltos se considera como la mejor marca obtenida.
// Se pide:
// a) Para cada participante mostrar por pantalla el número de participante, la
// edad y la marca obtenida.
// b) Informar el número del participante del atleta que obtuvo la mejor marca.

#include <stdio.h>

void ingresar_datos_participante(int* n_participante, int* f_nacimiento, int* mejor_salto)
{
    int numero_participante, fecha_nacimiento, i, salto, salto_maximo = 0;
    printf("Ingrese el numero del participante: ");
    scanf("%i", &numero_participante);
    printf("Ingrese la fecha de nacimiento (aaaammdd): ");
    scanf("%i", &fecha_nacimiento);
    for (i = 0; i < 3; i++)
    {
        printf("Ingrese la distancia del salto: ");
        scanf("%i", &salto);
        if (salto > salto_maximo)
        {
            salto_maximo = salto;
        }
    }
    *mejor_salto = salto_maximo;
    *n_participante = numero_participante;
    *f_nacimiento = fecha_nacimiento;
}

void mostrar_participante(int n_participante, int f_nacimiento, int mejor_salto)
{
    int edad;
    edad = 2025 - ( f_nacimiento / 10000 );
    printf("Participante N°%i, con %i anios de edad, obtuvo un salto de %i metros.\n", n_participante, edad, mejor_salto);
}

int main()
{
    int i, n_participante, f_nacimiento, mejor_salto, mejor_salto_general = 0, participante_mejor_salto_general = 0;
    for (i = 0; i < 5; i++)
    {
        ingresar_datos_participante(&n_participante, &f_nacimiento, &mejor_salto);
        mostrar_participante(n_participante, f_nacimiento, mejor_salto);
        if (mejor_salto > mejor_salto_general)
        {
            mejor_salto_general = mejor_salto;
            participante_mejor_salto_general = n_participante;
        }
    }
    printf("El participante con el mejor salto es el numero %i.", participante_mejor_salto_general);
    return 0;
}