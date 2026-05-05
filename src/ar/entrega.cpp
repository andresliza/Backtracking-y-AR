#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct SolucionAR {
    int tiempoTotal;
    vector<int> ordenTareas;
    vector<int> asignacionMaquinas;
};

SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos) {
    vector<bool> tareasCompletadas(n, false);
    vector<int> cargaMaquinas(m, 0);
    SolucionAR sol;
    
    int tareasRestantes = n;
    
    while (tareasRestantes > 0) {
        int mejorTarea = -1;
        int mejorMaquina = -1;
        int minimoFin = numeric_limits<int>::max();
        
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
        
        cargaMaquinas[mejorMaquina] = minimoFin;
        tareasCompletadas[mejorTarea] = true;
        sol.ordenTareas.push_back(mejorTarea + 1);
        sol.asignacionMaquinas.push_back(mejorMaquina + 1);
        tareasRestantes--;
    }
    
    sol.tiempoTotal = 0;
    for (int carga : cargaMaquinas) {
        if (carga > sol.tiempoTotal) sol.tiempoTotal = carga;
    }
    
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    if (!(cin >> P)) return 0;

    while (P--) {
        int n, m;
        if (!(cin >> n >> m)) break;

        vector<vector<int>> tiempos(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> tiempos[i][j];
            }
        }

        SolucionAR sol = AlgoritmoAR(n, m, tiempos);

        cout << sol.tiempoTotal << "\n";
        for (int i = 0; i < n; ++i) {
            cout << sol.ordenTareas[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << sol.asignacionMaquinas[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
