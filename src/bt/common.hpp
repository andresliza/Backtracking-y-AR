#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>

using namespace std;

/* 
 * Estructura para almacenar la solución del problema de Máxima Diversidad.
 * Contiene el valor máximo de diversidad encontrado y el vector de decisiones.
 */
struct Solucion {
    int valor;                 // Valor de la Óptima Actual (voa)
    vector<int> elegidos;      // Tupla de la Óptima Actual (soa)
};

#endif
