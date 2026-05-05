#ifndef AR_HPP
#define AR_HPP

#include <vector>

using namespace std;

/* 
 * Estructura para almacenar la solución del problema de Programación de Tareas.
 */
struct SolucionAR {
    int tiempoTotal;               // Makespan (tiempo de la máquina con más carga)
    vector<int> ordenTareas;       // Orden en el que se seleccionan las tareas
    vector<int> asignacionMaquinas; // Máquina asignada a cada tarea en ese orden
};

/*
 * Ejecuta el algoritmo voraz (Avance Rápido) para el problema de programación de tareas.
...
 * n: número de tareas
 * m: número de máquinas
 * tiempos: matriz n x m con los tiempos de cada tarea en cada máquina
 */
SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos);

#endif
