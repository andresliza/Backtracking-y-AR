FUNCION AlgoritmoVoraz(N, M, Tiempos[N][M])

   TareasPendientes = {1, 2, ..., N}     // lista de tareas pendientes
   TiempoAcumulado[M] = {0, 0, ..., 0} // tiempo acumulado en cada máquina
   Resultado = []                // orden de selección de las tareas
   MaquinasPorTarea = []         // el elemento i refleja qué máquina se eligió para la tarea i

   MIENTRAS TareasPendientes NO esté vacío HACER
   
       MejorTarea = -1
       MejorMaquina = -1
       MinimoFin = INFINITO // para que el primer si anidado en los bucles siempre se cumpla
       
       // para cada tarea...
       PARA CADA tarea EN TareasPendientes HACER
           // analizamos su tiempo en cada máquina (el acumulado + el que toma la tarea en la máquina)
           PARA maq = 1 HASTA M HACER
               TiempoFin = TiempoAcumulado[maq] + Tiempos[tarea][maq]
               
               // si ese tiempo es menor que el mínimo, tenemos un mejor candidato
               SI TiempoFin < MinimoFin ENTONCES
                   MinimoFin = TiempoFin
                   MejorTarea = tarea
                   MejorMaquina = maq
               FIN SI
           FIN PARA
       FIN PARA
       
       // actualizamos el tiempo acumulado de la mejor maquina y añadimos la mejor tarea al resultado
       TiempoAcumulado[MejorMaquina] = MinimoFin
       Resultado.Añadir(MejorTarea)
       // añadimos la máquina que ha resultado mejor para esa tarea en el orden de selección
       MaquinasPorTarea.Añadir(MejorMaquina)
       // y eliminamos esa tarea de las pendientes
       TareasPendientes.Eliminar(MejorTarea)
       
   FIN MIENTRAS
   
   // el resultado final es la carga máxima entre todas las máquinas
   TiempoTotal = Maximo(TiempoAcumulado)
   
   DEVOLVER {TiempoTotal, Resultado, MaquinasPorTarea}

FIN FUNCION

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

        // Ejecutar algoritmo
        {TiempoTotal, Resultado, MaquinasPorTarea} = AlgoritmoVoraz(N, M, Tiempos)
        
        // Escribir resultados según el formato de salida
        Escribir(TiempoTotal)
        Escribir(Resultado)           // N números: orden de las tareas
        Escribir(MaquinasPorTarea)    // N números: máquina de cada tarea
    FIN PARA

FIN FUNCION
