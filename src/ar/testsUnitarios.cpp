#include <iostream>
#include <vector>
#include <cassert>
#include "ar.hpp"

using namespace std;

void ejecutarTest(string nombreTest, int n, int m, const vector<vector<int>>& tiempos, int tiempoEsperado) {
    SolucionAR sol = AlgoritmoAR(n, m, tiempos);
    
    if (sol.tiempoTotal == tiempoEsperado) {
        cout << "[OK] " << nombreTest << " pasado correctamente (Tiempo: " << sol.tiempoTotal << ")" << endl;
    } else {
        cout << "[ERROR] " << nombreTest << " falló. Esperado: " << tiempoEsperado << ", Obtenido: " << sol.tiempoTotal << endl;
        assert(false);
    }
}

int main() {
    cout << "--- Ejecutando Tests Unitarios (Programación de Tareas) ---" << endl;

    // Ejemplo 1
    vector<vector<int>> t1 = {
        {13, 25},
        {7, 16},
        {22, 19},
        {13, 14},
        {14, 23}
    };
    ejecutarTest("Ejemplo 1 (n=5, m=2)", 5, 2, t1, 34);

    // Ejemplo 2
    vector<vector<int>> t2 = {
        {21, 22, 24, 25, 9},
        {7, 26, 22, 7, 2},
        {21, 13, 22, 17, 20},
        {10, 19, 1, 6, 12},
        {4, 6, 10, 9, 17},
        {13, 11, 3, 19, 22},
        {17, 13, 19, 16, 13}
    };
    ejecutarTest("Ejemplo 2 (n=7, m=5)", 7, 5, t2, 16);

    cout << "✓ Todos los tests unitarios pasaron correctamente." << endl;
    return 0;
}
