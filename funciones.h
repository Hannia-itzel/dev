#pragma once
#include "estructuras.h"

double calcular_lanzamiento();
int decidir_intento();
void ordenar_tabla(struct Atleta tabla[], int numAtletas);
void mostrar_tabla(struct Atleta tabla[], int numAtletas);
double calcular_puntos(double intentos[], int numIntentos);
