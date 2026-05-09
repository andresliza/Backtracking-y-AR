#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "bt_aux.hpp"

using namespace std;

// Peor caso refinado: matriz con distancias pequeñas (1) pero un d_max grande (100).
vector<vector<int>> generarMatrizPeorCaso(int n) {
    vector<vector<int>> d(n, vector<int>(n, 1));
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    d[n-1][n-2] = 100;
    d[n-2][n-1] = 100;
    return d;
}

// Mejor caso: Los primeros m elementos forman la solución óptima 
vector<vector<int>> generarMatrizMejorCaso(int n, int m) {
    vector<vector<int>> d(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i != j) d[i][j] = 100;
        }
    }
    return d;
}

double medirTiempo(int n, int m, const vector<vector<int>>& d) {
    auto start = chrono::high_resolution_clock::now();
    AlgoritmoBT(n, m, d);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

double calcularMediana(vector<double> tiempos) {
    sort(tiempos.begin(), tiempos.end());
    int n = tiempos.size();
    if (n % 2 == 0) return (tiempos[n / 2 - 1] + tiempos[n / 2]) / 2.0;
    else return tiempos[n / 2];
}

int main() {
    srand(time(0));

    int m = 5;

    // --- PEOR CASO (se mantiene igual, ya validado) ---
    ofstream csv_peor("resultados_peor.csv");
    csv_peor << "N,M,Tiempo_Mediano_us\n";
    cout << "--- Generando Peor Caso (Evitando podas) ---" << endl;
    for (int n = 10; n <= 30; n += 2) {
        vector<double> tiempos;
        vector<vector<int>> d = generarMatrizPeorCaso(n);
        for (int i = 0; i < 3; ++i) tiempos.push_back(medirTiempo(n, m, d));
        double mediana = calcularMediana(tiempos);
        csv_peor << n << "," << m << "," << mediana << "\n";
        cout << "N=" << n << "\t" << mediana / 1000.0 << " ms" << endl;
    }
    csv_peor.close();

    // --- MEJOR CASO (Ampliado para detectar curvatura) ---
    ofstream csv_mejor("resultados_mejor.csv");
    csv_mejor << "N,M,Tiempo_Mediano_us\n";
    cout << "\n--- Generando Mejor Caso (Ampliado N hasta 500) ---" << endl;
    for (int n = 10; n <= 500; n += 20) {
        vector<double> tiempos;
        vector<vector<int>> d = generarMatrizMejorCaso(n, m);
        // ejecutamos 10 veces para mayor precisión
        for (int i = 0; i < 10; ++i) tiempos.push_back(medirTiempo(n, m, d));
        double mediana = calcularMediana(tiempos);
        csv_mejor << n << "," << m << "," << mediana << "\n";
        cout << "N=" << n << "\t" << mediana / 1000.0 << " ms" << endl;
    }
    csv_mejor.close();

    cout << "------------------------------------------" << endl;
    return 0;
}
