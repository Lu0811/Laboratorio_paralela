#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>  // Para std::min

#define MAX 500
#define BLOCK_SIZE 50  // Tamaño del bloque

void multiplicacionBloques(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &C) {
    for (std::size_t i = 0; i < MAX; i += BLOCK_SIZE) {
        for (std::size_t j = 0; j < MAX; j += BLOCK_SIZE) {
            for (std::size_t k = 0; k < MAX; k += BLOCK_SIZE) {
                for (std::size_t ii = i; ii < std::min(i + BLOCK_SIZE, static_cast<std::size_t>(MAX)); ++ii) {
                    for (std::size_t jj = j; jj < std::min(j + BLOCK_SIZE, static_cast<std::size_t>(MAX)); ++jj) {
                        for (std::size_t kk = k; kk < std::min(k + BLOCK_SIZE, static_cast<std::size_t>(MAX)); ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> A(MAX, std::vector<int>(MAX, 1));
    std::vector<std::vector<int>> B(MAX, std::vector<int>(MAX, 2));
    std::vector<std::vector<int>> C(MAX, std::vector<int>(MAX, 0));

    // Medir tiempo para la multiplicación por bloques
    auto start = std::chrono::high_resolution_clock::now();
    multiplicacionBloques(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_bloques = end - start;
    std::cout << "Tiempo para la multiplicación de matrices por bloques de tamaño " << MAX << ": " << duration_bloques.count() << " segundos." << std::endl;

    // Resetear matriz C para medir la multiplicación clásica
    std::fill(C.begin(), C.end(), std::vector<int>(MAX, 0));

    // Medir tiempo para la multiplicación clásica
    start = std::chrono::high_resolution_clock::now();
    for (std::size_t i = 0; i < MAX; ++i) {
        for (std::size_t j = 0; j < MAX; ++j) {
            C[i][j] = 0;
            for (std::size_t k = 0; k < MAX; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_clasica = end - start;
    std::cout << "Tiempo para la multiplicación de matrices clásica de tamaño " << MAX << ": " << duration_clasica.count() << " segundos." << std::endl;

    // Comparación de resultados
    std::cout << "Multiplicación por bloques es " << (duration_clasica.count() / duration_bloques.count()) << " veces más rápida que la multiplicación clásica." << std::endl;

    return 0;
}
