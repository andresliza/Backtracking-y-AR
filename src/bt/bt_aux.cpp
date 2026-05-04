#include "bt_aux.hpp"

void Generar(int nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act) {
    s[nivel]++;
    if (s[nivel] == 1) {
        for (int i = 0; i < nivel; ++i) {
            if (s[i] == 1) {
                v_act += d[i][nivel] + d[nivel][i];
            }
        }
    }
}

void Retroceder(int& nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act) {
    if (s[nivel] == 1) {
        for (int i = 0; i < nivel; ++i) {
            if (s[i] == 1) {
                v_act -= (d[i][nivel] + d[nivel][i]);
            }
        }
    }
    s[nivel] = -1;
    nivel--;
}

bool HayHermanos(int nivel, const vector<int>& s) {
    return s[nivel] < 1;
}

int ContarElegidos(const vector<int>& s, int nivel) {
    int cuenta = 0;
    for (int i = 0; i <= nivel; ++i) {
        if (s[i] == 1) cuenta++;
    }
    return cuenta;
}

bool Criterio(int nivel, int n, int m, const vector<int>& s) {
    int elegidos = ContarElegidos(s, nivel);
    int restantes = (n - 1) - nivel;
    if (elegidos > m) return false;
    if (elegidos + restantes < m) return false;
    return true;
}
