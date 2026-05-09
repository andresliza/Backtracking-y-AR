#ifndef BT_AUX_HPP
#define BT_AUX_HPP

#include <vector>

using namespace std;

struct Solucion {
    int valor;                 // valor de la Óptima Actual (voa)
    vector<int> elegidos;      // tupla de la Óptima Actual (soa)
};

// Función principal
Solucion AlgoritmoBT(int n, int m, const vector<vector<int>>& d);

// Funciones auxiliares
void Generar(int nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act);
void Retroceder(int& nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act);
bool HayHermanos(int nivel, const vector<int>& s);
bool Criterio(int nivel, int n, int m, int m_act, int v_act, int voa, int d_max);

#endif
