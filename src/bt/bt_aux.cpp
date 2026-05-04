#include "bt_aux.hpp"

void Generar(int nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act) {
    // la progresión es: -1 (no elegido) -> 1 (elegido) -> 0 (descartado)
    // si lo elegimos, incrementamos la subpoblacion y sumamos lo que aporta
    if (s[nivel] == -1) {
        s[nivel] = 1; 
        m_act++;
        for (int i = 0; i < nivel; ++i) 
            if (s[i] == 1) v_act += d[i][nivel] + d[nivel][i];
    // si ya lo hemos elegido, lo dejamos fuera deshaciendo los cambios
    } else if (s[nivel] == 1) {
        for (int i = 0; i < nivel; ++i) 
            if (s[i] == 1) v_act -= (d[i][nivel] + d[nivel][i]);
        m_act--;
        s[nivel] = 0; 
    }
}

void Retroceder(int& nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act) {
    // si habíamos elegido el elemento, deshacemos sus cambios
    if (s[nivel] == 1) {
        for (int i = 0; i < nivel; ++i) 
            if (s[i] == 1) v_act -= (d[i][nivel] + d[nivel][i]);
        m_act--;
    }
    s[nivel] = -1; // lo dejamos como "no explorado"
    nivel--;
}

bool HayHermanos(int nivel, const vector<int>& s) {
    // solo hay hermanos si l nivel es 1 (1->0).
    return s[nivel] == 1;
}

bool Criterio(int nivel, int n, int m, int m_act, int v_act, int voa, int d_max) {
    // no seguimos si ya nos pasamos de m, o si aunque eligiéramos a todos los 
    // que quedan no llegaríamos a juntar m.
    int restantes = (n - 1) - nivel;
    if (m_act > m || m_act + restantes < m) return false;

    // si todos los elementos que faltan tuvieran la distancia máxima y aún así superamos la
    // solución actual, podemos podar con seguridad
    int terminos_totales = m * (m - 1);
    int terminos_actuales = m_act * (m_act - 1);
    int cota_superior = v_act + (terminos_totales - terminos_actuales) * d_max;
    if (voa != -1 && cota_superior <= voa) return false;

    return true;
}
