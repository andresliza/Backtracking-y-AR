# 📝 Diseño en pseudocódigo (Avance Rápido)

## 1. Programa Principal
El programa principal se encarga de gestionar los casos de prueba, leer la entrada y mostrar los resultados una vez que el algoritmo ha terminado su trabajo.

```pseudo
FUNCION Principal

    // Número de casos de prueba
    Leer P
    
    PARA i = 1 HASTA P HACER
        // N = número de tareas, M = número de máquinas
        Leer N, M
        Matriz Tiempos[N, M]
        
        PARA j = 1 HASTA N HACER
            PARA k = 1 HASTA M HACER
                Leer Tiempos[j, k]
            FIN PARA
        FIN PARA

        // Ejecutar algoritmo de Avance Rápido
        {TiempoTotal, Resultado, MaquinasPorTarea} = AlgoritmoAR(N, M, Tiempos)
        
        // Escribir resultados según el formato de salida
        Escribir(TiempoTotal)
        Escribir(Resultado)           // N números: orden de las tareas
        Escribir(MaquinasPorTarea)    // N números: máquina de cada tarea
    FIN PARA

FIN FUNCION
```

## 2. Algoritmo de Avance Rápido (Voraz)
Este algoritmo sigue una estrategia voraz: en cada paso busca la mejor opción disponible en ese momento (la tarea y máquina que terminen lo antes posible) y la selecciona sin volver atrás.

```pseudo
FUNCION AlgoritmoAR(N, M, Tiempos[N][M])

   TareasPendientes = {1, 2, ..., N}     // Lista de tareas sin asignar
   TiempoAcumulado[M] = {0, 0, ..., 0}   // Carga actual de cada máquina
   Resultado = []                        // Orden en el que elegimos las tareas
   MaquinasPorTarea = []                 // Máquina elegida para cada tarea

   MIENTRAS TareasPendientes NO esté vacío HACER
   
       MejorTarea = -1
       MejorMaquina = -1
       MinimoFin = INFINITO // Para que la primera comparación siempre se cumpla
       
       // Buscamos la pareja (tarea, máquina) que termine más pronto
       PARA CADA tarea EN TareasPendientes HACER
           PARA maq = 1 HASTA M HACER
               // Calculamos cuándo terminaría esta tarea en esta máquina
               TiempoFin = TiempoAcumulado[maq] + Tiempos[tarea][maq]
               
               // Si es menor que lo que teníamos, es nuestro nuevo mejor candidato
               SI TiempoFin < MinimoFin ENTONCES
                   MinimoFin = TiempoFin
                   MejorTarea = tarea
                   MejorMaquina = maq
               FIN SI
           FIN PARA
       FIN PARA
       
       // Aplicamos la decisión y actualizamos el estado
       TiempoAcumulado[MejorMaquina] = MinimoFin
       Resultado.Añadir(MejorTarea)
       MaquinasPorTarea.Añadir(MejorMaquina)
       TareasPendientes.Eliminar(MejorTarea)
       
   FIN MIENTRAS
   
   // El tiempo total es la carga de la máquina que más tarde termina
   TiempoTotal = Maximo(TiempoAcumulado)
   
   DEVOLVER {TiempoTotal, Resultado, MaquinasPorTarea}

FIN FUNCION
```
