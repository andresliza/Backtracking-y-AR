#include "ar.hpp"
#include <algorithm>
#include <limits>

SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos) {
    vector<bool> tareasCompletadas(n, false);
    vector<int> cargaMaquinas(m, 0);
    SolucionAR sol;
    
    int tareasRestantes = n;
    
    while (tareasRestantes > 0) {
        int mejorTarea = -1;
        int mejorMaquina = -1;
        int minimoFin = std::numeric_limits<int>::max();
        
        // Buscamos el par (tarea, máquina) que termine antes
        for (int i = 0; i < n; ++i) {
            if (!tareasCompletadas[i]) {
                for (int j = 0; j < m; ++j) {
                    int tiempoFin = cargaMaquinas[j] + tiempos[i][j];
                    if (tiempoFin < minimoFin) {
                        minimoFin = tiempoFin;
                        mejorTarea = i;
                        mejorMaquina = j;
                    }
                }
            }
        }
        
        // Actualizamos estado
        cargaMaquinas[mejorMaquina] = minimoFin;
        tareasCompletadas[mejorTarea] = true;
        sol.ordenTareas.push_back(mejorTarea + 1); // 1-based
        sol.asignacionMaquinas.push_back(mejorMaquina + 1); // 1-based
        tareasRestantes--;
    }
    
    // El tiempo total es el máximo de las cargas
    sol.tiempoTotal = 0;
    for (int carga : cargaMaquinas) {
        if (carga > sol.tiempoTotal) sol.tiempoTotal = carga;
    }
    
    return sol;
}
