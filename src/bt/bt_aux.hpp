#ifndef BT_AUX_HPP
#define BT_AUX_HPP

#include "common.hpp"

// Intenta elegir el elemento actual (1) y si no, prueba a no elegirlo (0).
// Es como ir probando opciones en un examen: primero la que más puntos da.
void Generar(int nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act);

// Deshace lo que hicimos en Generar para poder volver atrás en el árbol.
// Limpia el rastro para que la siguiente rama empiece de cero.
void Retroceder(int& nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act, int& m_act);

// ¿Nos queda alguna opción por probar en este nivel?
bool HayHermanos(int nivel, const vector<int>& s);

/*
 * Esta es la función clave de la "poda". 
 * Decide si vale la pena seguir bajando por esta rama o si es una pérdida de tiempo.
 */
bool Criterio(int nivel, int n, int m, int m_act, int v_act, int voa, int d_max);

#endif
