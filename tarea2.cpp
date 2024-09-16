#include <iostream>
#include <vector>
#include <chrono>

#define MAX 500

void multiplicacionMatrices(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &C) {
    for (std::size_t i = 0; i < MAX; ++i) {
        for (std::size_t j = 0; j < MAX; ++j) {
            C[i][j] = 0;
            for (std::size_t k = 0; k < MAX; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> A(MAX, std::vector<int>(MAX, 1));
    std::vector<std::vector<int>> B(MAX, std::vector<int>(MAX, 2));
    std::vector<std::vector<int>> C(MAX, std::vector<int>(MAX, 0));

    auto start = std::chrono::high_resolution_clock::now();
    multiplicacionMatrices(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo para la multiplicacion de matrices de tamano " << MAX << ": " << duration.count() << " segundos." << std::endl;

    return 0;
}
