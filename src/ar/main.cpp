#include <iostream>
#include "ar.hpp"

using namespace std;

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
