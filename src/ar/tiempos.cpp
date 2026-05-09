#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "ar.hpp"

using namespace std;

vector<vector<int>> generarMatrizTiempos(int n, int m) {
    vector<vector<int>> t(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            t[i][j] = rand() % 100 + 1; // Tiempos entre 1 y 100
        }
    }
    return t;
}

double medirTiempo(int n, int m, const vector<vector<int>>& t) {
    auto start = chrono::high_resolution_clock::now();
    AlgoritmoAR(n, m, t);
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

    vector<int> ns;
    for (int i = 100; i <= 2500; i += 100) ns.push_back(i);

    ofstream csv("resultados_ar.csv");
    csv << "N,M,Tiempo_Mediano_us\n";

    cout << "--- Análisis Experimental (M fijo en 10) ---" << endl;
    cout << "N\tM\tTiempo Mediano (ms)" << endl;
    cout << "------------------------------------------" << endl;

    int m_fijo = 10;
    for (int n : ns) {
        vector<double> tiempos;
        
        for (int i = 0; i < 10; ++i) {
            vector<vector<int>> t = generarMatrizTiempos(n, m_fijo);
            tiempos.push_back(medirTiempo(n, m_fijo, t));
        }

        double mediana = calcularMediana(tiempos);
        csv << n << "," << m_fijo << "," << mediana << "\n";
        
        cout << n << "\t" << m_fijo << "\t" << mediana / 1000.0 << " ms" << endl;
    }

    csv.close();
    cout << "------------------------------------------" << endl;
    return 0;
}
