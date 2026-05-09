# 📝 Diseño en pseudocódigo (Backtracking)

## 1. Programa Principal
El programa principal lee la matriz de distancias y el tamaño de la subpoblación deseada ($m$), llama al algoritmo y muestra el valor de la diversidad máxima encontrada.

```pseudo
FUNCION Principal

    // Número de casos de prueba
    Leer T
    
    PARA i = 0 HASTA T-1 HACER
        // n = número de elementos, m = tamaño de la subpoblación
        Leer n, m
        Matriz d[n, n]
        
        PARA j = 0 HASTA n - 1 HACER
            PARA k = 0 HASTA n - 1 HACER
                Leer d[j, k]
            FIN PARA
        FIN PARA

        // Ejecutar algoritmo de Backtracking
        {soa, voa} = AlgoritmoBT(n, m, d)
        
        // Escribir el valor de la diversidad máxima
        Escribir(voa)
    FIN PARA

FIN FUNCION
```

## 2. Algoritmo de Backtracking (Iterativo)
Para evitar problemas de memoria en la pila, hemos diseñado una versión iterativa que simula el recorrido del árbol de decisión mediante un bucle `MIENTRAS` y un control manual del nivel.

```pseudo
FUNCION AlgoritmoBT(n, m, d)

    nivel = 0
    Vector s[n] = InicializarVector(-1)    // -1: sin explorar, 1: elegido, 0: descartado
    soa = VACIO
    voa = -1
    
    MIENTRAS nivel != -1
    
        Generar(nivel, s)
        
        // Si hemos llegado a elegir m elementos, tenemos una solución candidata
        SI m_act == m ENTONCES
            SI v_act > voa ENTONCES
                voa = v_act
                soa = Copia(s)
            FIN SI
        FIN SI
            
        // Comprobamos si merece la pena seguir bajando por esta rama
        SI nivel < n - 1 Y m_act < m Y Criterio(nivel, s, voa, n, m) ENTONCES
            nivel = nivel + 1
        SI NO
            // Si no podemos bajar, buscamos el siguiente hermano o retrocedemos
            MIENTRAS nivel >= 0 Y NO HayHermanos(nivel, s) HACER
                Retroceder(nivel, s)
            FIN MIENTRAS
        FIN SI
        
    FIN MIENTRAS
    
    DEVOLVER {soa, voa}

FIN FUNCION
```

## 3. Subrutinas Auxiliares
Estas funciones gestionan los cambios de estado en el árbol y las podas para mejorar el rendimiento.

```pseudo
FUNCION Generar(nivel, s)
    // Pasa de -1 a 1 (elegir), o de 1 a 0 (descartar)
    SI s[nivel] == -1 ENTONCES 
        s[nivel] = 1
    SINO 
        s[nivel] = 0
    FIN SI
FIN FUNCION

FUNCION HayHermanos(nivel, s)
    // Solo hay hermanos si acabamos de probar a elegir el elemento (1)
    DEVOLVER s[nivel] == 1
FIN FUNCION

FUNCION Retroceder(nivel, s)
    s[nivel] = -1 // Resetear estado para futuras exploraciones
    nivel = nivel - 1
FIN FUNCION

FUNCION Criterio(nivel, s, voa, n, m)
    // Poda por tamaño: ¿podemos llegar todavía a m elementos?
    SI (m_act + restantes) < m ENTONCES DEVOLVER FALSO
    
    // Poda por cota superior: ¿es posible mejorar la voa?
    SI CotaSuperior(v_act) <= voa ENTONCES DEVOLVER FALSO
    
    DEVOLVER VERDADERO 
FIN FUNCION
```
