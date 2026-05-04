#include <iostream>
#include "bt.hpp"

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n, m;
        if (!(cin >> n >> m)) break;

        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> d[i][j];
            }
        }

        Solucion s = AlgoritmoBT(n, m, d);
        cout << s.valor << endl;
    }

    return 0;
}
