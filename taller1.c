#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_ATLETAS 10
#define NUM_INTENTOS 5


int main() {
    srand(time(0));
    
    struct Atleta atletas[NUM_ATLETAS];
    
    for (int i = 0; i < NUM_ATLETAS; i++) {
        printf("Nombre del atleta %d: ", i + 1);
        scanf("%s", atletas[i].nombre);
        atletas[i].puntos = 0.0;
    }
    
    for (int i = 0; i < NUM_INTENTOS; i++) {
        for (int j = 0; j < NUM_ATLETAS; j++) {
            if (decidir_intento()) {
                atletas[j].intentos[i] = -1.0; // Marcador de intento no realizado
            } else {
                atletas[j].intentos[i] = calcular_lanzamiento();
            }
        }
    }
    
    for (int i = 0; i < NUM_ATLETAS; i++) {
        atletas[i].puntos = calcular_puntos(atletas[i].intentos, NUM_INTENTOS);
    }
    ordenar_tabla(atletas, NUM_ATLETAS);
    
    mostrar_tabla(atletas, NUM_ATLETAS);
    
    return 0;
}