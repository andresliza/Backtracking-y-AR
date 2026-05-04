
FUNCION AlgoritmoBT(n, m, d)

    nivel = 0
    Vector s[n] = InicializarVector(-1)    // Tupla solución
    soa = VACIO
    voa = -1
    
    MIENTRAS nivel != -1
    
        Generar(nivel, s)
        
        SI EsSolucion(nivel, s, m) ENTONCES
            v = CalcularSolucion(s, d)
            
            SI Mejora(v, voa) ENTONCES
                voa = v
                soa = Copia(s)
            FIN SI
        FIN SI
            
        SI Criterio(nivel, s, voa, n, m) ENTONCES
            nivel = nivel + 1
        SI NO
            MIENTRAS nivel >= 0 Y NO HayHermanos(nivel, s) HACER
                Retroceder(nivel, s)
            FIN MIENTRAS
        FIN SI
        
    FIN MIENTRAS
    
    DEVOLVER {soa, voa}

FIN FUNCION

// Subrutinas auxiliares

FUNCION Generar(nivel, s)
    s[nivel] = s[nivel] + 1
FIN FUNCION

FUNCION HayHermanos(nivel, s)
    DEVOLVER s[nivel] < 1
FIN FUNCION

FUNCION Retroceder(nivel, s)
    s[nivel] = -1
    nivel = nivel - 1
FIN FUNCION

FUNCION EsSolucion(nivel, s, m)
    DEVOLVER ContarElegidos(s) == m Y nivel == n - 1
FIN FUNCION

FUNCION Mejora(v, voa)
    DEVOLVER v > voa
FIN FUNCION

FUNCION CalcularSolucion(s, d)
    v = 0
    
    PARA i = 0 HASTA Tamaño(s) - 1
        PARA j = 0 HASTA Tamaño(s) - 1
            SI s[i] == 1 Y s[j] == 1 HACER
                v = v + d[i, j]
            FIN SI
        FIN PARA
    FIN PARA 
    
    DEVOLVER v
FIN FUNCION

FUNCION Criterio(nivel, s, voa, n, m)

    elegidos = ContarElegidosHasta(s, nivel)
    restantes = (n - 1) - nivel
    
    SI elegidos > m ENTONCES DEVOLVER FALSO
    
    SI (elegidos + restantes) < m DEVOLVER FALSO
    
    DEVOLVER VERDADERO 

FIN FUNCION

FUNCION Principal

    // Número de casos de prueba
    Leer T
    
    PARA i = 0 HASTA T-1 HACER
        // n = número de elementos, m = tamaño de la subpoblacion
        Leer n, m
        Matriz d[n, n]
        
        PARA j = 0 HASTA n - 1 HACER
            PARA k = 0 HASTA n - 1 HACER
                Leer d[j, k]
            FIN PARA
        FIN PARA

        // Ejecutar algoritmo
        {soa, voa} = AlgoritmoBT(n, m, d)
        Escribir(voa)
    FIN PARA

FIN FUNCION
