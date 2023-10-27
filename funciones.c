#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// Función para calcular el lanzamiento
double calcular_lanzamiento() 
{
    return 5.5 + ((double)rand() / RAND_MAX) * (15 - 5.5);
}

// Función para decidir si un atleta intentará un lanzamiento
int decidir_intento() 
{
    return (rand() % 100) < 30;
}

void ordenar_tabla(struct Atleta tabla[], int numAtletas) 
{
    for (int i = 0; i < numAtletas - 1; i++) 
    {
        for (int j = 0; j < numAtletas - i - 1; j++) 
        {
            if (tabla[j].puntos < tabla[j + 1].puntos) 
            {
                struct Atleta temp = tabla[j];
                tabla[j] = tabla[j + 1];
                tabla[j + 1] = temp;
            }
        }
    }
}

void mostrar_tabla(struct Atleta tabla[], int numAtletas) {
    printf("|   Atleta   |  Intento 1 |  Intento 2 |  Intento 3 |  Intento 4 |  Intento 5 | Puntos |\n");
    for (int i = 0; i < numAtletas; i++) {
        printf("| %-10s |", tabla[i].nombre);
        for (int j = 0; j < 5; j++) {
            if (tabla[i].intentos[j] == -1.0) {
                printf("     NL    |");
            } else {
                printf("    %.2f   |", tabla[i].intentos[j]);
            }
        }
        printf("  %.1f  |\n", tabla[i].puntos);
    }
}

double calcular_puntos(double intentos[], int numIntentos) {
    double mejorIntento = 0.0;
    for (int i = 0; i < numIntentos; i++) {
        if (intentos[i] > mejorIntento) {
            mejorIntento = intentos[i];
        }
    }
    return (mejorIntento * 13.4);
}