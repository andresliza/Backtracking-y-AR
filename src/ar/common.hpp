#ifndef COMMON_HPP
#define COMMON_HPP

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

#endif
