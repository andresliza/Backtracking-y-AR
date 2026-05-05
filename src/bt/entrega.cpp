#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para almacenar la solución del problema
struct Solucion {
    int valor;                 
    vector<int> elegidos;      
};

// Intenta elegir el elemento actual (1) y si no, prueba a no elegirlo (0).
void Generar(int nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act) {
    if (s[nivel] == -1) {
        s[nivel] = 1; 
        m_act++;
        for (int i = 0; i < nivel; ++i) 
            if (s[i] == 1) v_act += d[i][nivel] + d[nivel][i];
    } else if (s[nivel] == 1) {
        for (int i = 0; i < nivel; ++i) 
            if (s[i] == 1) v_act -= (d[i][nivel] + d[nivel][i]);
        m_act--;
        s[nivel] = 0; 
    }
}

// Deshace lo que hicimos en Generar para poder volver atrás en el árbol.
void Retroceder(int& nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act) {
    if (s[nivel] == 1) {
        for (int i = 0; i < nivel; ++i) 
            if (s[i] == 1) v_act -= (d[i][nivel] + d[nivel][i]);
        m_act--;
    }
    s[nivel] = -1; 
    nivel--;
}

// ¿Nos queda alguna opción por probar en este nivel?
bool HayHermanos(int nivel, const vector<int>& s) {
    return s[nivel] == 1;
}

// Función de poda
bool Criterio(int nivel, int n, int m, int m_act, int v_act, int voa, int d_max) {
    int restantes = (n - 1) - nivel;
    if (m_act > m || m_act + restantes < m) return false;

    // Cota superior para maximización
    if (voa != -1) {
        int terminos_totales = m * (m - 1);
        int terminos_actuales = m_act * (m_act - 1);
        long long cota_superior = (long long)v_act + (long long)(terminos_totales - terminos_actuales) * d_max;
        if (cota_superior <= voa) return false;
    }

    return true;
}

Solucion AlgoritmoBT(int n, int m, const vector<vector<int>>& d) {
    int nivel = 0, v_act = 0, m_act = 0;
    vector<int> s(n, -1);
    Solucion optima = {-1, vector<int>(n, 0)};

    int d_max = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (d[i][j] > d_max) d_max = d[i][j];

    while (nivel != -1) {
        Generar(nivel, s, d, v_act, m_act);

        if (m_act == m) {
            if (v_act > optima.valor) {
                optima.valor = v_act;
                optima.elegidos = s;
                for (int i = nivel + 1; i < n; ++i) optima.elegidos[i] = 0;
            }
        }

        if (nivel < n - 1 && m_act < m && Criterio(nivel, n, m, m_act, v_act, optima.valor, d_max)) {
            nivel++;
        } else {
            while (nivel >= 0 && !HayHermanos(nivel, s)) {
                Retroceder(nivel, s, d, v_act, m_act);
            }
        }
    }
    return optima;
}

int main() {
    // Optimización de entrada/salida para evitar Time Limit en Mooshak
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n, m;
        if (!(cin >> n >> m)) break;

        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> d[i][j];
            }
        }

        Solucion s = AlgoritmoBT(n, m, d);
        cout << s.valor << "\n"; // Usamos \n en lugar de endl por velocidad
    }

    return 0;
}
