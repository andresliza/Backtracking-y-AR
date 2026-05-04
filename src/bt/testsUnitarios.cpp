#include <iostream>
#include <vector>
#include <cassert>
#include "bt.hpp"

using namespace std;

/*
 * FUNCIONAMIENTO:
 *   Ejecuta el algoritmo de backtracking con los parámetros dados y verifica
 *   si el resultado coincide con el valor esperado usando aserciones.
 */
void ejecutarTest(string nombreTest, int n, int m, const vector<vector<int>>& d, int valorEsperado) {
    Solucion sol = AlgoritmoBT(n, m, d);
    
    if (sol.valor == valorEsperado) {
        cout << "[OK] " << nombreTest << " pasado correctamente (Valor: " << sol.valor << ")" << endl;
    } else {
        cout << "[ERROR] " << nombreTest << " falló. Esperado: " << valorEsperado << ", Obtenido: " << sol.valor << endl;
        assert(false);
    }
}

int main() {
    cout << "--- Ejecutando Tests Unitarios (Máxima Diversidad) ---" << endl;

    // Ejemplo 1 del enunciado
    vector<vector<int>> d1 = {
        {0, 3, 2, 4},
        {2, 0, 4, 5},
        {2, 1, 0, 4},
        {2, 3, 2, 0}
    };
    ejecutarTest("Ejemplo 1 (n=4, m=2)", 4, 2, d1, 8);

    // Ejemplo 2 del enunciado
    vector<vector<int>> d2 = {
        {0, 3, 2, 4},
        {2, 0, 4, 5},
        {2, 1, 0, 4},
        {2, 3, 2, 0}
    };
    ejecutarTest("Ejemplo 2 (n=4, m=3)", 4, 3, d2, 19);

    // Ejemplo 3 del enunciado
    vector<vector<int>> d3 = {
        {0, 5, 4, 2, 5, 3},
        {4, 0, 1, 1, 3, 3},
        {2, 5, 0, 3, 0, 4},
        {3, 3, 4, 0, 4, 7},
        {2, 5, 7, 5, 0, 6},
        {4, 8, 5, 6, 8, 0}
    };
    ejecutarTest("Ejemplo 3 (n=6, m=3)", 6, 3, d3, 36);

    cout << "✓ Todos los tests unitarios pasaron correctamente." << endl;
    return 0;
}
