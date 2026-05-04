#ifndef BT_HPP
#define BT_HPP

#include "common.hpp"

/*
 * ENTRADA:
 *   n: Número total de elementos disponibles.
 *   m: Número de elementos a seleccionar.
 *   d: Matriz de distancias entre elementos.
 * SALIDA:
 *   Una estructura Solucion con el valor máximo y el vector de selección.
 */
Solucion AlgoritmoBT(int n, int m, const vector<vector<int>>& d);

#endif
