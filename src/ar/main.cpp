#include <iostream>
#include <vector>

using namespace std;

struct SolucionAR {
    int tiempoTotal;
    vector<int> ordenTareas;
    vector<int> asignacionMaquinas;
};

// Declaración de la función que está en ar.cpp
SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos);

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
