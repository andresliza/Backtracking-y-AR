#include "bt_aux.hpp"

Solucion AlgoritmoBT(int n, int m, const vector<vector<int>>& d) {
    int nivel = 0, v_act = 0, m_act = 0;
    vector<int> s(n, -1);
    Solucion optima = {-1, vector<int>(n, 0)};

    // buscamos la distancia más grande de la tabla para usarla en las estimaciones (poda)
    int d_max = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (d[i][j] > d_max) d_max = d[i][j];

    while (nivel != -1) {
        Generar(nivel, s, d, v_act, m_act);

        // si ya hemos elegido m elementos, tenemos una solución completa. podamos esta rama.
        if (m_act == m) {
            if (v_act > optima.valor) {
                optima.valor = v_act;
                optima.elegidos = s;
                // los niveles que faltan son todos 0
                for (int i = nivel + 1; i < n; ++i) optima.elegidos[i] = 0;
            }
        }

        /* 
         * bajamos de nivel solo si:
         * 1. no estamos en el último nivel
         * 2. aún no hemos llegado a una subpoblación de tamaño m
         * 3. el criterio nos dice que hay esperanza de mejorar.
         */
        if (nivel < n - 1 && m_act < m && Criterio(nivel, n, m, m_act, v_act, optima.valor, d_max)) {
            nivel++;
        } else {
            // retrocedemos buscando otro camino.
            while (nivel >= 0 && !HayHermanos(nivel, s)) {
                Retroceder(nivel, s, d, v_act, m_act);
            }
        }
    }
    return optima;
}
