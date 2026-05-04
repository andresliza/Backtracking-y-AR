#ifndef BT_AUX_HPP
#define BT_AUX_HPP

#include "common.hpp"

/*
 * ENTRADA:
 *   nivel: Nivel actual del árbol.
 *   s: Vector de decisiones.
 *   d: Matriz de distancias.
 *   v_act: Valor acumulado actual (referencia).
 * FUNCIONAMIENTO:
 *   Suma 1 al valor de s[nivel] y actualiza v_act si se elige el elemento.
 */
void Generar(int nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act);

/*
 * ENTRADA:
 *   nivel: Nivel actual (referencia).
 *   s: Vector de decisiones.
 *   d: Matriz de distancias.
 *   v_act: Valor acumulado actual (referencia).
 * FUNCIONAMIENTO:
 *   Deshace la decisión de s[nivel], actualiza v_act y decrementa el nivel.
 */
void Retroceder(int& nivel, vector<int>& s, const vector<vector<int>>& d, int& v_act);

/*
 * ENTRADA:
 *   nivel: Nivel actual.
 *   s: Vector de decisiones.
 * SALIDA:
 *   Verdadero si s[nivel] tiene más opciones por probar.
 */
bool HayHermanos(int nivel, const vector<int>& s);

/*
 * ENTRADA:
 *   s: Vector de decisiones.
 *   nivel: Nivel hasta el que contar.
 * SALIDA:
 *   Número de elementos elegidos (s[i] == 1).
 */
int ContarElegidos(const vector<int>& s, int nivel);

/*
 * ENTRADA:
 *   nivel: Nivel actual.
 *   n: Tamaño total.
 *   m: Tamaño objetivo.
 *   s: Vector de decisiones.
 * SALIDA:
 *   Verdadero si la rama es prometedora (poda por población).
 */
bool Criterio(int nivel, int n, int m, const vector<int>& s);

#endif
