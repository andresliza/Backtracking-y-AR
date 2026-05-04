#include "bt.hpp"
#include "bt_aux.hpp"

/*
 * ENTRADA:
 *   n: Número total de elementos.
 *   m: Tamaño del subconjunto.
 *   d: Matriz de distancias.
 * SALIDA:
 *   Solucion con la diversidad máxima.
 */
Solucion AlgoritmoBT(int n, int m, const vector<vector<int>>& d) {
    int nivel = 0;
    int v_act = 0;
    vector<int> s(n, -1);
    Solucion optima = {-1, vector<int>()};

    while (nivel != -1) {
        Generar(nivel, s, d, v_act);

        if (nivel == n - 1) {
            if (ContarElegidos(s, nivel) == m) {
                if (optima.valor == -1 || v_act > optima.valor) {
                    optima.valor = v_act;
                    optima.elegidos = s;
                }
            }
        }

        if (nivel < n - 1 && Criterio(nivel, n, m, s)) {
            nivel++;
        } else {
            while (nivel >= 0 && !HayHermanos(nivel, s)) {
                Retroceder(nivel, s, d, v_act);
            }
        }
    }
    return optima;
}
