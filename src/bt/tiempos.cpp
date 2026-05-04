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

vector<vector<int>> generarMatrizDistancias(int n) {
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = rand() % 100;
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

    // N crece de 2 en 2, pero M tiene un tope de 5
    vector<int> ns;
    for (int i = 4; i <= 60; i += 2) ns.push_back(i);

    ofstream csv("resultados.csv");
    csv << "N,M,Tiempo_Mediano_us\n";

    cout << "--- Análisis Experimental (M limitado a 5) ---" << endl;
    cout << "N\tM\tTiempo Mediano (ms)" << endl;
    cout << "------------------------------------------" << endl;

    for (int n : ns) {
        // M es el mínimo entre 5 y n/2
        int m = min(5, n / 2); 
        vector<double> tiempos;
        
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
    return 0;
}
