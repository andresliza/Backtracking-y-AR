# 🏳️‍🌈 Problema de Máxima Diversidad -- Backtracking 

# 🧮 Contexto

De una población se pretende seleccionar una subpoblación, y se quiere que la población sea diversa, por lo que se seleccionan los individuos más distantes entre sí.


# 📚 El Problema

Tenemos $n$ elementos de los que hay que seleccionar $m$. Entre cada dos elementos i y j hay una distancia d(i,j). De todos los subconjuntos de $m$ elementos queremos obtener el que da la mayor suma de distancias entre elementos en el subconjunto: 

$$ \max_{S} \sum_{i,j \in S} d(i,j) $$

# 🫐 Entrada

La primera línea de la entrada contiene un entero, T, que indica el número de casos de prueba.

Cada caso de prueba contiene una primera línea con dos números con los valores de n y m. A continuación hay n líneas, cada una con n enteros, para representar las distancias d. La distancia de un elemento a sí mismo será siempre cero, y las distancias entre dos elementos dados pueden variar dependiendo del sentido.

# 🦘 Salida

Para cada caso de prueba, la salida es una línea con el máximo beneficio obtenido.

# 🪱 Ejemplo de Entrada

```
3
4 2
0 3 2 4
2 0 4 5
2 1 0 4
2 3 2 0
4 3
0 3 2 4
2 0 4 5
2 1 0 4
2 3 2 0
6 3
0 5 4 2 5 3
4 0 1 1 3 3 
2 5 0 3 0 4 
3 3 4 0 4 7 
2 5 7 5 0 6 
4 8 5 6 8 0
```

# 🦋 Ejemplo de Salida

```
8
19
36
```
