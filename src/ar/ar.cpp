#include "ar.hpp"
#include <limits>

SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos) {
    vector<bool> tareasCompletadas(n, false); // vector de tamaño n que indica si la tarea i está completada
    vector<int> cargaMaquinas(m, 0); // tiempo acumulado de cada maquina
    SolucionAR sol;
    
    int tareasRestantes = n;
    
    while (tareasRestantes > 0) {
        int mejorTarea = -1;
        int mejorMaquina = -1;
        int minimoFin = numeric_limits<int>::max(); // infinito, básicamente
        
        for (int i = 0; i < n; ++i) {
        // si la tarea elegida no está completada
            if (!tareasCompletadas[i]) {
                for (int j = 0; j < m; ++j) {
                // vemos si su tiempo en la máquina + el tiempo acumulado en la máquina
                // es menor que el tiempo menor que ya tiene acumulado.
                    int tiempoFin = cargaMaquinas[j] + tiempos[i][j];
                    if (tiempoFin < minimoFin) {
                        minimoFin = tiempoFin;
                        mejorTarea = i;
                        mejorMaquina = j;
                    }
                }
            }
        }
        
        // actualizamos el tiempo acumulado de la mejor maquina
        cargaMaquinas[mejorMaquina] = minimoFin;
        tareasCompletadas[mejorTarea] = true;
        // usamos índices que empiezan en 1, por eso el +1
        sol.ordenTareas.push_back(mejorTarea + 1);
        sol.asignacionMaquinas.push_back(mejorMaquina + 1);
        tareasRestantes--;
    }
    
    // el tiempo total es el máximo de los tiempos acumulados de cada máquina
    sol.tiempoTotal = 0;
    for (int carga : cargaMaquinas) {
        if (carga > sol.tiempoTotal) sol.tiempoTotal = carga;
    }
    
    return sol;
}
