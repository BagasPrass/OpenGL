#include <iostream>

using namespace std;

int main() {
    // Matriks A
    int A[3][3] = { {1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9} };

    // Matriks B
    int B[3][3] = { {9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1} };

    // Matriks hasil perkalian
    int C[3][3] = { {0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0} };

    // Perkalian matriks
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Menampilkan hasil perkalian
    cout << "Hasil perkalian matriks A dan B:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
