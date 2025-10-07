// Se realiza una encuesta para estimar el grado de aceptación de los productos x e y en
// el mercado. A cada encuestado se le pregunta si consume el producto x y si consume el
// producto y. La respuesta puede ser sí o no.
// Se pide calcular e informar el porcentaje de consumidores de:
// a) del producto x
// b) del producto y
// c) del producto x solamente
// d) del producto y solamente
// e) de ambos productos
// f) de ninguno de los productos
// X para finalizar el programa (idea mia)

#include <stdio.h>

int main()
{
    int respuesta_x, respuesta_y, encuestas_totales = 0, porcentaje_x, porcentaje_y, finalizar=1;
    float cantidad_si_x = 0, cantidad_no_x = 0, cantidad_si_y = 0, cantidad_no_y = 0;
    while (finalizar == 1)
        {
            encuestas_totales++;
            printf("Responde con si o no:\n");
            printf("Consumis el producto X? (Si = 0 ; No = 1)\n");
            scanf("%i", &respuesta_x);
            printf("Consumis el producto Y? (Si = 0 ; No = 1)\n");
            scanf("%i", &respuesta_y);
            if (respuesta_x == 0)
                cantidad_si_x++;
            else
                cantidad_no_x++;
            if (respuesta_y == 0)
                cantidad_si_y++;
            else
                cantidad_no_y++;
            printf("Deseas finalizar con el programa? (Si = 0 ; No = 1)\n");
            scanf("%i", &finalizar);
        }
    porcentaje_x=((cantidad_si_x / encuestas_totales)*100);
    porcentaje_y=((cantidad_si_y / encuestas_totales)*100);
    printf("De %i encuestas, el %i%% es consumidor del producto x\n", encuestas_totales, porcentaje_x);
    printf("De %i encuestas, el %i%% es consumidor del producto y", encuestas_totales, porcentaje_y);
    return 0;
}

// una verga el ejercicio, queda asi