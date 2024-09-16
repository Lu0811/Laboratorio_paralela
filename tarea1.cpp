#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

double matriz[MAX][MAX], vector[MAX], resultado1[MAX], resultado2[MAX];

void inicializar_arrays() {
    for (int i = 0; i < MAX; i++) {
        vector[i] = rand() % 100;
        resultado1[i] = 0.0;
        resultado2[i] = 0.0;
        for (int j = 0; j < MAX; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}

void bucle_eficiente() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            resultado1[i] += matriz[i][j] * vector[j];
        }
    }
}

void bucle_ineficiente() {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            resultado2[i] += matriz[i][j] * vector[j];
        }
    }
}

int main() {
    inicializar_arrays();

    clock_t inicio = clock();
    bucle_eficiente();
    clock_t fin = clock();
    double tiempo_bucle_eficiente = (double)(fin - inicio) / CLOCKS_PER_SEC;

    inicio = clock();
    bucle_ineficiente();
    fin = clock();
    double tiempo_bucle_ineficiente = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo del bucle eficiente (por filas): %f segundos\n", tiempo_bucle_eficiente);
    printf("Tiempo del bucle ineficiente (por columnas): %f segundos\n", tiempo_bucle_ineficiente);

    return 0;
}
