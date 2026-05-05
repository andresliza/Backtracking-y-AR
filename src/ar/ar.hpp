#ifndef AR_HPP
#define AR_HPP

#include <vector>

using namespace std;

struct SolucionAR {
    int tiempoTotal;
    vector<int> ordenTareas;
    vector<int> asignacionMaquinas;
};

SolucionAR AlgoritmoAR(int n, int m, const vector<vector<int>>& tiempos);

#endif
