#ifndef AR_HPP
#define AR_HPP

#include "common.hpp"

/*
 * Ejecuta el algoritmo voraz (Avance Rápido) para el problema de programación de tareas.
 * 
 * n: número de tareas
 * m: número de máquinas
 * tiempos: matriz n x m con los tiempos de cada tarea en cada máquina
 */
SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos);

#endif
