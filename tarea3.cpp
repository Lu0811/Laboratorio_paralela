#include <iostream>
#include <chrono>

const int N = 500;
const int TAMANIO_BLOQUE = 50;

void inicializar_matrices(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }
}

void multiplicacion_matrices_por_bloques(double A[N][N], double B[N][N], double C[N][N]) {
    for (int ii = 0; ii < N; ii += TAMANIO_BLOQUE) {
        for (int jj = 0; jj < N; jj += TAMANIO_BLOQUE) {
            for (int kk = 0; kk < N; kk += TAMANIO_BLOQUE) {
                for (int i = ii; i < std::min(ii + TAMANIO_BLOQUE, N); ++i) {
                    for (int j = jj; j < std::min(jj + TAMANIO_BLOQUE, N); ++j) {
                        for (int k = kk; k < std::min(kk + TAMANIO_BLOQUE, N); ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    double A[N][N], B[N][N], C[N][N];

    inicializar_matrices(A, B, C);

    auto inicio = std::chrono::high_resolution_clock::now();
    
    multiplicacion_matrices_por_bloques(A, B, C);
    
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "Tiempo de ejecución (bloques): " << duracion.count() << " segundos\n";

    return 0;
}
