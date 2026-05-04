#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "bt.hpp"

using namespace std;

/*
 * FUNCIONAMIENTO:
 *   Genera una matriz de distancias aleatoria de tamaño n x n con valores entre 0 y 99.
 *   La diagonal principal siempre es 0.
 */
vector<vector<int>> generarMatrizDistancias(int n) {
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = rand() % 100;
            }
        }
    }
    return d;
}

/*
 * FUNCIONAMIENTO:
 *   Ejecuta el algoritmo una vez para una matriz dada y retorna el tiempo en microsegundos.
 */
double medirTiempo(int n, int m, const vector<vector<int>>& d) {
    auto start = chrono::high_resolution_clock::now();
    AlgoritmoBT(n, m, d);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

/*
 * FUNCIONAMIENTO:
 *   Calcula la mediana de un vector de tiempos (double).
 */
double calcularMediana(vector<double> tiempos) {
    sort(tiempos.begin(), tiempos.end());
    int n = tiempos.size();
    if (n % 2 == 0) {
        return (tiempos[n / 2 - 1] + tiempos[n / 2]) / 2.0;
    } else {
        return tiempos[n / 2];
    }
}

int main() {
    srand(time(0));

    // Tamaños de n a evaluar. 
    // Backtracking crece factorial/exponencialmente, por lo que n=28 ya puede tardar varios segundos.
    vector<int> ns = {4, 8, 12, 16, 20, 22, 24, 26}; 

    ofstream csv("resultados.csv");
    csv << "N,M,Tiempo_Mediano_us\n";

    cout << "--- Iniciando Análisis Experimental (Backtracking) ---" << endl;
    cout << "N\tM\tTiempo Mediano (ms)" << endl;
    cout << "------------------------------------------" << endl;

    for (int n : ns) {
        int m = n / 2; // Caso de mayor complejidad combinatoria
        vector<double> tiempos;
        
        // Ejecutar 10 veces para obtener una mediana (Estilo DyV)
        for (int i = 0; i < 10; ++i) {
            vector<vector<int>> d = generarMatrizDistancias(n);
            tiempos.push_back(medirTiempo(n, m, d));
        }

        double mediana = calcularMediana(tiempos);
        csv << n << "," << m << "," << mediana << "\n";
        
        cout << n << "\t" << m << "\t" << mediana / 1000.0 << " ms" << endl;
    }

    csv.close();
    cout << "------------------------------------------" << endl;
    cout << "✓ Análisis completado. Resultados guardados en 'resultados.csv'" << endl;
    
    return 0;
}
